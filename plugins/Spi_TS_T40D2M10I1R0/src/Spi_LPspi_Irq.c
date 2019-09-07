/**
*   @file    Spi_LPspi_Irq.c
*   @implements     Spi_LPspi_Irq.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_LPspi_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_LPspi_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_LPspi_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are 
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_LPspi_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function
* and any type other than an integral type.
* This violation can not be avoided because it appears when addressing memory mapped registers
* or other hardware specific features.
*
* @section Spi_LPspi_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_LPspi.h"
/*
* @violates @ref Spi_LPspi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Mcal.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @violates @ref Spi_LPspi_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_MODULE_ID_IRQ_C                      83
#define SPI_VENDOR_ID_IRQ_C                      43
#define SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define SPI_AR_RELEASE_MINOR_VERSION_IRQ_C       2
/*
* @violates @ref Spi_LPspi_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_REVISION_VERSION_IRQ_C    2
#define SPI_SW_MAJOR_VERSION_IRQ_C               1
#define SPI_SW_MINOR_VERSION_IRQ_C               0
#define SPI_SW_PATCH_VERSION_IRQ_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_IRQ_C != SPI_VENDOR_ID)
    #error "Spi_LPspi_Irq.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_IRQ_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_LPspi_Irq.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_IRQ_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_IRQ_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_IRQ_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_LPspi_Irq.c and Spi_LPSPI.h are different"
#endif

/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_VENDOR_ID_IRQ_C != SPI_VENDOR_ID_LPSPI)
    #error "Spi_LPspi_Irq.c and Spi_LPSPI.h have different vendor ids"
#endif

#if (( SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MAJOR_VERSION_LPSPI) || \
     ( SPI_AR_RELEASE_MINOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MINOR_VERSION_LPSPI) || \
     ( SPI_AR_RELEASE_REVISION_VERSION_IRQ_C != SPI_AR_RELEASE_REVISION_VERSION_LPSPI))
#error "AutoSar Version Numbers of Spi_LPSPI.h and Spi_LPspi_Irq.c are different"
#endif

#if (( SPI_SW_MAJOR_VERSION_IRQ_C != SPI_SW_MAJOR_VERSION_LPSPI) || \
     ( SPI_SW_MINOR_VERSION_IRQ_C != SPI_SW_MINOR_VERSION_LPSPI) || \
     ( SPI_SW_PATCH_VERSION_IRQ_C != SPI_SW_PATCH_VERSION_LPSPI))
#error "Software Version Numbers of Spi_LPspi_Irq.c and Spi_LPSPI.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_LPspi_Irq.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_LPspi_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

    /* Notifications */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #if (SPI_DMA_USED == STD_ON)
        #ifdef LPSPI_0_ENABLED
            #if (LPSPI_0_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_0(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_0(void);
            #endif
        #endif

        #ifdef LPSPI_1_ENABLED
            #if (LPSPI_1_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_1(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_1(void);
            #endif
        #endif

        #ifdef LPSPI_2_ENABLED
            #if (LPSPI_2_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_2(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_2(void);
            #endif
        #endif

        #ifdef LPSPI_3_ENABLED
            #if (LPSPI_3_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_3(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_3(void);
            #endif
        #endif

        #ifdef LPSPI_4_ENABLED
            #if (LPSPI_4_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_4(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_4(void);
            #endif
        #endif
        
        #ifdef LPSPI_5_ENABLED
            #if (LPSPI_5_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_5(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_5(void);
            #endif
        #endif
        
        #ifdef LPSPI_6_ENABLED
            #if (LPSPI_6_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_6(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_6(void);
            #endif
        #endif
        
        #ifdef LPSPI_7_ENABLED
            #if (LPSPI_7_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_7(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_7(void);
            #endif
        #endif
        
        #ifdef LPSPI_8_ENABLED
            #if (LPSPI_8_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_8(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_8(void);
            #endif
        #endif
        
        #ifdef LPSPI_9_ENABLED
            #if (LPSPI_9_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_9(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_9(void);
            #endif
        #endif
        
        #ifdef LPSPI_10_ENABLED
            #if (LPSPI_10_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_10(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_10(void);
            #endif
        #endif
        
        #ifdef LPSPI_11_ENABLED
            #if (LPSPI_11_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_11(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_11(void);
            #endif
        #endif
        
        #ifdef LPSPI_12_ENABLED
            #if (LPSPI_12_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_12(void);

    FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_12(void);
            #endif
        #endif
    #endif
#endif


    /* Interrupt service routines */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #ifdef LPSPI_0_ENABLED
        #if (LPSPI_0_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_0);
        #endif
    #endif

    #ifdef LPSPI_1_ENABLED
        #if (LPSPI_1_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_1);
        #endif
    #endif

    #ifdef LPSPI_2_ENABLED
        #if (LPSPI_2_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_2);
        #endif
    #endif

    #ifdef LPSPI_3_ENABLED
        #if (LPSPI_3_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_3);
        #endif
    #endif

    #ifdef LPSPI_4_ENABLED
        #if (LPSPI_4_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_4);
        #endif
    #endif
    
    #ifdef LPSPI_5_ENABLED
        #if (LPSPI_5_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_5);
        #endif
    #endif
    
    #ifdef LPSPI_6_ENABLED
        #if (LPSPI_6_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_6);
        #endif
    #endif
    
    #ifdef LPSPI_7_ENABLED
        #if (LPSPI_7_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_7);
        #endif
    #endif
    
    #ifdef LPSPI_8_ENABLED
        #if (LPSPI_8_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_8);
        #endif
    #endif
    
    #ifdef LPSPI_9_ENABLED
        #if (LPSPI_9_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_9);
        #endif
    #endif
    
    #ifdef LPSPI_10_ENABLED
        #if (LPSPI_10_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_10);
        #endif
    #endif
    
    #ifdef LPSPI_11_ENABLED
        #if (LPSPI_11_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_11);
        #endif
    #endif
    
    #ifdef LPSPI_12_ENABLED
        #if (LPSPI_12_ENABLED == STD_ON)
    ISR(Spi_LPspi_IsrTDF_LPSPI_12);
        #endif
    #endif
#endif

/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 0. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 0
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_0_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #if (SPI_DMA_USED == STD_ON)
        #ifdef LPSPI_0_ENABLED
            #if (LPSPI_0_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_0(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_0_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_0(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_0_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the LPSPI 1. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_1_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
        #ifdef LPSPI_1_ENABLED
            #if (LPSPI_1_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_1(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_1_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_1(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_1_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the LPSPI 2. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 2
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_2_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
        #ifdef LPSPI_2_ENABLED
            #if (LPSPI_2_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_2(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_2_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_2(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_2_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 3. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 3
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_3_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_3_ENABLED
            #if (LPSPI_3_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_3(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_3_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_3(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_3_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 4. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 4
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_4_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_4_ENABLED
            #if (LPSPI_4_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_4(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_4_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_4(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_4_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 5. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 5
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_5_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_5_ENABLED
            #if (LPSPI_5_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_5(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_5_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_5(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_5_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 6. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 6
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_6_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_6_ENABLED
            #if (LPSPI_6_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_6(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_6_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_6(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_6_HWUNIT));
}
            #endif
        #endif  
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 7. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 7
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_7_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_7_ENABLED
            #if (LPSPI_7_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_7(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_7_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_7(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_7_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 8. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 8
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_8_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_8_ENABLED
            #if (LPSPI_8_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_8(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_8_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_8(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_8_HWUNIT));
}
            #endif
        #endif 
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 9. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 9
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_9_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_9_ENABLED
            #if (LPSPI_9_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_9(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_9_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_9(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_9_HWUNIT));
}
            #endif
        #endif  
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 10. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 10
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_10_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_10_ENABLED
            #if (LPSPI_10_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_10(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_10_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_10(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_10_HWUNIT));
}
            #endif
        #endif 
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 11. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 11
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_11_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_11_ENABLED
            #if (LPSPI_11_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_11(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_11_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_11(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_11_HWUNIT));
}
            #endif
        #endif 
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the LPSPI 12. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for LPSPI 12
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_12_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef LPSPI_12_ENABLED
            #if (LPSPI_12_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrRxDma_LPSPI_12(void)
{
    Spi_LPspi_IsrDmaRx(LPSPI_HWUNIT2LPSPI(LPSPI_12_HWUNIT));
}
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LPspi_IsrTxDma_LPSPI_12(void)
{
    Spi_LPspi_IsrDmaTx(LPSPI_HWUNIT2LPSPI(LPSPI_12_HWUNIT));
}
            #endif
        #endif        
    #endif /* End SPI_DMA_USED */

/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 0.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 0
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_0_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef LPSPI_0_ENABLED
        #if (LPSPI_0_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_0)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_0_HWUNIT), LPSPI_0_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 1.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_1_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef LPSPI_1_ENABLED
        #if (LPSPI_1_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_1)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_1_HWUNIT), LPSPI_1_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 2.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 2.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_2_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef LPSPI_2_ENABLED
        #if (LPSPI_2_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_2)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_2_HWUNIT), LPSPI_2_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 3. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 3.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_3_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_3_ENABLED
        #if (LPSPI_3_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_3)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_3_HWUNIT), LPSPI_3_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 4. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 4.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_4_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_4_ENABLED
        #if (LPSPI_4_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_4)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_4_HWUNIT), LPSPI_4_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 5. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 5.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_5_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_5_ENABLED
        #if (LPSPI_5_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_5)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_5_HWUNIT), LPSPI_5_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 6. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 6.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_6_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_6_ENABLED
        #if (LPSPI_6_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_6)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_6_HWUNIT), LPSPI_6_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 7. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 7.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_7_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_7_ENABLED
        #if (LPSPI_7_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_7)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_7_HWUNIT), LPSPI_7_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 8. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 8.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_8_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_8_ENABLED
        #if (LPSPI_8_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_8)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_8_HWUNIT), LPSPI_8_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 9. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 9.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_9_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_9_ENABLED
        #if (LPSPI_9_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_9)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_9_HWUNIT), LPSPI_9_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 10. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 10.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_10_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_10_ENABLED
        #if (LPSPI_10_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_10)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_10_HWUNIT), LPSPI_10_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 11. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 11.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_11_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_11_ENABLED
        #if (LPSPI_11_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_11)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_11_HWUNIT), LPSPI_11_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the LPSPI 12. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for LPSPI 12.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter LPSPI_12_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef LPSPI_12_ENABLED
        #if (LPSPI_12_ENABLED == STD_ON)
/*
* @violates @ref Spi_LPspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_LPspi_IsrTDF_LPSPI_12)
{
    Spi_LPspi_IsrFifoRx(LPSPI_HWUNIT2LPSPI(LPSPI_12_HWUNIT), LPSPI_12_OFFSET);
    /*
    * @violates @ref Spi_LPspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
#endif /* End SPI_LEVEL_DELIVERED */
/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_LPspi_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/** @} */



