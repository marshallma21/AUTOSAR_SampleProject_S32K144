/**
*   @file    StdRegMacros.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Macros for accessing memory mapped registers.
*   @details Macro definitions used for accessing memory mapped registers.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
*   Dependencies         : none
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section StdRegMacros_h_REF_1
*     Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-
*     like macro.
*     This violation is due to function like macros defined for register operations. Function like
*     macros are used to reduce code complexity.
*
* @section StdRegMacros_h_REF_2
*     Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*     contents of a header being included twice.
*     This comes from the order of includes in the .c file and from include dependencies. As a safe
*     approach, any file must include all its dependencies. Header files are already protected 
*     against double inclusions.
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on 
*     the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*/

#ifndef STDREGMACROS_H
#define STDREGMACROS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file        StdRegMacros.h
* @brief Include platform types
* @violates @ref StdRegMacros_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in
* order to prevent the contents of a header being included twice.
*/
#include "Platform_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STDREGMACROS_VENDOR_ID                    43
#define STDREGMACROS_MODULE_ID                    0
#define STDREGMACROS_AR_RELEASE_MAJOR_VERSION     4
#define STDREGMACROS_AR_RELEASE_MINOR_VERSION     2
#define STDREGMACROS_AR_RELEASE_REVISION_VERSION  2
#define STDREGMACROS_SW_MAJOR_VERSION             1
#define STDREGMACROS_SW_MINOR_VERSION             0
#define STDREGMACROS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((STDREGMACROS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (STDREGMACROS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of StdRegMacros.h and Platform_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/**
@{
* @brief Bit masks declarations.
*/
#ifndef BIT31
    #define BIT31   ((uint32)0x80000000UL)
#else 
      #if (BIT31 != 0x80000000UL) 
             #error "BIT31 is defined outside MCAL and it is value is not 0x80000000UL". 
       #endif 
#endif 
    
#ifndef BIT30
    #define BIT30   ((uint32)0x40000000UL)
#else 
      #if (BIT30 != 0x40000000UL) 
             #error "BIT30 is defined outside MCAL and it is value is not 0x40000000UL". 
       #endif 
#endif 

#ifndef BIT29
    #define BIT29   ((uint32)0x20000000UL)
#else 
      #if (BIT29 != 0x20000000UL) 
             #error "BIT29 is defined outside MCAL and it is value is not 0x20000000UL". 
       #endif 
#endif 

#ifndef BIT28
    #define BIT28   ((uint32)0x10000000UL)
#else 
      #if (BIT28 != 0x10000000UL) 
             #error "BIT28 is defined outside MCAL and it is value is not 0x10000000UL". 
       #endif 
#endif 

#ifndef BIT27
    #define BIT27   ((uint32)0x08000000UL)
#else 
      #if (BIT27 != 0x08000000UL) 
             #error "BIT27 is defined outside MCAL and it is value is not 0x08000000UL". 
       #endif 
#endif 

#ifndef BIT26
    #define BIT26   ((uint32)0x04000000UL)
#else 
      #if (BIT26 != 0x04000000UL) 
             #error "BIT26 is defined outside MCAL and it is value is not 0x04000000UL". 
       #endif 
#endif 

#ifndef BIT25
    #define BIT25   ((uint32)0x02000000UL)
#else 
      #if (BIT25 != 0x02000000UL) 
             #error "BIT25 is defined outside MCAL and it is value is not 0x02000000UL". 
       #endif 
#endif 

#ifndef BIT24
    #define BIT24   ((uint32)0x01000000UL)
#else 
      #if (BIT24 != 0x01000000UL) 
             #error "BIT24 is defined outside MCAL and it is value is not 0x01000000UL". 
       #endif 
#endif 

#ifndef BIT23
    #define BIT23   ((uint32)0x00800000UL)
#else 
      #if (BIT23 != 0x00800000UL) 
             #error "BIT23 is defined outside MCAL and it is value is not 0x00800000UL". 
       #endif 
#endif 

#ifndef BIT22
    #define BIT22   ((uint32)0x00400000UL)
#else 
      #if (BIT22 != 0x00400000UL) 
             #error "BIT22 is defined outside MCAL and it is value is not 0x00400000UL". 
       #endif 
#endif 

#ifndef BIT21
    #define BIT21   ((uint32)0x00200000UL)
#else 
      #if (BIT21 != 0x00200000UL) 
             #error "BIT21 is defined outside MCAL and it is value is not 0x00200000UL". 
       #endif 
#endif 

#ifndef BIT20
    #define BIT20   ((uint32)0x00100000UL)
#else 
      #if (BIT20 != 0x00100000UL) 
             #error "BIT20 is defined outside MCAL and it is value is not 0x00100000UL". 
       #endif 
#endif 

#ifndef BIT19
    #define BIT19   ((uint32)0x00080000UL)
#else 
      #if (BIT19 != 0x00080000UL) 
             #error "BIT19 is defined outside MCAL and it is value is not 0x00080000UL". 
       #endif 
#endif 

#ifndef BIT18
    #define BIT18   ((uint32)0x00040000UL)
#else 
      #if (BIT18 != 0x00040000UL) 
             #error "BIT18 is defined outside MCAL and it is value is not 0x00040000UL". 
       #endif 
#endif 

#ifndef BIT17
    #define BIT17   ((uint32)0x00020000UL)
#else 
      #if (BIT17 != 0x00020000UL) 
             #error "BIT17 is defined outside MCAL and it is value is not 0x00020000UL". 
       #endif 
#endif 

#ifndef BIT16
    #define BIT16   ((uint32)0x00010000UL)
#else 
      #if (BIT16 != 0x00010000UL) 
             #error "BIT16 is defined outside MCAL and it is value is not 0x00010000UL". 
       #endif 
#endif 

#ifndef BIT15
    #define BIT15   ((uint32)0x00008000UL)
#else 
      #if (BIT15 != 0x00008000UL) 
             #error "BIT15 is defined outside MCAL and it is value is not 0x00008000UL". 
       #endif 
#endif 

#ifndef BIT14
    #define BIT14   ((uint32)0x00004000UL)
#else 
      #if (BIT14 != 0x00004000UL) 
             #error "BIT14 is defined outside MCAL and it is value is not 0x00004000UL". 
       #endif 
#endif 

#ifndef BIT13
    #define BIT13   ((uint32)0x00002000UL)
#else 
      #if (BIT13 != 0x00002000UL) 
             #error "BIT13 is defined outside MCAL and it is value is not 0x00002000UL". 
       #endif 
#endif 

#ifndef BIT12
    #define BIT12   ((uint32)0x00001000UL)
#else 
      #if (BIT12 != 0x00001000UL) 
             #error "BIT12 is defined outside MCAL and it is value is not 0x00001000UL". 
       #endif 
#endif 

#ifndef BIT11  
    #define BIT11   ((uint32)0x00000800UL)
#else 
      #if (BIT11 != 0x00000800UL) 
             #error "BIT11 is defined outside MCAL and it is value is not 0x00000800UL". 
       #endif 
#endif 

#ifndef BIT10
    #define BIT10   ((uint32)0x00000400UL)
#else 
      #if (BIT10 != 0x00000400UL) 
             #error "BIT10 is defined outside MCAL and it is value is not 0x00000400UL". 
       #endif 
#endif 

#ifndef BIT9
    #define BIT9    ((uint32)0x00000200UL)
#else 
      #if (BIT9 != 0x00000200UL) 
             #error "BIT9 is defined outside MCAL and it is value is not 0x00000200UL". 
       #endif 
#endif 

#ifndef BIT8
    #define BIT8    ((uint32)0x00000100UL)
#else 
      #if (BIT8 != 0x00000100UL) 
             #error "BIT8 is defined outside MCAL and it is value is not 0x00000100UL ". 
       #endif 
#endif 

#ifndef BIT7
    #define BIT7    ((uint32)0x00000080UL)
#else 
      #if (BIT7 != 0x00000080UL) 
             #error "BIT7 is defined outside MCAL and it is value is not 0x00000080UL". 
       #endif 
#endif 

#ifndef BIT6
    #define BIT6    ((uint32)0x00000040UL)
#else 
      #if (BIT6 != 0x00000040UL) 
             #error "BIT6 is defined outside MCAL and it is value is not 0x00000040UL". 
       #endif 
#endif 

#ifndef BIT5
    #define BIT5    ((uint32)0x00000020UL)
#else 
      #if (BIT5 != 0x00000020UL) 
             #error "BIT5 is defined outside MCAL and it is value is not 0x00000020UL". 
       #endif 
#endif 

#ifndef BIT4
    #define BIT4    ((uint32)0x00000010UL)
#else 
      #if (BIT4 != 0x00000010UL) 
             #error "BIT4 is defined outside MCAL and it is value is not 0x00000010UL". 
       #endif 
#endif 

#ifndef BIT3
    #define BIT3    ((uint32)0x00000008UL)
#else 
      #if (BIT3 != 0x00000008UL) 
             #error "BIT3 is defined outside MCAL and it is value is not 0x00000008UL". 
       #endif 
#endif 

#ifndef BIT2
    #define BIT2    ((uint32)0x00000004UL)
#else 
      #if (BIT2 != 0x00000004UL) 
             #error "BIT2 is defined outside MCAL and it is value is not 0x00000004UL". 
       #endif 
#endif 

#ifndef BIT1
    #define BIT1    ((uint32)0x00000002UL)
#else 
      #if (BIT1 != 0x00000002UL) 
             #error "BIT1 is defined outside MCAL and it is value is not 0x00000002UL". 
       #endif 
#endif 

#ifndef BIT0
    #define BIT0    ((uint32)0x00000001UL)
#else 
      #if (BIT0 != 0x00000001UL) 
             #error "BIT0 is defined outside MCAL and it is value is not 0x00000001UL". 
       #endif 
#endif
/**@}*/
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief 8 bits memory write macro
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_WRITE8(address, value)        ((*(volatile uint8*)(address))=  (value))
/**
* @brief 16 bits memory write macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_WRITE16(address, value)       ((*(volatile uint16*)(address))= (value))
/**
* @brief 32 bits memory write macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_WRITE32(address, value)       ((*(volatile uint32*)(address))= (value))


/**
* @brief 8 bits memory read macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_READ8(address)                (*(volatile uint8*)(address))
/**
* @brief 16 bits memory read macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_READ16(address)               (*(volatile uint16*)(address))
/**
* @brief 32 bits memory read macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_READ32(address)               (*(volatile uint32*)(address))

/**
* @brief 8 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AWRITE8(address, i, value)     (REG_WRITE8 ((address)+(i), (value)))
/**
* @brief 16 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AWRITE16(address, i, value)    (REG_WRITE16((address)+((uint32)((i)<<1U)), (value)))
/**
* @brief 32 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AWRITE32(address, i, value)    (REG_WRITE32((address)+((uint32)((i)<<2U)), (value)))


/**
* @brief 8 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AREAD8(address, i )            (REG_READ8 ((address)+(i)))
/**
* @brief 16 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AREAD16(address, i)            (REG_READ16((address)+((uint32)((i)<<1U))))
/**
* @brief 32 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_AREAD32(address, i)            (REG_READ32((address)+((uint32)((i)<<2U))))


/**
* @brief 8 bits bits clearing macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_CLEAR8(address, mask)     ((*(volatile uint8*)(address))&= (~(mask)))
/**
* @brief 16 bits bits clearing macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_CLEAR16(address, mask)    ((*(volatile uint16*)(address))&= (~(mask)))
/**
* @brief 32 bits bits clearing macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32*)(address))&= (~(mask)))


/**
* @brief 8 bits bits getting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_GET8(address, mask)       ((*(volatile uint8*)(address))& (mask))
/**
* @brief 16 bits bits getting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_GET16(address, mask)      ((*(volatile uint16*)(address))& (mask))
/**
* @brief 32 bits bits getting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_GET32(address, mask)      ((*(volatile uint32*)(address))& (mask))


/**
* @brief 8 bits bits setting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_SET8(address, mask)       ((*(volatile uint8*)(address))|= (mask))
/**
* @brief 16 bits bits setting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_SET16(address, mask)      ((*(volatile uint16*)(address))|= (mask))
/**
* @brief 32 bits bits setting macro.
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_BIT_SET32(address, mask)      ((*(volatile uint32*)(address))|= (mask))


/**
* @brief 8 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_RMW8(address, mask, value)    (REG_WRITE8((address), ((REG_READ8(address)& ((uint8)~(mask)))| (value))))
/**
* @brief 16 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_RMW16(address, mask, value)   (REG_WRITE16((address), ((REG_READ16(address)& ((uint16)~(mask)))| (value))))
/**
* @brief 32 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref StdRegMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32)~(mask)))| (value))))


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef STDREGMACROS_H */

/** @} */
