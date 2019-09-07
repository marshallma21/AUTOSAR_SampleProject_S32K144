/**
*   @file    Mcl_Dma.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - eDMA low level driver.
*   @details eDMA module low level functions.
*
*   @addtogroup MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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
* @section Mcl_DMA_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This violation is generated becuase conversions must not be performed between a pointer 
* to a function and any type other than an integral type. The cast can't be avoided as it is 
* used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcl_DMA_c_REF_4
* Violates MISRA 2004 Required Rule 19.15,Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_DMA_c_REF_7
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_DMA_c_REF_9
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The code could not be made static because is intern only for a certain compiler switch definition.
*
* @section Mcl_DMA_c_REF_10
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
* @section Mcl_DMA_c_REF_11
* Violates MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity
* to different underlying if...
* This violation is due to nescessary of generic implementation. It will be fixed when investigation and re-desgin complete
*
*/
#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Mcl_Dma.h"
#include "StdRegMacros.h"
#include "CDD_Mcl.h"
#include "CDD_Mcl_Cfg.h"
#include "SchM_Mcl.h"

#ifdef MCL_DISABLE_DEM_REPORT_ERROR_STATUS
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
#endif

#include "Mcl_IPW.h"
#include "Mcl_IPW_Notif.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_DMA_VENDOR_ID_C                    43
#define MCL_DMA_AR_RELEASE_MAJOR_VERSION_C     4
#define MCL_DMA_AR_RELEASE_MINOR_VERSION_C     2
#define MCL_DMA_AR_RELEASE_REVISION_VERSION_C  2
#define MCL_DMA_SW_MAJOR_VERSION_C             1
#define MCL_DMA_SW_MINOR_VERSION_C             0
#define MCL_DMA_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_DMA_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMA_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_Dma.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_DMA_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMA_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_Dma.c and StdRegMacros.h are different"
    #endif
#endif

#if (MCL_DMA_VENDOR_ID_C != MCL_DMA_VENDOR_ID)
    #error "Mcl_Dma.c and Mcl_Dma.h have different vendor IDs"
#endif
/* Check if source file and Mcl_Dma header file are of the same Autosar version */
#if ((MCL_DMA_AR_RELEASE_MAJOR_VERSION_C != MCL_DMA_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMA_AR_RELEASE_MINOR_VERSION_C != MCL_DMA_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMA_AR_RELEASE_REVISION_VERSION_C != MCL_DMA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Dma.h and Mcl_Dma.c are different"
#endif
/* Check if source file and Mcl_Dma header file are of the same Software version */
#if ((MCL_DMA_SW_MAJOR_VERSION_C != MCL_DMA_SW_MAJOR_VERSION) || \
     (MCL_DMA_SW_MINOR_VERSION_C != MCL_DMA_SW_MINOR_VERSION) || \
     (MCL_DMA_SW_PATCH_VERSION_C != MCL_DMA_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Dma.h and Mcl_Dma.c are different"
#endif
#ifdef MCL_DISABLE_DEM_REPORT_ERROR_STATUS
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Dem header file are of the same Autosar version */
     #if (( MCL_DMA_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
          ( MCL_DMA_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Mcl_Dma.c and Dem.h are different"
     #endif
 #endif
#endif
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_DMA_c_REF_4 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of a header file
*        being included twice
*/
#include "Mcl_MemMap.h"

/**
* @brief        Function that initializes the eDMA module.
* @details      This function sets the DMACR register with the value of "config" and set
*               the channel's priority, ECP and DPA
*
* @param[in]    pConfig - pointer to DMA configuration structure
*
* @return void
*
*/
FUNC(void, MCL_CODE) Mcl_Dma_Init( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) pConfig, Mcl_DmaInstanceType dma_instance)
{
    /* @brief Variable used for storing used priorities flags */
    VAR(uint16, AUTOMATIC) u16PriorityGrFlags[DMA_GROUPS];
    /* @brief Variable used for storing used channels flags */
    VAR(uint16, AUTOMATIC) u16ChannelGrFlags[DMA_GROUPS];
    /* @brief Variable used for storing current available priority */
    VAR(uint8, AUTOMATIC) u8CurrentPriority = 0U;
    /* @brief Variable used for storing the current channel number from within a DMA instance */
    VAR(uint8, AUTOMATIC) u8CurrentRelativeChannel = 0U;
    /* @brief Variable used for storing the current absolute channel number from all DMA instances */
    VAR(uint8, AUTOMATIC) u8CurrentAbsoluteChannel = 0U;
     /* @brief Variable used for storing the current group from the current DMA instances */
    VAR(uint8, AUTOMATIC) u8CurrentGroup = 0U;
    /* @brief Counter value used in loops */
    VAR(uint8, AUTOMATIC) u8Counter;
    /* @brief u8Reach value used in loops*/
    VAR(uint8, AUTOMATIC) u8Reach = 0U;
    /* @brief Pointer to DMA channel specific configuration */
    P2CONST(Mcl_DmaChannelConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaChannelConfig;
    
    for (u8Counter = 0U;u8Counter < DMA_GROUPS;u8Counter++)
    {
        u16PriorityGrFlags[u8Counter] = 0U;
        u16ChannelGrFlags[u8Counter] = 0U;
    }
    
     /* Enter exclusive area to protect DMA_CR and DMA_CPR */
     SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_12();
     /* Dma_Init() should enable minor loop mapping*/
     /** @violates @ref Mcl_DMA_c_REF_2 Cast from unsigned long to pointer. */
     /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
     REG_WRITE32(DMA_CR_ADDR32((uint32)(dma_instance)), (uint32)(*(pConfig->pDmaConfigInstance))[dma_instance].pDmaControl | DMA_MINOR_LOOP_MAPPING_EN_U32);   
    

    /* Initializing channels priorities, ECP and DPA */
    for (u8Counter = 0U; u8Counter < pConfig->NumChannels; u8Counter++)
    {
        
        pDmaChannelConfig = &((*(pConfig->pChannelsConfig))[u8Counter]);
        
        if (DMA_MOD_IDX_U8((uint32)pDmaChannelConfig->Dma_Channel) == dma_instance)
        {
            /* Update the DCHPRIn registers. */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            /** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
            REG_WRITE8(DMA_CPR((uint32)pDmaChannelConfig->Dma_Channel), pDmaChannelConfig->Dma_ChannelPriority); 
#ifdef MCL_DMA_ENABLE_INIT_DCHMID
#if (MCL_DMA_ENABLE_INIT_DCHMID == STD_ON)   
            /* Update the DCHMIDn registers. */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_WRITE8(DMA_DCHMID((uint32)pDmaChannelConfig->Dma_Channel), pDmaChannelConfig->Dma_MasterId);
#endif
#endif

#ifdef MCL_DMA_SETUP_EARS
#if (MCL_DMA_SETUP_EARS == STD_ON)   
            /* Update the EARS register. */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_RMW32(DMA_EARS((uint32)pDmaChannelConfig->Dma_Channel), ((1UL) << (uint32)pDmaChannelConfig->Dma_Channel), pDmaChannelConfig->Dma_AsynchronousRequest);
#endif
#endif
    
     
#if (MCL_DMA_NB_CONTROLLERS == 0x02U) 
            if (DMA_INSTANCE0 == dma_instance)
#endif            
            {
                u8CurrentRelativeChannel = pDmaChannelConfig->Dma_Channel;
            }
#if (MCL_DMA_NB_CONTROLLERS == 0x02U)          
            else  if (DMA_INSTANCE1 == dma_instance)
            {
                if (DMA_CHANNELS_PER_MODULE_U8 <= pDmaChannelConfig->Dma_Channel)
                {
                    u8CurrentRelativeChannel = (uint8)(pDmaChannelConfig->Dma_Channel - DMA_CHANNELS_PER_MODULE_U8 );
                }
                else
                {
                  /* Empty else to fix misra */
                }
            }
            else
            {
              /* Empty else to fix misra */
            }
#endif

#if ( MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON )
            /* Set Error Enable Interrupts register for the corresponding configured channel */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_WRITE8(DMA_SEEI_ADDR32((uint32)(dma_instance)), u8CurrentRelativeChannel);
#endif            
            /* calculate to which group u8CurrentRelativeChannel belongs */  
            u8CurrentGroup = (uint8)(u8CurrentRelativeChannel / MCL_EDMA_CHANNELS_IN_GROUP) ;
            /* Set the corresponding priority flags - keep only last 4 bits from Dma_ChannelPriority */
            u16PriorityGrFlags[u8CurrentGroup] |=  (uint16)((uint16)0x1U << (pDmaChannelConfig->Dma_ChannelPriority & ((uint16)((uint16)0x1U << DMA_CH_PRI_MASK_U8) - (uint16)0x1U)));
            /* Set the corresponding used channel flags */
            u16ChannelGrFlags[u8CurrentGroup] |=  (uint16)((uint32)0x1U << (u8CurrentRelativeChannel % MCL_EDMA_CHANNELS_IN_GROUP));
        }
        else
        {
          /* Empty else to fix misra */
        }
    }
    
    /* If dma channels corresponding to Dma instances are different, the ending value for loop is different*/
#ifdef MCL_DIFFERENT_CH_NUMBER_PER_INSTANCE
    if (DMA_INSTANCE0 == dma_instance)
    {
         u8Reach = MCL_DMA_NB_CHANNELS_OF_INSTANCE0;
    } 
    else if (DMA_INSTANCE1 == dma_instance)
    {
         u8Reach = MCL_DMA_NB_CHANNELS_OF_INSTANCE1;
    }
    else
    {
      /* Empty else to fix misra */
    }
#else
    u8Reach = DMA_CHANNELS_PER_MODULE_U8;
#endif

   /*  the following loop is used for computing the priorities for the channels which didn't have prio configured, 
    *  considering the already configured priorities and the fact that all priorities from within a group
    *  must be different, higher than 0, lower than 16 */
    for (u8Counter = 0U; u8Counter < u8Reach; u8Counter++)
    {
        if (DMA_INSTANCE0 == dma_instance)
        {
             u8CurrentAbsoluteChannel = u8Counter;

        }
#if (MCL_DMA_NB_CONTROLLERS == 0x02U)   
        else if (DMA_INSTANCE1 == dma_instance)
        {
             u8CurrentAbsoluteChannel = (uint8)(u8Counter + DMA_CHANNELS_PER_MODULE_U8);
        }
#endif
        else
        {
          /* Empty else to fix misra */
        }
        
        /* calculate to which group u8Counter belongs */ 
        u8CurrentGroup = (uint8)(u8Counter / MCL_EDMA_CHANNELS_IN_GROUP);
        
        /* if channel has no priority assigned */
        if((uint16)0x0U == (u16ChannelGrFlags[u8CurrentGroup] & (uint16)((uint32)0x1U << (u8Counter % MCL_EDMA_CHANNELS_IN_GROUP))))
        {
            u8CurrentPriority = 0U;
            /* Priority not configured for channel, compute corresponding priority */
            while(((uint16)0x0U != (u16PriorityGrFlags[u8CurrentGroup] & (uint16)((uint32)0x1U << u8CurrentPriority))) && (MCL_EDMA_CHANNELS_IN_GROUP >= u8CurrentPriority))
            {
                /* Priority flag is set, increase current priority */
                u8CurrentPriority++;
            }
            
            /* Set the flag for the corresponding found priority */            
            u16PriorityGrFlags[u8CurrentGroup] |= (uint16)((uint32)0x1U << u8CurrentPriority);
            /* Update the DCHPRIn register. */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            /** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
            REG_WRITE8(DMA_CPR((uint32)u8CurrentAbsoluteChannel), u8CurrentPriority); 
        }
        else
        {
          /* Empty else to fix misra */
        }
    }

    /* Exit exclusive area */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_12();    
    
}

#if (MCL_DEINIT_API == STD_ON)
/**
* @brief        Function that deinitializes the eDMA module.
* @details      This function deinitialized the underlaying hardware, sets default values to registers.
*
* @param[in]    pConfig - pointer to DMA configuration structure
*               dma_instance - number of the DMA instance to deinitialize
*
* @return void
*
*/
FUNC(void, MCL_CODE) Mcl_Dma_DeInit( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) pConfig, Mcl_DmaInstanceType dma_instance)
{
    /** Pointer to DMA channel specific configuration */
    P2CONST(Mcl_DmaChannelConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaChannelConfig;
    /** Variable used for storing the current channel number from a DMA instance */
    VAR(uint8, AUTOMATIC) u8CurrentRelativeChannel = 0U;
    /** Variable used for storing the current absolute channel number from all existing DMA instances */
    VAR(uint8, AUTOMATIC) u8CurrentAbsoluteChannel = 0U;
    /** Variable used for storing current available priority */
    VAR(uint8, AUTOMATIC) u8CurrentPriority = 0U;
    /** @brief Variable used for storing the current group from the current DMA instances */
    VAR(uint8, AUTOMATIC) u8CurrentGroup = 0U;
    /** @brief Variable used for storing the default value applied to the DCHPRI register */
    VAR(uint8, AUTOMATIC) u8ChPriRegDefaultVal = 0U;
    /** @brief Counter value used in loops */
    VAR(uint8, AUTOMATIC) u8logicalChannel = 0U;
    
    /** Enter exclusive area to protect DMA_CR and DMA_CPR */
     SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13();
    /** De-initialize DMA_CR */
    /** ERGA and ERCA are set to prepare for changing the channel priorities */
    /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_WRITE32(DMA_CR_ADDR32((uint32)(dma_instance)), (uint32)(DMA_CR_DEFAULT_VAL_U32|DMA_CR_ERCA_U32|DMA_CR_ERGA_U32));
    /** De-initialize channel registers EEI and DCHMID */
    /** Loop through all MCL logical channels configured */
    for (u8logicalChannel = 0U; u8logicalChannel < pConfig->NumChannels; u8logicalChannel++)
    {
        pDmaChannelConfig = &((*(pConfig->pChannelsConfig))[u8logicalChannel]);   
        /** set absolute channel */
        u8CurrentAbsoluteChannel = pDmaChannelConfig->Dma_Channel;
        /** if channel corresponds to current dma_instance */
        if (DMA_MOD_IDX_U8((uint32)u8CurrentAbsoluteChannel) == dma_instance)
        {
            /** set relative channel */
            u8CurrentRelativeChannel = u8CurrentAbsoluteChannel;
            #if (MCL_DMA_NB_CONTROLLERS == 0x02U)   
            /** Calculate the relative DMA channel number within a DMA instance */      
            if (DMA_CHANNELS_PER_MODULE_U8 <= u8CurrentAbsoluteChannel)
            {
                u8CurrentRelativeChannel = (uint8)(u8CurrentAbsoluteChannel - DMA_CHANNELS_PER_MODULE_U8 );
            }
            #endif 
            /** Clear Enable Request Register for the corresponding configured channel */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_WRITE8(DMA_CERQ_ADDR32((uint32)(dma_instance)), u8CurrentRelativeChannel);
            #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
            /** Clear EEI register bit for the corresponding configured channel by using CEEI for atomic operation */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_WRITE8(DMA_CEEI_ADDR32((uint32)(dma_instance)), u8CurrentRelativeChannel);
            #endif    
            #ifdef MCL_DMA_ENABLE_INIT_DCHMID
            #if (MCL_DMA_ENABLE_INIT_DCHMID == STD_ON)        
            /** De-initialize the DCHMID register */
            /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_WRITE8(DMA_DCHMID((uint32)u8CurrentAbsoluteChannel), DMA_EMI_DIS_U8);
            #endif
            #endif
        }
    }
    /** De-initialize DCHPRI registers, set default priorities, default TCD for all channels of the current Dma instance */
    /** Loop through all MCL DMA hardware channels from the current Dma instance */
    for (u8CurrentRelativeChannel = 0U; u8CurrentRelativeChannel < MCL_DMA_NB_CHANNELS; u8CurrentRelativeChannel++)
    {
        u8CurrentPriority = (uint8)(u8CurrentRelativeChannel % MCL_EDMA_CHANNELS_IN_GROUP) ;
        /** Calculate to which group u8CurrentRelativeChannel belongs */ 
        u8CurrentGroup = (uint8)(u8CurrentRelativeChannel / MCL_EDMA_CHANNELS_IN_GROUP);
        /** Calculate the default value for the DCHPRI register */
        u8ChPriRegDefaultVal = (uint8)(u8CurrentGroup << DMA_DCHPRI_GRPPRI_SHIFT_LEFT_U8) | u8CurrentPriority ;
        /** initialize absolute number of the channel */
        u8CurrentAbsoluteChannel = u8CurrentRelativeChannel;
        /** calculate absolute number of the channel */
        #if (MCL_DMA_NB_CONTROLLERS == 0x02U)   
        /** Calculate the relative DMA channel number within a DMA instance */      
        if (DMA_INSTANCE1 == dma_instance)
        {
            u8CurrentAbsoluteChannel = (uint8)(u8CurrentRelativeChannel + DMA_CHANNELS_PER_MODULE_U8 );
        }
        #endif 
        /** De-initialize the DCHPRI register, write the priority corresponding to the channel number */
        /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        /** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
        REG_WRITE8(DMA_CPR((uint32)u8CurrentAbsoluteChannel), u8ChPriRegDefaultVal); 
        /** De-initialize the TCD number 8 to reset the value of biter, channel control/status fields in TCD register */
        /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        REG_WRITE32(DMA_TCD_CHANNEL(u8CurrentAbsoluteChannel,DMA_TCD_8TH_WORD_OFFSET_U32), DMA_TCD_8TH_DEFAULT_VAL_U32);
        /** De-initialize the TCD number 6 to reset the value of citer, doff fields in TCD register */
        /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        REG_WRITE32(DMA_TCD_CHANNEL(u8CurrentAbsoluteChannel,DMA_TCD_6TH_WORD_OFFSET_U32), DMA_TCD_6TH_DEFAULT_VAL_U32);
    }
    /** De-initialize DMA_CR: set ERGA and ERCA to 0 */
    /** @violates @ref Mcl_DMA_c_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_WRITE32(DMA_CR_ADDR32((uint32)(dma_instance)), DMA_CR_DEFAULT_VAL_U32);  
    /** Exit exclusive area */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13();    
}
#endif
/*================================================================================================*/
/**
* @brief        Basic configuration of a TCD.
* @details      This function configures the basic fields of a TCD.
*               You can use it in a scatter/gather operations, where you need to configure a TCD, but not one loaded into a channel.
*
* @param[in]      pTcdAddress        - pointer to the address of the TCD.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
*
* @return void
*
*/
FUNC(void, MCL_CODE) Mcl_Dma_ConfigTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor)
{
    VAR(uint32, AUTOMATIC) u32Reg_value;
  
    /* Set saddr */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_1ST_WORD_OFFSET_U32, (uint32)(config_descriptor->u32saddr));      
    
    u32Reg_value = (config_descriptor->u32smod<<DMA_SMOD_SHIFT_MASK_U32) | 
                   (config_descriptor->u32ssize<<DMA_SSIZE_SHIFT_MASK_U32) | 
                   (config_descriptor->u32dmod<<DMA_DMOD_SHIFT_MASK_U32) | 
                   (config_descriptor->u32dsize<<DMA_DSIZE_SHIFT_MASK_U32) | 
                   (config_descriptor->u32soff);
    /* Enter exclusive area to protect words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15();
    
    /* Set smod, ssize, dmod, dsize, soff */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_2ND_WORD_OFFSET_U32, (uint32)u32Reg_value);                   
    /* Set nbytes */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_3RD_WORD_OFFSET_U32, (uint32)(config_descriptor->u32num_bytes));  
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */    
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_4TH_WORD_OFFSET_U32, (uint32)(0x0U));   
    /* Set daddr */   
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_5TH_WORD_OFFSET_U32, (uint32)(config_descriptor->u32daddr));       
    
    u32Reg_value = (config_descriptor->u32iter<<DMA_ITER_SHIFT_MASK_U32) | config_descriptor->u32doff;
    /* Set citer and doff */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_6TH_WORD_OFFSET_U32, u32Reg_value);                   
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_7TH_WORD_OFFSET_U32, (uint32)(0x0U));  
    
    u32Reg_value = (uint32)0x0U | (config_descriptor->u32iter<<DMA_ITER_SHIFT_MASK_U32);
    /* Set biter */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_8TH_WORD_OFFSET_U32, u32Reg_value);   
    
    /* Exit exclusive area to protect words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15();    

}


/*================================================================================================*/
/**
* @brief        Basic DMA channel configuration.
* @details      This function configures the basic TCD fields of a channel.
*
* @param[in]      dma_channel        - the number of the channel that will be configured.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
*
* @return void
* 
*/
FUNC(void, MCL_CODE) Mcl_Dma_ConfigChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                        P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor)
{
    /* Call ConfigTcd with the corresponding channel's TCD address */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    Mcl_Dma_ConfigTcd((Mcl_DmaTcdType*)DMA_TCD((uint32)(dma_channel)), config_descriptor);
   
}


/*================================================================================================*/
/**
* @brief        Function that configures a channel for linking with another channel.
* @details      This function configures a channel with channel-linking functionality.
*
* @param[in]      dma_channel        - the number of the channel that will be configured.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
* @param[in]      next_channel       - is the channel that will be linked.           
*
* @return void
*
*/ 
FUNC(void, MCL_CODE) Mcl_Dma_ConfigLinkedChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                              P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                              VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel)  
{
    /* Config TCD according to config_descriptor */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */  
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */    
    Mcl_Dma_ConfigTcd((Mcl_DmaTcdType*)DMA_TCD((uint32)(dma_channel)), config_descriptor);
    
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_31();
    
    /* set major_linkch */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_WRITE8(DMA_TCD((uint32)(dma_channel)) + DMA_TCD_8TH_WORD_OFFSET_U32 + DMA_TCD_CSR_OFFSET_U32, (uint8)next_channel);  
    
    /** @brief  set the TCD.major_elink bit. */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_SET_MAJOR_ELINK((uint32)dma_channel);
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_31();
}



/*================================================================================================*/
/**
* @brief        Function that sets up a channel with scatter/gather functionality.
* @details      This function configures a channel with scatter/gather functionality.
*
* @param[in]      dma_channel        - the number of the channel that will be configured.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
* @param[in]      pNext_tcd          - pointer to the address of the next TCD that will be loaded into the channel.
*
* @return void
* 
*/
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                                     P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                     P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd)
{   
    /* Config TCD according to config_descriptor */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    Mcl_Dma_ConfigTcd((Mcl_DmaTcdType*)DMA_TCD((uint32)(dma_channel)), config_descriptor);
    
    /* Set Scatter Gather Address with the address of the next TCD */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)(DMA_TCD((uint32)(dma_channel))) + DMA_TCD_7TH_WORD_OFFSET_U32, (uint32)(pNext_tcd));
    
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_30();
    
    /** @brief set the e_sg bit */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_SET_E_SG((uint32)dma_channel);    
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_30();
}




/*================================================================================================*/
/**
* @brief        Function that configures a TCD with channel-linking functionality.
* @details      This function configures a TCD with channel-linking functionality.
*
* @param[in]      pTcdAddress        - pointer to the address of the TCD.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
* @param[in]      next_channel       - is the channel that will be linked.
*
* @return void 
*         
*/ 
FUNC(void, MCL_CODE) Mcl_Dma_ConfigLinkedTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                          P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                          VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel)  
{

    /* Config TCD according to config_descriptor */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    Mcl_Dma_ConfigTcd(pTcdAddress, config_descriptor);
    
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_26();
    /* set major_linkch */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: The cast is needed to access only the major link part of the word without accessing the flags. */
    REG_WRITE8((uint32)((uint32)pTcdAddress + DMA_TCD_8TH_WORD_OFFSET_U32 + DMA_TCD_CSR_OFFSET_U32), (uint8)next_channel);  
    
    /** @brief  set the TCD.major_elink bit. */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: The cast is needed to access only the major link part of the word without accessing the flags. */
    REG_BIT_SET32((uint32)pTcdAddress + DMA_TCD_8TH_WORD_OFFSET_U32, (uint32)DMA_TCD_MAJOR_E_LINK_MASK_U32);   
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_26();
}



/*================================================================================================*/
/**
* @brief        Function that configures a TCD with scatter/gather functionality.
* @details      This function configures a TCD with scatter/gather functionality.
*
* @param[in]      pTcdAddress        - pointer to the address of the TCD.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
* @param[in]      pNext_tcd          - pointer to the address of the next TCD that will be loaded into the channel.
*
* @return void
*
*/
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                 P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                 P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd)
{   

    /* Config TCD according to config_descriptor */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    Mcl_Dma_ConfigTcd(pTcdAddress, config_descriptor);
    
    /* Set Scatter Gather Address with the address of the next TCD */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_7TH_WORD_OFFSET_U32, (uint32)(pNext_tcd));
 
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_27();
    
    /* Set Enable Scatter/Gather Processing */ 
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_BIT_SET32((uint32)pTcdAddress + DMA_TCD_8TH_WORD_OFFSET_U32, (uint32)DMA_TCD_E_SG_MASK_U32);
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_27();
}

/*================================================================================================*/
/**
* @brief        Function that configures a channel for scatter gather and linking with another channel.
* @details      This function configures a channel for scatter gather  with channel-linking functionality.
*
* @param[in]      dma_channel        - the number of the channel that will be configured.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
* @param[in]      next_channel       - is the channel that will be linked.           
*
* @return void
*
*/ 
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherLinkedChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                                           P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                           P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                           VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel)
{

    /* Configure linked channel */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    Mcl_Dma_ConfigLinkedChannel(dma_channel, config_descriptor, next_channel);
    
    /* Set Scatter Gather Address with the address of the next TCD */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
 /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)(DMA_TCD(dma_channel)) + DMA_TCD_7TH_WORD_OFFSET_U32, (uint32)(pNext_tcd));
    
    /** @brief  set the TCD.esg bit. */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_SET_E_SG((uint32)dma_channel);
    
}

/*================================================================================================*/
/**
* @brief        Function that configures a TCD for scatter gather and linking with another channel.
* @details      This function configures a TCD for scatter gather  with channel-linking functionality.
*
 * @param[in]     pTcdAddress        - Tcd address used for configuring SGA with linking.
* @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
*                                      of a  Transfer Control Descriptor (TCD).
* @param[in]      pNext_tcd            - Pointer to the TCD address used for scatter gather
* @param[in]      next_channel       - is the channel that will be linked.           
*
* @return void
*
*/ 
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherLinkedTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                       P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                       P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                       VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel)
{
    /* Configure linked channel */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    Mcl_Dma_ConfigLinkedTcd(pTcdAddress, config_descriptor, next_channel);
    
    /* Set Scatter Gather Address with the address of the next TCD */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_WRITE32((uint32)pTcdAddress + DMA_TCD_7TH_WORD_OFFSET_U32, (uint32)(pNext_tcd));
    
    /* Set Enable Scatter/Gather Processing */ 
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    REG_BIT_SET32((uint32)pTcdAddress + DMA_TCD_8TH_WORD_OFFSET_U32, (uint32)DMA_TCD_E_SG_MASK_U32);
}

/*================================================================================================*/
/**
* @brief        Function that sets the priority for the DMA channel passed as parameter.
* @details      This function sets the priority for the DMA channel passed as parameter.
*
* @param[in]      nChannel    - the channel number for which the priority is changed.
* @param[in]      nPriority   -  the priority that is assigned to the specified channel.
*
* @return void
*
*/
FUNC(void, MCL_CODE) Mcl_Dma_SetChannelPriority( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel, 
                                             VAR(Mcl_DmaPriorityType, AUTOMATIC) nPriority)
{
    VAR(uint32, AUTOMATIC) u32ChArbitration = 0UL;

    /* Enter exclusive area to protect DMA_CR and DMA_CPR */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14();
    
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    u32ChArbitration = REG_READ32(DMA_CR_ADDR32((uint32)(DMA_MOD_IDX_U8((uint32)nChannel))));
    
    /* Switch to Round Robin channel arbitration*/
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_RMW32(DMA_CR_ADDR32((uint32)DMA_MOD_IDX_U8((uint32)nChannel)), DMA_CR_ERCA_U32, DMA_CR_ERCA_U32);
    
    /* Set DMA_CPR with the priority specified by nPriority to channel nChannel*/
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
/** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
    REG_RMW8(DMA_CPR((uint32)(nChannel)), DMA_PRIORITY_MASK_U8, nPriority);
    
    /* Switch back to initial channel arbitration */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_RMW32(DMA_CR_ADDR32((uint32)DMA_MOD_IDX_U8((uint32)nChannel)), DMA_CR_ERCA_U32, (uint32)(u32ChArbitration & DMA_CR_ERCA_U32));
    
    /* Exit exclusive area to protect DMA_CR and DMA_CPR */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14();
}


/*================================================================================================*/
/**
* @brief        Function that starts a transfer on a DMA channel.
* @details      This function starts a transfer on a DMA channel.
*
* @param[in]      nChannel    - the DMA channel to be started.
*
* @return void
*
*/
FUNC(void, MCL_CODE) Mcl_Dma_StartChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel)
{

    
    #ifdef MCAL_CACHE_RUNTIME_MNGMNT
    #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)
    #if (STD_ON == MCL_SYNCRONIZE_CACHE) 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    /* Flush DCACHE to synchronize data */
    retVal = Mcl_IPW_CacheFlush(MCL_LMEM_CACHE_ALL);
    if ((Std_ReturnType)E_NOT_OK == retVal)
    {   /* memory synchronization failed, notify user */
        #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
        /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        Mcl_IPW_ErrorNotification(DMA_MOD_IDX_U8((uint32)nChannel) , MCL_DMA_MEM_SYNC_ERROR);
        #endif
    }
    else
    {
        /* cache memory sync successful */
    }
    #endif
    #endif
    #endif
    /* Start the DMA channel nChannel*/
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_WRITE8(DMA_SSRT_ADDR32((uint32)DMA_MOD_IDX_U8((uint32)nChannel)), (nChannel & DMA_CTRL_MAX_CHANNELS_MASK_U8));

}


/*================================================================================================*/
/**
* @brief        Function that indicates if a DMA channel transfer is completed.
* @details      This function indicates if a DMA channel transfer is completed.
*
* @param[in]      nChannel    - the DMA channel to be checked for transfer completed.
* @param[out]     bCompleted  - the status of the DMA transfer.
*
* @return boolean
*
*/
FUNC(boolean, MCL_CODE) Mcl_Dma_IsTransferCompleted( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel)
{
    VAR(boolean, AUTOMATIC) bCompleted = (boolean)FALSE;
    #ifdef MCAL_CACHE_RUNTIME_MNGMNT
    #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)
    #if (STD_ON == MCL_SYNCRONIZE_CACHE) 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    #endif
    #endif
    #endif
        

    /* Check DONE bit from DMA_TCD_CSR */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
/** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
    if(0UL != REG_BIT_GET32(DMA_TCD_CHANNEL(nChannel, (uint32)DMA_TCD_8TH_WORD_OFFSET_U32), DMA_TCD_DONE_U32)) 
    {
        /* Transfer is completed */
        bCompleted = (boolean)TRUE;
        
        #ifdef MCAL_CACHE_RUNTIME_MNGMNT
        #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)
        #if (STD_ON == MCL_SYNCRONIZE_CACHE) 
        /* invalidate DCACHE to synchronize data */
        retVal = Mcl_IPW_CacheClear(MCL_LMEM_CACHE_ALL);
        if ((Std_ReturnType)E_NOT_OK == retVal)
        {   /* memory synchronization failed, notify user */
            #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
            /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            Mcl_IPW_ErrorNotification(DMA_MOD_IDX_U8((uint32)nChannel) , MCL_DMA_MEM_SYNC_ERROR);
            #endif
        }
        else
        {
            /* cache memory sync successful */
        }
        #endif
        #endif
        #endif
    }
    else
    {
        /* Transfer is not completed */
        bCompleted = (boolean)FALSE;
    }
    /* Return the transfer status */
    return (bCompleted);

}


/*================================================================================================*/
/**
* @brief        Function that indicates if DMA transfer is in execution.
* @details      This function indicates if DMA transfer corresponding to the DMA channel 
*               passed as parameter is in execution.
*
* @param[in]      nChannel    - the DMA channel to be checked for transfer in execution.
* @param[out]     bCompleted  - the status of the DMA transfer.
*
* @return boolean
*
*/
FUNC(boolean, MCL_CODE) Mcl_Dma_IsTransferActive( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel)
{
    VAR(boolean, AUTOMATIC) bActive = (boolean)FALSE;
    
    /* Check ACTIVE bit from DMA_TCD_CSR */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
/** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
    if(0UL != REG_BIT_GET32(DMA_TCD_CHANNEL(nChannel, (uint32)DMA_TCD_8TH_WORD_OFFSET_U32), DMA_TCD_ACTIVE_U32)) 
    {
        /* Transfer is active */
        bActive = (boolean)TRUE;
    }
    else
    {
        /* Transfer is not active */
        bActive = (boolean)FALSE;
    }
    /* Return the transfer status */
    return (bActive);
}


#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/*===============================================================================================*/
/**
* @brief        This function enables the user notifications
* @details      This function
*               - clears Dma interrupt flags
*               - enables selected interrupts
*
* @param[in]    Dma hardware channel number
*
* @param[in]    Notification            notification type to be enabled
*
* @return       void
*
*
*/
FUNC (void, MCL_CODE) Mcl_Dma_EnableNotification( VAR(Mcl_DmaChannelType,AUTOMATIC) nChannel,
                                              VAR(Mcl_DmaTransferNotifType,AUTOMATIC) Notification)
{  
    /* Clear Dma interrupt request for the corresponging channel */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_CLEAR_INT_REQ(nChannel);
    
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_29();
    
    if(MCL_DMA_TRANSFER_COMPLETE == Notification)
    {
        /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        DMA_SET_INT_MAJ((uint32)nChannel);
    }
    else if (MCL_DMA_TRANSFER_HALF_COMPLETE == Notification)
    {
        /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        DMA_SET_INT_HALF((uint32)nChannel);
    }
    else
    {
        /*Empty else to fix misra*/
    }

    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_29();
}

/*===============================================================================================*/
/**
* @brief        This function disables the user notifications
* @details      This function
*               - clears Dma interrupt flags
*               - disables selected interrupts
*
* @param[in]    Dma hardware channel number
*
* @return       void
*
*
*/
FUNC (void, MCL_CODE) Mcl_Dma_DisableNotification( VAR(Mcl_DmaChannelType,AUTOMATIC) nChannel)
{
    /* Clear Dma interrupt request for the corresponging channel */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_CLEAR_INT_REQ(nChannel);
    
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_28();
    
    /* Clear the transfer completion inetrrupt flag */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    if((boolean)TRUE == DMA_TCD_GET_INT_MAJ(nChannel))
    {
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        DMA_CLR_INT_MAJ((uint32)nChannel);
    }
    
    /* Clear the half transfer completion interrupt flag */
    /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    if((boolean)TRUE == DMA_TCD_GET_INT_HALF(nChannel))
    {
        /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        DMA_CLR_INT_HALF((uint32)nChannel);
    }
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_28();
}
#endif /* MCL_DMA_NOTIFICATION_SUPPORTED */ 

/*================================================================================================*/
/**
* @brief        Function that indicates if an interrupt request was set.
* @details      This function indicates if an interrupt request was set 
*               for the corresponding channel.
*
* @param[in]      nChannel    - the DMA channel to be checked for interrupt request.
*
* @return boolean
*
*/
FUNC (boolean, MCL_CODE) Mcl_Dma_GetMultiRegChInfo(VAR(Mcl_DmaChannelType,AUTOMATIC) nChannel, VAR(Mcl_DmaRequestType,AUTOMATIC) request)
{
    VAR(boolean, AUTOMATIC) bChBitSet = (boolean)FALSE;
    VAR(uint8, AUTOMATIC) u8relativeChannelInDmaInstance = (uint8)(nChannel % DMA_CHANNELS_PER_MODULE_U8) ;
    VAR(uint8, AUTOMATIC) u8lastChannelInIntLowRegister = (uint8)(DMA_CHANNELS_PER_MODULE_U8);
    VAR(uint32, AUTOMATIC) u32multiRegisterValue = (uint32)0;
    
#if (MCL_DMA_NB_CHANNELS == 0x40UL)
    u8lastChannelInIntLowRegister = (uint8)(DMA_CHANNELS_PER_MODULE_U8 / 2U);
#endif
    if ((MCL_DMA_GET_INT == request) || (MCL_DMA_GET_ERR == request))
    {
        if((u8lastChannelInIntLowRegister) > (u8relativeChannelInDmaInstance)) 
        {
            /* find register*/
            if (MCL_DMA_GET_INT == request)
            {
                /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                u32multiRegisterValue = REG_READ32(DMA_INTL_ADDR32(DMA_MOD_IDX_U8((uint32)nChannel))) ;
                
            }else /* (MCL_DMA_GET_ERR == request) */
            {
                /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                u32multiRegisterValue = REG_READ32(DMA_EERL_ADDR32(DMA_MOD_IDX_U8((uint32)nChannel))) ;
            }
           
            /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
/** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
            if (0UL != (u32multiRegisterValue & (uint32)((uint32)1u << u8relativeChannelInDmaInstance)))
            {
                /* Interrupt request is set. */
                bChBitSet = (boolean)TRUE;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            if (MCL_DMA_GET_INT == request)
            {
                /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                u32multiRegisterValue = REG_READ32(DMA_INTH_ADDR32(DMA_MOD_IDX_U8((uint32)nChannel))) ;
                
            }else /*(MCL_DMA_GET_ERR == request)*/
            {
                /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                u32multiRegisterValue = REG_READ32(DMA_EERH_ADDR32(DMA_MOD_IDX_U8((uint32)nChannel))) ;
            }
           
            /** @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
/** @violates @ref Mcl_DMA_c_REF_11 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicity to different underlying*/
            if (0UL != (u32multiRegisterValue & (uint32)((uint32)1U << (u8relativeChannelInDmaInstance % (DMA_CHANNELS_PER_MODULE_U8 / 2U)))))
            {
                /* Interrupt request is set. */
                bChBitSet = (boolean)TRUE;
            }
            else
            {
                /* do nothing */
            }
        }
    }
    /* Return the interrupt request status */
    return (bChBitSet);
}
#if (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON)
/*================================================================================================*/
/**
* @brief        Function reports error status in the DMA_ES and DMA_ERR registers.
* @details      Function reports error status in the DMA_ES and DMA_ERR registers 
*               for the corresponding dma instance.
*
* @param[in]      nChannel    - the DMA channel to be checked for interrupt request.
*
* @return boolean
*
*/
FUNC (void, MCL_CODE) Mcl_Dma_GetGlobalErrorStatus
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) dmaInstance,
    P2VAR(Mcl_DmaGlobalErrorStatusType, AUTOMATIC, MCL_APPL_DATA) dmaGlobalErrorStatus
)
{
    VAR(uint32,AUTOMATIC) u32GlobalErrorStatus   = (uint32)MCL_DMA_NO_ERROR;
    VAR(uint32,AUTOMATIC) u32ErrChannel          = (uint32)MCL_DMA_NO_CHANNEL_U16;
    
    /* get global error status from DMA_ES register */
    /* @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    u32GlobalErrorStatus = REG_READ32(DMA_ES_ADDR32((uint32)(dmaInstance)));

    /* get erroneous channel specified by DMA_ES register*/
    u32ErrChannel = (u32GlobalErrorStatus & DMA_ES_ERRCHN_U32) >> DMA_ES_ERRCHN_SHIFT_RIGTH_U8;
    /* if there are 2 controllers, then the absolute hardware channel must be computed */
#if (MCL_DMA_NB_CONTROLLERS == 0x02U)     
    if (DMA_INSTANCE1 == dmaInstance)
    {
        u32ErrChannel = u32ErrChannel + DMA_CHANNELS_PER_MODULE_U8;
    }
#else 
    (void)dmaInstance;
#endif    
    /* get error information about channel u32ErrChannel from DMA_ERR register */
    dmaGlobalErrorStatus->errorId = Mcl_Dma_GetChannelErrorStatus((Mcl_DmaChannelType)u32ErrChannel);
    
    /* set erroneous channel */
    if ((MCL_DMA_NO_ERROR == dmaGlobalErrorStatus->errorId) || (MCL_DMA_HW_INCONSISTENCY_ERROR == dmaGlobalErrorStatus->errorId))
    {
        dmaGlobalErrorStatus->erroneousChannel = MCL_DMA_NO_CHANNEL_U16;
        
    }else 
    {
        dmaGlobalErrorStatus->erroneousChannel = (Mcl_DmaErroneousChannelType)u32ErrChannel;
    }
}
#endif

#if ((MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON) || (MCL_DMA_GET_CH_ERR_STATUS_API == STD_ON))
/*================================================================================================*/
/**
* @brief        Function reports the error status from the DMA_ES and DMA_ERR registers.
* @details      Function reports error status in the DMA_ES and DMA_ERR registers 
*               for the corresponding channel.
*
* @param[in]      hwChannel    the DMA hardware channel to be checked for report the status.
*                
* @return Mcl_DmaChannelErrorStatusType
*/
/** @violates @ref Mcl_DMA_c_REF_9 MISRA 2004 Required Rule 8.10, could be made static */
FUNC(Mcl_DmaChannelErrorStatusType, MCL_CODE) Mcl_Dma_GetChannelErrorStatus
(
    VAR(Mcl_DmaChannelType,AUTOMATIC) hwChannel
)
{
    VAR(uint32,AUTOMATIC) u32GlobalErrorStatus               = (uint32)MCL_DMA_NO_ERROR;
    VAR(uint32,AUTOMATIC) u32ErrChannel                      = (uint32)MCL_DMA_NO_CHANNEL_U16;
    VAR(uint8,AUTOMATIC) u8ChannelErrorStatus                = (uint8)MCL_DMA_NO_ERROR;
    VAR(Mcl_DmaChannelErrorStatusType,AUTOMATIC) errorStatus =  MCL_DMA_NO_ERROR;
    
    /* get global error status from DMA_ES register */
    /* @violates @ref Mcl_DMA_c_REF_2 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_DMA_c_REF_10 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    u32GlobalErrorStatus = REG_READ32(DMA_ES_ADDR32((uint32)(DMA_MOD_IDX_U8(hwChannel))));
    /* get channel error status from DMA_ERR register */
    u8ChannelErrorStatus = (uint8)Mcl_Dma_GetMultiRegChInfo(hwChannel, MCL_DMA_GET_ERR);  
    /* gat erroneous channel specified by DMA_ES register*/
    u32ErrChannel = (u32GlobalErrorStatus & DMA_ES_ERRCHN_U32) >> DMA_ES_ERRCHN_SHIFT_RIGTH_U8;
    /* if there are 2 controllers, then the absolute hardware channel must be computed */
#if (MCL_DMA_NB_CONTROLLERS == 0x02U)      
    if (DMA_INSTANCE1 == DMA_MOD_IDX_U8(hwChannel))
    {
        u32ErrChannel = u32ErrChannel + DMA_CHANNELS_PER_MODULE_U8;
    }
#endif
    /* report errorstatus */
    if(((((uint32)MCL_DMA_NO_ERROR != u32GlobalErrorStatus) && ((uint32)hwChannel == u32ErrChannel)) && ((uint8)MCL_DMA_NO_ERROR == u8ChannelErrorStatus))||
        ((((uint32)MCL_DMA_NO_ERROR != u32GlobalErrorStatus)&& ((uint32)hwChannel != u32ErrChannel)) && ((uint8)MCL_DMA_NO_ERROR != u8ChannelErrorStatus))||
        (((uint32)MCL_DMA_NO_ERROR == u32GlobalErrorStatus) && ((uint8)MCL_DMA_NO_ERROR != u8ChannelErrorStatus))
        )
    {
        errorStatus = MCL_DMA_HW_INCONSISTENCY_ERROR;
    }
    else if ((uint8)MCL_DMA_NO_ERROR == u8ChannelErrorStatus)
    {
         errorStatus = MCL_DMA_NO_ERROR;
    }
#if (MCL_DMA_ECC_REPORTING_ENABLED == STD_ON)
    else if ((uint32)0U != (u32GlobalErrorStatus & DMA_ES_UCE_U32))
    {
        errorStatus = MCL_DMA_ECC_ERROR;
    }
#endif
    else if ((uint32)0U != (u32GlobalErrorStatus & DMA_ES_BUS_U32))
    {
        errorStatus = MCL_DMA_BUS_ERROR;
    }
    else if ((uint32)0U != (u32GlobalErrorStatus & DMA_ES_DESCRIPTOR_U32))
    {
        errorStatus = MCL_DMA_DESCRIPTOR_ERROR;
    }
    else if ((uint32)0U != (u32GlobalErrorStatus & (DMA_ES_GPE_U32 | DMA_ES_CPE_U32)))
    {
        errorStatus = MCL_DMA_PRIORITY_ERROR;
    }
    else
    {
        errorStatus = MCL_DMA_UNRECOGNIZED_ERROR;
    }
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Dem reporting section */
    if(((((uint32)MCL_DMA_NO_ERROR != u32GlobalErrorStatus) && ((uint32)hwChannel == u32ErrChannel)) && ((uint8)MCL_DMA_NO_ERROR == u8ChannelErrorStatus))||
        ((((uint32)MCL_DMA_NO_ERROR != u32GlobalErrorStatus)&& ((uint32)hwChannel != u32ErrChannel)) && ((uint8)MCL_DMA_NO_ERROR != u8ChannelErrorStatus))||
        (((uint32)MCL_DMA_NO_ERROR == u32GlobalErrorStatus) && ((uint8)MCL_DMA_NO_ERROR != u8ChannelErrorStatus))
        )
    {
        /* registers DMA_ES and DMA_ERR report inconsistent information
         * (DMA_ES reports error for channel hwChannel and DMA_ERR reports no error for hwChannel) or
         * (DMA_ES reports error for another channel and DMA_ERR reports error for hwChannel) or
         * (DMA_ES reports reports no error and DMA_ERR reports error for hwChannel)
         */
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Inconsistency.state)
        {
                                   Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Inconsistency.id, DEM_EVENT_STATUS_FAILED);
                    }
    }
    else if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Inconsistency.state)
    {
                                   Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Inconsistency.id, DEM_EVENT_STATUS_PASSED);
                }
    else
    {
    /*do nothing*/
    }

#if (MCL_DMA_ECC_REPORTING_ENABLED == STD_ON)  
    if((uint32)0U != (u32GlobalErrorStatus & DMA_ES_UCE_U32))
    {
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Ecc.state)
        {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Ecc.id, DEM_EVENT_STATUS_FAILED);
                    }
    }
    else if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Ecc.state)
    {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Ecc.id, DEM_EVENT_STATUS_PASSED);
                }
    else
    {
    /*do nothing*/
    }
#endif
    if ((uint32)0U != (u32GlobalErrorStatus & DMA_ES_BUS_U32))
    {
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Bus.state)
        {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Bus.id, DEM_EVENT_STATUS_FAILED);
                    }
    }
    else if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Bus.state)
    {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Bus.id, DEM_EVENT_STATUS_PASSED);
                }
    else
    {
    /*do nothing*/
    }
    if ((uint32)0U != (u32GlobalErrorStatus & DMA_ES_DESCRIPTOR_U32)) 
    {
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Descriptor.state)
        {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Descriptor.id, DEM_EVENT_STATUS_FAILED);
                    }
    }
    else if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Descriptor.state)
    {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Descriptor.id, DEM_EVENT_STATUS_PASSED);
                }
    else
    {
    /*do nothing*/
    }
    if ((uint32)0U != (u32GlobalErrorStatus & (DMA_ES_GPE_U32 | DMA_ES_CPE_U32)))
    {
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Priority.state)
        {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Priority.id, DEM_EVENT_STATUS_FAILED);
                    }
    }            
    else if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Priority.state)
    {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Priority.id, DEM_EVENT_STATUS_PASSED);
                }
    else
    {
    /*do nothing*/
    }

    if (errorStatus == MCL_DMA_UNRECOGNIZED_ERROR)
    {
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Unrecognized.state)
        {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Unrecognized.id, DEM_EVENT_STATUS_FAILED);
                    }
    }
    else if (errorStatus == MCL_DMA_NO_ERROR)
    {
        if((uint32)STD_ON == Mcl_pDemCfgPtr->Mcl_E_Dma_Unrecognized.state)
        {
                                    Dem_ReportErrorStatus((Dem_EventIdType)Mcl_pDemCfgPtr->Mcl_E_Dma_Unrecognized.id, DEM_EVENT_STATUS_PASSED);
                    }
    }
    else
    {
    /*do nothing*/
    }
#endif
    return errorStatus;
}
#endif
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_DMA_c_REF_4 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of a header file
*        being included twice
*
* @violates @ref Mcl_DMA_c_REF_7 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*
*/
#include "Mcl_MemMap.h"

#endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */
