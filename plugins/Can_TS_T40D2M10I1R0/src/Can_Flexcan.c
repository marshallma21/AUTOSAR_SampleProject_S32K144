/**
*   @file    Can_FlexCan.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - LLD module implementation.
*   @details Low Level Driver implementation.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
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
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Can_Flexcan_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Flexcan_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Flexcan_c_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Flexcan_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The code is not dynamically linked. An absolute stack address is obtained when taking the address of the near auto variable.
* A source of error in writing dynamic code is that the stack segment may be different from the data segment.
*
* @section Can_Flexcan_c_REF_5
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_Flexcan_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_Flexcan_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_Flexcan_c_REF_8
* Violates MISRA 2004 Required Rule 13.7, Results boolean operations whose results are maybe variant.
*
* @section Can_Flexcan_c_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type.
*
*
* @section Can_Flexcan_c_REF_10
* Violates MISRA 2004 Required Rule 8.7, Global variables containing the generated configuration
* shall be defined in a separate source file and can't be defined inside a function although it is accessed
* by a single function.
*
* @section Can_Flexcan_c_REF_11
* Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) should be
* effectively Boolean. Expressions that are effectively Boolean
* should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).
*
* @section Can_Flexcan_c_REF_12
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if:
* (a) it is not a conversion to a wider integer type of the samesignedness, or
* (b) the expression is complex, or
* (c) the expression is not constant and is a function argument, or
* (d) the expression is not constant and is a return expression
*
* @section Can_Flexcan_c_REF_13
* Violates MISRA 2004 Advisory Rule 11.4 , A cast should not be performed between a pointer to object type
* and a different pointer to object type.
*
* @section Can_Flexcan_c_REF_14
* Violates MISRA 2004 Required Rule 17.1 , Pointer arithmetic shall only be applied to pointers that address
* an array or array element.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_IPW.h"
#include "CanIf_Cbk.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
#if CAN_ENABLE_USER_MODE_SUPPORT == STD_ON
  #ifndef USER_MODE_REG_PROT_ENABLED
     #define USER_MODE_REG_PROT_ENABLED   (STD_ON)
  #endif
  #include "RegLockMacros.h"
#endif
#endif

/*
* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "SchM_Can.h"
#include "Mcal.h"
#ifndef CAN_TIMEOUT_AS_LOOP
    #include "Os.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Can_FlexCan.c
*/
#define CAN_FLEXCAN_VENDOR_ID_C                    43
#define CAN_FLEXCAN_MODULE_ID_C                    80
/*
* @violates @ref Can_Flexcan_c_REF_5 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
#define CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C     4
/*
* @violates @ref Can_Flexcan_c_REF_5 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
#define CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C     2
/*
* @violates @ref Can_Flexcan_c_REF_5 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
#define CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_C  2
#define CAN_FLEXCAN_SW_MAJOR_VERSION_C             1
#define CAN_FLEXCAN_SW_MINOR_VERSION_C             0
#define CAN_FLEXCAN_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CAN header file are of the same vendor */
#if (CAN_FLEXCAN_VENDOR_ID_C != CAN_FLEXCAN_VENDOR_ID_H)
    #error "Can_FlexCan.c and Can_FlexCan.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C    != CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C    != CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_C != CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_FlexCan.c and Can_FlexCan.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_FLEXCAN_SW_MAJOR_VERSION_C != CAN_FLEXCAN_SW_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_SW_MINOR_VERSION_C != CAN_FLEXCAN_SW_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_SW_PATCH_VERSION_C != CAN_FLEXCAN_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_FlexCan.c and Can_FlexCan.h are different"
#endif


/* Check if current file and CAN_IPW header file are of the same vendor */
#if (CAN_FLEXCAN_VENDOR_ID_C != CAN_IPW_VENDOR_ID_H)
    #error "Can.c and Can_IPW.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can.c and Can_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_FLEXCAN_SW_MAJOR_VERSION_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_FLEXCAN_SW_MINOR_VERSION_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_FLEXCAN_SW_PATCH_VERSION_C != CAN_IPW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can.c and Can_IPW.h are different"
#endif

/* Check if current file and CANIF_CBK header file are of the same version */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != CANIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != CANIF_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can.c and CanIf_Cbk.h are different"
    #endif
  #endif
#endif



/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_FlexCan.c and Det.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #ifdef CAN_ENABLE_USER_MODE_SUPPORT
   #if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
    /* Check if current file and Mcal.h file are of the same Software version */
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.c and Mcal.h are different"
    #endif
    /* Check if current file and StdRegMacros.h file are of the same Software version */
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.c and StdRegMacros.h are different"
    #endif
   #endif
  #endif
  #ifndef CAN_TIMEOUT_AS_LOOP
    #if ((CAN_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != OS_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != OS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of FlexCan.c and Mcal.h are different"
    #endif
  #endif
#endif
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

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"
/**
* @brief          Array holding current status/run-time configuration of individual FlexCAN controllers
* @details        Array holding current status/run-time configuration of individual FlexCAN controllers
*                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for id, INT nesting level,
*                 Index of MB buffer being cancelled, Index of the first MB used for Tx , Controller Options.
*
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatuses[CAN_MAXCTRL_CONFIGURED];

/**
* @brief          Variable to hold the number of tick correspond to TimeOutDuration
* @details        Variable to hold the number of tick correspond to TimeOutDuration
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(uint32, CAN_VAR) Can_u32TicksDelayDuration;

#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"

#define CAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"


 /**
* @brief          define number of bytes of MBs
* @details        define number of bytes of MBs
*
*/
#if (CAN_FD_MODE_ENABLE == STD_ON)
    /*maximum threshold values for DLC*/
    /* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    CONST(uint8, CAN_CONST)         Can_Flexcan_aDataLengthMax[CAN_FLEXCAN_NUM_VAL_DLC_U8] = {CAN_FLEXCAN_MAX_PAYLOAD8_U8, 
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD12_U8,
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD16_U8,
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD20_U8,
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD24_U8,
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD32_U8,
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD48_U8,
                                                                                              CAN_FLEXCAN_MAX_PAYLOAD64_U8
                                                                                             };
    /*minimum threshold values for DLC*/ 
    /* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    /* @violates @ref Can_Flexcan_c_REF_10 Violates MISRA 2004 Advisory Rule 8.7, Global variables containing the generated configuration */
    CONST(uint8, CAN_CONST)         Can_Flexcan_aDataLengthMin[CAN_FLEXCAN_NUM_VAL_DLC_U8] = {CAN_FLEXCAN_MIN_PAYLOAD0_U8, 
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD9_U8,
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD13_U8,
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD17_U8,
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD21_U8,
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD25_U8,
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD33_U8,
                                                                                              CAN_FLEXCAN_MIN_PAYLOAD49_U8
                                                                                             };
#endif

/**
* @brief          define number of filter's payload
* @details        define number of filter's payload
*
*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
    /* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    /* @violates @ref Can_Flexcan_c_REF_10 Violates MISRA 2004 Advisory Rule 8.7, Global variables containing the generated configuration */
    CONST(uint8, CAN_CONST)         Can_Flexcan_aNumFilter[CAN_FLEXCAN_NUM_FILT_PAYLOAD_U8] = {CAN_FLEXCAN_FILTER_PAYLOAD7_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD9_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD11_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD13_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD15_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD17_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD19_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD21_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD23_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD25_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD27_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD29_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD31_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD33_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD35_U8,
                                                                                               CAN_FLEXCAN_FILTER_PAYLOAD37_U8
                                                                                              };
 #endif

/**
* @brief          CAN base address array
* @details        CAN base address array
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(uint32, CAN_CONST) Can_u32BaseAddress[] = {
#ifdef  FLEXCAN0_BASEADDR
        FLEXCAN0_BASEADDR,
#endif /* FLEXCAN0_BASEADDR */
#ifdef  FLEXCAN1_BASEADDR
        FLEXCAN1_BASEADDR,
#endif /* FLEXCAN1_BASEADDR */
#ifdef  FLEXCAN2_BASEADDR
        FLEXCAN2_BASEADDR,
#endif /* FLEXCAN2_BASEADDR */
#ifdef  FLEXCAN3_BASEADDR
        FLEXCAN3_BASEADDR,
#endif /* FLEXCAN3_BASEADDR */
#ifdef  FLEXCAN4_BASEADDR
        FLEXCAN4_BASEADDR,
#endif /* FLEXCAN4_BASEADDR */
#ifdef  FLEXCAN5_BASEADDR
        FLEXCAN5_BASEADDR,
#endif /* FLEXCAN5_BASEADDR */
#ifdef  FLEXCAN6_BASEADDR
        FLEXCAN6_BASEADDR,
#endif /* FLEXCAN6_BASEADDR */
#ifdef  FLEXCAN7_BASEADDR
        FLEXCAN7_BASEADDR
#endif /* FLEXCAN7_BASEADDR */
};
    
    
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */  

CONST(Can_MaskFlagType, CAN_CONST) Can_IflagImask[(uint8)((uint8)CAN_MAXMB_SUPPORTED >> FLEXCAN_MB_SHIFT5BIT_U8)][FLEXCAN_CONTROLLERS_NO] =
        {
                
                {
                   #ifdef  FLEXCAN0_BASEADDR
                    {
                        (FLEXCAN0_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN0_BASEADDR + 0x28U )
                    }
                   #endif
                   #ifdef  FLEXCAN1_BASEADDR
                   ,{
                        (FLEXCAN1_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN1_BASEADDR + 0x28U)
                    }
                   #endif
                   #ifdef  FLEXCAN2_BASEADDR
                   ,{
                        (FLEXCAN2_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN2_BASEADDR + 0x28U)
                    }
                   #endif
                   #ifdef  FLEXCAN3_BASEADDR
                   ,{
                        (FLEXCAN3_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN3_BASEADDR + 0x28U)
                    }
                   #endif
                   #ifdef  FLEXCAN4_BASEADDR
                   ,{
                        (FLEXCAN4_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN4_BASEADDR + 0x28U)
                    }
                   #endif 
                   #ifdef  FLEXCAN5_BASEADDR
                   ,{
                        (FLEXCAN5_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN5_BASEADDR + 0x28U)
                    }
                   #endif
                   #ifdef  FLEXCAN6_BASEADDR
                   ,{
                        (FLEXCAN6_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN6_BASEADDR + 0x28U )
                    }
                   #endif
                   #ifdef  FLEXCAN7_BASEADDR
                   ,{
                        (FLEXCAN7_BASEADDR + 0x30U)
                        ,
                        (FLEXCAN7_BASEADDR + 0x28U)
                    }
                   #endif
                },
            #if ((CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8) || (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_96_U8 )) 
                {
                   #ifdef  FLEXCAN0_BASEADDR
                    {
                        (FLEXCAN0_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN0_BASEADDR + 0x24U )
                    }
                   #endif
                   #ifdef  FLEXCAN1_BASEADDR
                   ,{
                        (FLEXCAN1_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN1_BASEADDR + 0x24U )
                    }
                   #endif
                   #ifdef  FLEXCAN2_BASEADDR
                   ,{
                        (FLEXCAN2_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN2_BASEADDR + 0x24U ) 
                    }
                   #endif
                   #ifdef  FLEXCAN3_BASEADDR
                   ,{
                        (FLEXCAN3_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN3_BASEADDR + 0x24U )
                    }
                   #endif
                   #ifdef  FLEXCAN4_BASEADDR
                   ,{
                        (FLEXCAN4_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN4_BASEADDR + 0x24U ) 
                    }
                   #endif
                   #ifdef  FLEXCAN5_BASEADDR
                   ,{
                        (FLEXCAN5_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN5_BASEADDR + 0x24U ) 
                    }
                   #endif
                   #ifdef  FLEXCAN6_BASEADDR
                   ,{
                        (FLEXCAN6_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN6_BASEADDR + 0x24U ) 
                    }
                   #endif
                   #ifdef  FLEXCAN7_BASEADDR
                   ,{
                        (FLEXCAN7_BASEADDR + 0x2CU )
                        ,
                        (FLEXCAN7_BASEADDR + 0x24U ) 
                    }
                   #endif
                },
            #endif        
            #if  (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_96_U8 )
                {
                    #ifdef  FLEXCAN0_BASEADDR
                        {
                            (FLEXCAN0_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN0_BASEADDR + 0x6CU ) 
                        }
                    #endif
                    #ifdef  FLEXCAN1_BASEADDR
                       ,{
                            (FLEXCAN1_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN1_BASEADDR + 0x6CU )
                        }
                    #endif
                    #ifdef  FLEXCAN2_BASEADDR
                       ,{
                            (FLEXCAN2_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN2_BASEADDR + 0x6CU )
                        }
                    #endif
                    #ifdef  FLEXCAN3_BASEADDR
                       ,{
                            (FLEXCAN3_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN3_BASEADDR + 0x6CU )
                        }
                    #endif
                    #ifdef  FLEXCAN4_BASEADDR
                       ,{
                            (FLEXCAN4_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN4_BASEADDR + 0x6CU )
                        }
                    #endif
                    #ifdef  FLEXCAN5_BASEADDR
                       ,{
                            (FLEXCAN5_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN5_BASEADDR + 0x6CU )
                        }
                    #endif
                    #ifdef  FLEXCAN6_BASEADDR
                       ,{
                            (FLEXCAN6_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN6_BASEADDR + 0x6CU )
                        }
                    #endif
                    #ifdef  FLEXCAN7_BASEADDR
                       ,{
                       
                            (FLEXCAN7_BASEADDR + 0x74U )
                            ,
                            (FLEXCAN7_BASEADDR + 0x6CU )
                        }
                    #endif
                }
            #endif
    };
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"


#define CAN_START_SEC_CODE
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Can_MemMap.h"


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
extern FUNC(boolean, COM_APPL_CODE) CanLPduReceiveCalloutFunction(uint8 Hrh,Can_IdType CanId,uint8 CanDlc,const uint8 *CanSduPtr);

LOCAL_INLINE FUNC(void, CAN_CODE) Can_FlexCan_DisableInterrupts (VAR(uint8, AUTOMATIC) u8Controller);

LOCAL_INLINE FUNC(void, CAN_CODE) Can_FlexCan_EnableInterrupts ( \
                                        VAR(uint8, AUTOMATIC) u8Controller, \
                                        P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor \
                                                               );
/**
* Compiler_Warning: Ready for MPC55XX platform
*/
LOCAL_INLINE FUNC(uint32, CAN_CODE) Can_FlexCan_GetFlagIndex (CONST(uint32, AUTOMATIC) u32flagReg);

#if (CAN_RXFIFO_ENABLE == STD_ON)
    static FUNC (void, CAN_CODE) Can_FlexCan_InitRxFiFo( VAR(uint8, AUTOMATIC) Controller, VAR(uint8, AUTOMATIC) u8HwOffset);
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

static FUNC (void, CAN_CODE) Can_FlexCan_InitTransmitMBs( VAR(uint8, AUTOMATIC) Controller, VAR(uint8, AUTOMATIC) u8HwOffset);

static FUNC (void, CAN_CODE) Can_FlexCan_InitReceiveMBs( VAR(uint8, AUTOMATIC) Controller, VAR(uint8, AUTOMATIC) u8HwOffset );

#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
    static FUNC (void, CAN_CODE) Can_FlexCan_InitRxGlobalMask( VAR(uint16, AUTOMATIC) u16MBGlobalIndex, VAR(uint8, AUTOMATIC) u8HwOffset, VAR(uint8, AUTOMATIC) u8RxglobalMskFlag);
#endif
static FUNC (void, CAN_CODE) Can_FlexCan_InitRxInvidualMask( VAR(uint16, AUTOMATIC) u16MBGlobalIndex, VAR(uint8, AUTOMATIC) u8HwOffset);
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToStopMode(  VAR(uint8, AUTOMATIC) Controller,
                                                                            P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor,
                                                                            VAR(boolean, AUTOMATIC) canif_notification_required
                                                                          );
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToStartMode(  VAR(uint8, AUTOMATIC) Controller,
                                                                            P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor
                                                                          );
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToSleepMode(  VAR(uint8, AUTOMATIC) Controller );
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToWakeupMode(  VAR(uint8, AUTOMATIC) Controller );
static FUNC (void, CAN_CODE) Can_FlexCan_ProcessTxPoll( CONST(uint8, AUTOMATIC) controller, CONST(uint16, AUTOMATIC) u16MBGlobalIndex );

#if (CAN_RXFIFO_ENABLE == STD_ON)
static FUNC (void, CAN_CODE) Can_FlexCan_ProcessRxFifo( CONST(uint8, AUTOMATIC) controller, CONST(uint8, AUTOMATIC) u8MbIndex);
#endif

static FUNC (void, CAN_CODE) Can_FlexCan_ProcessRxNormal( CONST(uint8, AUTOMATIC) controller, CONST(uint16, AUTOMATIC) u16MBGlobalIndex );
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_UpdateMB( VAR(uint8, AUTOMATIC) u8CtrlId, VAR(uint16, AUTOMATIC) u16MBGlobalIndex ,
                                                                P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo, VAR(boolean, AUTOMATIC) bEnabledFD
                                                            );
#if (CAN_DEV_ERROR_DETECT == STD_ON)
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_ValidHth (  Can_HwHandleType Hth,
                                                               P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo,
                                                               VAR(uint16, AUTOMATIC) u16MBGlobalIndex,
                                                               VAR(boolean, AUTOMATIC) bEnabledFD
                                                            );
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

#ifdef CAN_FLEXCAN_CLKSRC_AVAIABLE
static FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_SellectClockSource( VAR(uint8, AUTOMATIC) u8Controller, VAR(uint8, AUTOMATIC) u8HwOffset, VAR(uint8, AUTOMATIC) u8BaudrateIndex );
#endif /* CAN_FLEXCAN_CLKSRC_AVAIABLE */
static FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_GotoFreezeMode( VAR(uint8, AUTOMATIC) u8HwOffset);

static FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_ResetController( VAR(uint8, AUTOMATIC) u8HwOffset);

#if (CAN_FD_MODE_ENABLE == STD_ON)                                                              
    #ifdef ERR_IPV_FLEXCAN_0016
        #if (ERR_IPV_FLEXCAN_0016 == STD_ON)
            static FUNC (void, CAN_CODE) Can_FlexCan_SetFDENBitErrata( VAR(uint8, AUTOMATIC) u8HwOffset );
        #else
            #error : the define ERR_IPV_FLEXCAN_0016 must not be STD_OFF
        #endif /* (ERR_IPV_FLEXCAN_0016 == STD_ON) */
    #endif /* (ERR_IPV_FLEXCAN_0016) */
#endif /* (CAN_FD_MODE_ENABLE == STD_ON) */

/*================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

LOCAL_INLINE FUNC(void, CAN_CODE) Can_FlexCan_DisableInterrupts (VAR(uint8, AUTOMATIC) u8Controller)
{
    VAR(uint8, AUTOMATIC) u8RegCount=0U;
    VAR(uint8, AUTOMATIC) u8HwOffset=0U;
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[u8Controller].u8ControllerOffset;
    do
    {
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_WRITE32( Can_IflagImask[u8RegCount][u8HwOffset].u32CanImask, (uint32)(0U));
        u8RegCount++;
    }
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while(u8RegCount < (CanStatic_pControlerDescriptors[u8Controller].u8NumberOfMB >> FLEXCAN_MB_SHIFT5BIT_U8));
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07();
    /* Disable BusOff, Error, TxW, RxW interrupts. */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_CLEAR32( FLEXCAN_CTRL(u8HwOffset), FLEXCAN_CTRL_BOFFMSK_U32);
    
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_CLEAR32( FLEXCAN_CTRL(u8HwOffset), FLEXCAN_CTRL_ERRMSK_U32);
    
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07();
}


/*================================================================================================*/
LOCAL_INLINE FUNC(void, CAN_CODE) Can_FlexCan_EnableInterrupts ( \
                                        VAR(uint8, AUTOMATIC) u8Controller, \
                                        P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor \
                                                               )
{
    VAR(uint8, AUTOMATIC) u8RegCount=0U;
    VAR(uint8, AUTOMATIC) u8HwOffset=0U;
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[u8Controller].u8ControllerOffset;
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if  ( (CAN_CONTROLLERCONFIG_TXPOL_EN_U32 != (CAN_CONTROLLERCONFIG_TXPOL_EN_U32 & CanStatic_pControlerDescriptors[u8Controller].u32Options)) || \
         (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 != (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & CanStatic_pControlerDescriptors[u8Controller].u32Options)) \
        )
    {
        /* Enable INTs from MBs. */
        do
        {
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32(Can_IflagImask[u8RegCount][u8HwOffset].u32CanImask, Can_ControllerStatuses[u8Controller].u32MBInterruptMask[u8RegCount]);
            u8RegCount++;
        }
 
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        while(u8RegCount < (CanStatic_pControlerDescriptors[u8Controller].u8NumberOfMB >> FLEXCAN_MB_SHIFT5BIT_U8));
        /* Mark flag that tells if at least one INT is enabled. */
    }

    /*
      (CAN204) The Can module shall track all individual enabling and disabling of interrupts in other functions (i.e. Can_SetControllerMode), so that the correct interrupt enable state can be restored.
    */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08();
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( CAN_CONTROLLERCONFIG_BOPOL_EN_U32 != (CAN_CONTROLLERCONFIG_BOPOL_EN_U32 & CanStatic_pControlerDescriptors[u8Controller].u32Options))
    {
        /* BusOff - enable the interrupt. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_CTRL(u8HwOffset), FLEXCAN_CTRL_BOFFMSK_U32);
        
        /* Mark flag that tells if at least one INT is enabled. */
    }
    if ( CAN_CONTROLLERCONFIG_ERR_EN_U32 == (CAN_CONTROLLERCONFIG_ERR_EN_U32 & pCanControlerDescriptor->u32Options))
    {
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_CTRL(u8HwOffset), FLEXCAN_CTRL_ERRMSK_U32);
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08();
}

/*================================================================================================*/
/**
* Compiler_Warning: Ready for MPC55XX platform
*/

LOCAL_INLINE FUNC(uint32, CAN_CODE) Can_FlexCan_GetFlagIndex (CONST(uint32, AUTOMATIC) u32flagReg)
    {
        #ifdef MCU_MPC55XX
            return (uint32)(32U - __CLZ32 (u32flagReg));
        #else
            VAR(uint32, AUTOMATIC) temp = 0U;
            /* @violates @ref Can_Flexcan_c_REF_11 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
               should be effectively Boolean. Expressions that are effectively Boolean
               should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:). */

            /* @violates @ref Can_Flexcan_c_REF_12 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
               converted to a different underlying type if:
              (a) it is not a conversion to a wider integer type of the samesignedness, or
              (b) the expression is complex, or
              (c) the expression is not constant and is a function argument, or
              (d) the expression is not constant and is a return expression */
            temp = u32flagReg ^ (u32flagReg - !!u32flagReg); 
            /* @violates @ref Can_Flexcan_c_REF_13 Violates MISRA 2004 Advisory Rule 11.4 , A cast should not be performed between a pointer to object type
               and a different pointer to object type.*/
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, Pointer arithmetic other than array indexing used 
               This violation is due to the structure of the types used.*/
            /* @violates @ref Can_Flexcan_c_REF_12 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
               converted to a different underlying type if:
               (a) it is not a conversion to a wider integer type of the samesignedness, or
               (b) the expression is complex, or
               (c) the expression is not constant and is a function argument, or
               (d) the expression is not constant and is a return expression*/
            /* @violates @ref Can_Flexcan_c_REF_14 Violates MISRA 2004 Required Rule 17.1 , Pointer arithmetic 
               shall only be applied to pointers that address an array or array element.*/
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2,  Taking address of near auto variable
                The code is not dynamically linked. An absolute stack address is obtained when taking the address of the near auto variable.
                A source of error in writing dynamic code is that the stack segment may be different from the data segment. */
            return (uint32)((((uint32*)&temp)[1]>>20)-1022); 
        #endif
    }

/*================================================================================================*/
/**
* @brief          This function performs to set the FDEN bit in the CAN_MCR register for Can FD.
* @details        This function performs to set the FDEN for Can FD (Errata e10368).
*                 This routine is called by:
*                  - Can_ChangeBaudrate() from Can.c file.
*
* @param[in]      Controller hardware offset
*
* @pre            FlexCAN is already in freeze mode.     
*
*
*/
#if (CAN_FD_MODE_ENABLE == STD_ON)
    #ifdef ERR_IPV_FLEXCAN_0016
        #if (ERR_IPV_FLEXCAN_0016 == STD_ON)
static FUNC (void, CAN_CODE) Can_FlexCan_SetFDENBitErrata( VAR(uint8, AUTOMATIC) u8HwOffset )
{
#if STD_OFF == CAN_E10368_INCONSISTENT
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
  #ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
  #endif
#endif

#if STD_ON == CAN_E10368_INCONSISTENT
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), (uint32)(FLEXCAN_MCR_FDEN_U32));
#else
    
    #ifdef ERR_IPV_FLEXCAN_0016_ACTIVE
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if (ERR_IPV_FLEXCAN_0016_ACTIVE == (boolean)TRUE)
    #endif /*ERR_IPV_FLEXCAN_0016_ACTIVE*/
        {
            /* Step 3: Set the LPB (Loop Back Mode) bit of the CAN_CTRL1 register. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_CTRL(u8HwOffset), (uint32)(FLEXCAN_CTRL_LPB_U32));
            
            /* Step 4: Configure only one message buffer to be transmitted.*/
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            REG_WRITE32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(0U)), (uint32)(0x682U) << (uint32)FLEXCAN_STANDARD_ID_SHIFT_U32);
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            REG_WRITE32( FLEXCAN_MB((u8HwOffset), (uint32)(0U)), (uint32)(FLEXCAN_MBCS_CODETX_U32 | FLEXCAN_MBCS_CODETXEN_U32 | FLEXCAN_MBCS_SRR_U32| FLEXCAN_MBCS_RTR_U32 | ((uint32)0x5U << (uint32)16U)) );
            
            /*Extra steps, configure standard baudrate and fd baudrate */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32( FLEXCAN_CTRL(u8HwOffset), (uint32)((uint32)0x00490001U | FLEXCAN_CTRL_LPB_U32));
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32(FLEXCAN_FDCBT(u8HwOffset), (uint32)(0x00000421U));
            
            /* Step 5: Set the FDEN bit of the CAN_MCR register. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FDEN_U32);
            
            /* Step 6: Clear the HALT bit of the MCR register to leave freeze mode. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
            
            /* Step 7: Wait the FRZACK bit of the CAN_MCR register to be cleared by the hardware. */
            u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            while ( (FLEXCAN_MCR_FRZACK_U32 == ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
                    (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
                  )
            {
        #ifdef CAN_TIMEOUT_AS_LOOP
                u32TotalElapsedTime++;
        #else
                /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
                u32TotalElapsedTime += u32ElapsedTime;
        #endif
            }
            
            /* Step 8: Wait the respective bit of the CAN_IFLAG register to be set (successfully transmission in loop back mode). */
            u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            while ( ( (uint32)0U == ((uint32)REG_READ32(FLEXCAN_IFLAG1(u8HwOffset))) ) && \
                    (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
                  )
            {
        #ifdef CAN_TIMEOUT_AS_LOOP
                u32TotalElapsedTime++;
        #else
                /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
                u32TotalElapsedTime += u32ElapsedTime;
        #endif
            }
            
            /* Step 9: Clear the respective bit of the CAN_IFLAG register by writing 1. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32(  FLEXCAN_IFLAG1(u8HwOffset), (uint32)0xFFFFFFFFU);
            
            /* Step 10: Set the HALT and FRZ bits of the CAN_MCR register. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
            
            /* Step 11: Wait the FRZACK bit of the CAN_MCR register to be set by the hardware. */
            u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            while ( (FLEXCAN_MCR_FRZACK_U32 != ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
                    (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
                  )
            {
        #ifdef CAN_TIMEOUT_AS_LOOP
                u32TotalElapsedTime++;
        #else
                /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
                u32TotalElapsedTime += u32ElapsedTime;
        #endif
            }
            
            /*Extra steps, configure standard baudrate and fd baudrate */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32( FLEXCAN_CTRL(u8HwOffset), (uint32)0U );
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32(FLEXCAN_FDCBT(u8HwOffset), (uint32)0U);
            /* Step 12: Clear the LPB (Loop Back Mode) bit of the CAN_CTRL1 register. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_CTRL(u8HwOffset), (uint32)(FLEXCAN_CTRL_LPB_U32));
        }
    #ifdef ERR_IPV_FLEXCAN_0016_ACTIVE
       else
       {
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), (uint32)(FLEXCAN_MCR_FDEN_U32));
       }
    #endif /*ERR_IPV_FLEXCAN_0016_ACTIVE*/
#endif /* Errata inconsistency */
}
        #endif /* (ERR_IPV_FLEXCAN_0016 == STD_ON) */
    #endif /* (ERR_IPV_FLEXCAN_0016) */
#endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
/*================================================================================================*/
/**
* @brief          Service for Rx FIFO initialization in the Can_FlexCan_InitController function
* @details        Service for Rx FIFO initialization in the Can_FlexCan_InitController function
*
*                 This routine is called by:
*                  - Can_FlexCan_InitController()
*
* @param[in]      + Controller: CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*                 + u8HwOffset: The hardware offset for this controller.
*
*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
static FUNC (void, CAN_CODE) Can_FlexCan_InitRxFiFo( VAR(uint8, AUTOMATIC) Controller, VAR(uint8, AUTOMATIC) u8HwOffset)
{
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Controller hardware offset on chip. */
    
    /* Used to save the the index pointing to the table id connfiguration. */
    VAR(uint8, AUTOMATIC)             u8RxFifoTableIdIndex = 0U;
    /* Used to index the Table ID for RxFifo. */
    VAR(uint8, AUTOMATIC)             u8RxFifoTableId = 0U;
    /* Used to access configured table id and filtermask. */
    VAR(uint8, AUTOMATIC)             u8TempIndex = 0U;
    /* Used to filter FIFO number */
    VAR(uint8, AUTOMATIC)             u8FilterIndex = 0U;
    /* Fill the local pointer copy with address of the Controller Descriptor.  */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &(Can_pCurrentConfig->ControlerDescriptors[Controller]);
    
    /* If RX FIFO is used, then configure the Controller's registers for Rx Fifo. */
    if ( CAN_CONTROLLERCONFIG_RXFIFO_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_RXFIFO_U32) )
    {
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FEN_U32) ;
#ifndef CAN_NOT_SUPPORT_CTRL2_RXFGMASK
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_RMW32( FLEXCAN_CTRL2(u8HwOffset),(FLEXCAN_CTRL2_RFFN_U32) ,(uint32)((((uint32)Can_pCurrentConfig->ControlerDescriptors[Controller].u8RxFiFoUsedMb-(uint32)8U)/(uint32)2U)<<24U));
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_RXFGMASK(u8HwOffset), (((uint32)(Can_pCurrentConfig->ControlerDescriptors[Controller].u32RxFifoGlobalMask)) & FLEXCAN_RXFGMASK_CONFIG_MASK_U32));
#endif /* defined CAN_NOT_SUPPORT_CTRL2_RXFGMASK */
        /* Processing MB must start after the last MB used by the Rx Fifo filters */
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_11();
        switch (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_IDAM_MASK_U32)
        {
            case CAN_CONTROLLERCONFIG_IDAM_A_U32:
                /* One full ID per filter element - clear IDAM bits. */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_RMW32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_IDAM_U32, ((uint32)(FLEXCAN_MCR_IDAM32_U32))) ;
                break;

            case CAN_CONTROLLERCONFIG_IDAM_B_U32:
                /* Two full standard IDs or two partial 14-bit exteneded IDs per filter element. */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                 REG_RMW32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_IDAM_U32, ((uint32)(FLEXCAN_MCR_IDAM16_U32))) ;
                 break;

            case CAN_CONTROLLERCONFIG_IDAM_C_U32:
                /* Four partial 8-bit IDs (standard or extended) per filter element. */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_RMW32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_IDAM_U32, ((uint32)(FLEXCAN_MCR_IDAM08_U32))) ;
                break;

            case CAN_CONTROLLERCONFIG_IDAM_D_U32:
                /* RX Fifo is enabled, but all frames will be rejected. */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_RMW32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_IDAM_U32, ((uint32)(FLEXCAN_MCR_IDAM_U32))) ;
                break;
            default:
                break;
        } /* end switch. */
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_11();
        /*Initialize the index used to acces the fifo Rx fifo filter list for all controllers*/
        u8RxFifoTableIdIndex = 0U;
        /* Calculate the index pointing to table id configuration. */
        for(u8TempIndex = 0U; u8TempIndex < Controller; u8TempIndex++)
        {            
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ( CAN_CONTROLLERCONFIG_RXFIFO_U32 == (Can_pCurrentConfig->ControlerDescriptors[u8TempIndex].u32Options & CAN_CONTROLLERCONFIG_RXFIFO_U32) )
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                u8RxFifoTableIdIndex = u8RxFifoTableIdIndex + (4U*(Can_pCurrentConfig->ControlerDescriptors[u8TempIndex].u8RxFiFoUsedMb-6U));
            }
        }

        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u8FilterIndex = ((Can_pCurrentConfig->ControlerDescriptors[Controller].u8RxFiFoUsedMb - 8U) / 2U);
        /* Init the IDTable and RXIMR registers of RxFifo. */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        for ( u8TempIndex = u8RxFifoTableIdIndex; u8TempIndex < (u8RxFifoTableIdIndex + (4U * (Can_pCurrentConfig->ControlerDescriptors[Controller].u8RxFiFoUsedMb - 6U))); u8TempIndex++)
        {
            /* Calculate the physical address for each table to write the Table ID and FilterMask. */
            REG_WRITE32( FLEXCAN_RXFIFO_ID((u8HwOffset), (uint32)(u8RxFifoTableId)), 
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            (uint32)(((Can_pCurrentConfig->pRxFiFoTableIdConfig) + u8TempIndex)->u32TableId) );

        #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
            /* Check if BCC support is enabled in configuration */
            if ( CAN_CONTROLLERCONFIG_BCC_EN_U32 != (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_BCC_EN_U32) )
            {
        #endif
              if (u8RxFifoTableId <= Can_Flexcan_aNumFilter[u8FilterIndex])
              {
                REG_WRITE32(FLEXCAN_RXIMR((u8HwOffset), (uint32)(u8RxFifoTableId)), 
                 /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                 /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                (uint32)((((Can_pCurrentConfig->pRxFiFoTableIdConfig) + u8TempIndex))->u32TableFilterMask));
              }  
        #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
            }
        #endif
            /* Increment the Table Id index for RxFifo configuration. */
            u8RxFifoTableId++;
        }

        /* Configure Interrupt Mask Bits in case handling of RX is implemented by interrupts (not by polling). */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( CAN_CONTROLLERCONFIG_RXPOL_EN_U32 != (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & CanStatic_pControlerDescriptors[Controller].u32Options) )
        {
            /* Check if Overflow RxFifo interrupt is enabled and set the IMASK bit if yes. */
            if ( CAN_CONTROLLERCONFIG_OVER_EN_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_OVER_EN_U32) )
            {
                Can_ControllerStatuses[Controller].u32MBInterruptMask[FLEXCAN_IMASK1_INDEX_U8] |= FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32;
            }
            /* Check if Warning RxFifo interrupt is enabled and set the IMASK bit if yes. */
            if ( CAN_CONTROLLERCONFIG_WARN_EN_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_WARN_EN_U32) )
            {
                Can_ControllerStatuses[Controller].u32MBInterruptMask[FLEXCAN_IMASK1_INDEX_U8] |= FLEXCAN_FIFO_WARNING_INT_MASK_U32;
            }
            /* If RxFifo is enabled, then frames are implicitly enabled. IDAM bits can filter the messages or can block at all. */
            Can_ControllerStatuses[Controller].u32MBInterruptMask[FLEXCAN_IMASK1_INDEX_U8] |= FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32;
        }
    }
}
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
/*================================================================================================*/
/**
* @brief          Initialize Filter Global Mask for Receive Message buffer
* @details        Initialize Filter Global Mask for Receive Message buffer
*
*                 This routine is called by:
*                  - Can_FlexCan_InitReceiveMBs()
*
* @param[in]      + u16MBGlobalIndex: Index of MB in the MBs' information structure to process.
*                 + u8HwOffset: The hardware offset for this controller.
*
*/

static FUNC (void, CAN_CODE) Can_FlexCan_InitRxGlobalMask( VAR(uint16, AUTOMATIC) u16MBGlobalIndex, VAR(uint8, AUTOMATIC) u8HwOffset, VAR(uint8, AUTOMATIC) u8RxglobalMskFlag)
{ 
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Variable for indexing the MBs inside a single controller. */
    VAR(uint8, AUTOMATIC)             u8MbCtrlIndex = 0U;
  
    /* Pointer to the MB container structure. */
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    /* Get the index of Hardware Message Buffer */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
    u8MbCtrlIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
    /* Check if BCC support is enabled in configuration */
#if (CAN_EXTENDEDID == STD_ON)
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( CAN_STANDARD == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdType) )
    {
#endif /* (CAN_EXTENDEDID == STD_ON) */

        if((u8MbCtrlIndex != FLEXCAN_MB_14_U8) && (u8MbCtrlIndex != FLEXCAN_MB_15_U8) && (u8RxglobalMskFlag == 0U))
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RXGMASK(u8HwOffset), (((uint32)((uint32)(Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex] << 18U)) & FLEXCAN_RXGMASK_CONFIG_MASK_U32));
            }
            else
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RXGMASK(u8HwOffset), (uint32)(FLEXCAN_NO_MASK_U32));
            }
            
        }
        else if(u8MbCtrlIndex == FLEXCAN_MB_14_U8)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {  
                 /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                 /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                 REG_WRITE32(FLEXCAN_RX14MASK(u8HwOffset), (((uint32)((uint32)(Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex] << 18U)) & FLEXCAN_RX14MASK_CONFIG_MASK_U32));
                 
            }
            else 
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(FLEXCAN_RX14MASK(u8HwOffset), ((FLEXCAN_NO_MASK_U32) & FLEXCAN_RX14MASK_CONFIG_MASK_U32));
               
            }
        }
        else if(u8MbCtrlIndex == FLEXCAN_MB_15_U8)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {  
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RX15MASK(u8HwOffset), (((uint32)((uint32)(Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex] << 18U)) & FLEXCAN_RX15MASK_CONFIG_MASK_U32));  
            }
            else
            {
                 /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                 /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                 /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 REG_WRITE32(FLEXCAN_RX15MASK(u8HwOffset), ((FLEXCAN_NO_MASK_U32) & FLEXCAN_RX15MASK_CONFIG_MASK_U32));
           
            }
        }
        else
        {
            /* Already the  RX Global MASK register is updated, its used as acceptance mask for all Rx MBs except for 14 and 15 MB's*/
        }
#if (CAN_EXTENDEDID == STD_ON)    
    }
    else
    {
        if((u8MbCtrlIndex != FLEXCAN_MB_14_U8) && (u8MbCtrlIndex != FLEXCAN_MB_15_U8) && (u8RxglobalMskFlag == 0U))
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {            
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RXGMASK(u8HwOffset), (((uint32)((Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex])) & FLEXCAN_RXGMASK_CONFIG_MASK_U32));
            }
            else
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RXGMASK(u8HwOffset), (uint32)(FLEXCAN_NO_MASK_U32));
            } 
        }
        else if(u8MbCtrlIndex == FLEXCAN_MB_14_U8)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {  
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RX14MASK(u8HwOffset), (((uint32)((Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex])) & FLEXCAN_RX14MASK_CONFIG_MASK_U32));
                
            }
            else 
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(FLEXCAN_RX14MASK(u8HwOffset), ((FLEXCAN_NO_MASK_U32) & FLEXCAN_RX14MASK_CONFIG_MASK_U32));
                
            }
        }
        else if(u8MbCtrlIndex == FLEXCAN_MB_15_U8)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RX15MASK(u8HwOffset), (((uint32)((Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex])) & FLEXCAN_RX15MASK_CONFIG_MASK_U32));
              
            }
            else 
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(FLEXCAN_RX15MASK(u8HwOffset), ((FLEXCAN_NO_MASK_U32) & FLEXCAN_RX15MASK_CONFIG_MASK_U32));
    
            }
        }
        else
        {
            /* Already the  RX Global MASK register is updated, its used as acceptance mask for all Rx MBs except for 14 and 15 MB's*/
        }  
    }
#endif /* (CAN_EXTENDEDID == STD_ON) */   
}
#endif /* CAN_BCC_SUPPORT_ENABLE == STD_ON */

/*================================================================================================*/
/**
* @brief          Initialize Filter Individual Mask for Receive Message buffer
* @details        Initialize Filter Individual Mask for Receive Message buffer
*
*                 This routine is called by:
*                  - Can_FlexCan_InitReceiveMBs()
*
* @param[in]      + u16MBGlobalIndex: Index of MB in the MBs' information structure to process.
*                 + u8HwOffset: The hardware offset for this controller.
*
*/
static FUNC (void, CAN_CODE) Can_FlexCan_InitRxInvidualMask( VAR(uint16, AUTOMATIC) u16MBGlobalIndex, VAR(uint8, AUTOMATIC) u8HwOffset)
{   
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Variable for indexing the MBs inside a single controller. */
    VAR(uint8, AUTOMATIC)             u8MbCtrlIndex = 0U;
       
    /* Pointer to the MB container structure. */
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    /* Get the index of Hardware Message Buffer */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
    u8MbCtrlIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
    
    #if (CAN_EXTENDEDID == STD_ON)
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( CAN_STANDARD == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdType) )
        {
    #endif /* (CAN_EXTENDEDID == STD_ON) */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(FLEXCAN_RXIMR((u8HwOffset), (uint32)(u8MbCtrlIndex)), (uint32)((uint32)(Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex] << 18U));

            }
            else
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                REG_WRITE32(FLEXCAN_RXIMR((u8HwOffset), (uint32)(u8MbCtrlIndex)), (uint32)(FLEXCAN_NO_MASK_U32));
                
            }            
    #if (CAN_EXTENDEDID == STD_ON)
        }
        else
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            if(CAN_MAXMASKCOUNT !=(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex))
            {                                   
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                REG_WRITE32(FLEXCAN_RXIMR((u8HwOffset), (uint32)(u8MbCtrlIndex)), (uint32)((Can_pCurrentConfig->pFilterMasks)[((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdMaskIndex]));
                
            }
            else
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(FLEXCAN_RXIMR((u8HwOffset), (uint32)(u8MbCtrlIndex)), (uint32)(FLEXCAN_NO_MASK_U32));
             
            }
        }
    #endif /* (CAN_EXTENDEDID == STD_ON) */
}

/*================================================================================================*/
/**
* @brief          Service for Receive Message buffer initialization in the Can_FlexCan_InitController function
* @details        Service for Receive Message buffer initialization in the Can_FlexCan_InitController function
*
*                 This routine is called by:
*                  - Can_FlexCan_InitController()
*
* @param[in]      + Controller: CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*                 + u8HwOffset: The hardware offset for this controller.
*
*/
static FUNC (void, CAN_CODE) Can_FlexCan_InitReceiveMBs( VAR(uint8, AUTOMATIC) Controller, VAR(uint8, AUTOMATIC) u8HwOffset )
{
#if ((CAN_RXFIFO_ENABLE == STD_ON) || (CAN_BCC_SUPPORT_ENABLE == STD_ON))
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
#endif/* ((CAN_RXFIFO_ENABLE == STD_ON) || (CAN_BCC_SUPPORT_ENABLE == STD_ON)) */
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Variable for indexing all the MBs fron hardware unit chain (all controllers). */
    VAR(uint16, AUTOMATIC)            u16MBGlobalIndex = 0U;
    /* ID of current MB. */
    VAR(uint32, AUTOMATIC)            u32MbMessageId = 0U;
    /* Temporary register value. */
    VAR(uint32, AUTOMATIC)            u32MbConfig = 0U;
    /* Variable for indexing the MBs inside a single controller. */
    VAR(uint8, AUTOMATIC)             u8MbCtrlIndex = 0U;
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
    /* The Flag prevent to set value to Global Mask many time */
    VAR(uint8, AUTOMATIC) u8RxglobalMskFlag = 0U;
#endif
    
#if ((CAN_RXFIFO_ENABLE == STD_ON) || (CAN_BCC_SUPPORT_ENABLE == STD_ON))
    /* Fill the local pointer copy with address of the Controller Descriptor.  */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &(Can_pCurrentConfig->ControlerDescriptors[Controller]);
#endif /* ((CAN_RXFIFO_ENABLE == STD_ON) || (CAN_BCC_SUPPORT_ENABLE == STD_ON)) */

    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);

    /* Parse all MBs that are of type RECEIVE from the chain list, but process only the MBs for controller transmitted as parameter in this function. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    for (u16MBGlobalIndex = 0U; u16MBGlobalIndex < (uint16)Can_pCurrentConfig->uCanFirstHTHIndex; u16MBGlobalIndex++)
    {
        /* u16MBGlobalIndex variable is incrementing based of existing HOH for MBs. */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        if ( Controller == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId))
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            u8MbCtrlIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
            
        #if (CAN_RXFIFO_ENABLE == STD_ON)
            /* Skip the MB configuration if FIFO is enabled and this is the FIRST RX MB configured . */
            if ( (CAN_CONTROLLERCONFIG_RXFIFO_U32 != (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_RXFIFO_U32)) ||
                 (u8MbCtrlIndex != (uint8)0U)
               )
            {
        #endif /* CAN_RXFIFO_ENABLE == STD_ON */
            #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                /* Check if BCC support is enabled in configuration */
                if ( CAN_CONTROLLERCONFIG_BCC_EN_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_BCC_EN_U32) )
                {
                    Can_FlexCan_InitRxGlobalMask( u16MBGlobalIndex, u8HwOffset, u8RxglobalMskFlag);
                    u8RxglobalMskFlag++;
                }
                else
                {
            #endif /* CAN_BCC_SUPPORT_ENABLE == STD_ON */
            
                    Can_FlexCan_InitRxInvidualMask( u16MBGlobalIndex, u8HwOffset);
                    
            #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)            
                }
            #endif /* CAN_BCC_SUPPORT_ENABLE == STD_ON */
            
                /* Get the ID of the current MB. */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                u32MbMessageId = (uint32)((pCanMbConfigContainer->pMessageBufferConfigsPtr + u16MBGlobalIndex)->uMessageId);

                /* Clear variable for every MB. */
                u32MbConfig = (uint32)0U;

            #if (CAN_EXTENDEDID == STD_ON)
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                if ( CAN_STANDARD == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->uIdType) )
                {
            #endif /* (CAN_EXTENDEDID == STD_ON) */               
                    /* Copy the Message ID (serves as acceptance filter for Rx MBs). For Standard type, ID is placed on bits 28:18 on ID Reg of the MB structure. */
                    u32MbMessageId <<= FLEXCAN_STANDARD_ID_SHIFT_U32;
            #if (CAN_EXTENDEDID == STD_ON)
                }
                else
                {
                    /* Set the IDE bit if the ID type is EXTENDED or MIXED. */
                    u32MbConfig = FLEXCAN_MBCS_IDE_U32 ;
                   /* For EXTENDED MB type the ID is placed starting from bits 0 ( unlike STANDARD type when is placed starting to bit 18). */
                }
            #endif /* (CAN_EXTENDEDID == STD_ON) */

                /* Enable the MB as a Rx object. MB is used for Rx & Mark the buffer as empty. */
                u32MbConfig |= (FLEXCAN_MBCS_CODERXEMPTY_U32);

                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                REG_WRITE32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)(u32MbConfig));
                /* Copy the Message ID (serves as acceptance filter for Rx MBs). */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                REG_WRITE32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)((u32MbMessageId) | ((REG_READ32(FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)))) & 0xE0000000U)));
                
                /* Save the mask bit from IMASK register for this MB used by Can_EnableControllerInterrupts() API. */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                if ( CAN_CONTROLLERCONFIG_RXPOL_EN_U32 != (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & CanStatic_pControlerDescriptors[Controller].u32Options) )
                {
                    Can_ControllerStatuses[Controller].u32MBInterruptMask[(uint8)((uint8)u8MbCtrlIndex >> FLEXCAN_MB_SHIFT5BIT_U8)] |= ((uint32)1U << (uint8)(u8MbCtrlIndex & FLEXCAN_MASK_32BITS_U32));
                }
            #if (CAN_RXFIFO_ENABLE == STD_ON)
                }
            #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

            /* At this point "u8MbCtrlIndex" is updated and considering RxFifo if enebaled also. */
            Can_ControllerStatuses[Controller].u8FirstTxMBIndex = u8MbCtrlIndex + 1U;
        }
    }
}

/*================================================================================================*/
/**
* @brief          Service for Transmit Message buffer initialization in the Can_FlexCan_InitController function
* @details        Service for Transmit Message buffer initialization in the Can_FlexCan_InitController function
*
*                 This routine is called by:
*                  - Can_FlexCan_InitController()
*
* @param[in]      + Controller: CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*                 + u8HwOffset: The hardware offset for this controller.
*
*/
static FUNC (void, CAN_CODE) Can_FlexCan_InitTransmitMBs( VAR(uint8, AUTOMATIC) Controller, VAR(uint8, AUTOMATIC) u8HwOffset )
{
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Variable for indexing all the MBs fron hardware unit chain (all controllers). */
    VAR(uint16, AUTOMATIC)            u16MBGlobalIndex = 0U;
    /* ID of current MB. */
    VAR(uint32, AUTOMATIC)            u32MbMessageId = 0U;
    /* Variable for indexing the MBs inside a single controller. */
    VAR(uint8, AUTOMATIC)             u8MbCtrlIndex = 0U;
    
    /* Fill the local pointer copy with address of the Controller Descriptor.  */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &(Can_pCurrentConfig->ControlerDescriptors[Controller]);
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);

    /* Parse all MBs that are of type TRANSMIT from the chain list, but process only the MBs for controller transmitted as parameter in this function. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    for (u16MBGlobalIndex = (uint16)Can_pCurrentConfig->uCanFirstHTHIndex; u16MBGlobalIndex < (uint16)pCanMbConfigContainer->uMessageBufferConfigCount; u16MBGlobalIndex++)
    {
        /* u16MBGlobalIndex variable is incrementing based of existing HOH for MBs. */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used  */
        if ( Controller == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId))
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4 */
            if (CAN_TRANSMIT == ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->eMBType )
            {
                    /* Enable the MB as an TX object. MB is used for Tx & SRR must be set for Tx buffers. */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                    REG_WRITE32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)(FLEXCAN_MBCS_CODETX_U32 | FLEXCAN_MBCS_SRR_U32));

                    /* Configure only PRIO field of MBCS register of every Tx MB. */
                    if ( CAN_CONTROLLERCONFIG_LPRIO_EN_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_LPRIO_EN_U32) )
                    {
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
                        u32MbMessageId = (uint32)((uint32)(((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8LocalPriority) << FLEXCAN_MB_ID_PRIO_SHIFT_U32) ;

                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        REG_WRITE32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)((u32MbMessageId) | ((REG_READ32(FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)))) & 0xE0000000U) ));

                    }
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    if ( CAN_CONTROLLERCONFIG_TXPOL_EN_U32 != (CAN_CONTROLLERCONFIG_TXPOL_EN_U32 & CanStatic_pControlerDescriptors[Controller].u32Options) )
                    {
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        u8MbCtrlIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
                        Can_ControllerStatuses[Controller].u32MBInterruptMask[(uint8)((uint8)u8MbCtrlIndex >> FLEXCAN_MB_SHIFT5BIT_U8)] |= ((uint32)1U << (uint8)(u8MbCtrlIndex & FLEXCAN_MASK_32BITS_U32));
                    }

            }
        }
    }

}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Stop state/mode.
*
*                 This routine is called by:
*                  - Can_FlexCan_SetControllerMode()
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
* @param[in]      Transition Possible transitions
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
*/
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToStopMode(  VAR(uint8, AUTOMATIC) Controller,
                                                                            P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor,
                                                                            VAR(boolean, AUTOMATIC) canif_notification_required
                                                                          )
{
    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    VAR(uint16, AUTOMATIC)          u16MBGlobalIndex = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)           u8HwOffset = 0U;
    /* Temporary variable for MB config register. */
    VAR(uint32, AUTOMATIC)          u32MbConfig = 0U;
#if (CAN_RXFIFO_ENABLE == STD_ON)
    /*Temporary variable verify Rx FIFO is enabled or no*/
    VAR(boolean, AUTOMATIC) bFifoMB = (boolean)FALSE;
#endif
    
    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[Controller].u8ControllerOffset;

    /*
       (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transision to a state that was already reached.
    */
    if ( CAN_STOPPED == Can_ControllerStatuses[Controller].ControllerState)
    {
        /* If the controller is already in STOP state, return CAN_OK. */
        eReturnValue = CAN_OK;
    }
    else
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Valid transitions to Stop are only from Start and Wakeup. */
            if ( CAN_STARTED != Can_ControllerStatuses[Controller].ControllerState)
            {
                
                (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
            }
            else
            {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /*
                (CAN263) The function Can_SetControllerMode(CAN_T_STOP) shall set the bits inside the CAN hardware such that the CAN controller
                        stops participating on the network.
                */
                
                if ((Std_ReturnType)E_OK == Can_FlexCan_GotoFreezeMode(u8HwOffset))
                {
                    eReturnValue = CAN_OK;
                }
                
                /* Check if Software BusOff Recovery is enabled. */
                if ( CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32) )
                {
                    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06();
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_BIT_CLEAR32( FLEXCAN_CTRL(u8HwOffset), FLEXCAN_CTRL_BOFFREC_U32);
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_BIT_SET32( FLEXCAN_CTRL(u8HwOffset), FLEXCAN_CTRL_BOFFREC_U32);
                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06();
                }
                /*if Rx FIFO is enabled.*/
                #if (CAN_RXFIFO_ENABLE == STD_ON)
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                if(CAN_CONTROLLERCONFIG_RXFIFO_U32 == ((Can_pControlerDescriptors[Controller].u32Options) & CAN_CONTROLLERCONFIG_RXFIFO_U32))
                {
                    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06();
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /*Clear flags for FIFO before delete content of FIFO*/
                    REG_BIT_SET32( FLEXCAN_IFLAG1(u8HwOffset), (FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32|FLEXCAN_FIFO_WARNING_INT_MASK_U32|FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32));
                    /*When this bit was trigged, the FIFO content was cleared*/
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_BIT_SET32( FLEXCAN_IFLAG1(u8HwOffset), FLEXCAN_IFLAG1_BUF0I_U32);
                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06(); 
                    bFifoMB = (boolean)TRUE;
                }
                #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                /* Loop through all MBs. -> Cancel pending messages. */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                for ( u16MBGlobalIndex = 0U; u16MBGlobalIndex < Can_pCurrentConfig->MBConfigContainer.uMessageBufferConfigCount; u16MBGlobalIndex++)
                {
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                    if  ( Controller == (((Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId)
                        )
                    {
                    #if (CAN_RXFIFO_ENABLE == STD_ON)
                        if ((boolean)FALSE == bFifoMB)
                        {
                    #endif
                            /*
                            (CAN282) The function Can_SetControllerMode(CAN_T_STOP) shall cancel pending messages.
                            (CAN273)After bus-off detection, the Can module shall cancel still pending messages without raising a cancellation notification.
                            */
                            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                            u32MbConfig = ( ((uint32)REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex))) & ~FLEXCAN_MBCS_CODE_U32) | FLEXCAN_MBCS_CODETX_U32 );
                            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                            REG_WRITE32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)(u32MbConfig));
                    #if (CAN_RXFIFO_ENABLE == STD_ON)
                        }
                        else
                        {
                            bFifoMB = (boolean)FALSE;
                        }
                    #endif
                    }
                }
                /*
                The Can module shall track all individual enabling and disabling of  interrupts
                    in other functions (i.e. Can_SetControllerMode), so that the correct interrupt enable state can be restored.
                When Freeze mode (or Autosar equiv Stop mode) need to not participate on network ->
                    no interrupt is required to be enabled.
                */
                /* Check if Ints are enabled by Can_EnableControllerInterrupts. */
                if ( CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].eInterruptMode )
                {
                    Can_FlexCan_DisableInterrupts(Controller);
                }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
    /* @violates @ref Can_Flexcan_c_REF_8 Results boolean operations whose results are maybe variant */
    if (CAN_OK == eReturnValue)
    {
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    /* [SWS_CAN_00499] The CAN driver shall deactivate Pretended Networking before the CAN Controller is stopped by SetControllerMode(CAN_T_STOP). */
         /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
         /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_MCR(u8HwOffset), ((~FLEXCAN_PNET_ENABLE_U32) & REG_READ32 (FLEXCAN_MCR(u8HwOffset))));
        Can_ControllerStatuses[Controller].eCanIcomState = CAN_ICOM_DEACTIVATED;
#endif
        /* Set the Stop state to the controller. */
        Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;
        /*Do not notify CanIf for bus off events*/
        if((boolean)TRUE == canif_notification_required)
        {
            CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
        }   
    }
    
    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Start state/mode.
*
*                 This routine is called by:
*                  - Can_FlexCan_SetControllerMode()
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
*/
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToStartMode(  VAR(uint8, AUTOMATIC) Controller,
                                                                            P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor
                                                                          )
{
    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)           u8HwOffset = 0U;
    /* Timeout counter. */
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif
    VAR(uint32, AUTOMATIC)          u32TempVar = 0U;

    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[Controller].u8ControllerOffset;
    
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Valid transitions to Start mode are only from Stop state. */
    if ( CAN_STOPPED != Can_ControllerStatuses[Controller].ControllerState)
    {
        
        (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
    }
    else
    {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        /* (CAN384) Each time the CAN controller state machine is triggered with the state transition value CAN_T_START, the function
        Can_SetControllerMode shall re-initialize the CAN controller with the same controller configuration set previously used by functions
        Can_ChangeBaudrate or Can_Init.*/
        if ((Std_ReturnType)E_OK == Can_FlexCan_InitController( Controller))
        {      

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        /* [SWS_CAN_00498] The CAN driver shall deactivate Pretended Networking before the CAN Controller is started by SetControllerMode(CAN_T_START) */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        u32TempVar = REG_READ32 (FLEXCAN_MCR(u8HwOffset));
        if(FLEXCAN_PNET_ENABLE_U32 != (FLEXCAN_PNET_ENABLE_U32 & u32TempVar))
        {
             /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
             /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32(FLEXCAN_MCR(u8HwOffset), ((~FLEXCAN_PNET_ENABLE_U32) & u32TempVar));
            Can_ControllerStatuses[Controller].eCanIcomState = CAN_ICOM_DEACTIVATED;
        }
#endif
            /*
            (CAN261) The function Can_SetControllerMode(CAN_T_START) shall set the hardware registers in a way that makes the CAN controller participating on the network.

            */
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13();

            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
            
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13();
        
            /*
            (CAN196) The function Can_SetControllerMode shall enable interrupts that are needed in the new state.
            (CAN425)   Enabling of CAN interrupts shall not be executed, when CAN interrupts have been disabled by function CAN_DisableControllerInterrupts.
             */

            if ( CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].eInterruptMode )
            {
                Can_FlexCan_EnableInterrupts(Controller, pCanControlerDescriptor);
            }
            /* (CAN262) The function Can_SetControllerMode(CAN_T_START) shall wait for limited time until the CAN controller is fully operational. Compare to CAN371. */

            u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
            u32TempVar = (uint32)0U;
            do 
            {
#ifdef CAN_TIMEOUT_AS_LOOP
                u32TotalElapsedTime++;
#else
                /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
                u32TotalElapsedTime += u32ElapsedTime;
#endif
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u32TempVar = ( (uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & (FLEXCAN_MCR_FRZ_U32 | FLEXCAN_MCR_HALT_U32 | FLEXCAN_MCR_NOTRDY_U32));
            } while ((u32TotalElapsedTime < Can_u32TicksDelayDuration) && ( 0x0U != u32TempVar));

            if ((uint32)0x0U == u32TempVar)
            {
                /* Set the Start State. */
                Can_ControllerStatuses[Controller].ControllerState = CAN_STARTED;
                eReturnValue = CAN_OK;
            }
            else
            /* software timeout */
            {
                eReturnValue = CAN_NOT_OK;
            }
        }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    if (CAN_OK == eReturnValue)
    {
        CanIf_ControllerModeIndication(Controller, CANIF_CS_STARTED);
    }
    
    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Sleep state/mode.
*
*                 This routine is called by:
*                  - Can_FlexCan_SetControllerMode()
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
*/
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToSleepMode(  VAR(uint8, AUTOMATIC) Controller )
{
    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    
    /*
       (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transision to a state that was already reached.
    */
    if ( CAN_SLEEPED == Can_ControllerStatuses[Controller].ControllerState )
    {
        /* If the controller is already in SLEEP state, return CAN_OK. */
        eReturnValue = CAN_OK;
    }
    else
    {
    
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Valid transitions to Sleep state are only from Stop state. */
        if ( CAN_STOPPED != Can_ControllerStatuses[Controller].ControllerState)
        {
            
            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
            /*[CAN290]If the CAN HW does not support a sleep mode, the function Can_SetControllerMode(CAN_T_SLEEP) shall set the CAN controller to the logical sleep mode*/
            /*[CAN405] This logical sleep mode shall left only, if function Can_SetControllerMode(CAN_T_WAKEUP) is called.*/
            eReturnValue = CAN_OK;
            Can_ControllerStatuses[Controller].ControllerState = CAN_SLEEPED;
            CanIf_ControllerModeIndication(Controller, CANIF_CS_SLEEP);
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
    return eReturnValue;
}
/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to Wakeup state/mode.
*                 This routine is called by:
*                  - Can_FlexCan_SetControllerMode()
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
*/

static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerToWakeupMode(  VAR(uint8, AUTOMATIC) Controller )
{
    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    /*Controllers option for wakeup support(CAN_CONTROLLERCONFIG_WAKSUP_EN_U32) is not necessarly to be checked because if this is not supported,
    the controller cannot be in state CAN_SLEEPED, so the Det_ReportError will be raised*/
    if (CAN_STOPPED == Can_ControllerStatuses[Controller].ControllerState)
    {
        /*CanIf shall be notified only for transitions.
        [CAN373] The function Can_Mainfunction_Mode shall call the function CanIf_ControllerModeIndication to 
        notify the upper layer about a successful state transition of the CAN controller, in case the state transition 
        was triggered by function Can_SetControllerMode 
        */
        eReturnValue = CAN_OK;
    }
    else
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* 
            Valid transitions to Wakeup state are only from Sleep state. 
        */
        if (CAN_SLEEPED != Can_ControllerStatuses[Controller].ControllerState)
        {
            
            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
            /* When Wakeup is not supported the driver should do nothing and return CAN_OK. */
            eReturnValue = CAN_OK;
            Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;
            CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
    
    return eReturnValue;
}
/*================================================================================================*/
/**
* @brief          Service to write data into the Message buffer for transition
* @details        This routine is used in case enabled FD feature.
*
*                 This routine is called by:
*                  - Can_FlexCan_Write()
*
* @param[in]     u8CtrlId - The ID of Can controller 
*                u16MBGlobalIndex - The index of HOH in the structure array which stores the information of configured HOHs
*                PduInfo - Pointer to SDU user memory, DLC and Identifier
*                bEnabledFD - Be TRUE if CAN FD is enabled, otherwise it is FALSE
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
*/
static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_UpdateMB( VAR(uint8, AUTOMATIC) u8CtrlId, VAR(uint16, AUTOMATIC) u16MBGlobalIndex ,
                                                                P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo, VAR(boolean, AUTOMATIC) bEnabledFD
                                                            )
{
    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC) eReturnValue = CAN_BUSY;
    /* Variable for determining the IFLAG register for every MB: IFLAGx */
    VAR(uint8, AUTOMATIC)          u8IflagRegIndex = 0U;
    /* Variable for determining the mash bit in the IFLAGx register for current MB. */
    VAR(uint32, AUTOMATIC)         u32TempFlag = 0U;
    /* Variable for storing the value of IFLAG register. */
    VAR(uint32, AUTOMATIC)         u32IflagReg = 0U;
    /* Variable for byte index of the MB data. */
    VAR(uint8, AUTOMATIC)          u8MbDataByte = 0U;
    /* Variable for storing the ID of the MB from MB structure. */
    VAR(uint32, AUTOMATIC)         u32MbMessageId = 0U;
#if (CAN_FD_MODE_ENABLE == STD_ON)
    /*Can_Flexcan_aDataLengthMax, Can_Flexcan_aDataLengthMin, Can_Flexcan_aDataLengthMax index counter*/
    VAR(uint8, AUTOMATIC)          u8DataLengthCount = 0U;
    /* The length of data which will be filled in MB */
    VAR(uint8, AUTOMATIC)          u8RealDataLength = (uint8)8U;
#endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
    /* Variable for storing the ConfigReg of the MB. */
    VAR(uint32, AUTOMATIC)         u32MbConfig = 0U;
    /* DLC offset value is 16*/
    CONST(uint8, AUTOMATIC)        u8DataLengthOffset =16U;
    VAR(uint8, AUTOMATIC)          u8MbIndex;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
    VAR(PduInfoType, AUTOMATIC) PduInfoPtr;
    VAR(PduIdType, CAN_VAR) TxPduId;
    #endif
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)          u8HwOffset = 0U;
    
    /* Get the hardware offset for this controller. Note that hardware offset may not be the same with the controller index from the 'Can_ControlerDescriptorType' structure. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset;

    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
    u8MbIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
    /* Calculate the index of the IFLAG register and u32TxGuard (index=0 for MB32...MB63, index=1 for MB0...MB31, index=2 for MBO64 ... 96). */
    u8IflagRegIndex = (uint8)((uint8)u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8);
    /* Get the content of IFLAG register for which corresponds this MB. */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u32IflagReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag);

    /* Calculate the bit in the IFLAG register. */
    u32TempFlag = ((uint32)0x01U) << ((uint32)u8MbIndex & FLEXCAN_MASK_32BITS_U32);
    
    /* This MB is not signaled as used by another message. */
    if ( (uint32)0x0U == (u32IflagReg & u32TempFlag) )
    {
        /* Is the MB still empty? */
         /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
         /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
         /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        if ( FLEXCAN_MBCS_CODETX_U32 == (uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32)))
        {
            u32MbMessageId = (uint32)PduInfo->id;
            u32MbConfig = (FLEXCAN_MBCS_CODETX_U32 | FLEXCAN_MBCS_CODETXEN_U32 | FLEXCAN_MBCS_SRR_U32 );
            
        #if (CAN_FD_MODE_ENABLE == STD_ON)
            if   (((uint8)PduInfo->length)<=(uint8)Can_Flexcan_aDataLengthMax[0])
            {
        #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
                u32MbConfig |= ((uint32)PduInfo->length<<(uint32)u8DataLengthOffset);
        #if (CAN_FD_MODE_ENABLE == STD_ON)
                u8RealDataLength = (uint8)PduInfo->length;
            }
            else
            {
                if ((((uint32)PduInfo->id) & (uint32)CAN_FD_ID_DESCRIPTOR) == CAN_FD_ID_DESCRIPTOR )
                {
                    for (u8DataLengthCount=1U; u8DataLengthCount<CAN_FLEXCAN_NUM_VAL_DLC_U8; u8DataLengthCount++)
                    {       
                        if ((((uint8)PduInfo->length)<=(uint8)Can_Flexcan_aDataLengthMax[u8DataLengthCount])&&(((uint8)PduInfo->length)>=(uint8)Can_Flexcan_aDataLengthMin[u8DataLengthCount]))
                        {
                            u32MbConfig |= ((uint32)((uint32)CAN_FLEXCAN_MAX_PAYLOAD8_U8+(uint32)u8DataLengthCount)<<((uint32)u8DataLengthOffset));
                            u8RealDataLength = (uint8)Can_Flexcan_aDataLengthMax[u8DataLengthCount];
                        }
                    }

                }
                /* else{ Development error detection from upper layer} */
            }
            
            if ((boolean)TRUE == bEnabledFD)
            {
                /*check to see if CanIf bit send from the user enables FD*/
                if ((((uint32)PduInfo->id) & (uint32)CAN_FD_ID_DESCRIPTOR) == CAN_FD_ID_DESCRIPTOR )
                {

                    u32MbConfig |= FLEXCAN_MB_EDL_BRS_U32;
                
                }
            }
        #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */

                    
            /* Set-up the MB content for Tx. Remember the PduId for reporting when the frame is transmitted. */
            Can_ControllerStatuses[u8CtrlId].u32TxPduId[u8MbIndex] = PduInfo->swPduHandle;

        #if (CAN_EXTENDEDID == STD_ON)
            if ( (u32MbMessageId & FLEXCAN_MBC_ID_IDE_U32) != (uint32)0U)
            {
                /* Set the IDE bit in the MBCS register of the MB */
                u32MbConfig |= FLEXCAN_MBCS_IDE_U32;
                /* Clear the MSB bit of the id - this is used for sending embedded information by CanIf to Can to say if it is an extended or standard message type. */
                u32MbMessageId &= (~FLEXCAN_MBC_ID_IDE_U32);
            }
            else
            {
        #endif /* (CAN_EXTENDEDID == STD_ON) */
                /* Standard ID - need to shift left 18 bits. */
            u32MbMessageId <<= FLEXCAN_STANDARD_ID_SHIFT_U32;
        #if (CAN_EXTENDEDID == STD_ON)
            }
        #endif /* (CAN_EXTENDEDID == STD_ON) */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            REG_WRITE32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)((u32MbMessageId) | ((REG_READ32(FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)))) & 0xE0000000U) ));
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
            if ( (NULL_PTR == PduInfo->sdu) )
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                if((boolean)TRUE == Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MBGlobalIndex].CanTriggerTransmitEnable)
                {
                    /* this MB enabel the trigger transmit feature */
                    /* [SWS_CAN_00503] Can_Write() shall accept a null pointer as SDU
                            (Can_PduType.Can_SduPtrType = NULL) if the trigger transmit API is enabled
                            for this hardware object (CanTriggerTransmitEnable = TRUE). */
                    /* [SWS_CAN_00504] If the trigger transmit API is enabled for the hardware object, Can_Write() shall interpret a null pointer as SDU 
                                (Can_PduType.Can_SduPtrType = NULL) as request for using the trigger transmit interface. 
                                   If so and the hardware object is free, Can_Write() shall call CanIf_TriggerTransmit() to acquire the PDU’s data. */
                    TxPduId = PduInfo->swPduHandle;
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                    PduInfoPtr.SduLength = ((Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength;
                    
                    /* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Advisory Rule 12.1, Mixed mode arithmetic. */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                    PduInfoPtr.SduDataPtr = (uint8 *)((pointerSizeType)(CAN_GET_BASE_ADDRESS(u8HwOffset)) + (uint32)(FLEXCAN_MB_OFFSET(u16MBGlobalIndex)) + 0x08U);
                    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                    if(CAN_OK == CanIf_TriggerTransmit(TxPduId, &PduInfoPtr))
                    {
                        /* return value is OK */
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        if(((Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength >= (uint32)PduInfoPtr.SduLength)
                        {
                            u32MbConfig = u32MbConfig & FLEXCAN_REMOVE_DLC_U8;
                        #if (CAN_FD_MODE_ENABLE == STD_ON)
                            if(((uint8)PduInfoPtr.SduLength)<=(uint8)Can_Flexcan_aDataLengthMax[0])
                            {
                        #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
                                u32MbConfig |= ((uint32)PduInfoPtr.SduLength<<(uint32)u8DataLengthOffset);
                        #if (CAN_FD_MODE_ENABLE == STD_ON)
                                u8RealDataLength = (uint8)PduInfoPtr.SduLength;
                            }
                            else
                            {
                                for (u8DataLengthCount=1U; u8DataLengthCount<CAN_FLEXCAN_NUM_VAL_DLC_U8; u8DataLengthCount++)
                                {       
                                    if ((((uint8)PduInfoPtr.SduLength)<=(uint8)Can_Flexcan_aDataLengthMax[u8DataLengthCount])&&(((uint8)PduInfoPtr.SduLength)>=(uint8)Can_Flexcan_aDataLengthMin[u8DataLengthCount]))
                                    {
                                        u32MbConfig |= ((uint32)((uint32)CAN_FLEXCAN_MAX_PAYLOAD8_U8+(uint32)u8DataLengthCount)<<((uint32)u8DataLengthOffset));
                                        u8RealDataLength = (uint8)Can_Flexcan_aDataLengthMax[u8DataLengthCount];
                                    }
                                }
                            }
                            
                            if ((boolean)TRUE == bEnabledFD)
                            {
                                for ( u8MbDataByte = (uint8)PduInfoPtr.SduLength; u8MbDataByte < u8RealDataLength; u8MbDataByte++)
                                {
                                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                    /* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Advisory Rule 12.1, Mixed mode arithmetic. */   
                                    REG_WRITE8(FLEXCAN_MB_DATA((u8HwOffset), (uint32)(u16MBGlobalIndex), (uint32)(u8MbDataByte)), (uint8)(Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIndex].u8FdPaddingValue));
                                }
                            }
                        #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
                            eReturnValue = CAN_OK;
                        }
                        else
                        {
                            eReturnValue = CAN_NOT_OK;
                        }
                    }
                    else /* return value is NOT_OK */
                    {
                        /* [SWS_CAN_00506] If development error detection for CanDrv is enabled:
                            Can_Write() shall raise CAN_E_PARAM_POINTER and shall return CAN_NOT_OK if
                            the trigger transmit API (CanIf_TriggerTransmit()) returns E_NOT_OK. */
                        #if (CAN_DEV_ERROR_DETECT == STD_ON)
                            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, CAN_E_PARAM_POINTER);
                        #endif
                        eReturnValue = CAN_NOT_OK;
                    }
                }
                else /* this MB do not enabel the trigger transmit feature */
                {
                    /* [SWS_CAN_00505] If development error detection for CanDrv is enabled:
                        Can_Write() shall raise CAN_E_PARAM_POINTER and shall return CAN_NOT_OK if
                        the trigger transmit API is disabled for this hardware object
                        (CanTriggerTransmitEnable = FALSE) and the SDU pointer inside PduInfo is a null
                        pointer. */
                        #if (CAN_DEV_ERROR_DETECT == STD_ON)
                            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, CAN_E_PARAM_POINTER);
                        #endif
                        eReturnValue = CAN_NOT_OK;
                }
            }
            else /* sdu pointer is not null */
            {
        #endif
                /* Copy the data into the MB memory. The driver will not read from a null pointer SDU. */
                for ( u8MbDataByte = (uint8)0U; u8MbDataByte < PduInfo->length; u8MbDataByte++)
                {
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE8(FLEXCAN_MB_DATA((uint32)(u8HwOffset), (uint32)(u16MBGlobalIndex), (uint32)(u8MbDataByte)), (uint8)((PduInfo->sdu)[u8MbDataByte]));
                }

            #if (CAN_FD_MODE_ENABLE == STD_ON)
                if ((boolean)TRUE == bEnabledFD)
                {
                    for ( u8MbDataByte = PduInfo->length; u8MbDataByte < u8RealDataLength ; u8MbDataByte++)
                    {
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE8(FLEXCAN_MB_DATA((u8HwOffset), (uint32)(u16MBGlobalIndex), (uint32)(u8MbDataByte)), (uint8)(Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MBGlobalIndex].u8FdPaddingValue));
                    }
                }
            #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
        #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
            }
        #endif

            /* @violates @ref Can_Flexcan_c_REF_8 Violates MISRA 2004 Required Rule 13.7, Results boolean operations whose results are maybe variant */
            if (CAN_NOT_OK != eReturnValue)
            {
                /* Transmit the Data - now the data should be on Can Bus. Configure the DLC. */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)(u32MbConfig));
                eReturnValue = CAN_OK;
            }

        }
        else
        /* MB not empty anymore, preempting code has grabbed it before we managed to set the guard bit. Clear the guard bit. */
        {
            /*
               (CAN213) The function Can_Write shall perform no actions if the hardware transmit object is busy with another transmit request for an L-PDU that has higher priority than that for the current request:
                  - The transmission of the L-PDU with higher priority shall not be cancelled and the function Can_Write is left without any actions.
                  - The function Can_Write shall return CAN_BUSY.
            */
            /* MB not TX empty anymore, preempting code has grabbed it before we managed to set the guard bit. Clear the guard, end of critical section. */
            eReturnValue = CAN_BUSY;
        }
    }
    else /* else of "if((uint32)0x0U==(u32IflagReg&u32TempFlag))" */
    /* MB is locked because it has the IFLAG bit set. */
    {
        /*
        The fact that the return value of the function is the same irrespective of whether the MB is locked out or busy with a lower prio message is a deficiency in the AutoSAR spec.
        CanIf has no way of telling whether the message was cancelled or not in the special case and a priority inversion can occur.
        */
        /*
           (CAN214) The function Can_Write shall return CAN_BUSY if a preemptive call of Can_Write has been issued, that could not be
                    handled reentrant (i.e. a call with the same HTH).
        */
        eReturnValue = CAN_BUSY;
    }
    
    (void)bEnabledFD;   /* Prevent compiler warning when CAN_FD is disabled */
    return eReturnValue;
}


/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_Write if polling is selected.
* @details        Processes Tx interrupt flags.
*
*               This routine is called by:
*                   - Can_FlexCan_ProcessTx()
*                   - Can_FlexCan_MainFunctionWrite()
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      u16MBGlobalIndex MB in the MBs' information structure to process.
*
* @pre            MB is configured for Tx.
* @post           CanIf is informed with cancellation or transmit success.
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
static FUNC (void, CAN_CODE) Can_FlexCan_ProcessTxPoll( CONST(uint8, AUTOMATIC) controller, CONST(uint16, AUTOMATIC) u16MBGlobalIndex )
{
    /* Pointer to the MBs structure configuration. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC) pCanMbConfigContainer = NULL_PTR;
    /* Variable for indexing the MBs. */
    VAR(uint8, AUTOMATIC)            u8MbIndex = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)            u8HwOffset = 0U;
    /* Variable for determining the IFLAG register for every MB: IFLAGx */
    VAR(uint8, AUTOMATIC)            u8IflagRegIndex = 0U;
    /* Variable for determining the mash bit in the IFLAGx register for current MB. */
    VAR(uint32, AUTOMATIC)           u32TempFlag = 0U;
    /* Variable for storing the value of IFLAG register. */
    VAR(uint32, AUTOMATIC)           u32IflagReg = 0U;
#if (CAN_TXPOLL_SUPPORTED == STD_OFF)
    /* Variable for storing the value of IMASKx register. */
    VAR(uint32, AUTOMATIC)           u32ImaskReg = 0U;
#endif

    /* Get the address of the MBConfigContainer in local pointer */
    pCanMbConfigContainer = &(Can_pCurrentConfig->MBConfigContainer);
    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8MbIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
    
    /* Calculate the index of the IFLAG/IMASK register. */
    u8IflagRegIndex = (uint8)((uint8)u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8) ;
    
    /* Get the content of IFLAG register for which corresponds this MB. */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u32IflagReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag);

    /* Calculate the bit in the IFLAG/IMASK register allocated to a MB */
    u32TempFlag = ((uint32)0x01U) << ((uint32)u8MbIndex & FLEXCAN_MASK_32BITS_U32);
#ifndef ERR_IPV_FLEXCAN_0015      
    /* Check the interrupt flag of the current MB. */
    if ( (uint32)0x0U != (u32IflagReg & u32TempFlag) )
    {
#endif
#if (CAN_TXPOLL_SUPPORTED == STD_OFF)
        /*Get the content of IMASK register for which corresponds this MB. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u32ImaskReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanImask);

        /* Check for spurious interrupt. */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
        if ( ((uint32)CAN_CONTROLLERCONFIG_TXPOL_EN_U32 == (CAN_CONTROLLERCONFIG_TXPOL_EN_U32 & CanStatic_pControlerDescriptors[controller].u32Options) )
        || ((uint32)u32TempFlag == (u32ImaskReg & u32TempFlag)) )
        {
#endif

            /* The interrupt flag is set, message was either transmitted or cancelled.
                This code does not check whether the u32TxGuard is set.
                It does not have to do the check as it only operates on MBs with the interrupt flag set and CanWrite does not
                operate on MBs which have the interrupt flag set.
                Set the u32TxGuard. */
            /*
                (CAN031) The function Can_MainFunction_Write shall perform the polling of TX confirmation and TX cancellation confirmation when CanTxProcessing is set to POLLING.
            */  

    #ifdef ERR_IPV_FLEXCAN_0015
        #if(ERR_IPV_FLEXCAN_0015==STD_ON)
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            if  ( (((uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32))) == FLEXCAN_MBCS_CODETX_U32) && \
                   ( 0U != ((((uint32)0x01U) << (uint32)u8MbIndex) &  Can_ControllerStatuses[controller].u32TxCancelFlag[u8IflagRegIndex] )) \
                )
            {
            #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8)
                Can_ControllerStatuses[controller].u32TxCancelFlag[u8IflagRegIndex] &= (PduIdType)(~(((uint32)0x01U) << ((uint32)u8MbIndex)));
            #else
                Can_ControllerStatuses[controller].u32TxCancelFlag[u8IflagRegIndex] &= ~(((uint32)0x01U) << ((uint32)u8MbIndex));
            #endif
        #else
             #error : the define ERR_IPV_FLEXCAN_0015 must not be STD_OFF
        #endif
    #else
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                switch ( (uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32)) )
                {
    #endif
                            

        #ifdef ERR_IPV_FLEXCAN_0015
            #if(ERR_IPV_FLEXCAN_0015==STD_ON)
                }
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                else if((((uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32))) == FLEXCAN_MBCS_CODETX_U32) && ((uint32)0x0U != (u32IflagReg & u32TempFlag)))
            #else
                #error : the define ERR_IPV_FLEXCAN_0015 must not be STD_OFF
            #endif
        #else
                        /* Frame was transmitted */
                    case ( FLEXCAN_MBCS_CODETX_U32 ):
        #endif
                {
                    /* Clear the interrupt flag - w1c. */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    REG_WRITE32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag, u32TempFlag);  

                    /*
                        (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with the CanIf module in a direct way.
                                The driver only sees the CanIf module as origin and destination.
                    */
                    CanIf_TxConfirmation( Can_ControllerStatuses[controller].u32TxPduId[u8MbIndex]);
                }
        #ifdef ERR_IPV_FLEXCAN_0015
            #if(ERR_IPV_FLEXCAN_0015==STD_ON)
                else /* error condition, this should never occur */
                {
                    /*This is left blank in oreder to respect MISRA rule 14.10*/
                }
            #else
                #error : the define ERR_IPV_FLEXCAN_0015  not be STD_OFF
            #endif
        #else
                        break;
                    default: 
                        break;

                } /* end switch */
        #endif
            
    /*Support for spurious interrupt*/
    #if (CAN_TXPOLL_SUPPORTED == STD_OFF)
        }
        else
        {
            /*Clear interrupt status flag when spurious interrupt is detected*/
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag, u32TempFlag);
        }
    #endif
#ifndef ERR_IPV_FLEXCAN_0015
    } /*if ( (uint32)0x0U != (u32IflagReg & u32TempFlag) )*/
#endif
}/*Can_FlexCan_ProcessTxPoll*/

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper during Can_MainFunction_Read if polling is selected and Rxfifo is disabled or doesn't supported.
* @details        Processes Rx interrupt flags.
                  This routine is called by:
                    - Can_FlexCan_ProcessRx() from Can_Flexcan.c file
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      u16MBGlobalIndex: index of MB to process in the struct which stores information of MBs 
*
* @pre            MB is configured for Rx.
* @post           Inform CanIf in case a data frame was received.
*
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
static FUNC (void, CAN_CODE) Can_FlexCan_ProcessRxNormal( CONST(uint8, AUTOMATIC) controller, CONST(uint16, AUTOMATIC) u16MBGlobalIndex )
{

    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif
    /* Variable for indexing the MBs. */
    VAR(Can_HwHandleType, AUTOMATIC)      u8MbIndex = 0U;
    /* Number of data bytes. */
    VAR(uint8, AUTOMATIC)      u8MbDataLength = 0U;
    /* Physical data bytes. */
    VAR(uint8, AUTOMATIC)      u8CanMbData[64];
    /* Index for data byte of MB. */
    VAR(uint8, AUTOMATIC)      u8DatabyteIndex = 0U;
    /* Variable for storing the Hrh. */
    VAR(Can_HwHandleType, AUTOMATIC)      u32MbHrh = 0U;
    /* Variables for storing the CanID. */
    VAR(Can_IdType, AUTOMATIC) u32MbMessageId = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)      u8HwOffset = 0U;
    /* Variable for determining the IFLAG register for every MB: IFLAGx. */
    VAR(uint8, AUTOMATIC)      u8IflagRegIndex = 0U;
    /* Variable for determining the mash bit in the IFLAGx register for current MB. */
    VAR(uint32, AUTOMATIC)     u32TempFlag = 0U;
    /* Variable for storing the value of IFLAG register. */
    VAR(uint32, AUTOMATIC)     u32IflagReg = 0U;
    /* Variable for storing the ConfigReg of the MB. */
    VAR(uint32, AUTOMATIC)     u32MbConfig = 0U;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Variable for detect overflow event */
    /* VAR(boolean, AUTOMATIC)  bMbOver = (VAR(boolean, AUTOMATIC))FALSE;  */
#endif
#if (CAN_RXPOLL_SUPPORTED == STD_OFF)
    /* Variable for storing the value of IMASKx register. */
    VAR(uint32, AUTOMATIC)     u32ImaskReg = 0U;
#endif

    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Identifies the HRH and its corresponding CAN Con-troller. */
    VAR(Can_HwType, AUTOMATIC) Mailbox;
    /* Pointer to the received L-PDU. */
    VAR(PduInfoType, AUTOMATIC) PduInfoPtr;

    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    
    u8CanMbData[0U]=(uint8)0U;
    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8MbIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
    /* while(u8MbIndex <= mbindex_end) */
    {
        /* Calculate the Index of the IFLAG register. */
        u8IflagRegIndex = (uint8)((uint8)u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8);
        
        /* Get the content of IFLAG register for which corresponds this MB. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u32IflagReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag);

        /* Calculate the Flag value. */
        u32TempFlag = ((uint32)0x1U) << ((uint32)u8MbIndex & FLEXCAN_MASK_32BITS_U32);

        /* Check the interrupt flag. */
        if ( (uint32)0x0U != (u32IflagReg & u32TempFlag) )
        {
#if (CAN_RXPOLL_SUPPORTED == STD_OFF)
            /*Get the content of IMASK register for which corresponds this MB. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ImaskReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanImask);

            /* Check for spurious interrupt in Interrupt mode */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
            if ( ((uint32)CAN_CONTROLLERCONFIG_RXPOL_EN_U32 == (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & CanStatic_pControlerDescriptors[controller].u32Options) )
            || ((uint32)u32TempFlag == (u32ImaskReg & u32TempFlag)) )
            {   
#endif
                u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
                /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
                /*Check and wait if the BUSY code is set during the move-in process*/
                do
                {
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u32MbConfig = (uint32)REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)));
            #ifdef CAN_TIMEOUT_AS_LOOP
                    u32TotalElapsedTime++;
            #else
                    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                    (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
                    u32TotalElapsedTime += u32ElapsedTime;
            #endif
                }
                while ((FLEXCAN_MBCS_CODERXBUSY_U32 == (u32MbConfig & FLEXCAN_MBCS_CODERXBUSY_U32)) && (u32TotalElapsedTime < Can_u32TicksDelayDuration));

        #if (CAN_DEV_ERROR_DETECT == STD_ON)
                /* CAN395: If the development error detection for the Can module is enabled, the Can module shall raise the error CAN_E_DATALOST in
                        case of OVERWRITE or OVERRUN event detection.*/
                /* Check if a MBs used to receive data was overwrite */

                if(FLEXCAN_MBCS_CODERXOVRR_U32 == (u32MbConfig & FLEXCAN_MBCS_CODE_U32))
                {
                    /* bMbOver = (VAR(boolean, AUTOMATIC))TRUE; */
                    (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
                }

        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /* Create a local copy of the MB to ensure that it is locked out for minimum amount of time.
                    Read the DLC; this read access also locks the MB. */
                u8MbDataLength = (uint8)( (u32MbConfig & FLEXCAN_MBCS_LENGTH_U32) >> FLEXCAN_MBCS_LENGTH_SHIFT_U32);
                
            #if (CAN_FD_MODE_ENABLE == STD_ON)
                if   ((((uint8)u8MbDataLength)>=(uint8)FLEXCAN_DATA_LENGTH_MIN_U8) && (((uint8)u8MbDataLength)<=(uint8)FLEXCAN_DATA_LENGTH_MAX_U8))
                {
                   u8MbDataLength = Can_Flexcan_aDataLengthMax[(uint8)u8MbDataLength - FLEXCAN_DATA_LENGTH_OFFSET_U8];
                }
            #endif

                /* Prevents that a buffer overflow to be generated by a CAN bus error affecting length field */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                if( u8MbDataLength > ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength )
                {
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u8MbDataLength = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength;
                }
                
                /* Get the ID of the message. For extended IDs the most significant bit mus tbe set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/
                if ((uint32)0x0U == (u32MbConfig & (uint32)FLEXCAN_MBCS_IDE_U32))
                {
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u32MbMessageId = (Can_IdType)((uint32)((REG_READ32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBID_ID_STANDARD_U32)) >> (uint32)(18U)));
                }
                else
                {
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u32MbMessageId = (Can_IdType)((uint32)(REG_READ32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBID_ID_EXTENDED_U32)) | FLEXCAN_MBC_ID_IDE_U32);
                }
                
                /* Get the ID of the message. For FD the most significant bit mus tbe set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/
            #if (CAN_FD_MODE_ENABLE == STD_ON) 
                if ((uint32)0x0U != ((uint32)(u32MbConfig & (uint32)(FLEXCAN_FD_MB_MESSAGE_U32))))
                {
                    u32MbMessageId = u32MbMessageId | CAN_FD_ID_DESCRIPTOR;
                }
            #endif
            
                /*
                   (CAN060) Data mapping by CAN to memory is defined in a way that the CAN data byte which is sent out first is array element 0,
                           the CAN data byte which is sent out last is array element 7.
                   (CAN299) The Can module shall copy the L-SDU in a shadow buffer after reception, if the RX buffer cannot be protected (locked)
                           by CAN Hardware against overwriting by a newly received message.
                   (CAN300) The Can module shall copy the L-SDU in a shadow buffer, if the CAN Hardware is not globally accessible.
                */

                for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < u8MbDataLength; u8DatabyteIndex++)
                {
                    /* Copy the data  */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u8CanMbData[u8DatabyteIndex] = REG_READ8(FLEXCAN_MB_DATA((uint32)(u8HwOffset), (uint32)(u16MBGlobalIndex),(u8DatabyteIndex))) ;
                }

                /* Determine Hrh of the message. */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                u32MbHrh = (Can_HwHandleType)((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID;

                /* Clear the interrupt flag - w1c. */
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag, u32TempFlag);
                
                /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
                    unless the CPU reads the C/S word of another MB.*/
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_READ32( FLEXCAN_TIMER(u8HwOffset));
                
            #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                 /*[CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
                 
                /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                if ((boolean)TRUE == CanLPduReceiveCalloutFunction((uint8)u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
                {
            #endif
                         /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                        /* Standard/Extended CAN ID of CAN L-PDU */
                        Mailbox.CanId = u32MbMessageId;
                        /* ID of the corresponding Hardware Object Range */
                        Mailbox.Hoh = u32MbHrh;
                        /* ControllerId provided by CanIf clearly identify the corresponding controller */
                        Mailbox.ControllerId = controller;
                        /* length of the SDU in bytes */
                        PduInfoPtr.SduLength = u8MbDataLength; 
                        /* pointer to the SDU (i.e. payload data) of the PDU */
                         /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                        PduInfoPtr.SduDataPtr=&u8CanMbData[0];
                         /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                        CanIf_RxIndication(&Mailbox, &PduInfoPtr );
                #if (CAN_DEV_ERROR_DETECT == STD_ON)
                    /* If the overflow event occurs */
                    /* if ((VAR(boolean, AUTOMATIC))TRUE == bMbOver) */
                    /* { */
                        /* u8MbIndex = mbindex_end; */
                    /* } */
                #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
            #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                }
            #endif
        #if (CAN_RXPOLL_SUPPORTED == STD_OFF)
            }
            else
            {
                /*Clear interrupt status flag when spurious interrupt is detected*/
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag, u32TempFlag);
                
            }
        #endif  
        }/*if ( (uint32)0x0U != (u32IflagReg & u32TempFlag) )*/

    } /* end while */
}

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper during Can_MainFunction_Read if polling is selected and Rxfifo is supported and enabled.
* @details        Processes Rx interrupt flags.
                  This routine is called by:
                    - Can_FlexCan_ProcessRx() from Can_Flexcan.c file
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      u16MBGlobalIndex: index of MB to process in the struct which stores information of MBs 
*
* @pre            MB is configured for Rx.
* @post           Inform CanIf in case a data frame was received.
*
*
*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
static FUNC (void, CAN_CODE) Can_FlexCan_ProcessRxFifo( CONST(uint8, AUTOMATIC) controller, CONST(uint8, AUTOMATIC) u8MbIndex)
{
    /* Number of data bytes. */
    VAR(uint8, AUTOMATIC)      u8MbDataLength = 0U;
    /* Physical data bytes. */
    VAR(uint8, AUTOMATIC)      u8CanMbData[64];
    /* Index for data byte of MB. */
    VAR(uint8, AUTOMATIC)      u8DatabyteIndex = 0U;
    /* Variable for storing the Hrh. */
    VAR(Can_HwHandleType, AUTOMATIC)      u32MbHrh = 0U;
    /* Variables for storing the CanID. */
    VAR(Can_IdType, AUTOMATIC) u32MbMessageId = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)      u8HwOffset = 0U;
    /* Variable for determining the IFLAG register for every MB: IFLAGx. */
    VAR(uint8, AUTOMATIC)      u8IflagRegIndex = 0U;
    /* Variable for determining the mash bit in the IFLAGx register for current MB. */
    VAR(uint32, AUTOMATIC)     u32TempFlag = 0U;
    /* Variable for storing the value of IFLAG register. */
    VAR(uint32, AUTOMATIC)     u32IflagReg = 0U;
    /* Variable for storing the ConfigReg of the MB. */
    VAR(uint32, AUTOMATIC)     u32MbConfig = 0U;

    VAR(boolean, AUTOMATIC) bFifoNotEmpty = (VAR(boolean, AUTOMATIC))FALSE;   
#if (CAN_RXPOLL_SUPPORTED == STD_OFF)
    /* Variable for storing the value of IMASKx register. */
    VAR(uint32, AUTOMATIC)     u32ImaskReg = 0U;
#endif

    /* Variable for indexing all the MBs fron hardware unit chain (all controllers). */
    VAR(uint16, AUTOMATIC)            u16MBGlobalIndex = 0U;
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Identifies the HRH and its corresponding CAN Con-troller. */
    VAR(Can_HwType, AUTOMATIC) Mailbox;
    /* Pointer to the received L-PDU. */
    VAR(PduInfoType, AUTOMATIC) PduInfoPtr;
    /* Index for browsing the available Rx MBs in FIFO's memory. */
    VAR(uint8, AUTOMATIC)      u8BrwMbIndex = 0U;
    
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);

    /* Find the index of first HOH of this controller */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while ( (u16MBGlobalIndex < (uint16)Can_pCurrentConfig->uCanFirstHTHIndex) && \
            ((controller != (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId)) || \
            ((uint8)0U != (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex))) \
          )
    {
        u16MBGlobalIndex ++;
    }
    
    u8CanMbData[0U]=(uint8)0U;
    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;

    do
    {
        bFifoNotEmpty = (VAR(boolean, AUTOMATIC))FALSE;   
        /* Calculate the Index of the IFLAG register. */
        u8IflagRegIndex = (uint8)((uint8)u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8);
        
        /* Get the content of IFLAG register for which corresponds this MB. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u32IflagReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag);

        /* Calculate the Flag value. */
        u32TempFlag = ((uint32)0x1U) << ((uint32)u8MbIndex & FLEXCAN_MASK_32BITS_U32);

        /* Check the interrupt flag. */
        if ( (uint32)0x0U != (u32IflagReg & u32TempFlag) )
        {
#if (CAN_RXPOLL_SUPPORTED == STD_OFF)
            /*Get the content of IMASK register for which corresponds this MB. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ImaskReg = REG_READ32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanImask);

            /* Check for spurious interrupt in Interrupt mode */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
            if ( ((uint32)CAN_CONTROLLERCONFIG_RXPOL_EN_U32 == (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & CanStatic_pControlerDescriptors[controller].u32Options) )
            || ((uint32)u32TempFlag == (u32ImaskReg & u32TempFlag)) )
            {
#endif
                MCAL_FAULT_INJECTION_POINT(CAN_FIP_3_CHANGE_LENGTH_FIELD);
                /* ********************* Phase1 ********************* */
                /* Check if "mbindex" corresponds to flags for Int Fifo status: Overflow or Warning.
                            If Fifo is disabled, then current flags are normal MB interrupt bits. */
                if ( FLEXCAN_FIFOOVERFLOW_INT_INDEX_U8 == (uint32)u8MbIndex )
                {
                    /* Call the handling routine for Overflow fifo event. */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
                    if ( NULL_PTR != Can_pControlerDescriptors[controller].Can_RxFifoOverflowNotification )
                    {
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
                        Can_pControlerDescriptors[controller].Can_RxFifoOverflowNotification();
                    }
                        
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
                    /*Clear the interrupt status flag for FIFO Overflow*/
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    REG_WRITE32( FLEXCAN_IFLAG1(controller), (uint32)FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32);
                }

                if ( FLEXCAN_FIFOWARNING_INT_INDEX_U8 == (uint32)u8MbIndex )
                {
                    /* Call Rx FIFO warning Notification. */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    if ( NULL_PTR != Can_pControlerDescriptors[controller].Can_RxFifoWarningNotification )
                    {
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
                        Can_pControlerDescriptors[controller].Can_RxFifoWarningNotification();
                    }                            

                    /*Clear the interrupt status flag for FIFO warning */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    REG_WRITE32( FLEXCAN_IFLAG1(controller), (uint32)FLEXCAN_FIFO_WARNING_INT_MASK_U32);
                }

                if ( FLEXCAN_FIFOFRAME_INT_INDEX_U8 == (uint32)u8MbIndex )
                {
                    /* Access data available in MB0 when there is Buffer MB5 Interrupt - Frames Available in FIFO. */
                    bFifoNotEmpty = (VAR(boolean, AUTOMATIC))TRUE;
                    
                    /* ********************* Phase2 ********************* */
                    /* Create a local copy of the MB to ensure that it is locked out for minimum amount of time.
                        Read the DLC; this read access also locks the MB. */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u32MbConfig = (uint32)REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)));
                    u8MbDataLength = (uint8)( (u32MbConfig & FLEXCAN_MBCS_LENGTH_U32) >> FLEXCAN_MBCS_LENGTH_SHIFT_U32);
                    
                #if (CAN_FD_MODE_ENABLE == STD_ON)
                    if   ((((uint8)u8MbDataLength)>=(uint8)FLEXCAN_DATA_LENGTH_MIN_U8) && (((uint8)u8MbDataLength)<=(uint8)FLEXCAN_DATA_LENGTH_MAX_U8))
                    {
                       u8MbDataLength = Can_Flexcan_aDataLengthMax[(uint8)u8MbDataLength - FLEXCAN_DATA_LENGTH_OFFSET_U8];
                    }
                #endif

                    /* Prevents that a buffer overflow to be generated by a CAN bus error affecting length field */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    if( u8MbDataLength > ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength )
                    {
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        u8MbDataLength = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength;
                    }
                    
                    /* Get the ID of the message.
                      For extended IDs the most significant bit mus tbe set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/
                    /* condition to test */
                    if ((uint32)0x0U == (u32MbConfig & (uint32)FLEXCAN_MBCS_IDE_U32))
                    {
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        u32MbMessageId = (Can_IdType)((uint32)((REG_READ32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)) ) & (uint32)(FLEXCAN_MBID_ID_STANDARD_U32)) >> (uint32)(18U)));
                    }
                    else
                    {
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        u32MbMessageId = (Can_IdType)((uint32)(REG_READ32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u16MBGlobalIndex)) ) & (uint32)(FLEXCAN_MBID_ID_EXTENDED_U32)) | FLEXCAN_MBC_ID_IDE_U32);
                    }
                    
                    /* Get the ID of the message.
                      For FD the most significant bit mus tbe set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/
                #if (CAN_FD_MODE_ENABLE == STD_ON) 
                    if ((uint32)0x0U != ((uint32)(u32MbConfig & (uint32)(FLEXCAN_FD_MB_MESSAGE_U32)))) 
                    {
                        u32MbMessageId = u32MbMessageId | CAN_FD_ID_DESCRIPTOR;
                    }
                #endif
                    /*
                       (CAN060) Data mapping by CAN to memory is defined in a way that the CAN data byte which is sent out first is array element 0,
                               the CAN data byte which is sent out last is array element 7.
                       (CAN299) The Can module shall copy the L-SDU in a shadow buffer after reception, if the RX buffer cannot be protected (locked)
                               by CAN Hardware against overwriting by a newly received message.
                       (CAN300) The Can module shall copy the L-SDU in a shadow buffer, if the CAN Hardware is not globally accessible.
                    */

                    for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < u8MbDataLength; u8DatabyteIndex++)
                    {
                        /* Copy the data  */
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        u8CanMbData[u8DatabyteIndex] = REG_READ8(FLEXCAN_MB_DATA((uint32)(u8HwOffset), (uint32)(u16MBGlobalIndex), (u8DatabyteIndex))) ;
                    }

                    /* Determine Hrh of the message. */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u32MbHrh = (Can_HwHandleType)((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID;
                        
                    /* Clear the interrupt flag - w1c. */
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    REG_WRITE32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag, u32TempFlag);
                    
                    /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
                        unless the CPU reads the C/S word of another MB.*/
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    REG_READ32( FLEXCAN_TIMER(u8HwOffset));
                    
                #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                     /*[CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
                     
                    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                    if ((boolean)TRUE == CanLPduReceiveCalloutFunction((uint8)u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
                    {
                #endif
                     /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                    /* Standard/Extended CAN ID of CAN L-PDU */
                    Mailbox.CanId = u32MbMessageId;
                    /* ID of the corresponding Hardware Object Range */
                    Mailbox.Hoh = u32MbHrh;
                    /* ControllerId provided by CanIf clearly identify the corresponding controller */
                    Mailbox.ControllerId = controller;
                    /* length of the SDU in bytes */
                    PduInfoPtr.SduLength = u8MbDataLength; 
                    /* pointer to the SDU (i.e. payload data) of the PDU */
                     /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                    PduInfoPtr.SduDataPtr=&u8CanMbData[0];
                     /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                    CanIf_RxIndication(&Mailbox, &PduInfoPtr );
                #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                    }
                #endif
                    
                }
        #if (CAN_RXPOLL_SUPPORTED == STD_OFF)
            }
            else
            {
                /*Clear interrupt status flag when spurious interrupt is detected*/
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_WRITE32(Can_IflagImask[u8IflagRegIndex][u8HwOffset].u32CanIflag, u32TempFlag);
                
            }
        #endif 
        }/*if ( (uint32)0x0U != (u32IflagReg & u32TempFlag) )*/

        u8BrwMbIndex ++;

     /* Processing all available received MBs in FIFO until FIFO is empty or the number of while loop reaches to the FLEXCAN_FIFO_DEPTH_UNIT_U8 times of the FIFO's depth */
    } while( (bFifoNotEmpty == (VAR(boolean, AUTOMATIC))TRUE) &&
             ((FLEXCAN_FIFO_DEPTH_UNIT_U8 * FLEXCAN_FIFO_DEPTH_U8) > u8BrwMbIndex )
           );
}
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

/*================================================================================================*/

/**
* @brief          Can_FlexCan_ValidHth servers Can_FlexCan_Write to check the conditions on the Hth used.
* @details        The function is available if the development error detection for the Can module is enabled .
*                 and it shall report the errors if the conditions on Hth is not satisfied.
*
* @param[in]      Hth information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use
*                 because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier
* @param[in]      u16MBGlobalIndex - the index of the Hth in the array recording the HOH's information .
* @param[in]      bEnabledFD indicates if the FD feature is supported and enabled.
*                   + bEnabledFD = TRUE: indicates the FD feature is supported and enabled
*                   + bEnabledFD = FALSE: indicates the FD feature is not supported or enabled
*
* @return         A Can_ReturnType value
* @retval         CAN_OK if all conditions are satisfied
* @retval         CAN_NOT_OK if development error is occurred
*
*/
#if (CAN_DEV_ERROR_DETECT == STD_ON)

static FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_ValidHth (  Can_HwHandleType Hth,
                                                               P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo,
                                                               VAR(uint16, AUTOMATIC) u16MBGlobalIndex,
                                                               VAR(boolean, AUTOMATIC) bEnabledFD
                                                            )
{
    VAR(Can_ReturnType, AUTOMATIC) eReturnValue = CAN_OK;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;

    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);

    /* Hth must be below uMessageBufferConfigCount and should be a Tx MB type. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( (Hth >= CanStatic_pCurrentConfig->u32CanMaxObjectId) || \
         (CAN_TRANSMIT != ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->eMBType) \
       )
       
    {
        /*
           (CAN217) If development error detection for the Can module is enabled: The function Can_Write shall raise the error CAN_E_PARAM_HANDLE
                   if the parameter Hth is not a configured Hardware Transmit Handle.
        */
        
        (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_PARAM_HANDLE);
        eReturnValue = CAN_NOT_OK;
    }
    else
    {
    #if (CAN_FD_MODE_ENABLE == STD_ON) 
        /* Report error if length > 8 bytes. */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( \
                ((PduInfo->length) > ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8MBPayloadLength) || \
                ( ((boolean) FALSE == bEnabledFD) && ((PduInfo->length) > (uint8)8U) ) || \
                (( (((uint32)PduInfo->id) & (uint32)CAN_FD_ID_DESCRIPTOR) != CAN_FD_ID_DESCRIPTOR) && ( (PduInfo->length) > (uint8)8U )) \
           )
        {
            /*
               (CAN218) If development error detection for the Can module is enabled: The function Can_Write shall raise the
                       error CAN_E_PARAM_DLC if the length is more than 8 byte.
            */
            
            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_PARAM_DLC);
            eReturnValue = CAN_NOT_OK;
        }
    #else /* if(CAN_FD_MODE_ENABLE == STD_OFF) */
        if ( (PduInfo->length) > 8U )
        {
            /*
               (CAN218) If development error detection for the Can module is enabled: The function Can_Write shall raise the
                       error CAN_E_PARAM_DLC if the length is more than 8 byte.
            */
            
            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_PARAM_DLC);
            eReturnValue = CAN_NOT_OK;
        }
    #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
    }
    
    (void)bEnabledFD;   /* Prevent compiler warning when CAN_FD is disabled */
    return eReturnValue;
}
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

/*================================================================================================*/
/**
* @brief          Service for putting the controller into Freeze Mode
* @details        Service for putting the controller into Freeze Mode
*
* @param[in]      Controller: The Can controller configured
*
*/
static FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_GotoFreezeMode( VAR(uint8, AUTOMATIC) u8HwOffset)
{

    /* Variable for return status. */
    VAR(Std_ReturnType, AUTOMATIC) eReturnValue = (Std_ReturnType)E_NOT_OK;
    /* Timeout counter. */
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif

    /* Go to Freeze mode through setting both CAN_MCR[FRZ] and CAN_MCR[HALT] to 1 */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
    
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);

    /* Check whether the controller is in Low power mode (CAN_MCR[MDIS] = 1 - Module Disable). If it is, clear it to 0 to enable the module*/
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( FLEXCAN_MCR_MDIS_U32 == ((uint32)(REG_READ32( FLEXCAN_MCR(u8HwOffset))) & FLEXCAN_MCR_MDIS_U32) )
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03();
        /* Clear CAN_MCR[MDIS] to enable Can module. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_MDIS_U32);
        
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03();
    }
    
    /* Poll the MCR register until CAN_MCR[FRZACK] (Freeze Mode Acknowledge) is set to 1 or timeout is reached */
    u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while ( (FLEXCAN_MCR_FRZACK_U32 != ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
            (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
          )
    {
#ifdef CAN_TIMEOUT_AS_LOOP
        u32TotalElapsedTime++;
#else
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
        u32TotalElapsedTime += u32ElapsedTime;
#endif
    }
    
    /* If the timeout is reached, then request a Soft Reset */
    if (u32TotalElapsedTime >= Can_u32TicksDelayDuration)
    {
        /* Set CAN_MCR[SOFTRST] to 1 for a Soft Reset request */
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03();
        /* Execute Controller Reset. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SOFTRST_U32);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03();
        
        u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        while ( (FLEXCAN_MCR_SOFTRST_U32 != ((uint32)(REG_READ32( FLEXCAN_MCR(u8HwOffset))) & FLEXCAN_MCR_SOFTRST_U32)) && \
                (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
              )
        {
#ifdef CAN_TIMEOUT_AS_LOOP
            u32TotalElapsedTime++;
#else
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
            u32TotalElapsedTime += u32ElapsedTime;
#endif
        }
        
        if (u32TotalElapsedTime < Can_u32TicksDelayDuration)
        {
            /* Re-configure MCR_SUPV bit because this bis is reset by Soft reset */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SUPV_U32);
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
    #endif
#endif
            eReturnValue = (Std_ReturnType)E_OK;
        }
        /* Else if the timeout is reached -> return E_NOT_OK */
        /* else {eReturnValue = (Std_ReturnType)E_NOT_OK;} */
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Service for the clock source selection
* @details        This function services for selecting the clock source to the CAN Protocol Engine (PE) to be either the peripheral clock or the oscillator clock
*
* @param[in]      Controller: The Can controller configured
*
*/
#ifdef CAN_FLEXCAN_CLKSRC_AVAIABLE
static FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_SellectClockSource( VAR(uint8, AUTOMATIC) u8Controller, VAR(uint8, AUTOMATIC) u8HwOffset, VAR(uint8, AUTOMATIC) u8BaudrateIndex )
{
    /* Variable for return status. */
    VAR(Std_ReturnType, AUTOMATIC)  eReturnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC)          u32ValueControlRegister = 0U;
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif

    /* Disable module to configure clock source (if it is supported)*/
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09();
     /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
     /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_MDIS_U32); 
    
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09();
    /* Load local time-out variable with configured time-out value*/
    u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
    /* After controller disable, wait until low power mode acknowledgement bit to set*/
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while ( (FLEXCAN_MCR_LPMACK_U32 != ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_LPMACK_U32)) && \
            (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
          )
    {
#ifdef CAN_TIMEOUT_AS_LOOP
        u32TotalElapsedTime++;
#else
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
        u32TotalElapsedTime += u32ElapsedTime;
#endif
    }

    if (u32TotalElapsedTime < Can_u32TicksDelayDuration)
    {
    
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        if (Can_ControllerStatuses[u8Controller].CanClockMode == CAN_ALTERNATE)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ValueControlRegister = (uint32)(Can_pCurrentConfig->ControlerDescriptors[u8Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegisterAlternate);
        }
        else
        {
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ValueControlRegister = (uint32)(Can_pCurrentConfig->ControlerDescriptors[u8Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegister);
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        }
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */

        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09();
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_WRITE32( FLEXCAN_CTRL(u8HwOffset), (uint32)(((uint32)(u32ValueControlRegister & CAN_CLKSRC_CONFIG_MASK_U32)) & FLEXCAN_CTRL_CONFIG_MASK_U32));
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_MDIS_U32); 
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09();

        eReturnValue = (Std_ReturnType)E_OK;
    }
    
    return (eReturnValue);
}
#endif /* CAN_FLEXCAN_CLKSRC_AVAIABLE */

/*================================================================================================*/
/**
* @brief          Service for reset the controller.
* @details        Re-initialization must start with a reset (soft).
*                 This routine is called by:
*                  - Can_FlexCan_InitController() from Can_FlexCan.c file.
*
* @param[in]      u8HwOffset: The hardware offset for the used controller.
*
* @post           Controller is enabled and reset.
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
static FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_ResetController( VAR(uint8, AUTOMATIC) u8HwOffset)
{

    /* Variable for return status. */
    VAR(Std_ReturnType, AUTOMATIC) eReturnValue = (Std_ReturnType)E_NOT_OK;
    /* Timeout counter. */
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04();
    /* Execute Controller Reset. */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SOFTRST_U32);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04();
    
    /* Wait the Reset end off. */
    u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while ( (FLEXCAN_MCR_SOFTRST_U32 == ((uint32)(REG_READ32( FLEXCAN_MCR(u8HwOffset))) & FLEXCAN_MCR_SOFTRST_U32)) && \
            (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
          )
    {
        /* MCR[SOFT_RST] still set -> reset in progress. */
#ifdef CAN_TIMEOUT_AS_LOOP
        u32TotalElapsedTime++;
#else
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
        u32TotalElapsedTime += u32ElapsedTime;
#endif
    }
    
    if (u32TotalElapsedTime < Can_u32TicksDelayDuration)
    {
        /* Re-configure MCR_SUPV bit because this bis is reset by Soft reset */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SUPV_U32);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
#endif
#endif
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return (eReturnValue);
}



/*=================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
    #ifdef CAN_FLEXCAN_REG_PROT_AVAILABLE
        FUNC(void, CAN_CODE) Can_FlexCan_SetUserAccessAllowed(void)
        {
        #ifdef FLEXCAN_A_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN0_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN0_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_B_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN1_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN1_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_C_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN2_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN2_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_D_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN3_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN3_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_E_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN4_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN4_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_F_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN5_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN5_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_G_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN6_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN6_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        #ifdef FLEXCAN_H_REG_PROT_AVAILABLE
            #ifdef  FLEXCAN7_BASEADDR
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                SET_USER_ACCESS_ALLOWED(FLEXCAN7_BASEADDR, CAN_FLEXCAN_PROT_MEM_U32);
            #endif
        #endif
        }
    #endif /* CAN_FLEXCAN_REG_PROT_AVAILABLE */
#endif /* (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT) */
#endif


/*================================================================================================*/

/**
* @brief          Initialisation of indicator, statuses, etc.
* @details        Initialisation of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_Init() from Can.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
FUNC (void, CAN_CODE) Can_FlexCan_InitVariables( void )
{

    /* Index CAN controllers from configuration. */
    VAR(uint8, AUTOMATIC) u8CtrlIndex = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(float32, AUTOMATIC) f32TempFloat;
#endif
#if (CAN_TX_RX_INTR_SUPPORTED == STD_ON)
    VAR(uint8, AUTOMATIC) u8MbIndex = 0U;
    VAR(uint16, AUTOMATIC) u16MBGlobalIndex = 0U;

    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
#endif

#ifdef CAN_TIMEOUT_AS_LOOP
    Can_u32TicksDelayDuration = (uint32)CAN_TIMEOUT_DURATION;
#else
    f32TempFloat = (float32)(CAN_TIMEOUT_DURATION / (float32)CAN_TIMEOUT_COUNTER_TICK2NS());
    if ( (f32TempFloat - (float32)((uint32)f32TempFloat) ) > (float32)0)
    {
        Can_u32TicksDelayDuration = (uint32)((uint32)f32TempFloat + (uint32)1);
    }
    else
    {
        Can_u32TicksDelayDuration = (uint32)((uint32)f32TempFloat);
    }
#endif
    /* Init all global varibales/statuses for all controllers. */
    for ( u8CtrlIndex = 0U; u8CtrlIndex < (uint8)CanStatic_pCurrentConfig->u8ControllersConfigured; u8CtrlIndex++)
    {
        /* Init INT Disable nesting indicator. It is incremented after every call of Can_DisableControllerInterrupts().
           The function Can_EnableControllerInterrupts() shall perform no action when Can_DisableControllerInterrupts() has not been called before. */
        Can_ControllerStatuses[u8CtrlIndex].s8IntDisableLevel = (sint8)0;
        /* Set to null the first Tx MB index for every controller. */
        Can_ControllerStatuses[u8CtrlIndex].u8FirstTxMBIndex = (uint8)0U;

        /* Set  interrupt mode status to interrupt enabled mode.
           This is needed in order to support the implementation of requirements CAN425 and CAN426 into Can_SetControllerMode API. */
        Can_ControllerStatuses[u8CtrlIndex].eInterruptMode= CAN_INTERRUPT_ENABLED;

        /* Set the controller state to STOP after power-up */
        Can_ControllerStatuses[u8CtrlIndex].ControllerState = CAN_STOPPED;

        /* Set the controller current baudrate index as default */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        Can_ControllerStatuses[u8CtrlIndex].u8CurrentBaudRateIndex = (uint8)(Can_pControlerDescriptors[u8CtrlIndex].u8DefaultBaudRateIndex);
        
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        /* Set the controller clock mode to normal clock */
        Can_ControllerStatuses[u8CtrlIndex].CanClockMode = CAN_NORMAL;
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        Can_ControllerStatuses[u8CtrlIndex].eCanIcomState = CAN_ICOM_DEACTIVATED;
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */
    }
#if (CAN_TX_RX_INTR_SUPPORTED == STD_ON)
    /* Map tu16MBGlobalIndex (the index of HOH in the HOW array) into the u16MBMapping array*/
    for ( u16MBGlobalIndex = 0U; u16MBGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount; u16MBGlobalIndex++)
    {
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u8MbIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u8CtrlIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId;
        Can_ControllerStatuses[u8CtrlIndex].u16MBMapping[u8MbIndex] = u16MBGlobalIndex;
    }
#endif /* (CAN_TX_RX_INTR_SUPPORTED == STD_ON) */
}

/*================================================================================================*/
/**
* @brief          Service for (re)initializing only CAN controller specific settings.
* @details        CAN controller (re-)initialization.
*                 This routine is called by:
*                  - Can_Init() from Can.c file.
*                  - Can_ChangeBaudrate() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set the MBs and interrupts into predefinite state for Can bus communication.
*
*
*/
FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_InitController( VAR(uint8, AUTOMATIC) Controller)
{
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)           u8HwOffset = 0U;
    /* Variable for return status. */
    VAR(Std_ReturnType, AUTOMATIC)  eResetReturn = (Std_ReturnType)E_OK;
    /* Variable to hold the index of the current baudrate */
    VAR(uint8, AUTOMATIC)           u8BaudrateIndex = 0U;
    VAR(uint8, AUTOMATIC)           u8RegCount = 0U;
    VAR(uint32, AUTOMATIC)          u32ValueControlRegister = 0U;
    /* Max number of mb */
    VAR(uint8, AUTOMATIC)           u8MbMax = 0U;
    VAR(uint32, AUTOMATIC)          u32TempAddr;
    VAR(uint32, AUTOMATIC)          u32TempAddrMax;

    /* Fill the local pointer copy with address of the Controller Descriptor.  */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &(Can_pCurrentConfig->ControlerDescriptors[Controller]);
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);

    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[Controller].u8ControllerOffset;
    
    /* Get the index of the current baudrate */
    u8BaudrateIndex = Can_ControllerStatuses[Controller].u8CurrentBaudRateIndex;

    /* Go to Freeze mode to be able to enter Module Disable mode */
    eResetReturn = Can_FlexCan_GotoFreezeMode(u8HwOffset);
    
#ifdef CAN_FLEXCAN_CLKSRC_AVAIABLE
    if ((Std_ReturnType)E_OK == eResetReturn)
    {
        /* Selects the clock source to the CAN Protocol Engine (PE) to be either the peripheral clock or the oscillator clock */
        eResetReturn = Can_FlexCan_SellectClockSource(Controller, u8HwOffset, u8BaudrateIndex);
    } 
#endif /* CAN_FLEXCAN_CLKSRC_AVAIABLE */

    if ((Std_ReturnType)E_OK == eResetReturn)
    {
        /* Reset Controller*/
        eResetReturn = Can_FlexCan_ResetController( u8HwOffset);
    }
    
    if ((Std_ReturnType)E_OK == eResetReturn)
    {
    #if (CAN_FD_MODE_ENABLE == STD_ON)
        /* The configuration for Message Buffer Data Size (MBDS)*/
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ((uint32)(FLEXCAN_MCR_FDEN_U32) == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable))
        {
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_RMW32( FLEXCAN_FDCTRL(u8HwOffset), FLEXCAN_FDCTRL_MBDSR_MASK_U32, pCanControlerDescriptor->u32MBBlockSize); 
        }
    #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SRXDIS_U32);
        
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
        Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;
    #if (CAN_FD_MODE_ENABLE == STD_ON)

        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ((uint32)(FLEXCAN_MCR_FDEN_U32) == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable))
        {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            
#ifdef ERR_IPV_FLEXCAN_0016
    #if (ERR_IPV_FLEXCAN_0016 == STD_ON)
            Can_FlexCan_SetFDENBitErrata(u8HwOffset);
    #endif
#else
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), (uint32)(FLEXCAN_MCR_FDEN_U32));
#endif

            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
            
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32(FLEXCAN_FDCBT(u8HwOffset), (uint32)(((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdCbtRegister)) ));
            
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if (FLEXCAN_FDCTRL_FDRATE_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTxBitRateSwitch))
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_BIT_SET32( FLEXCAN_FDCTRL(u8HwOffset), (uint32)(FLEXCAN_FDCTRL_FDRATE_U32) );
            }
            else
            {
              /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
              /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_BIT_CLEAR32( FLEXCAN_FDCTRL(u8HwOffset), (uint32)(FLEXCAN_FDCTRL_FDRATE_U32));
            }
            
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ((uint32)0U != pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTrcvDelayCompensation)
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_BIT_SET32(FLEXCAN_FDCTRL(u8HwOffset), (uint32)(FLEXCAN_FDCTRL_TDCEN_U32));
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_RMW32(FLEXCAN_FDCTRL(u8HwOffset), FLEXCAN_FDCTRL_TDCOFF_U32,(uint32)((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTrcvDelayCompensation)<<FLEXCAN_FDCTRL_TDCOFF_OFFSET_U8));
            }
            else
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                REG_BIT_CLEAR32(FLEXCAN_FDCTRL(u8HwOffset), (uint32)(FLEXCAN_FDCTRL_TDCEN_U32));
            }
            
      #ifndef CAN_NOT_SUPPORT_CTRL2_RXFGMASK
          #if ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON))
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_RMW32(FLEXCAN_CTRL2(u8HwOffset), (FLEXCAN_FD_CTRL2_STFCNTEN_U32) | (FLEXCAN_FD_CTRL2_EDFLTDIS_U32) | (FLEXCAN_FD_CTRL2_PREXCEN_U32), ((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdCTRL2Register)));
          #endif
      #endif /* defined CAN_NOT_SUPPORT_CTRL2_RXFGMASK */
        }       
    #endif

#ifndef CAN_NOT_SUPPORT_CTRL2_RXFGMASK
        /* Update the value of the CTRL2[TASD]] bit field */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_RMW32(FLEXCAN_CTRL2(u8HwOffset), FLEXCAN_CTRL2_TASD_U32, (uint32)(((uint32)pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].u8TxArbitrationStartDelay)) << FLEXCAN_CTRL2_TASD_SHIFT_U32);
#endif /* defined CAN_NOT_SUPPORT_CTRL2_RXFGMASK */
/*
* @ errata ERR_IPV_FLEXCAN_0008 software errata FlexCAN: Non-Correctable Errors In FlexCAN Access 
*   Put Device In Freeze Mode bit not working properly
*   CAN_MEMORY_ECC_SUPPORT = STD_ON it does not represent an implementation of the feature, it represents just avaialability in HW and it is used in order to make sure that 
*   this feature is completeley disabled before starting using the HW. 
*/            
#ifndef CAN_NOT_SUPPORT_CTRL2_RXFGMASK
    #if (CAN_MEMORY_ECC_SUPPORT == STD_ON) 
        /* Enable that the MECR register is updated */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_CTRL2(u8HwOffset), FLEXCAN_CTRL2_ECRWRE_U32);
        /* Enables writes on MECR register */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MECR(u8HwOffset), FLEXCAN_MECR_ECRWRDIS_U32);
        /*Disable Error Correction  */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_MECR(u8HwOffset), FLEXCAN_MECR_ECCDIS_U32);
        /* Disables writes on MECR register */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_MECR(u8HwOffset), FLEXCAN_MECR_ECRWRDIS_U32);
        /* Disable update on MECR register */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_CTRL2(u8HwOffset), FLEXCAN_CTRL2_ECRWRE_U32);
    #endif
#endif /* defined CAN_NOT_SUPPORT_CTRL2_RXFGMASK */

    #ifdef ERR_IPV_FLEXCAN_0015
    #if(ERR_IPV_FLEXCAN_0015==STD_ON)
        /* If RFIFO is enabled then the first MBs will be used by the FIFO, initialize the
        u32CancelMBIndex to the value of Max. MB supported to avoid the false TX-MB cancellation */
        if ( CAN_CONTROLLERCONFIG_RXFIFO_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_RXFIFO_U32))
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Can_ControllerStatuses[Controller].u32CancelMBIndex = CanStatic_pControlerDescriptors[Controller].u8NumberOfMB;
        }
        else /* RxFIFO is disabled */
        {
            /* Init the Cancelled MB index with a precalculated value - out of range for every controller. */
            Can_ControllerStatuses[Controller].u32CancelMBIndex = pCanMbConfigContainer->uMessageBufferConfigCount;
        }
    #else
        #error : the define ERR_IPV_FLEXCAN_0015 must not be STD_OFF
    #endif
#else
        /* Init the Cancelled MB index with a precalculated value - out of range for every controller. */
        Can_ControllerStatuses[Controller].u32CancelMBIndex = pCanMbConfigContainer->uMessageBufferConfigCount;
#endif
        /* Clear Tx guard flags. */
        do
        {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            Can_ControllerStatuses[Controller].u32TxGuard[u8RegCount] = (uint32)0x0UL;
            
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();

#ifdef ERR_IPV_FLEXCAN_0015
    #if(ERR_IPV_FLEXCAN_0015==STD_ON)
        #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8)
            Can_ControllerStatuses[Controller].u32TxCancelFlag[u8RegCount] = (PduIdType)0x0UL;
        #else
            Can_ControllerStatuses[Controller].u32TxCancelFlag[u8RegCount] = (uint32)0x0UL;
        #endif
    #else
        #error : the define ERR_IPV_FLEXCAN_0015 must not be STD_OFF
    #endif
#endif
            u8RegCount++;
        }
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        while(u8RegCount < (uint8)((uint8)CanStatic_pControlerDescriptors[Controller].u8NumberOfMB >> FLEXCAN_MB_SHIFT5BIT_U8));
        
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
        /* Check if BCC support is enabled in configuration */
        if ( CAN_CONTROLLERCONFIG_BCC_EN_U32 != (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_BCC_EN_U32) )
        {
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            /* Enable individual MB filter masking. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_BCC_U32);
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
        }
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */

        /* FlexCan uses local priority feature - extend the ID during the arbitration process with PRIO field from MB reg. */
        if ( CAN_CONTROLLERCONFIG_LPRIO_EN_U32 == (pCanControlerDescriptor->u32Options & CAN_CONTROLLERCONFIG_LPRIO_EN_U32) )
        {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_LPRIOEN_U32);
            
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
        }

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        if (Can_ControllerStatuses[Controller].CanClockMode == CAN_ALTERNATE)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ValueControlRegister = (uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegisterAlternate);
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ValueControlRegister |= (uint32)(CanStatic_pControlerDescriptors[Controller].pStaticControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegisterAlternate);
        }
        else
        {
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ValueControlRegister = (uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegister);
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32ValueControlRegister |= (uint32)(CanStatic_pControlerDescriptors[Controller].pStaticControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegister);
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        }
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */

        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_WRITE32( FLEXCAN_CTRL(u8HwOffset), (uint32)(((uint32)u32ValueControlRegister) & FLEXCAN_CTRL_CONFIG_MASK_U32));
        
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
    #if (CAN_CBT_ENABLE == STD_ON)
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ((pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerCbtRegister.u32CanCbtEnable) == FLEXCAN_CBT_BTF_U32)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( FLEXCAN_CBT(u8HwOffset), (uint32)(((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerCbtRegister.u32CanCbtRegister))));
        }
    #endif

        /* Loop Back Mode configuration. Clear also the MCR[SRCXDIS] to allow receiving frames transmitted by itself. */
         /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        if ( FLEXCAN_CTRL_LPB_U32 == (u32ValueControlRegister & FLEXCAN_CTRL_LPB_U32) )
        {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SRXDIS_U32);
            
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
        }
        u32TempAddr = CAN_GET_BASE_ADDRESS(u8HwOffset) + FLEXCAN_MB_OFFSET_U32;
        
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        u32TempAddrMax = u32TempAddr + (uint32)((uint32)(CanStatic_pControlerDescriptors[Controller].u8NumberOfMB) * (uint32)16U);
        
        while(u32TempAddr < u32TempAddrMax)
        {
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32( u32TempAddr, (uint32)0U);
            u32TempAddr = u32TempAddr + 4U;
        }
        /* Stage1: init RxFifo ******************************************************************** */

#if (CAN_RXFIFO_ENABLE == STD_ON)
        Can_FlexCan_InitRxFiFo(Controller, u8HwOffset);
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

        /* Stage2: Init Rx and Tx MBs ******************************************************************** */
        Can_FlexCan_InitReceiveMBs ( Controller, u8HwOffset);
    
        Can_FlexCan_InitTransmitMBs(Controller, u8HwOffset);

        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if(Can_pControlerDescriptors[Controller].u8MaxMBCount > 0U)
        {
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u8MbMax = Can_pControlerDescriptors[Controller].u8MaxMBCount - 1U;
        }
        else
        {
            u8MbMax = 0U;
        }
        /* Set the number of MBs configured for this controller (Rx + Tx MBs). */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_RMW32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_MAXMB_U32, ((uint32)u8MbMax)) ;
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_SUPV_U32);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
    #endif
#endif

#ifdef ERR_IPV_FLEXCAN_0015
      #if(ERR_IPV_FLEXCAN_0015==STD_ON)  
    /* Do not set the Abort Enable bit of the MCR */
      #else
        #error : the define ERR_IPV_FLEXCAN_0015 must not be STD_OFF
      #endif
#else
    #if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
            /* Abort Enable: Tx Cancelation supported and used for this Controller. */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_AEN_U32);
    #endif /* (ERR_IPV_0015==STD_ON) */
#endif

        /* Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) - If events are set for polling mode these bits are not set.
            Clear all INTs flags  .. for MBs (w1c bits). */
        u8RegCount=0U;
        do
        {
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            REG_WRITE32( Can_IflagImask[u8RegCount][u8HwOffset].u32CanIflag, (uint32)(FLEXCAN_32BITMASK_U32) );
            u8RegCount++;
        }
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        while(u8RegCount < (uint8)(CanStatic_pControlerDescriptors[Controller].u8NumberOfMB >> FLEXCAN_MB_SHIFT5BIT_U8));

        /* Clear bits for Tx/Rx/BusOff/Err/(w1c bits). */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_WRITE32( FLEXCAN_ESR(u8HwOffset), (uint32)(((uint32)(FLEXCAN_ESR_BOFFINT_U32 | FLEXCAN_ESR_ERRINT_U32 | FLEXCAN_ESR_WAK_INT_U32)) & FLEXCAN_ESR_CONFIG_MASK_U32));

        /* Clear the Error Counters Register. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_WRITE32( FLEXCAN_ECR(u8HwOffset), (uint32)(((uint32)0UL) & FLEXCAN_ECR_CONFIG_MASK_U32));


        /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
            unless the CPU reads the C/S word of another MB.*/
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_READ32( FLEXCAN_TIMER(u8HwOffset));

    } /* (eResetReturn == E_OK) */
    
    return eResetReturn;
}


/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to another state/mode.
*                 This routine is called by:
*                  - Can_SetControllerMode() from Can.c file.
*                  - Can_IPW_ProcessBusOff() from Can_IPW.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
* @param[in]      Transition Possible transitions
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
* @pre            Controller is configured and must be into a state that permit the valid transition to another different state.
* @post           Shall enable interrupts that are needed in the new state. Shall disable interrupts that are not allowed in the new state.
*
* @requirements   CAN283
*
*/
FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor,
                                                           VAR(Can_StateTransitionType, AUTOMATIC) Transition,
                                                           VAR(boolean, AUTOMATIC) canif_notification_required)
{

    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    
    /*
      (CAN017) The function Can_SetControllerMode shall perform software triggered state transitions of the CAN controller State machine.
    */
    switch (Transition)
    {
        /* CANIF_CS_STARTED -> CANIF_CS_STOPPED. */
        /*
           (CAN283) The function Can_SetControllerMode(CAN_T_STOP) shall not call a cancellation notification.
        */
        case (CAN_T_STOP):
            eReturnValue = Can_FlexCan_SetControllerToStopMode(Controller, pCanControlerDescriptor, canif_notification_required);
            break;

        /* CANIF_CS_STOPPED -> CANIF_CS_STARTED. */
        case (CAN_T_START):
            eReturnValue = Can_FlexCan_SetControllerToStartMode(Controller, pCanControlerDescriptor);
            break;
            
        /* CANIF_CS_STOPPED -> CANIF_CS_SLEEP. */
        case (CAN_T_SLEEP):
            eReturnValue = Can_FlexCan_SetControllerToSleepMode(Controller);
            break;
        /* CANIF_CS_SLEEP -> CANIF_CS_STOPPED */
        case (CAN_T_WAKEUP):
            eReturnValue = Can_FlexCan_SetControllerToWakeupMode(Controller);
            break;
            /* Unknown transition requested. */
            default:
                /*
                   (CAN200) If development error detection for the Can module is enabled: if an invalid transition has been requested, the function Can_SetControllerMode shall raise the error CAN_E_TRANSITION and return CAN_NOT_OK.
                */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                
                (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                break;

        } /* end switch */

    return (eReturnValue);
}


/*================================================================================================*/
/**
* @brief          Service disables all interrupts for the given CAN controller.
* @details        This routine is called by:
*                 - Can_DisableControllerInterrupts() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
*
* @pre            Disable interrupts must be called prior to enable interrupts.
* @post           Clear all flags/bits that are needed for disabling the interrupts.
*
*
*/
FUNC (void, CAN_CODE) Can_FlexCan_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller)
{

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00();
    /*
       (CAN202) When Can_DisableControllerInterrupts has been called several times, Can_EnableControllerInterrupts must be called
                as many times before the interrupts are re-enabled.
    */
    Can_ControllerStatuses[Controller].s8IntDisableLevel++;

    /* If nesting level is zero or below zero; <0 needed for reentrancy. */
    /*
       (CAN049) The function Can_DisableControllerInterrupts shall disable all interrupts for this CAN controller only at the first call of this function.
    */
    if ( (sint8)1 == Can_ControllerStatuses[Controller].s8IntDisableLevel )
    {
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();
        /* Switch to disabled mode. */
        Can_ControllerStatuses[Controller].eInterruptMode = CAN_INTERRUPT_DISABLED;
        Can_FlexCan_DisableInterrupts(Controller);
    }
    else
    {
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();
    }
}


/*================================================================================================*/
/**
* @brief          Service enables all interrupts that shall be enabled according the current software status.
* @details        This routine is called by:
*                  - Can_EnableControllerInterrupts() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
*
* @pre            Can be executed only if disable interrupts was called before.
* @post           Enable all interrupts that must be enabled according the current sw status.
*
*
*/
FUNC (void, CAN_CODE) Can_FlexCan_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller,
                                                          P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor )
{
    /* Variable that tells if disable ints was called at least once before. */
    VAR(uint8, AUTOMATIC)   u8DisCalledBefore = 0U;


    /*
       (CAN202) When Can_DisableControllerInterrupts has been called several times, Can_EnableControllerInterrupts must be called as many
               times before the interrupts are re-enabled.
    */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01();
    
    if ( Can_ControllerStatuses[Controller].s8IntDisableLevel > (sint8)0 )
    {
        /* When s8IntDisableLevel is greater than 0  means Can_DisableControllerInterrupts was called at least once before this call of current function. */
        
        /* Decrement the nesting level. */
        Can_ControllerStatuses[Controller].s8IntDisableLevel--;

        u8DisCalledBefore = (uint8)0x1U;
    }

    /* Can_DisableControllerInterrupts and Can_EnableControllerInterrupts do not modify the software flags. */

    /*
       (CAN208) The function Can_EnableControllerInterrupts shall perform no action when Can_DisableControllerInterrupts has not been called before.
    */
    if ( ((sint8)0 == Can_ControllerStatuses[Controller].s8IntDisableLevel) && ((uint8)0x1U == u8DisCalledBefore) )
    {
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01();
        /* Switch to enabled mode. */
        Can_ControllerStatuses[Controller].eInterruptMode = CAN_INTERRUPT_ENABLED;
        Can_FlexCan_EnableInterrupts(Controller, pCanControlerDescriptor);
    }
    else
    {
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01();
    }
}


/*================================================================================================*/
/**
* @brief          Local function for canceling low priority msg during Can Write operation.
* @details        This routine is called by:
*                  - Can_FlexCan_Write() from Can_FlexCan.c file.
*                  - Can_AbortMb() from Can.c file.
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex index of the message buffer to be canceled
*
* @pre            A Tx message with a higher priority was requested for a MB.
* @post           Inform CanIf about cancellation in case of success.
*
*
*/
#if (CAN_API_ENABLE_ABORT_MB == STD_ON)

/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_FlexCan_Cancel( VAR(uint8, AUTOMATIC) controller,
                                          VAR(uint16, AUTOMATIC) u16MBGlobalIndex )
{
    VAR(uint8, AUTOMATIC)  u8MbIndex = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;
    /* Some temporary variables for registers read/write.  */
    /* Configuration register for current MB. */
    VAR(uint32, AUTOMATIC) u32MbConfig = 0U;
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8MbIndex = ((Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
    /* Tell the interrupt routine that cancellation of this MB is in progress. */
    Can_ControllerStatuses[controller].u32CancelMBIndex = (Can_HwHandleType)u8MbIndex;
    /* Get the hardware offset for this controller. Note that hardware offset may not be the same with the controller index from the 'Can_ControlerDescriptorType' structure. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* Check if the MB is still full. */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( (uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32)) == (uint32)(FLEXCAN_MBCS_CODETX_U32 | FLEXCAN_MBCS_CODETXEN_U32) )
    {

  #ifdef ERR_IPV_FLEXCAN_0015
    #if(ERR_IPV_FLEXCAN_0015==STD_ON)
        /* MB still full -> deactivate it. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
        u32MbConfig = ( REG_READ32( FLEXCAN_MB((u8HwOffset), (u16MBGlobalIndex))) & (uint32)(~FLEXCAN_MBCS_CODE_U32)) | FLEXCAN_MBCS_CODETX_U32;
        #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8)
            Can_ControllerStatuses[controller].u32TxCancelFlag[(u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8)] |= (PduIdType)(((uint32)0x01U) << ((uint32)u8MbIndex));
        #else
            Can_ControllerStatuses[controller].u32TxCancelFlag[(u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8)] |= ((uint32)0x01U) << ((uint32)u8MbIndex);
        #endif
     #else
        #error : the define ERR_IPV_FLEXCAN_0015 must not be STD_OFF
     #endif
  #else
        /* MB still full -> cancel it. */     
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u32MbConfig = ( REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(~FLEXCAN_MBCS_CODE_U32)) | FLEXCAN_MBCS_CODETX_U32 | FLEXCAN_MBCS_CODETXABORT_U32;
#endif
        /* Send command to abort the message */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        REG_WRITE32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex)), (uint32)(u32MbConfig));
    }
}
#endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */
/*================================================================================================*/
/**
* @brief          Process a message buffer abort
* @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
*                This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth - HW-transmit handler
*
* @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
*
*
*/
#if ((CAN_API_ENABLE_ABORT_MB == STD_ON))

FUNC(void, CAN_CODE) Can_FlexCan_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth )
{
    VAR(uint8, AUTOMATIC) u8Controller;
    /* Variable for indexing all the MBs fron hardware unit chain (all controllers). */
    VAR(uint16, AUTOMATIC)            u16MBGlobalIndex = 0U;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while ( (u16MBGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount) && \
            (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID != Hth) \
          )
    {
        u16MBGlobalIndex++;
    }
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8Controller = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId;
    
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( (Hth >= CanStatic_pCurrentConfig->u32CanMaxObjectId) || \
         (CAN_TRANSMIT != ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->eMBType) \
       )
    {
        /*
        (CAN217) If development error detection for the Can module is enabled: The function Can_Write shall raise the error CAN_E_PARAM_HANDLE
                if the parameter Hth is not a configured Hardware Transmit Handle.
        */
        
        (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ABORT_MB, (uint8)CAN_E_PARAM_HANDLE);
    }
    else
    {
        
        /* Test if controller is in valid range. */
        if ( (u8Controller >= (uint8)CanStatic_pCurrentConfig->u8ControllersConfigured) ||
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
             (FLEXCAN_NULL_OFFSET_U8 == (CanStatic_pControlerDescriptors[u8Controller].u8ControllerOffset)) )
        {
            
            (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ABORT_MB, (uint8)CAN_E_PARAM_CONTROLLER);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
#if ((CAN_ABORT_ONLY_ONE_MB==STD_OFF) && (CAN_MULTIPLEXED_TRANSMISSION==STD_ON))
            
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            while ( u16MBGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount )
            {
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                if (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID == Hth)
                {
                    Can_FlexCan_Cancel( u8Controller, u16MBGlobalIndex);
                }
                u16MBGlobalIndex++;
            }
#else /* CAN_ABORT_ONLY_ONE_MB==STD_OFF */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
            if ( (u16MBGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount))
            {
                Can_FlexCan_Cancel( u8Controller, u16MBGlobalIndex);
            }
#endif   /* CAN_ABORT_ONLY_ONE_MB==STD_ON */

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */
/*================================================================================================*/
/**
* @brief          Can_FlexCan_Write checks if hardware transmit object that is identified by the HTH is free.
* @details        Can_FlexCan_Write checks if hardware transmit object that is identified by the HTH is free.
*                     Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers/buffers.
*                         All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with CAN_OK.
*                     b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                         The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                         The transmission of the previous L-PDU is cancelled (asynchronously).
*                         The function returns with CAN_BUSY.
*                         This routine is called by:
*                         - Can_Write() from Can.c file.
*                     Algorithm Description:
*                     Case1: TxMUX supported = ON
*                           Can_Write receive the Hth handle and the PduInfo for transmission. It starts to check from the first MBs of the
*                           current controller to search for a free MB. On the first free MB it stops and place the PduInfo and activate the transmission.
*                           In this case function set CAN_OK for return value and all other functionality is skipped.
*                           If no MB is finded as free then the lowest priority MB is selected for comparing with the priority of the current PduInfo.
*                           If the current PduInfo has a higher priority than the current lower priority (from all MBs) then this lower priority MB is canceled.
*                    Case2: TxMUX supported = OFF
*                          CanWrite() receive the Hth handle and the PduInfo for transmission. It checks if MB with the same index as Hth is free and if yes prepare
*                          and sends the current PduInfo data. If that MB is bussy with another data then it checks the priority between these 2 structures.
*                          Depending by the last evaluation it decides what MB data to cancel.
*
* @param[in]      Hth information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use
*                 because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier
*
* @return          Can_ReturnType
* @retval          CAN_OK write command has been accepted
* @retval          CAN_NOT_OK development error occured
* @retval          CAN_BUSY no TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant
*
* @pre            The MB must be configured for Tx.
* @post           Transmit the data or ignore it in case of MB is full with another task.
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Can_ReturnType, CAN_CODE) Can_FlexCan_Write( Can_HwHandleType Hth,
                                                   P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo )
{

    /* Variable for return status. */
    VAR(Can_ReturnType, AUTOMATIC) eReturnValue = CAN_BUSY;
    /* Variable for keeping the controller Id. */
    VAR(uint8, AUTOMATIC)          u8CtrlId = 0U;
    /* Variable for indexing the MBs. */
    VAR(uint8, AUTOMATIC)          u8MbIndex = 0U;
    /* General purpose variable */
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)          u8HwOffset = 0U;
    /* Variable for determining the IFLAG register for every MB: IFLAGx */
    VAR(uint8, AUTOMATIC)          u8IflagRegIndex = 0U;
    /* Variable for determining the mash bit in the IFLAGx register for current MB. */
    VAR(uint32, AUTOMATIC)         u32TempFlag = 0U;
    VAR(uint16, AUTOMATIC)         u16MBGlobalIndex = 0U;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;

#if (CAN_FD_MODE_ENABLE == STD_ON)
    /*variable for current baudrate index*/  
    VAR(uint8, AUTOMATIC) u8BaudrateIndex = 0U;
    P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor;
    VAR(boolean, AUTOMATIC) bEnabledFD;
#endif
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    
    /* Calculate the MB index. When transmit multiplex is enabled search any MB to be free, MBs that have the same ObjectID
    When Multiplex is disabled ,you can have more than one controller, everyone having MBs configured. In this case the index of the MB is different from the
            one in the plugin */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    while ( (u16MBGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount) && \
            (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID != Hth) \
          )
    {
        u16MBGlobalIndex++;
    }
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8CtrlId = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId;

#if (CAN_FD_MODE_ENABLE == STD_ON)       
     /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &Can_pCurrentConfig->ControlerDescriptors[u8CtrlId];
    /* Get the index of the current baudrate */
    u8BaudrateIndex = Can_ControllerStatuses[u8CtrlId].u8CurrentBaudRateIndex;
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if (((uint32)FLEXCAN_MCR_FDEN_U32) == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable))
    {
        bEnabledFD = (boolean)TRUE;
    }
    else
    {
        bEnabledFD = (boolean)FALSE;
    }
#endif
    /* Get the hardware offset for this controller. Note that hardware offset may not be the same with the controller index from the 'Can_ControlerDescriptorType' structure. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset;

#if (CAN_DEV_ERROR_DETECT == STD_ON)

#if (CAN_FD_MODE_ENABLE == STD_ON)
    eReturnValue = Can_FlexCan_ValidHth(Hth, PduInfo, u16MBGlobalIndex, bEnabledFD);
#else
    eReturnValue = Can_FlexCan_ValidHth(Hth, PduInfo, u16MBGlobalIndex, (boolean)FALSE);
#endif /* (CAN_FD_MODE_ENABLE == STD_ON)   */
    if (CAN_OK == eReturnValue)
    {

#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */


    #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        /* [SWS_CAN_00470] If Pretended  Networking  is  activated  CanDrv  shall  reject Can_Write() requests with return value CAN_BUSY. */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if( CAN_ICOM_ACTIVATED == Can_ControllerStatuses[u8CtrlId].eCanIcomState)
        {
            eReturnValue = CAN_NOT_OK;
        }
        if (CAN_NOT_OK != eReturnValue)
        {
    #endif

    #if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
        /* Need to find a free MB for transmission. This do-while block is executed only when multiplex transmission is ON because the data can be stored in any MB
                that has the same ObjectID. */
        do
        {
    #endif /* (CAN_MULTIPLEXED_TRANSMISSION == STD_ON) */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u8MbIndex = ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
     
            /* Is the MB empty?
                 This test is a bit early; the u32TxGuard is not set yet and someone else can grab this MB before we reserve it
                 but it saves setting the guard on full or cancelled MBs only to discover they are not empty and clearing the guard again. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ( FLEXCAN_MBCS_CODETX_U32 == (uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u16MBGlobalIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32)) )
            {
                /*
                   (CAN212) The function Can_Write shall perform following actions if the hardware transmit object is free: The mutex for that HTH is set to 'signaled';
                         the ID, DLC and SDU are put in a format appropriate for the hardware; All necessary control operations to initiate the transmit are done;
                         The mutex for that HTH is released; The function returns with CAN_OK.
                */

                /* Calculate the index of the IFLAG register and u32TxGuard (index=0 for MB32...MB63, index=1 for MB0...MB31, index=2 for MBO64 ... 96). */
                u8IflagRegIndex = (uint8)((uint8)u8MbIndex >> FLEXCAN_MB_SHIFT5BIT_U8);
                                    
                /* Calculate the bit in the IFLAG register. */
                u32TempFlag = ((uint32)0x01U) << ((uint32)u8MbIndex & FLEXCAN_MASK_32BITS_U32);
                
                SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02();
                /* Test the GUARD MASK and the INTERRUPT FLAG.
                     Cannot operate on locked out MBs (re-entry).. also cannot operate on MBs for which the Tx confirmation has not been sent yet.
                     Below is read-modify-write cycle for u32TxGuard flag which may be interrupted -> must use SchM_Enter_Can_CAN_EXCLUSIVE_AREA_XX() for preventing broken u32TxGuard value. */

                if ( (uint32)0x0U == (Can_ControllerStatuses[u8CtrlId].u32TxGuard[u8IflagRegIndex] & u32TempFlag) )
                {
                    /* Interrupt flag is not set for this MB this meaning MB is not in progress. */
                    /* The mutex for that HTH is set to 'signaled': The guard is 0, the MB is not locked out at the moment -> lock it out. */
                    Can_ControllerStatuses[u8CtrlId].u32TxGuard[u8IflagRegIndex] |= u32TempFlag;

                    /* u32TxGuard was set without any risk of broken data - now can free the Critical section. */
                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
                    
                    /* Write data into the Message buffer for transition*/
                #if (CAN_FD_MODE_ENABLE == STD_ON)
                    eReturnValue = Can_FlexCan_UpdateMB(u8CtrlId, u16MBGlobalIndex, PduInfo, bEnabledFD);
                #else
                    eReturnValue = Can_FlexCan_UpdateMB(u8CtrlId, u16MBGlobalIndex, PduInfo, (boolean) FALSE);
                #endif /* (CAN_FD_MODE_ENABLE == STD_ON) */

                    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02();
                    Can_ControllerStatuses[u8CtrlId].u32TxGuard[u8IflagRegIndex] &= (uint32)(~u32TempFlag);
                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
                }
                else /* else of "if((uint32)0x0U==(Can_ControllerStatuses[u8CtrlId].u32TxGuard[0]&u32TempFlag))" */
                {

                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
                    /* MB is locked out because software flag (Guart bit) is set. */
                    eReturnValue = CAN_BUSY;

                }
            }
            else /* else of "if(FLEXCAN_MBCS_CODETX_U32==(uint32)(REG_READ32( FLEXCAN_MB((u8HwOffset), (u8MbIndex))) & (uint32)(FLEXCAN_MBCS_CODE_U32)))" */
            /* MB is not empty */
            {
                    /* MB is not empty. */
                    eReturnValue = CAN_BUSY;
            }


    #if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
        #if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
            if ((boolean)TRUE == bExitMplxTX)
            {
                break;
            }
        #endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */
        
            u16MBGlobalIndex++;
            
        } while ( (u16MBGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount) &&
                   /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                  (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID == Hth) &&
                  (CAN_BUSY == eReturnValue)
                );
    #endif /* (CAN_MULTIPLEXED_TRANSMISSION == STD_ON) */

    #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        }
        else
        {
            eReturnValue = CAN_BUSY;
        }
    #endif
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        eReturnValue = CAN_NOT_OK;
    }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer from ISR when Interrupt mode selected.
* @details        Processes Tx interrupt flags.
*               This routine is called by:
*                - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file.
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex_start: index of start MB which will be resolved
*                 mbindex_end:   index of end MB which will be resolved
*
* @pre            MB is configured for Tx.
* @post           CanIf is informed with cancellation or transmit success.
*
*/
#if (CAN_TX_RX_INTR_SUPPORTED == STD_ON)
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_FlexCan_ProcessTx( CONST(uint8, AUTOMATIC) controller,
                                          CONST(uint8, AUTOMATIC) mbindex_start,
                                          CONST(uint8, AUTOMATIC) mbindex_end )
{
    VAR(uint8, AUTOMATIC)   u8MbIndex = 0U;
    VAR(uint16, AUTOMATIC)   u16MbGlobalIndex = 0U;

    for (u8MbIndex = mbindex_start; u8MbIndex <= mbindex_end; u8MbIndex++)
    {
        if (u8MbIndex < (uint8)CAN_MAXMB_CONFIGURED)
        {
            u16MbGlobalIndex = Can_ControllerStatuses[controller].u16MBMapping[u8MbIndex];
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            if ( CAN_TRANSMIT == (Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MbGlobalIndex].eMBType) )
            {
                Can_FlexCan_ProcessTxPoll(controller, u16MbGlobalIndex);
            }
        }
    }
}
#endif /* (CAN_TX_RX_INTR_SUPPORTED == STD_ON) */

/*================================================================================================*/
/**
* @brief          Service to perform the polling of TX confirmation and TX cancellation confirmation
* @details        This routine is called by:
*               - Can_MainFunction_Write() from Can.c file.
*
* @pre            The controller must be configured for transmit in polling mode and at least one MB is configured for Tx.
* @post           Process the transmission data in case of availability.
*
*
*/
#if (CAN_TXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionWrite(void)
{

    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC)   u8CtrlId = 0U;
    
    VAR(uint16, AUTOMATIC)   u16CtrlGlobalIndex;

    /* Loop through all configured controller descriptors. */
    for ( u16CtrlGlobalIndex = Can_pCurrentConfig->uCanFirstHTHIndex; u16CtrlGlobalIndex < Can_pCurrentConfig->MBConfigContainer.uMessageBufferConfigCount; u16CtrlGlobalIndex++)
    {
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u8CtrlId = Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16CtrlGlobalIndex].u8ControllerId;

        /* Check whether the controller is enabled and whether Tx polling is used for this controller. */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( (FLEXCAN_NULL_OFFSET_U8 != CanStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset) &&
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
             ((uint32)0U != (CAN_CONTROLLERCONFIG_TXPOL_EN_U32 & (CanStatic_pControlerDescriptors[u8CtrlId].u32Options))) &&
              /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
             (CAN_TRANSMIT == (Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16CtrlGlobalIndex].eMBType ))
           )
        {
            /* Enabled & TxPoll used. Process Tx interrupt flags. */
            Can_FlexCan_ProcessTxPoll(u8CtrlId, u16CtrlGlobalIndex);
        }
    }
    
}

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to writepoll
* @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Send the data from that MB that is configured for Tx.
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionMultipleWritePoll( VAR(uint8, AUTOMATIC) writepoll)
{
    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC)  u8CtrlId = 0U;
    /* First MB to process. */
    VAR(uint16, AUTOMATIC)  u16CtrlGlobalIndex = 0U;

    if ( NULL_PTR != Can_pCurrentConfig )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_eDriverStatus )
            {
                /*
                   (CAN179) If development error detection for the module Can is enabled: The function Can_MainFunction_Write shall raise
                           the error CAN_E_UNINIT if the driver is not yet initialized.
                */
                
                (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_WRITE, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                
                /* Parse through all TX configured message buffer */
                for ( u16CtrlGlobalIndex = Can_pCurrentConfig->uCanFirstHTHIndex; u16CtrlGlobalIndex < Can_pCurrentConfig->MBConfigContainer.uMessageBufferConfigCount; u16CtrlGlobalIndex++)
                {
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u8CtrlId = Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16CtrlGlobalIndex].u8ControllerId;
                    
                    /*  Poll only the Tx MB which is referenced by Can_FlexCan_MainFunctionMultipleWritePoll */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    if ((writepoll == Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16CtrlGlobalIndex].u32CanMainFuncRWPeriodRef) &&
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        (FLEXCAN_NULL_OFFSET_U8 != CanStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset) &&
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        ((uint32)0U != (CAN_CONTROLLERCONFIG_TXPOL_EN_U32 & (CanStatic_pControlerDescriptors[u8CtrlId].u32Options))) &&
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                        (CAN_TRANSMIT == (Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16CtrlGlobalIndex].eMBType )))
                    {
                        /* Enabled & TxPoll used. Process Tx interrupt flags. */
                        Can_FlexCan_ProcessTxPoll(u8CtrlId, u16CtrlGlobalIndex);
                    }
                }
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}
#endif /* (CAN_TXPOLL_SUPPORTED == STD_ON) */

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer from ISR when Interrupt mode selected.
* @details        Processes Rx interrupt flags.
                  This routine is called by:
                    - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process
* @param[in]      mbindex_end last MB to process
*
* @pre            MB is configured for Rx.
* @post           Inform CanIf in case a data frame was received.
*
*
*/
#if (CAN_TX_RX_INTR_SUPPORTED == STD_ON)
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_FlexCan_ProcessRx( CONST(uint8, AUTOMATIC) controller,
                                             CONST(uint8, AUTOMATIC) mbindex_start,
                                             CONST(uint8, AUTOMATIC) mbindex_end )
{
    VAR(uint8, AUTOMATIC)   u8MbIndex;
    VAR(uint16, AUTOMATIC)   u16MbGlobalIndex;

    for (u8MbIndex = mbindex_start; u8MbIndex <= mbindex_end; u8MbIndex++)
    {
    #if (CAN_RXFIFO_ENABLE == STD_ON)
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( (CAN_CONTROLLERCONFIG_RXFIFO_U32 == ((Can_pControlerDescriptors[controller].u32Options) & CAN_CONTROLLERCONFIG_RXFIFO_U32)) && \
             (u8MbIndex < (Can_pCurrentConfig->ControlerDescriptors[controller].u8RxFiFoUsedMb - (uint8)1U))
           )
        {
            Can_FlexCan_ProcessRxFifo(controller, u8MbIndex);
        }
        else
        {
    #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
    
            u16MbGlobalIndex = Can_ControllerStatuses[controller].u16MBMapping[u8MbIndex];
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
            if ( CAN_RECEIVE == (Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MbGlobalIndex].eMBType) )
            {
                Can_FlexCan_ProcessRxNormal(controller, u16MbGlobalIndex);
            }
    #if (CAN_RXFIFO_ENABLE == STD_ON)
        }
    #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
    }
}

#endif /* (CAN_TX_RX_INTR_SUPPORTED == STD_ON) */


/*================================================================================================*/
/**
* @brief          Service to perform the polling of RX indications.
* @details        Processes Rx interrupt flags.
*                 This routine is called by:
*                    - Can_MainFunction_Read() from Can.c file.
*
* @pre            The controller must be configured for receive in polling mode and at least one MB is configured for Rx.
* @post           Process the reception data in case of availability.
*
*
*/
#if (CAN_RXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionRead( void)
{

    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC)  u8CtrlId = 0U;
#if (CAN_RXFIFO_ENABLE == STD_ON)
    /* First MB to process. */
    VAR(uint8, AUTOMATIC)  u8MbIndex = 0U;
#endif
    VAR(uint16, AUTOMATIC)  u16MBGlobalIndex = 0U;
    
    /* Loop through all configured controller descriptors. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    for ( u16MBGlobalIndex = 0U; u16MBGlobalIndex < (uint16)Can_pCurrentConfig->uCanFirstHTHIndex; u16MBGlobalIndex++)
    {
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u8CtrlId = Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MBGlobalIndex].u8ControllerId;
        /*
           (CAN108) The function Can_MainFunction_Read shall perform the polling of RX indications when CanRxProcessing is set to POLLING.
        */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( (FLEXCAN_NULL_OFFSET_U8 != CanStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset) &&
             /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
             ((uint32)0U != (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & (CanStatic_pControlerDescriptors[u8CtrlId].u32Options)))
           )
        {
        #if (CAN_RXFIFO_ENABLE == STD_ON)
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u8MbIndex = ((Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ( (CAN_CONTROLLERCONFIG_RXFIFO_U32 == ((Can_pControlerDescriptors[u8CtrlId].u32Options) & CAN_CONTROLLERCONFIG_RXFIFO_U32)) &&
                 (u8MbIndex == (uint8)0U)
               )
            {
                for (u8MbIndex = (uint8)FLEXCAN_FIFOFRAME_INT_INDEX_U8; u8MbIndex <= (uint8)FLEXCAN_FIFOOVERFLOW_INT_INDEX_U8; u8MbIndex++)
                {
                    Can_FlexCan_ProcessRxFifo(u8CtrlId, u8MbIndex);
                }
            }
            else
            {
        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        
                Can_FlexCan_ProcessRxNormal(u8CtrlId, u16MBGlobalIndex);
                
        #if (CAN_RXFIFO_ENABLE == STD_ON)
            }
        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        }
    }    
}

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to .readpoll
* @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
* @pre            Driver must be initialized.
* @post           Receive the data from that MB that is configured for Rx.
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
/**
* @violates @ref Can_Flexcan_c_REF_5 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionMultipleReadPoll( VAR(uint8, AUTOMATIC) readpoll)
{
    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC)  u8CtrlId = 0U;
#if (CAN_RXFIFO_ENABLE == STD_ON)
    /* First MB to process. */
    VAR(uint8, AUTOMATIC)  u8MbIndex = 0U;
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
    VAR(uint16, AUTOMATIC)  u16MBGlobalIndex = 0U;
    
    if ( NULL_PTR != Can_pCurrentConfig )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_eDriverStatus )
            {
                /*
                   (CAN181) If development error detection for the Can module is enabled: The function Can_MainFunction_Read shall raise the
                           error CAN_E_UNINIT if the driver not yet initialized.
                */               
                (void)Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* Loop through all configured controller descriptors. */
                for ( u16MBGlobalIndex = 0U; u16MBGlobalIndex < Can_pCurrentConfig->uCanFirstHTHIndex; u16MBGlobalIndex++)
                {
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    u8CtrlId = Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MBGlobalIndex].u8ControllerId;
                    
                    /*
                       (CAN108) The function Can_MainFunction_Read shall perform the polling of RX indications when CanRxProcessing is set to POLLING.
                    */
                    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    if ( (readpoll == Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u16MBGlobalIndex].u32CanMainFuncRWPeriodRef) &&
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        (FLEXCAN_NULL_OFFSET_U8 != CanStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset) &&
                         /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4,pointer arithmetic other than array indexing used */
                         ((uint32)0U != (CAN_CONTROLLERCONFIG_RXPOL_EN_U32 & (CanStatic_pControlerDescriptors[u8CtrlId].u32Options)))
                       )
                    {
                    #if (CAN_RXFIFO_ENABLE == STD_ON)
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        u8MbIndex = ((Can_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex;
                        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        if ( (CAN_CONTROLLERCONFIG_RXFIFO_U32 == ((Can_pControlerDescriptors[u8CtrlId].u32Options) & CAN_CONTROLLERCONFIG_RXFIFO_U32)) &&
                             (u8MbIndex == (uint8)0U)
                           )
                        {
                            for (u8MbIndex = (uint8)FLEXCAN_FIFOFRAME_INT_INDEX_U8; u8MbIndex <= (uint8)FLEXCAN_FIFOOVERFLOW_INT_INDEX_U8; u8MbIndex++)
                            {
                                Can_FlexCan_ProcessRxFifo(u8CtrlId, u8MbIndex);
                            }
                        }
                        else
                        {
                    #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                    
                            Can_FlexCan_ProcessRxNormal(u8CtrlId, u16MBGlobalIndex);
                            
                    #if (CAN_RXFIFO_ENABLE == STD_ON)
                        }
                    #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                    }
                }
                
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}
#endif /* (CAN_RXPOLL_SUPPORTED == STD_ON) */


/*================================================================================================*/
/**
* @brief          Service to perform the polling of CAN status register flags to detect transition of CAN Controller state
* @details        The function Can_MainFunction_Mode shall implement the polling of CAN status register flags to detect transition of CAN Controller state
*
* @pre
* @post
*
*/

FUNC (void, CAN_CODE) Can_FlexCan_MainFunctionMode( void)
{
    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC)  u8CtrlIndex = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;
    /* Old and new MCR status Register*/
    
    VAR(uint32, AUTOMATIC)  u32NewMcr = 0U;

    /* Loop through all configured controller descriptors. */
    for ( u8CtrlIndex = (uint8)0U; u8CtrlIndex < (uint8)CanStatic_pCurrentConfig->u8ControllersConfigured; u8CtrlIndex++)
    {
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        if ( (FLEXCAN_NULL_OFFSET_U8 != CanStatic_pControlerDescriptors[u8CtrlIndex].u8ControllerOffset) )
        {
            if(CAN_SLEEPED != Can_ControllerStatuses[u8CtrlIndex].ControllerState)
            {   
                /* Get the hardware offset for this controller. */

                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                u8HwOffset = CanStatic_pControlerDescriptors[u8CtrlIndex].u8ControllerOffset;
                /*
                    (CAN373) The function Can_Mainfunction_Mode shall call the function CanIf_ControllerModeIndication to notify the upper layer about a successful
                             state transition of the CAN controller, in case the state transition was triggered by function Can_SetControllerMode.
                */
                
                /* We have to look for all the possible transitions*/
                
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 u32NewMcr = (uint32)(REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_NOTRDY_U32);
                 
                 
                /*Check if logical state is synchronized with hardware state*/
                if((FLEXCAN_MCR_NOTRDY_U32 == u32NewMcr) && (CAN_STARTED == Can_ControllerStatuses[u8CtrlIndex].ControllerState))
                {
            #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE32(FLEXCAN_MCR(u8HwOffset), ((~FLEXCAN_PNET_ENABLE_U32) & u32NewMcr));
                    Can_ControllerStatuses[u8CtrlIndex].eCanIcomState = CAN_ICOM_DEACTIVATED;
            #endif
                    Can_ControllerStatuses[u8CtrlIndex].ControllerState = CAN_STOPPED;
                    CanIf_ControllerModeIndication(u8CtrlIndex, CANIF_CS_STOPPED);
                }
                else if ((FLEXCAN_MCR_NOTRDY_U32 != u32NewMcr) && (CAN_STOPPED == Can_ControllerStatuses[u8CtrlIndex].ControllerState))
                {

                    Can_ControllerStatuses[u8CtrlIndex].ControllerState = CAN_STARTED;

                    CanIf_ControllerModeIndication(u8CtrlIndex, CANIF_CS_STARTED);
                }   
                else
                {
                /* deliberately left blank to avoid MISRA violation (Rule 14.10 ) */
                }
            }
        }
    }
}

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_BusOff if polling is selected or from ISR when Interrupt mode selected.
* @details        Local function for calling notification function to notify upper layer during
*                 Can_MainFunction_BusOff if polling is selected or from ISR when Interrupt mode selected.
*                 This routine is called by:
*                  - Can_IPW_ProcessBusOff() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            A busoff condition must to be fulfilled.
* @post           Status flag is cleared.
*
*/
FUNC (void, CAN_CODE) Can_FlexCan_ProcessBusOff( CONST(uint8, AUTOMATIC) controller)
{
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC) u8HwOffset = 0U;


    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* Clear the ESR[BOFF_INT] bus off interrupt flag (w1c). */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    REG_WRITE32( FLEXCAN_ESR(u8HwOffset), (FLEXCAN_ESR_BOFFINT_U32 & FLEXCAN_ESR_CONFIG_MASK_U32));
}

/*================================================================================================*/
/**
* @brief          This function checks if a BusOff has occurred for the given controller.
* @details        This routine is called by:
*                  - Can_MainFunction_BusOff() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return        Std_ReturnType
* @retval        E_OK BusOff detected
* @retval        E_NOT_OK BusOff not detected
*
* @pre            A request for busoff checking is required.
* @post           Report the occurence or not for an busoff event.
*
*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Std_ReturnType, CAN_CODE) Can_FlexCan_CheckBusOff( VAR(uint8, AUTOMATIC) controller)
{

    /* Return value. */
    VAR(uint8, AUTOMATIC) eReturnValue = (uint8)E_NOT_OK;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC) u8HwOffset = 0U;

    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* Check Busoff flag if it's set. */
     /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
     /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
     /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ( FLEXCAN_ESR_BOFFINT_U32 == (FLEXCAN_ESR_BOFFINT_U32 & (uint32)REG_READ32( FLEXCAN_ESR(u8HwOffset))) )
    {
        /* Controller is in BusOff state. */
        eReturnValue = (uint8)E_OK;
    }

    return (eReturnValue);
}


/*================================================================================================*/
/**
* @brief          Process Rx Fifo FrameAvailable events.
* @details        This routine is called by:
*                  - Can_IPW_RxFifoFrameAvNotif() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return        Std_ReturnType
* @retval        E_OK Notification detected
* @retval        E_NOT_OK Notification not detected
*
* @pre            Driver must be initialized and RxFifo should be enabled.
*
*/
#if (CAN_RXFIFO_ENABLE == STD_ON)

/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC(void, CAN_CODE) Can_FlexCan_RxFifoFrameAvNotif( CONST(uint8, AUTOMATIC) controller)
{
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;
    /* Variable for indexing the MBs. */
    VAR(uint8, AUTOMATIC)    u8MbIndex = 0U;
    /* Number of data bytes. */
    VAR(uint8, AUTOMATIC)    u8MbDataLength = 0U;
    /* Physical data bytes. */
    VAR(uint8, AUTOMATIC)    u8CanMbData[8];
    /* Index for data byte of MB. */
    VAR(uint8, AUTOMATIC)    u8DatabyteIndex = 0U;
    /* Variable for storing the Hrh. */
    VAR(Can_HwHandleType, AUTOMATIC)    u32Hrh = 0U;
    /* Variables for storing the CanID. */
    VAR(Can_IdType, AUTOMATIC) u32MbMessageId = 0U;
    /* Temporary variable. */
    VAR(uint32, AUTOMATIC)   u32MbConfig = 0U;
        /* Identifies the HRH and its corresponding CAN Con-troller. */
        VAR(Can_HwType, AUTOMATIC) Mailbox;
        /* Pointer to the received L-PDU. */
        VAR(PduInfoType, AUTOMATIC) PduInfoPtr;

        
    VAR(uint16, AUTOMATIC)   u16MBGlobalIndex = 0U;
    /* Pointer to the MB container structure. */
    VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    
    pCanMbConfigContainer   = &(Can_pCurrentConfig->MBConfigContainer);
    
    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset = CanStatic_pControlerDescriptors[controller].u8ControllerOffset;

         MCAL_FAULT_INJECTION_POINT(CAN_FIP_4_CHANGE_LENGTH_FIELD);
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u32MbConfig = (uint32)REG_READ32( FLEXCAN_MB((u8HwOffset), (uint32)(u8MbIndex)));

    /* Create a local copy of the MB to ensure that it is locked out for minimum amount of time. Read the DLC; this read access also locks the MB. */
    u8MbDataLength = (uint8)((u32MbConfig & FLEXCAN_MBCS_LENGTH_U32) >> FLEXCAN_MBCS_LENGTH_SHIFT_U32);
    
    /*Prevents that a buffer overflow to be generated by a CAN bus error affecting length field*/
    if( u8MbDataLength > 8U )
    {
        u8MbDataLength = 8U;
    }            

    /* Get the ID of the message.
    For extended IDs the most significant bit must be set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/
    if (((uint32)0x0U == (u32MbConfig & (uint32)FLEXCAN_MBCS_IDE_U32)))
    {
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u32MbMessageId = (Can_IdType)((uint32)((REG_READ32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u8MbIndex))) & (uint32)(FLEXCAN_MBID_ID_STANDARD_U32)) >> (uint32)(18U)));
    }
    else
    {
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u32MbMessageId = (Can_IdType)((uint32)((uint32)(REG_READ32( FLEXCAN_MB_ID((u8HwOffset), (uint32)(u8MbIndex))) & (uint32)(FLEXCAN_MBID_ID_EXTENDED_U32)) | FLEXCAN_MBC_ID_IDE_U32));
    }

    /* Copy the data. */
    for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < u8MbDataLength; u8DatabyteIndex++)
    {
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        u8CanMbData[u8DatabyteIndex] = REG_READ8(FLEXCAN_MB_DATA((uint32)(u8HwOffset), (uint32)(u8MbIndex), (u8DatabyteIndex))) ;
    }

    /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
        unless the CPU reads the C/S word of another MB.*/
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    REG_READ32( FLEXCAN_TIMER(u8HwOffset));

    /*
    Call the RxIndication function - This service is implemented in the CAN Interface and called by the CAN Driver after a CAN L-PDU has been received.
    Within this service, the CAN Interface translates the CanId into the configured target PDU ID and routes this indication to the configured upper layer target service(s).
    */
    
    /* Find the global index of the first MB (MB0) of this controller.*/
    while ( (u16MBGlobalIndex < (uint16)Can_pCurrentConfig->uCanFirstHTHIndex) &&
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */   
            ((controller != (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8ControllerId)) ||
            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */   
            ((uint8)0U != (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u8HWMBIndex)))
          )
    {
        u16MBGlobalIndex ++;
    }
    /* Get HW object ID of the first MB */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    u32Hrh = (Can_HwHandleType)((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MBGlobalIndex)->u32HWObjID;

    #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
    /*[CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        if ((boolean)TRUE ==    CanLPduReceiveCalloutFunction((uint8)u32Hrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
        {
    #endif
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            /* Standard/Extended CAN ID of CAN L-PDU */
            Mailbox.CanId = u32MbMessageId;
            /* ID of the corresponding Hardware Object Range */
            Mailbox.Hoh = u32Hrh;
            /* ControllerId provided by CanIf clearly identify the corresponding controller */
            Mailbox.ControllerId = controller;
            /* length of the SDU in bytes */
            PduInfoPtr.SduLength = u8MbDataLength; 
            /* pointer to the SDU (i.e. payload data) of the PDU */
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            PduInfoPtr.SduDataPtr=&u8CanMbData[0];
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            CanIf_RxIndication(&Mailbox, &PduInfoPtr );
    #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
        }
    #endif
    /* Ack interrupt flag - w1c bit. */
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    REG_WRITE32( FLEXCAN_IFLAG1(u8HwOffset), (uint32)((FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32)));
}
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/*================================================================================================*/
/*
* @brief          Process a transition from one clock source to another.
* @details        This function is configuring Can controllers to run on the same baudrate, but having a different MCU source clock.
*                 This routine is called by:
*                  - Can_SetClockMode() from Can.c file.
*
* @param[in]      u8Controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      can_clk_mode clock mode selection
*
* @return        Std_ReturnType Result of the clock switch operation.
* @retval        E_OK  Switch clock operation was ok.
* @retval        E_NOT_OK  Switch clock operation was not ok.
*
* @pre            Driver must be initialized and all the controllers must be in Stop state.
*
* @note           Not AUTOSAR required. This is user implementation.
*/

#if (CAN_DUAL_CLOCK_MODE == STD_ON)

FUNC(Std_ReturnType, CAN_CODE) Can_FlexCan_SetClockMode( VAR(uint8, AUTOMATIC) u8Controller, VAR(Can_ClockModeType, AUTOMATIC) can_clk_mode)
{
    /* Return the operation success. */
    VAR(Std_ReturnType, AUTOMATIC) eReturnValue = (uint8)E_NOT_OK;
    
    if ((can_clk_mode == CAN_NORMAL) || (can_clk_mode == CAN_ALTERNATE))
    {
        /* Set the controller clock mode*/
        Can_ControllerStatuses[u8Controller].CanClockMode = can_clk_mode;
        eReturnValue = (Std_ReturnType)E_OK;
    }

    return (eReturnValue);
}

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

/*================================================================================================*/
/*
* @brief          Set controller into Pretended Networking mode with the ConfigurationID valid.
* @details        This function is API which support the Pretended Networking featrue. After this function is called, it will configure for controller with information in the configurationIDs (corresponding with ID valid )
*                 This routine is called by:
*                  - Can_SetIcomConfiguration() from Can.c file.
*
* @param[in]      Controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      u8ConfigIcomIndex the ID of CanIcomConfig
*
* @return        Std_ReturnType Result of the clock switch operation.
* @retval        E_OK  Configure was ok.
* @retval        E_NOT_OK  Configure was not ok.
*
* @pre            Driver must be initialized and all the controllers must be in Stop state.
*
* @note           At the momen, Just have Calypso to support this feature, base on ASR421.
*/

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CAN_CODE) Can_FlexCan_SetIcomConfig( VAR(uint8, AUTOMATIC) u8Controller, VAR(uint8, AUTOMATIC) u8ConfigIcomIndex )
{
    VAR(uint32, AUTOMATIC)          u32RegisterValue = 0U;
    
    /* Variable for store value of timeout*/
#if (CAN_PRETENDED_TIMEOUT_CHECK==STD_ON)
    VAR(uint32, AUTOMATIC)          u32Timercount = 0U;
#endif /* (CAN_PRETENDED_TIMEOUT_CHECK==STD_ON) */
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif
    /* Variable for return status. */
    VAR(Std_ReturnType, AUTOMATIC) eReturnValue = (Std_ReturnType)E_NOT_OK;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)           u8HwOffset = 0U;
    volatile P2CONST(Can_IcomConfigsType, CAN_CONST, CAN_APPL_CONST) CanIcomConfig;
    volatile P2CONST(Can_IcomRxMessageConfigsType, CAN_CONST, CAN_APPL_CONST) CanIcomRxMessageConfig;
    volatile P2CONST(Can_IcomRxMessageSignalType, CAN_CONST, CAN_APPL_CONST) CanIcomRxMessageSignalConfig;
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */   
    u8HwOffset = CanStatic_pControlerDescriptors[u8Controller].u8ControllerOffset;
    /* Get adress of structures of PNET mode. */
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    CanIcomConfig = &(CanStatic_pCurrentConfig->pCanIcomConfigs[u8ConfigIcomIndex]);
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    CanIcomRxMessageConfig = &(CanIcomConfig->pCanIcomRxMessageConfigs[0U]);
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    CanIcomRxMessageSignalConfig = &(CanIcomRxMessageConfig->pCanIcomRxMessageSignalConfigs[0U]);
    /* [SWS_CAN_00464]CanDrv is responsible to perform reconfiguration of the CAN Controller (incl. ICOM) according to the CanIcomConfig parameters for the  selected configuration (CanIcomConfigId). */
    /*Put the controller in freeze*/  
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);

    u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    while ( (FLEXCAN_MCR_FRZACK_U32 != ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
            (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
          )
    {
#ifdef CAN_TIMEOUT_AS_LOOP
        u32TotalElapsedTime++;
#else
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
        u32TotalElapsedTime += u32ElapsedTime;
#endif
    }
    
    if (u32TotalElapsedTime < Can_u32TicksDelayDuration)
    {
        /* Init PNET mode for controller */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_PNET_ENABLE_U32);
        Can_ControllerStatuses[u8Controller].eCanIcomState = CAN_ICOM_ACTIVATED;
        /* ======================================== Write all parameter for PNET================================================= */
        /* Write parameter for registers relate to PNET mode */

    #if (CAN_PRETENDED_TIMEOUT_CHECK==STD_ON)
        /* Write value for CAN_CTRL2_PN[MATCHTO] */
        u32Timercount = (uint32)(CanIcomRxMessageConfig->CanIcomMissingMessageTimerValue);
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_CAN_CTRL2_PN(u8HwOffset), (uint32)u32Timercount);
    #endif
        /* Write value for CAN_FLT_ID1 register */
        u32RegisterValue = (uint32)(CanIcomRxMessageConfig->CanIcomMessageId);
    #if (CAN_EXTENDEDID == STD_ON)
            u32RegisterValue = u32RegisterValue | (uint32)0x40000000U;
    #else
            u32RegisterValue = u32RegisterValue << FLEXCAN_STANDARD_ID_SHIFT_U32;
    #endif
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_CAN_FLT_ID1(u8HwOffset), (uint32)(u32RegisterValue));
        /* Write value for CAN_FLT_ID2_IDMASK register */
        u32RegisterValue = (uint32)(CanIcomRxMessageConfig->CanIcomMessageIdMask);
    #if (CAN_EXTENDEDID == STD_ON)
            u32RegisterValue = u32RegisterValue | (uint32)0x40000000U;
    #else
            u32RegisterValue = u32RegisterValue << FLEXCAN_STANDARD_ID_SHIFT_U32;
    #endif
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_CAN_FLT_ID2_IDMASK(u8HwOffset), (uint32)(u32RegisterValue));
        if ((boolean)TRUE == CanIcomRxMessageConfig->CanFiltPayload)
        {
             /* Write value for CAN_FLT_DLC register */
            u32RegisterValue = (uint32)(CanIcomRxMessageSignalConfig->DLCLowValue) << 16U;
            u32RegisterValue |= (uint32)(CanIcomRxMessageSignalConfig->DLCHighValue);
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32(FLEXCAN_CAN_FLT_DLC(u8HwOffset), (uint32)(u32RegisterValue));
            u32RegisterValue = 0U;
            /* Write value for CAN_PL1_HI register */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32(FLEXCAN_CAN_PL1_HI(u8HwOffset), CanIcomRxMessageSignalConfig->CanIcomSignalValueHigh);
            /* Write value for CAN_PL1_LO register */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32(FLEXCAN_CAN_PL1_LO(u8HwOffset), CanIcomRxMessageSignalConfig->CanIcomSignalValueLow);
        
            /* Write value for CAN_PL2_PLMASK_HI register */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32(FLEXCAN_CAN_PL2_PLMASK_HI(u8HwOffset), CanIcomRxMessageSignalConfig->CanIcomSignalMaskHigh);
            /* Write value for CAN_PL2_PLMASK_LO register */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32(FLEXCAN_CAN_PL2_PLMASK_LO(u8HwOffset), CanIcomRxMessageSignalConfig->CanIcomSignalMaskLow);
        }
        /* ======================================== Configure mode for PNET================================================= */

        /* Configure the CAN_CTRL1_PN[WTOF_MSK] */
    #if (CAN_PRETENDED_TIMEOUT_CHECK==STD_ON)
        if (0U != u32Timercount)
        {
            u32RegisterValue = FLEXCAN_CTRL1_PN_WTOF_U32;
        }
        else
        {
            u32RegisterValue = 0U;
        }
    #endif
        /* Configure the CAN_CTRL1_PN[WUMF_MSK] */
        u32RegisterValue = u32RegisterValue | FLEXCAN_CTRL1_PN_WUMF_U32;
        /* Filtering by both ID and payload */
        if ((boolean)TRUE == CanIcomRxMessageConfig->CanFiltPayload)
        {
            /* Configure the CAN_CTRL1_PN[PLFS] */
            switch(CanIcomRxMessageSignalConfig->CanIcomSignalOperation)
            {
                case (EQUAL):
                    /* Excatly payload filtering type */
                    u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_EXACTLY_PAYLOAD_U32;
                    break;
                case (GREATER):
                    /* Greater payload filtering type */
                    u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_GREATER_PAYLOAD_U32;
                    break;
                case (SMALLER):
                    /* Smaller payload filtering type */
                    u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_SMALLER_PAYLOAD_U32;
                    break;
                case (XOR):
                    /* Inside range payload filtering type */
                    u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_INSIDE_RANGE_PAYLOAD_U32;
                    break;
                default:
                    /* Prevent misra */
                    break;
            }
            u32RegisterValue = u32RegisterValue | (uint32)0x01U; /* mask for payload */
        }
        /* Configure the CAN_CTRL1_PN[IDFS] */
        switch(CanIcomRxMessageConfig->CanIcomIdOperation)
        {
            case (EXACTLY):
                /* Excatly ID filtering type */
                u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_EXACTLY_ID_U32;
                break;
            case (GREATER_MINNUM):
                /* Greater ID filtering type */
                u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_GREATER_ID_U32;
                break;
            case (SMALLER_MAXNUM):
                /* Smaller ID filtering type */
                u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_SMALLER_ID_U32;
                break;
            case (INSIDE_RANGE):
                /* Inside range ID filtering type */
                u32RegisterValue = u32RegisterValue|(uint32)FLEXCAN_INSIDE_RANGE_ID_U32;
                break;
            default:
                /* Prevent misra */
                break;
        }
        /* Configuration information for the combination type */
    #if (CAN_PRETENDED_COUNT_MESSAGE==STD_ON)
        u32RegisterValue = u32RegisterValue | (uint32)0x02U | (((uint32)CanIcomRxMessageConfig->CanIcomCounterValue) << 8U);
    #endif
        /* Write the configuration information in the CAN_CTRL1_PN register */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_CAN_CTRL1_PN(u8HwOffset), (uint32)u32RegisterValue);

        /* Change Can Controller back to normal mode */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
        u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        while ( (FLEXCAN_MCR_FRZACK_U32 == ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
                (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
            )
        {
#ifdef CAN_TIMEOUT_AS_LOOP
            u32TotalElapsedTime++;
#else
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
            u32TotalElapsedTime += u32ElapsedTime;
#endif
        }
        
        if (u32TotalElapsedTime < Can_u32TicksDelayDuration)
        {
            eReturnValue = (Std_ReturnType)E_OK;
        }
    }
    return (eReturnValue);
}


/*================================================================================================*/
/*
* @brief          Set controller into normal mode with the ConfigurationID equal 0.
* @details        When the user use the Can_SetIcomConfiguration() with ConfigurationID equal 0. The Pretended Networking is disabled.
*                 This routine is called by:
*                  - Can_SetIcomConfiguration() from Can.c file.
*
* @param[in]      Controller    CAN controller for which the init shall be done.
*
* @return        Std_ReturnType Result of the clock switch operation.
* @retval        E_OK  Configure was ok.
* @retval        E_NOT_OK  Configure was not ok.
*
* @pre            Driver must be initialized and all the controllers must be in Stop state.
*
* @note           At the momen, Just have Calypso to support this feature, base on ASR421.
*/

FUNC(Std_ReturnType, CAN_CODE) Can_FlexCan_DeactivateIcom( VAR(uint8, AUTOMATIC) u8Controller)
{
    VAR(uint32, AUTOMATIC)          u8HwOffset = 0U;
    VAR(uint32, AUTOMATIC)          u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    VAR(TickType, AUTOMATIC)        u32CurrentValue, u32ElapsedTime;
#endif
    /* Variable for return status. */
    VAR(Std_ReturnType, AUTOMATIC) eReturnValue = (Std_ReturnType)E_NOT_OK;
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */   
    u8HwOffset = CanStatic_pControlerDescriptors[u8Controller].u8ControllerOffset;
    /* [SWS_CAN_00471] Pretended Networking shall be deactivated (i.e. CanDrv shall behave as when it is configured without Pretended Networking support) by calling Can_SetIcomConfiguration() with a configuration ID = 0. */
    /* put controller into the Freeze mode */
    
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
    
    u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
    /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    while ( (FLEXCAN_MCR_FRZACK_U32 != ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
            (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
          )
    {
#ifdef CAN_TIMEOUT_AS_LOOP
            u32TotalElapsedTime++;
#else
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
            u32TotalElapsedTime += u32ElapsedTime;
#endif
    }
    
    if (u32TotalElapsedTime < Can_u32TicksDelayDuration)
    {
        /* Deactivate the PNET mode */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_PNET_ENABLE_U32);
        Can_ControllerStatuses[u8Controller].eCanIcomState = CAN_ICOM_DEACTIVATED;
        
        /* put controller out to the Freeze mode */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_HALT_U32);
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( FLEXCAN_MCR(u8HwOffset), FLEXCAN_MCR_FRZ_U32);
    
        u32TotalElapsedTime = 0U;
#ifndef CAN_TIMEOUT_AS_LOOP
        /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue);
#endif
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        while ( (FLEXCAN_MCR_FRZACK_U32 == ((uint32)REG_READ32( FLEXCAN_MCR(u8HwOffset)) & FLEXCAN_MCR_FRZACK_U32)) && \
                (u32TotalElapsedTime < Can_u32TicksDelayDuration) \
            )
        {
#ifdef CAN_TIMEOUT_AS_LOOP
            u32TotalElapsedTime++;
#else
             /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            (void)GetElapsedValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &u32CurrentValue, &u32ElapsedTime);
            u32TotalElapsedTime += u32ElapsedTime;
#endif
        }
        if (u32TotalElapsedTime <= Can_u32TicksDelayDuration)
        {
            eReturnValue = (Std_ReturnType)E_OK;
        }
    }
    
    return (eReturnValue);
}
/*================================================================================================*/
/* @violates @ref Can_Flexcan_c_REF_7 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC(void, CAN_CODE) Can_FlexCan_ProcessWakeupPN( CONST(uint8, AUTOMATIC) u8controller)
{
    VAR(uint32, AUTOMATIC) numbermbtemp = 0U;
    VAR(uint8, AUTOMATIC) u8HwOffset = 0U;
    volatile VAR(uint32, AUTOMATIC) can_numbermb = 0U;
    VAR(uint8, AUTOMATIC) u8CanMbData[8U];
    VAR(uint8, AUTOMATIC) u8DatabyteIndex = 0U;
    /* Identifies the HRH and its corresponding CAN Con-troller. */
    VAR(Can_HwType, AUTOMATIC) Mailbox;
    /* Pointer to the received L-PDU. */
    VAR(PduInfoType, AUTOMATIC) PduInfoPtr;
    
    /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */   
    u8HwOffset = CanStatic_pControlerDescriptors[u8controller].u8ControllerOffset;

    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    if(FLEXCAN_WU_MTC_WUMF_MSK_U32 ==((uint32)REG_READ32(FLEXCAN_CAN_WU_MTC(u8HwOffset)) & FLEXCAN_WU_MTC_WUMF_MSK_U32))
    {
        /* Wake-up by message wake-up */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_CAN_WU_MTC(u8HwOffset), FLEXCAN_WU_MTC_WUMF_MSK_W1C);
        /* [SWS_CAN_00468]If Pretended Networking is activated CanDrv shall call CanIf_RxIndication() if and only if the received message matches the wakeup conditions of the CanIcomConfig (see CanIcomWakeupCauses). */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        can_numbermb = (uint32)(((uint32)REG_READ32(FLEXCAN_CAN_CTRL1_PN(u8HwOffset)) & FLEXCAN_CTRL1_PN_NMATCH_U32) >> 8U);

        if (4U>can_numbermb)
        {
            can_numbermb = can_numbermb;
        }
        else
        {
            can_numbermb = 3U;
        }
        for (numbermbtemp = 0U; numbermbtemp <= can_numbermb; numbermbtemp++)
        {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            if (FLEXCAN_CAN_WMB_CS_IDE_U32 == (uint32)(REG_READ32(FLEXCAN_CAN_WMB_CS(u8HwOffset, (numbermbtemp))) & FLEXCAN_CAN_WMB_CS_IDE_U32))
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                Mailbox.CanId = (Can_IdType)(REG_READ32(FLEXCAN_CAN_WMB_ID(u8HwOffset, (numbermbtemp))) & FLEXCAN_CAN_WMB_ID_IDMB_U32);
            }
            else
            {
                /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                Mailbox.CanId = (Can_IdType)((REG_READ32(FLEXCAN_CAN_WMB_ID(u8HwOffset, (numbermbtemp))) & FLEXCAN_CAN_WMB_ID_IDMB_U32) >> FLEXCAN_STANDARD_ID_SHIFT_U32);
            }
            /* ID of the corresponding Hardware Object Range */
            Mailbox.Hoh = (Can_HwHandleType)numbermbtemp;
            /* ControllerId provided by CanIf clearly identify the corresponding controller */
            Mailbox.ControllerId = u8controller;
            /* length of the SDU in bytes */
            /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            PduInfoPtr.SduLength = (uint32)((uint32)(REG_READ32(FLEXCAN_CAN_WMB_CS(u8HwOffset, (numbermbtemp))) & FLEXCAN_CAN_WMB_CS_DLC_U32) >> 16U);
            /* Read the data of wake-up MB */
            for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < (uint8)PduInfoPtr.SduLength; u8DatabyteIndex++)
            {
                switch (u8DatabyteIndex)
                {
                    case (0U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)((((uint32)REG_READ32(FLEXCAN_CAN_WMB_D03(u8HwOffset, (numbermbtemp)))) >> 24U)& (uint32)0xFF);
                        break;
                    case (1U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)((((uint32)REG_READ32(FLEXCAN_CAN_WMB_D03(u8HwOffset, (numbermbtemp)))) >> 16U)& (uint32)0xFF);
                        break;
                    case (2U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)((((uint32)REG_READ32(FLEXCAN_CAN_WMB_D03(u8HwOffset, (numbermbtemp)))) >> 8U)& (uint32)0xFF);
                        break;
                    case (3U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)((((uint32)REG_READ32(FLEXCAN_CAN_WMB_D03(u8HwOffset, (numbermbtemp)))) >> 0U) & (uint32)0xFF);
                        break;
                    case (4U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)(((uint32)REG_READ32(FLEXCAN_CAN_WMB_D47(u8HwOffset, (numbermbtemp))) >> 24U) & (uint32)0xFF);
                        break;
                    case (5U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)(((uint32)REG_READ32(FLEXCAN_CAN_WMB_D47(u8HwOffset, (numbermbtemp))) >> 16U) & (uint32)0xFF);
                        break;
                    case (6U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)(((uint32)REG_READ32(FLEXCAN_CAN_WMB_D47(u8HwOffset, (numbermbtemp))) >> 8U) & (uint32)0xFF);
                        break;
                    case (7U):
                        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u8CanMbData[u8DatabyteIndex] = (uint8)(((uint32)REG_READ32(FLEXCAN_CAN_WMB_D47(u8HwOffset, (numbermbtemp))) >> 0U) & (uint32)0xFF);
                        break;
                    default:
                        break;
                }
            }
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            PduInfoPtr.SduDataPtr=&u8CanMbData[numbermbtemp];
            /* @violates @ref Can_Flexcan_c_REF_4 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            CanIf_RxIndication(&Mailbox, &PduInfoPtr );
        }
    }
    /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    if(FLEXCAN_WU_MTC_WTOF_MSK_U32 ==((uint32)REG_READ32(FLEXCAN_CAN_WU_MTC(u8HwOffset)) & FLEXCAN_WU_MTC_WTOF_MSK_U32))
    {
        /* Wake-up by timeout */
        /* @violates @ref Can_Flexcan_c_REF_2 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Flexcan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32(FLEXCAN_CAN_WU_MTC(u8HwOffset), FLEXCAN_WU_MTC_WTOF_MSK_W1C);
    }
}
#endif

#define CAN_STOP_SEC_CODE
/* @violates @ref Can_Flexcan_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Flexcan_c_REF_3 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */

#include "Can_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
