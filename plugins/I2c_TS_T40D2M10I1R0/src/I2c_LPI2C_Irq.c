/**
*   @file    I2c_LPI2C_Irq.c
*   @implements I2c_LPI2C_Irq.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - File used by I2C that contain the ISRs.
*   @details This file contains the ISR functions used to serve the I2C interrupts.
*
*   @addtogroup I2C
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPI2C
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
* @section I2c_LPI2C_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a 
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section I2c_LPI2C_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section I2c_LPI2C_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section I2c_LPI2C_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section I2c_LPI2C_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           I2c_LPI2C_Irq.c
*/
#include "CDD_I2c.h"
#include "I2c_LPI2C.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_LPI2C_IRQ_VENDOR_ID_C                    43
/**
* @violates @ref I2c_LPI2C_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_MAJOR_VERSION_LPI2C_IRQ_C     4
/**
* @violates @ref I2c_LPI2C_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_MINOR_VERSION_LPI2C_IRQ_C     2
/**
* @violates @ref I2c_LPI2C_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_REVISION_VERSION_LPI2C_IRQ_C  2
/**
* @violates @ref I2c_LPI2C_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_SW_MAJOR_VERSION_LPI2C_IRQ_C             1
/**
* @violates @ref I2c_LPI2C_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_SW_MINOR_VERSION_LPI2C_IRQ_C             0
/**
* @violates @ref I2c_LPI2C_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_SW_PATCH_VERSION_LPI2C_IRQ_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2C header file are of the same vendor */
#if (I2C_LPI2C_IRQ_VENDOR_ID_C != I2C_VENDOR_ID)
    #error "I2c_Irq.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Autosar version */
#if (((I2C_AR_RELEASE_MAJOR_VERSION_LPI2C_IRQ_C   != I2C_AR_RELEASE_MAJOR_VERSION)  || \
     (I2C_AR_RELEASE_MINOR_VERSION_LPI2C_IRQ_C    != I2C_AR_RELEASE_MINOR_VERSION)) || \
     (I2C_AR_RELEASE_REVISION_VERSION_LPI2C_IRQ_C != I2C_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar Version Numbers of I2c_Irq.c and CDD_I2c.h are different"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_LPI2C_IRQ_C != I2C_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_LPI2C_IRQ_C != I2C_SW_MINOR_VERSION) || \
     (I2C_SW_PATCH_VERSION_LPI2C_IRQ_C != I2C_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_Irq.c and CDD_I2c.h are different"
#endif
/* Check if current file and I2c_LPI2C header file are of the same vendor */
#if (I2C_LPI2C_IRQ_VENDOR_ID_C != I2C_LPI2C_VENDOR_ID)
    #error "I2c_Irq.c and I2c_LPI2C.h have different vendor ids"
#endif
/* Check if current file and I2c_LPI2C header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_LPI2C_IRQ_C    != I2C_LPI2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_AR_RELEASE_MINOR_VERSION_LPI2C_IRQ_C    != I2C_LPI2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_AR_RELEASE_REVISION_VERSION_LPI2C_IRQ_C != I2C_LPI2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_Irq.c and I2c_LPI2C.h are different"
#endif
/* Check if current file and I2c_LPI2C header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_LPI2C_IRQ_C != I2C_LPI2C_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_LPI2C_IRQ_C != 0)    || \
     (I2C_SW_PATCH_VERSION_LPI2C_IRQ_C != 1)       \
    )
    #error "Software Version Numbers of I2c_Irq.c and I2c_LPI2C.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
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

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define I2C_START_SEC_CODE
/** 
* @violates @ref I2c_LPI2C_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#if (I2C_UNIFIED_INTERRUPTS == STD_ON)
    #if defined(LPI2C_0)
    ISR(I2c_LPI2C_Isr_LPI2C_0);
    #endif

    #if defined(LPI2C_1)
    ISR(I2c_LPI2C_Isr_LPI2C_1);
    #endif
#else
    #if defined(LPI2C_0)
    ISR(I2c_LPI2C_0_MasterIsr);
    ISR(I2c_LPI2C_0_SlaveIsr);
    #endif

    #if defined(LPI2C_1)
    ISR(I2c_LPI2C_1_MasterIsr);
    ISR(I2c_LPI2C_1_SlaveIsr);
    #endif
#endif /* I2C_UNIFIED_INTERRUPTS == STD_ON */

#define I2C_STOP_SEC_CODE
/** 
* @violates @ref I2c_LPI2C_Irq_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
* @violates @ref I2c_LPI2C_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define I2C_START_SEC_CODE
/** 
* @violates @ref I2c_LPI2C_Irq_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
* @violates @ref I2c_LPI2C_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#if (I2C_UNIFIED_INTERRUPTS == STD_ON)
    #if defined(LPI2C_0)
    /**
    * @brief   Master& Slave interrupts for LPI2C_0.
    * @details This function implements the ISR occurring on a master event on
    *          LPI2C_0.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 0 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref I2c_LPI2C_Irq_c_REF_5 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(I2c_LPI2C_Isr_LPI2C_0)
    {
        I2c_LPI2C_MasterInterruptHandler(LPI2C_0);
        I2c_LPI2C_SlaveInterruptHandler(LPI2C_0);
        /** @violates @ref I2c_LPI2C_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif

    #if defined(LPI2C_1)
    /**
    * @brief   Master& Slave interrupts for LPI2C_1.
    * @details This function implements the ISR occurring on a master event on
    *          LPI2C_1.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 1 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref I2c_LPI2C_Irq_c_REF_5 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(I2c_LPI2C_Isr_LPI2C_1)
    {
        I2c_LPI2C_MasterInterruptHandler(LPI2C_1);
        I2c_LPI2C_SlaveInterruptHandler(LPI2C_1);
        /** @violates @ref I2c_LPI2C_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
#else
    #if defined(LPI2C_0)
    /**
    * @brief   Master interrupt for LPI2C_0.
    * @details This function implements the ISR occurring on a master event on
    *          LPI2C_0.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 0 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref I2c_LPI2C_Irq_c_REF_5 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(I2c_LPI2C_0_MasterIsr)
    {
        I2c_LPI2C_MasterInterruptHandler(LPI2C_0);
        /** @violates @ref I2c_LPI2C_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    /**
    * @brief   Slave Interrupt for LPI2C_0.
    * @details This function implements the ISR occurring on a slave event on
    *          LPI2C_0.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 0 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref I2c_LPI2C_Irq_c_REF_5 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(I2c_LPI2C_0_SlaveIsr)
    {
        I2c_LPI2C_SlaveInterruptHandler(LPI2C_0);
        /** @violates @ref I2c_LPI2C_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif

    #if defined(LPI2C_1)
    /**
    * @brief   Master interrupt for LPI2C_1.
    * @details This function implements the ISR occurring on a master event on
    *          LPI2C_1.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 1 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref I2c_LPI2C_Irq_c_REF_5 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(I2c_LPI2C_1_MasterIsr)
    {
        I2c_LPI2C_MasterInterruptHandler(LPI2C_1);
        /** @violates @ref I2c_LPI2C_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    /**
    * @brief   Slave Interrupt for LPI2C_1.
    * @details This function implements the ISR occurring on a slave event on
    *          LPI2C_1.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 1 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref I2c_LPI2C_Irq_c_REF_5 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(I2c_LPI2C_1_SlaveIsr)
    {
        I2c_LPI2C_SlaveInterruptHandler(LPI2C_1);
        /** @violates @ref I2c_LPI2C_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
#endif

#define I2C_STOP_SEC_CODE
/** 
* @violates @ref I2c_LPI2C_Irq_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
* @violates @ref I2c_LPI2C_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/*! @} */
