/**
*   @file    Crcu_Ipw.c
*
*   @version 1.0.1
*   @brief   AUTOSAR Crcu - CRCU driver middle level driver.
*   @details Implementation of the middle level CRCU driver.
*
*   @addtogroup CRCU_MODULE
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : CRCV2
*   Dependencies         : none
*
*   Autosar Version      : 4.2.
*                          2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_Ipw_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'.
*          MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section Crcu_Ipw_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_Ipw_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section Crcu_Ipw_c_REF_4
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
*          a pointer to a function and any type other than an integral type. 
*          This violation is due to the pointer arithmetic used to write/ read the data to/from the registers.
*
* @section Crcu_Ipw_c_REF_5
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
*          The cast is used to map a pointer to a Dma Tcd integral field.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
*
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Crcu_Ipw.h"
#include "Crcu_Reg_eSys_Crcv2.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define CRCU_IPW_VENDOR_ID_C                    43
/** @violates @ref Crcu_Ipw_c_REF_3 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_IPW_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Crcu_Ipw_c_REF_3 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_IPW_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref Crcu_Ipw_c_REF_3 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_IPW_AR_RELEASE_REVISION_VERSION_C  2
#define CRCU_IPW_SW_MAJOR_VERSION_C             1
#define CRCU_IPW_SW_MINOR_VERSION_C             0
#define CRCU_IPW_SW_PATCH_VERSION_C             1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if source file and Crcu_Ipw.h file are of the same vendor */
#if (CRCU_IPW_VENDOR_ID_C != CRCU_IPW_VENDOR_ID)
    #error "Crcu_Ipw.c and Crcu_Ipw.h have different vendor ids"
#endif

/* Check if the source file and Crcu_Ipw.h file are of the same Autosar version */
#if ((CRCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != CRCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_MINOR_VERSION_C    != CRCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_REVISION_VERSION_C != CRCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Ipw.c and Crcu_Ipw.h are different"
#endif

/* Check if source file and Crcu header file are of the same Software version */
#if ((CRCU_IPW_SW_MAJOR_VERSION_C != CRCU_IPW_SW_MAJOR_VERSION) || \
     (CRCU_IPW_SW_MINOR_VERSION_C != CRCU_IPW_SW_MINOR_VERSION) || \
     (CRCU_IPW_SW_PATCH_VERSION_C != CRCU_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Ipw.c and Crcu_Ipw.h are different"
#endif

/* Check if the source file and Crcu_Reg_eSys_Crcv2.h header file are of the same vendor */
#if (CRCU_IPW_VENDOR_ID_C != CRCU_REGESYS_CRCV2_VENDOR_ID)
    #error "Crcu_Ipw.c and Crcu_Reg_eSys_Crcv2.h have different vendor ids"
#endif
/* Check if the source file and Crcu_Reg_eSys_Crcv2.h header file are of the same Autosar version */
#if ((CRCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != CRCU_REGESYS_CRCV2_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_MINOR_VERSION_C    != CRCU_REGESYS_CRCV2_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_REVISION_VERSION_C != CRCU_REGESYS_CRCV2_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Ipw.c and Crcu_Reg_eSys_Crcv2.h are different"
#endif
/* Check if the source file and Crcu_Reg_eSys_Crcv2.h header file are of the same Software version */
#if ((CRCU_IPW_SW_MAJOR_VERSION_C != CRCU_REGESYS_CRCV2_SW_MAJOR_VERSION) || \
     (CRCU_IPW_SW_MINOR_VERSION_C != CRCU_REGESYS_CRCV2_SW_MINOR_VERSION) || \
     (CRCU_IPW_SW_PATCH_VERSION_C != CRCU_REGESYS_CRCV2_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Ipw.c and Crcu_Reg_eSys_Crcv2.h are different"
#endif

#if (STD_ON == CRCU_DMA_USED)

/*=================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/
#define CRCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Crcu_Ipw_c_REF_1 Only preprocessor statements and comments before '#include'. */
/** @violates @ref Crcu_Ipw_c_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

static VAR(Mcl_DmaTcdAttributesType, CRCU_VAR) crcuDmaTcdConfig;

#define CRCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Crcu_Ipw_c_REF_1 Only preprocessor statements and comments before '#include'. */
/** @violates @ref Crcu_Ipw_c_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
#define CRCU_START_SEC_CODE
/** @violates @ref Crcu_Ipw_c_REF_1 Only preprocessor statements and comments before '#include'. */
/** @violates @ref Crcu_Ipw_c_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

/*=================================================================================================
*                                      LOCAL FUNCTIONS
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL FUNCTIONS
=================================================================================================*/
/**
* @brief        Initializes the Dma channels used on Crcu driver.
* @details      The function @p Crcu_Ipw_Init will initialize the DMA channels used by the Crcu driver.
*
* @param[in]    pConfigPtr     Pointer to the initialization data structure
* 
* @return       void
*
* @api
*/
FUNC(void, CRCU_CODE) Crcu_Ipw_Init
(
    P2CONST(Crcu_ConfigType, AUTOMATIC, CRCU_APPL_CONST) pConfigPtr
)
{
    /* Ignore compiler warning */
    (void)pConfigPtr;
    
    /* Configure the Dma Tcd fields that will be the same for all Crc channels */
    crcuDmaTcdConfig.u32doff  = (uint32)0;    /* Destination address offset    */
    crcuDmaTcdConfig.u32smod  = (uint32)0;    /* Source address modulo         */
    crcuDmaTcdConfig.u32dmod  = (uint32)0;    /* Destination address modulo    */
    crcuDmaTcdConfig.u32iter  = (uint32)1;    /* Iteration count               */
}

/**
* @brief        Initializes the Dma channel used for transfering data from app to CRC IP, using DMA.
* @details      
*
* @param[in]    crcChannel - CRC Hw channel
* @param[in]    dmaChannel - Logic Id of the used DMA channel
* @param[in]    u8DataPtr  - Pointer to the buffer to perform CRC on
* @param[in]    u32Length  - Length of the data in buffer, in bytes
* 
* @return       void
*
* @api
*/
FUNC(void, CRCU_CODE) Crcu_Ipw_AsyncCalculateChannelCrc
(
    VAR    (Crcu_Crcv2_ChannelType, AUTOMATIC                 ) crcChannel,
    VAR    (Mcl_ChannelType,        AUTOMATIC                 ) dmaChannel,
    P2CONST(uint8,                  AUTOMATIC, CRCU_APPL_CONST) u8DataPtr,
    VAR    (uint32,                 AUTOMATIC                 ) u32Length,
    VAR    (uint8,                  AUTOMATIC                 ) u8NumBytesPerDmaTransfer
)
{
    /* Configure the specific Dma information */
    /** @violates @ref Crcu_Ipw_c_REF_4 Cast from a pointer to a function and any type other than an integral type */
    /** @violates @ref Crcu_Ipw_c_REF_5 A cast should not be performed between a pointer type and an integral type. */    
    crcuDmaTcdConfig.u32saddr     = (uint32)u8DataPtr;              /* Source address                   */
    crcuDmaTcdConfig.u32daddr     = CRCV2_DATA_ADDR32(crcChannel);  /* Destination adress               */
    crcuDmaTcdConfig.u32num_bytes = u32Length;                      /* Number of bytes to be transfered */

    if(sizeof(uint32) == u8NumBytesPerDmaTransfer)
    {
        crcuDmaTcdConfig.u32ssize = (uint32)DMA_SIZE_4BYTES;    /* Source transfer size          */
        crcuDmaTcdConfig.u32dsize = (uint32)DMA_SIZE_4BYTES;    /* Destination transfer size     */
        crcuDmaTcdConfig.u32soff  = (uint32)DMA_OFFSET_32_BITS; /* Source address offset         */
    }
    else
    {
        crcuDmaTcdConfig.u32ssize = (uint32)DMA_SIZE_1BYTE;     /* Source transfer size          */
        crcuDmaTcdConfig.u32dsize = (uint32)DMA_SIZE_1BYTE;     /* Destination transfer size     */
        crcuDmaTcdConfig.u32soff  = (uint32)DMA_OFFSET_8_BITS;  /* Source address offset         */
    }
    /* Configure the Dma channel with the information in the Tcd */
    Mcl_DmaConfigChannel(dmaChannel, &crcuDmaTcdConfig);
    /* Enable the notification at the end of the transfer */
    Mcl_DmaEnableNotification(dmaChannel, MCL_DMA_TRANSFER_COMPLETE);
    /* Start transfering data to the Crc engine using Dma */
    Mcl_DmaStartChannel(dmaChannel);
}

#define CRCU_STOP_SEC_CODE
/** @violates @ref Crcu_Ipw_c_REF_1 Only preprocessor statements and comments before '#include'. */
/** @violates @ref Crcu_Ipw_c_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

#endif /* (STD_ON == CRCU_DMA_USED) */

#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
