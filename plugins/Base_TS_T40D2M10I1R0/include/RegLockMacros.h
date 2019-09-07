/**
*   @file    RegLockMacros.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - IP module versions.
*   @details Implements macros for soft and hard lock on ARM hardware platform
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
* @section RegLockMacros_h_REF_1 
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Functions like macros are used to reduce code complexity.
* @section RegLockMacros_h_REF_2 
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters.The used compilers use more than 31 chars 
*          for identifiers.
* @section RegLockMacros_h_REF_3
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class
*          specifier, or a do-while-zero construct This is used to abstract access to register
*          protection bits
*/


#ifndef REGLOCKMACROS_H
#define REGLOCKMACROS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @violates @ref RegLockMacros_h_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Platform_Types.h"
/* @violates @ref RegLockMacros_h_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Mcal.h"
/* @violates @ref RegLockMacros_h_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "StdRegMacros.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REGLOCKMACROS_VENDOR_ID                    43
#define REGLOCKMACROS_MODULE_ID                    0
#define REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION     4
#define REGLOCKMACROS_AR_RELEASE_MINOR_VERSION     2
#define REGLOCKMACROS_AR_RELEASE_REVISION_VERSION  2
#define REGLOCKMACROS_SW_MAJOR_VERSION             1
#define REGLOCKMACROS_SW_MINOR_VERSION             0
#define REGLOCKMACROS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of RegLockMacros.h and Platform_Types.h are different"
    #endif
#endif

/* Check if source file and Mcal.h header file have same versions */
#if (REGLOCKMACROS_VENDOR_ID != MCAL_VENDOR_ID)
#error "RegLockMacros.h and Mcal.h have different vendor IDs"
#endif
#if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) || \
     (REGLOCKMACROS_AR_RELEASE_REVISION_VERSION != MCAL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of RegLockMacros.h and Mcal.h are different"
#endif
#if ((REGLOCKMACROS_SW_MAJOR_VERSION != MCAL_SW_MAJOR_VERSION) || \
     (REGLOCKMACROS_SW_MINOR_VERSION != MCAL_SW_MINOR_VERSION) || \
     (REGLOCKMACROS_SW_PATCH_VERSION != MCAL_SW_PATCH_VERSION))
#error "Software Version Numbers of RegLockMacros.h and Mcal.h are different"
#endif

/* Check if source file and StdRegMacros.h header file have same versions */
#if (REGLOCKMACROS_VENDOR_ID != STDREGMACROS_VENDOR_ID)
#error "SilRegMacros.h and StdRegMacros.h have different vendor IDs"
#endif
#if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (REGLOCKMACROS_AR_RELEASE_REVISION_VERSION != STDREGMACROS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SilRegMacros.h and StdRegMacros.h are different"
#endif
#if ((REGLOCKMACROS_SW_MAJOR_VERSION != STDREGMACROS_SW_MAJOR_VERSION) || \
     (REGLOCKMACROS_SW_MINOR_VERSION != STDREGMACROS_SW_MINOR_VERSION) || \
     (REGLOCKMACROS_SW_PATCH_VERSION != STDREGMACROS_SW_PATCH_VERSION))
#error "Software Version Numbers of SilRegMacros.h and StdRegMacros.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Sanity check on USER_MODE_REG_PROT_ENABLED. This define must exist and has to have one of the 
following 2 values: STD_ON or STD_OFF */
#ifndef USER_MODE_REG_PROT_ENABLED
    #error "USER_MODE_REG_PROT_ENABLED is not defined" 
#endif
#if ((USER_MODE_REG_PROT_ENABLED != STD_ON) && (USER_MODE_REG_PROT_ENABLED != STD_OFF))
    #error "USER_MODE_REG_PROT_ENABLED has a wrong value"
#endif


/**
* @brief Mask for setting a SLB bit in a SLBR register
*/
#define SLBR_SET_BIT_MASK_U8              ((uint8)0x88U)

/**
* @brief Mask for clearing a SLB bit in a SLBR register
*/
#define SLBR_CLR_BIT_MASK_U8              ((uint8)0x80U)

/**
* @brief Mask for reading a SLB bit in a SLBR register
*/
#define SLBR_GET_BIT_MASK_U8              ((uint8)0x08U)

/**
* @brief Mask used for getting the alignment of an address
*        inside a 32 bit word
*/
#define MODULO_4_BIT_MASK_U32             ((uint32)0x3UL)

/**
* @brief Offset to REG_PROT mirrored registers area 
*        of an IP module
*/
#define MIRRORED_ADDR_OFFSET_U32          ((uint32)0x2000UL)

/**
* @brief Offset to baseAddress of the SLBR registers area
*        of an IP module
*/
#define SLBR_ADDR_OFFSET_U32              ((uint32)0x3800UL)

/**
* @brief Macro for getting the address of a lockable
*        register's corresponding SLBR register 
*/
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define SLBR_ADDR32(baseAddr, regAddr)  (((uint32)(baseAddr)) + SLBR_ADDR_OFFSET_U32 +                  \
                                        ((uint32)((((uint32)(regAddr)) - ((uint32)(baseAddr)))>>0x2U))) 

#ifdef IPV_REG_PROT
#if (IPV_REG_PROT == IPV_REG_PROT_00_01_02_04)
/**
* @brief Offset to baseAddress of the REG_PROT GCR register
*        of an IP module
*/
#define GCR_OFFSET_U32                    ((uint32)0x900UL)
#else
/**
* @brief Offset to baseAddress of the REG_PROT GCR register
*        of an IP module
*/
#define GCR_OFFSET_U32                    ((uint32)0x3FFCUL)
#endif
#else
/**
* @brief Offset to baseAddress of the REG_PROT GCR register
*        of an IP module
*/
#define GCR_OFFSET_U32                    ((uint32)0x3FFCUL)
#endif
/**
* @brief REG_PROT GCR bit masks
*/
#define REGPROT_GCR_HLB_MASK_U32          (BIT31)
#define REGPROT_GCR_UAA_MASK_U32          (BIT23)

/**
* @brief REG_PROT GCR bit positions
*/
#define REGPROT_GCR_HLB_POS_U32           ((uint32)31UL)
#define REGPROT_GCR_UAA_POS_U32           ((uint32)23UL)



/*==================================================================================================
*                     MACROS FOR WORKING WITH SW AND HW LOCK    
==================================================================================================*/


/**
* @brief      Soft locks a register by setting it's corresponding soft lock bit
*
* @details    Based on the address of the register to be soft locked and on the address
*             of the IP where the register belongs to, the corresponding soft lock bit
*             is set    
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to soft lock
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_SET_SOFT_LOCK(baseAddr, regAddr)                                                            \
        do                                                                                                  \
        {                                                                                                   \
            REG_WRITE8(SLBR_ADDR32((baseAddr), (regAddr)),                                                  \
                    (uint8)(SLBR_SET_BIT_MASK_U8 >> (((regAddr) - (baseAddr)) & MODULO_4_BIT_MASK_U32)));   \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_SET_SOFT_LOCK(baseAddr, regAddr)
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Soft unlocks a register by clearing it's corresponding soft lock bit
*
* @details    Based on the address of the register to be soft unlocked and on the address
*             of the IP where the register belongs to, the corresponding soft lock bit
*             is cleared    
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to soft unlock
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_CLR_SOFT_LOCK(baseAddr, regAddr)                                                            \
        do                                                                                                  \
        {                                                                                                   \
            REG_WRITE8(SLBR_ADDR32((baseAddr), (regAddr)),                                                  \
                    (uint8)(SLBR_CLR_BIT_MASK_U8 >> (((regAddr) - (baseAddr)) & MODULO_4_BIT_MASK_U32)));   \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_CLR_SOFT_LOCK(baseAddr, regAddr)
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Reads the status of the soft lock bit of a register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register for which to get soft lock bit status
*
* @return     uint8  - 1 if the register's soft lock is enabled
*                    - 0 if the register's soft lock is disabled
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_GET_SOFT_LOCK(baseAddr, regAddr)                                                               \
            ((uint8)((REG_READ8(SLBR_ADDR32((baseAddr), (regAddr))) &                                          \
                    ((uint8)(SLBR_GET_BIT_MASK_U8 >> (((regAddr) - (baseAddr)) & MODULO_4_BIT_MASK_U32)))) >>  \
                        (MODULO_4_BIT_MASK_U32 - (((regAddr) - (baseAddr)) & MODULO_4_BIT_MASK_U32))))
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_GET_SOFT_LOCK(baseAddr, regAddr)    ((uint8)0x0UL)
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Sets one bit in a 8 bit register and locks the register automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register the bit belongs to, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the bit belongs to 
* @param[in]  regAddr  - address of the register the bit belongs to
* @param[in]  mask     - 8 bit mask of the bit
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_SET_LOCK8(baseAddr, regAddr, mask)                                  \
        do                                                                              \
        {                                                                               \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                   \
            REG_BIT_SET8((regAddr)+ MIRRORED_ADDR_OFFSET_U32,(mask));                   \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_SET_LOCK8(baseAddr, regAddr, mask)                                  \
        REG_BIT_SET8((regAddr),(mask))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Sets one bit in a 16 bit register and locks the register automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register the bit belongs to, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the bit belongs to 
* @param[in]  regAddr  - address of the register the bit belongs to
* @param[in]  mask     - 8 bit mask of the bit
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_SET_LOCK16(baseAddr, regAddr, mask)                                   \
        do                                                                                \
        {                                                                                 \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                     \
            REG_BIT_SET16((regAddr)+ MIRRORED_ADDR_OFFSET_U32,(mask));                    \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_SET_LOCK16(baseAddr, regAddr, mask)                                   \
        REG_BIT_SET16((regAddr),(mask))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Sets one bit in a 32 bit register and locks the register automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register the bit belongs to, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the bit belongs to 
* @param[in]  regAddr  - address of the register the bit belongs to
* @param[in]  mask     - 8 bit mask of the bit
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_SET_LOCK32(baseAddr, regAddr, mask)                                   \
        do                                                                                \
        {                                                                                 \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                     \
            REG_BIT_SET32((regAddr)+ MIRRORED_ADDR_OFFSET_U32,(mask));                    \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_SET_LOCK32(baseAddr, regAddr, mask)                                   \
        REG_BIT_SET32((regAddr),(mask))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Clears one bit in a 8 bit register and locks the register automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register the bit belongs to, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the bit belongs to 
* @param[in]  regAddr  - address of the register the bit belongs to
* @param[in]  mask     - 8 bit mask of the bit
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_CLEAR_LOCK8(baseAddr, regAddr, mask)                                           \
        do                                                                                         \
        {                                                                                          \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                              \
            REG_BIT_CLEAR8((regAddr)+ MIRRORED_ADDR_OFFSET_U32,(mask));                            \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_CLEAR_LOCK8(baseAddr, regAddr, mask)                                           \
        REG_BIT_CLEAR8((regAddr),(mask))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Clears one bit in a 16 bit register and locks the register automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register the bit belongs to, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the bit belongs to 
* @param[in]  regAddr  - address of the register the bit belongs to
* @param[in]  mask     - 8 bit mask of the bit
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_CLEAR_LOCK16(baseAddr, regAddr, mask)                                          \
        do                                                                                         \
        {                                                                                          \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                              \
            REG_BIT_CLEAR16((regAddr)+ MIRRORED_ADDR_OFFSET_U32,(mask));                           \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_CLEAR_LOCK16(baseAddr, regAddr, mask)                                          \
        REG_BIT_CLEAR16((regAddr),(mask))                                  
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Clears one bit in a 32 bit register and locks the register automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register the bit belongs to, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the bit belongs to 
* @param[in]  regAddr  - address of the register the bit belongs to
* @param[in]  mask     - 8 bit mask of the bit
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_CLEAR_LOCK32(baseAddr, regAddr, mask)                                          \
        do                                                                                         \
        {                                                                                          \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                              \
            REG_BIT_CLEAR32((regAddr)+ MIRRORED_ADDR_OFFSET_U32,(mask));                           \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_BIT_CLEAR_LOCK32(baseAddr, regAddr, mask)                                          \
        REG_BIT_CLEAR32((regAddr),(mask))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Writes the content of a 8 bit register and locks it automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to write and soft lock
* @param[in]  value    - 8 bit value the register will be written with 
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_WRITE_LOCK8(baseAddr, regAddr, value)                          \
        do                                                                     \
        {                                                                      \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                          \
            REG_WRITE8(((regAddr) + MIRRORED_ADDR_OFFSET_U32), (value));       \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_WRITE_LOCK8(baseAddr, regAddr, value)                          \
        REG_WRITE8((regAddr), (value))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Writes the content of a 16 bit register and locks it automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to write and soft lock
* @param[in]  value    - 16 bit value the register will be written with 
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_WRITE_LOCK16(baseAddr, regAddr, value)                           \
        do                                                                       \
        {                                                                        \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                            \
            REG_WRITE16(((regAddr) + MIRRORED_ADDR_OFFSET_U32), (value));        \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_WRITE_LOCK16(baseAddr, regAddr, value)                           \
        REG_WRITE16((regAddr), (value))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Writes the content of a 32 bit register and locks it automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT mirrored value
*             of the register, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to write and soft lock
* @param[in]  value    - 32 bit value the register will be written with 
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_WRITE_LOCK32(baseAddr, regAddr, value)                           \
        do                                                                       \
        {                                                                        \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                            \
            REG_WRITE32(((regAddr) + MIRRORED_ADDR_OFFSET_U32), (value));        \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_WRITE_LOCK32(baseAddr, regAddr, value)                           \
        REG_WRITE32((regAddr), (value))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */


/**
* @brief      Clears the content of a 8 bit register, writes it with the value in
*             'value' parameter masked with the one in 'mask' parameter and locks 
*             it automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT 
*             mirrored value of the register, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to write and soft lock
* @param[in]  mask     - 8 bit mask the register will be written with 
* @param[in]  value    - 8 bit value the register will be written with 
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_RMW_LOCK8(baseAddr, regAddr, mask, value)                            \
        do                                                                           \
        {                                                                            \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                \
            REG_RMW8((regAddr) + MIRRORED_ADDR_OFFSET_U32, (mask), (value));         \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_RMW_LOCK8(baseAddr, regAddr, mask, value)                            \
        REG_RMW8((regAddr), (mask), (value))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */


/**
* @brief      Clears the content of a 16 bit register, writes it with the value in
*             'value' parameter masked with the one in 'mask' parameter and locks 
*             it automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT 
*             mirrored value of the register, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to write and soft lock
* @param[in]  mask     - 16 bit mask the register will be written with 
* @param[in]  value    - 16 bit value the register will be written with 
*
* @return     void
*/

#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_RMW_LOCK16(baseAddr, regAddr, mask, value)                               \
        do                                                                               \
        {                                                                                \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                    \
            REG_RMW16((regAddr) + MIRRORED_ADDR_OFFSET_U32, (mask), (value));            \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/    
    #define REG_RMW_LOCK16(baseAddr, regAddr, mask, value)                               \
        REG_RMW16((regAddr), (mask), (value))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */


/**
* @brief      Clears the content of a 32 bit register, writes it with the value in
*             'value' parameter masked with the one in 'mask' parameter and locks 
*             it automatically 
*
* @details    Clears first the corresponding soft lock bit and writes the REG_PROT 
*             mirrored value of the register, which automatically soft locks the register
*
* @param[in]  baseAddr - base address of the IP the register belongs to 
* @param[in]  regAddr  - address of the register to write and soft lock
* @param[in]  mask     - 32 bit mask the register will be written with 
* @param[in]  value    - 32 bit value the register will be written with 
*
* @return     void
*/
#if (STD_ON == USER_MODE_REG_PROT_ENABLED)
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_RMW_LOCK32(baseAddr, regAddr, mask, value)                               \
        do                                                                               \
        {                                                                                \
            REG_CLR_SOFT_LOCK((baseAddr), (regAddr));                                    \
            REG_RMW32((regAddr) + MIRRORED_ADDR_OFFSET_U32, (mask), (value));            \
        }while(0)
#else
    /* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define REG_RMW_LOCK32(baseAddr, regAddr, mask, value)                               \
        REG_RMW32((regAddr), (mask), (value))
#endif /* (STD_ON == USER_MODE_REG_PROT_ENABLED) */

/**
* @brief      Sets the hardlock bit of an IP module 
*
* @param[in]  baseAddr - base address of the IP to be hard locked 
*
* @return     void
*/
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser, 
 * a constant, a parenthesised expression*/ 
#define SET_HARD_LOCK(baseAddr)  \
        REG_BIT_SET32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_HLB_MASK_U32)

/**
* @brief      Reads the Hard Lock bit of an IP module 
*
* @param[in]  baseAddr - base address of the IP for which hard lock status is read 
*
* @return     uint8  - 1 if hard lock is enabled
*                    - 0 if hard lock is disabled
*/
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser, 
 * a constant, a parenthesised expression*/ 
#define GET_HARD_LOCK(baseAddr)  \
        ((uint8)(REG_BIT_GET32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_HLB_MASK_U32) >> REGPROT_GCR_HLB_POS_U32))

/**
* @brief      Sets the User Access Allowed bit of an IP module 
*
* @param[in]  baseAddr - base address of the IP for which UAA bit is set 
*
* @return     void
*/
#ifdef IPV_REG_PROT
#if (IPV_REG_PROT == IPV_REG_PROT_00_01_02_04)
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser,
 * a constant, a parenthesised expression*/

#define SET_USER_ACCESS_ALLOWED(baseAddr, prot_mem )  \
        REG_BIT_SET32((baseAddr) + ((prot_mem) * GCR_OFFSET_U32), REGPROT_GCR_UAA_MASK_U32)
#else
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser, 
 * a constant, a parenthesised expression*/ 
#define SET_USER_ACCESS_ALLOWED(baseAddr, prot_mem)  \
        REG_BIT_SET32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_UAA_MASK_U32)
#endif
#else
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser,
 * a constant, a parenthesised expression*/
#define SET_USER_ACCESS_ALLOWED(baseAddr, prot_mem)  \
        REG_BIT_SET32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_UAA_MASK_U32)

#endif
/**
* @brief      Clears the User Access Allowed bit of an IP module 
*
* @param[in]  baseAddr - base address of the IP for which UAA bit is cleared 
*
* @return     void
*/
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser, 
 * a constant, a parenthesised expression*/ 
#define CLR_USER_ACCESS_ALLOWED(baseAddr)  \
        REG_BIT_CLEAR32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_UAA_MASK_U32)

/**
* @brief      Reads the User Access Allowed bit of an IP module 
*
* @param[in]  baseAddr - base address of the IP for which UAA is read 
*
* @return     uint8  - 1 if User Access Allow is enabled
*                    - 0 if User Access Allow is disabled
*/
#ifdef IPV_REG_PROT
#if (IPV_REG_PROT == IPV_REG_PROT_00_01_02_04)
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser,
 * a constant, a parenthesised expression*/
#define GET_USER_ACCESS_ALLOWED(baseAddr, prot_mem)  \
        ((uint8)(REG_BIT_GET32((baseAddr) + ((prot_mem) * GCR_OFFSET_U32), REGPROT_GCR_UAA_MASK_U32) >> REGPROT_GCR_UAA_POS_U32))
#else
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser,
 * a constant, a parenthesised expression*/
#define GET_USER_ACCESS_ALLOWED(baseAddr, prot_mem)  \
        ((uint8)(REG_BIT_GET32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_UAA_MASK_U32) >> REGPROT_GCR_UAA_POS_U32))
#endif
#else
/* @violates @ref RegLockMacros_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * @violates @ref RegLockMacros_h_REF_3 C macros shall only expand to a braced initialiser,
 * a constant, a parenthesised expression*/
#define GET_USER_ACCESS_ALLOWED(baseAddr, prot_mem)  \
        ((uint8)(REG_BIT_GET32((baseAddr) + GCR_OFFSET_U32, REGPROT_GCR_UAA_MASK_U32) >> REGPROT_GCR_UAA_POS_U32))
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef REGLOCKMACROS_H */

/** @} */
