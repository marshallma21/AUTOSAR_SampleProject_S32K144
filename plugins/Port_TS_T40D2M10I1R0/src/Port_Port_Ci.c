/**
*   @file    Port_Port_Ci.c
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - PORT Low level driver implementation.
*   @details Implementation of the PORT low level driver.
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

/**
*   @page misra_violations MISRA-C:2004 violations
*   
*   @section Port_Port_Ci_C_REF_1
*   Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'. 
*   MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*   
*   @section Port_Port_Ci_C_REF_3
*   Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*   This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*   
*   @section Port_Port_Ci_C_REF_4
*   Violates MISRA 2004 Required Rule 1.4, Identifier clash. 
*   The used compilers/linkers allow more than 31 characters significance for external identifiers.
*   
*   @section Port_Port_Ci_C_REF_5
*   Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*   This macro compute the address of any register by using the hardware offset of the controller. The address calculated as an unsigned int
*   is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*   
*   @section Port_Port_Ci_C_REF_7
*   Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used.
*   This violation is due to the use of pointer arithmetic, to access the channel parameters,
*   the indexing of the pointer is taken care and hence the unintended memory location will not
*   be accessed.
*   
*   @section Port_Port_Ci_C_REF_10
*   Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
*   an integral type. The cast is used to access memory mapped registers.
*   
*   @section [global]
*   Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
*   on the significance of more than 31 characters. The used compilers use more than 31 chars
*   for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "modules.h"
#include "Port.h"
#include "Port_Reg_eSys_Port_Ci.h"
#include "Port_Port_Ci.h"
#include "Reg_eSys_Gpio.h"
#include "SchM_Port.h"

#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED (PORT_USER_MODE_SOFT_LOCKING)
#endif
#include "SilRegMacros.h"

/*=================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @brief Module ID where this file is placed.
* @details Used to make sure that the file content is not compile twice if at least 2 modules using
* it are compiled in the project
*/
#define PORT_LLD_MODULE_ID        124

/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define PORT_PORT_CI_VENDOR_ID_C                     43
/* @violates @ref Port_Port_Ci_C_REF_4 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C      4
/* @violates @ref Port_Port_Ci_C_REF_4 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C      2
/* @violates @ref Port_Port_Ci_C_REF_4 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_C   2
#define PORT_PORT_CI_SW_MAJOR_VERSION_C              1
#define PORT_PORT_CI_SW_MINOR_VERSION_C              0
#define PORT_PORT_CI_SW_PATCH_VERSION_C              1

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Port_Ci.c and modules.h are of the same vendor */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Port_Ci.c and SilRegMacros.h are of the same version */
    #if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Port_Port_Ci.c and SilRegMacros.h are different"
    #endif
    /* Check if the files Port_Port_Ci.c and modules.h are of the same version */
    #if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C != MODULES_AR_RELEASE_MINOR_VERSION_H)    \
        )
       #error "AutoSar Version Numbers of Port_Port_Ci.c and modules.h are different"
    #endif
#endif
/* Check if the files Port_Port_Ci.c and modules.h are of the same vendor */

/* Check if Port_Port_Ci.c and Port.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_C != PORT_VENDOR_ID)
    #error "Port_Port_Ci.c and Port.h have different vendor ids"
#endif
/* Check if Port_Port_Ci.c and Port.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Port_Ci.c and Port.h are different"
#endif
/* Check if Port_Port_Ci.c and Port.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Port_Port_Ci.c and Port.h are different"
#endif

/* Check if Port_Port_Ci.c and Port_Reg_eSys_Port_Ci.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_C != PORT_REGESYS_PORT_CI_VENDOR_ID)
    #error "Port_Port_Ci.c and Port_Reg_eSys_Port_Ci.h have different vendor ids"
#endif
/* Check if Port_Port_Ci.c and Port_Reg_eSys_Port_Ci.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C    != PORT_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C    != PORT_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_C != PORT_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Port_Ci.c and Port_Reg_eSys_Port_Ci.h are different"
#endif
/* Check if Port_Port_Ci.c and Port_Reg_eSys_Port_Ci.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_C != PORT_REGESYS_PORT_CI_SW_MAJOR_VERSION) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_C != PORT_REGESYS_PORT_CI_SW_MINOR_VERSION) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_C != PORT_REGESYS_PORT_CI_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Port_Ci.c and Port_Reg_eSys_Port_Ci.h are different"
#endif

/* Check if Port_Port_Ci.c and Port_Port_Ci.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_C != PORT_PORT_CI_VENDOR_ID_H)
    #error "Port_Port_Ci.c and Port_Port_Ci.h have different vendor ids"
#endif
/* Check if Port_Port_Ci.c and Port_Port_Ci.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C    != PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C    != PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_C != PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Port_Ci.c and Port_Port_Ci.h are different"
#endif
/* Check if Port_Port_Ci.c and Port_Port_Ci.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_C != PORT_PORT_CI_SW_MAJOR_VERSION_H) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_C != PORT_PORT_CI_SW_MINOR_VERSION_H) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_C != PORT_PORT_CI_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Port_Ci.c and Port_Port_Ci.h are different"
#endif

/* Check if Port_Port_Ci.c and Reg_eSys_Gpio.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_C != REGESYS_GPIO_VENDOR_ID_REG) 
    #error "Port_Port_Ci.c and Port_Reg_eSys_Gpio.h have different vendor ids"
#endif
/* Check if Port_Port_Ci.c and Reg_eSys_Gpio.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_C    != REGESYS_GPIO_AR_RELEASE_MAJOR_VERSION_REG) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_C    != REGESYS_GPIO_AR_RELEASE_MINOR_VERSION_REG) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_C != REGESYS_GPIO_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Port_Port_Ci.c and Port_Reg_eSys_Gpio.h are different"
#endif
/* Check if Port_Port_Ci.c and Reg_eSys_Gpio.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_C != REGESYS_GPIO_SW_MAJOR_VERSION_REG) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_C != REGESYS_GPIO_SW_MINOR_VERSION_REG) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_C != REGESYS_GPIO_SW_PATCH_VERSION_REG)    \
    )
    #error "Software Version Numbers of Port_Port_Ci.c and Port_Reg_eSys_Gpio.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
                                       GLOBAL VARIABLES
=================================================================================================*/

#define PORT_START_SEC_VAR_NO_INIT_16
/* @violates @ref Port_Port_Ci_C_REF_3 Violates MISRA 2004 Required Rule 19.15 */
#include "Port_MemMap.h"

#if (STD_ON == PORT_DEV_ERROR_DETECT)
#if ((STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) ||         \
     (defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API))  \
    )
/**
* @brief Segment descriptor for data arranged in array
* @detail Port_Port_Ci_au16GpioDirChangeability variable is only used by Port_Port_Ci_SetPinDirection and Port_Port_Ci_SetPinMode
*         functions
*/
static VAR(uint16, PORT_VAR) Port_Port_Ci_au16GpioDirChangeability[PAD_16BLOCK_NO_U8];
#endif /* ((STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) ||         \
           (defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API))  \
          ) */
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
#define PORT_STOP_SEC_VAR_NO_INIT_16

/* @violates @ref Port_Port_Ci_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1 */
/* @violates @ref Port_Port_Ci_C_REF_3 Violates MISRA 2004 Required Rule 19.15 */
#include "Port_MemMap.h"

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
#define PORT_START_SEC_CODE
/* @violates @ref Port_Port_Ci_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1 */
/* @violates @ref Port_Port_Ci_C_REF_3 Violates MISRA 2004 Required Rule 19.15 */
#include "Port_MemMap.h"

LOCAL_INLINE FUNC(void, PORT_CODE) Port_Port_Ci_Init_UnusedPins
(
    P2CONST(Port_ConfigType, AUTOMATIC,  PORT_APPL_CONST) pConfigPtr
);

LOCAL_INLINE FUNC(void, PORT_CODE) Port_Port_Ci_Init_ConfiguredPins
(
    P2CONST(Port_ConfigType, AUTOMATIC,  PORT_APPL_CONST) pConfigPtr
);
/*=================================================================================================
                                       LOCAL FUNCTIONS
=================================================================================================*/
/**
* @brief        Initializes the PORT IP Driver
* @details      The function Port_Port_Ci_Init_UnusedPins will initialize ALL Unused Port Pins with the
*               configuration set pointed to by the parameter ConfigPtr.
*
* @param[in]    pConfigPtr  A pointer to the structure which contains initialization parameters
*
* @return       none
*
* @pre          none
* @post         No function of the driver is executed without the initialisation of the module.
*
*
*/
LOCAL_INLINE FUNC(void, PORT_CODE) Port_Port_Ci_Init_UnusedPins
(
    P2CONST(Port_ConfigType, AUTOMATIC,  PORT_APPL_CONST) pConfigPtr
)
{
    VAR(uint16, AUTOMATIC) u16PinIndex;
    VAR(uint16, AUTOMATIC) u16NumUnusedPins             = (uint16)(pConfigPtr->u16NumUnusedPins);
    
    VAR(uint32, AUTOMATIC) u32LocalPCR                  = (uint32)(pConfigPtr->pUnusedPadConfig->u32PCR);

    VAR(uint8, AUTOMATIC)  u8LocalPDO                   = (uint8)(pConfigPtr->pUnusedPadConfig->u8PDO);
    VAR(Port_PinDirectionType, AUTOMATIC)  eLocalPDDIR  = pConfigPtr->pUnusedPadConfig->ePDDir;
    
    VAR(Port_InternalPinIdType, AUTOMATIC) Pin;
    
    /* Initialize All Unused Port Pins */
    for (u16PinIndex = (uint16)0U; u16PinIndex < u16NumUnusedPins; u16PinIndex++)
    {
        /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
        Pin = pConfigPtr->au16UnusedPads[u16PinIndex];

        /* Check if the direction of the pin is OUTPUT. In this case the driver needs to set the output level too */
        if(PORT_PIN_OUT == eLocalPDDIR)
        {
            /* Set pin to High value */
            if (PORT_PIN_LEVEL_HIGH_U8 == u8LocalPDO)
            {
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(GPIO_PSOR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
            }
            /* Set pin to Low value */
            else if (PORT_PIN_LEVEL_LOW_U8 == u8LocalPDO)
            {
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(GPIO_PCOR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
            }
            else
            {
                /* No action to be done */
            }
            /* Configure the pin direction as output in the PDDR register of GPIO IP */
            /** 
            * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
            * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
            */
            REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
        }
        else
        {
            /* Not used port pins are configured as inputs */
            /* Configure the pin direction as input in the PDDR register of GPIO IP */
            /** 
            * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
            * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
            */
            REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
        }
        /* Write PCR configuration from Configuration tool */
        /** 
        * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
        * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
        */
        REG_WRITE32(PORT_PCR_ADDR32(Pin), u32LocalPCR);
    }
}

/**
* @brief        Initializes the PORT IP Driver
* @details      The function Port_Port_Ci_Init_ConfiguredPins will initialize ALL configured Port Pins with the
*               configuration set pointed to by the parameter ConfigPtr.
*
* @param[in]    pConfigPtr  A pointer to the structure which contains initialization parameters
*
* @return       none
*
* @pre          none
* @post         No function of the driver is executed without the initialisation of the module.
*
*
*/
LOCAL_INLINE FUNC(void, PORT_CODE) Port_Port_Ci_Init_ConfiguredPins
(
    P2CONST(Port_ConfigType, AUTOMATIC,  PORT_APPL_CONST) pConfigPtr
)
{
    VAR(uint16, AUTOMATIC) u16PinIndex;
    VAR(uint16, AUTOMATIC) u16NumPins                   = (uint16)(pConfigPtr->u16NumPins);

    VAR(uint32, AUTOMATIC) u32LocalPCR                  = (uint32)(pConfigPtr->pUnusedPadConfig->u32PCR);

    VAR(uint8, AUTOMATIC)  u8LocalPDO                   = (uint8)(pConfigPtr->pUnusedPadConfig->u8PDO);
    VAR(Port_PinDirectionType, AUTOMATIC)  eLocalPDDIR  = pConfigPtr->pUnusedPadConfig->ePDDir;

    VAR(Port_InternalPinIdType, AUTOMATIC) Pin;
    
    /* Initialize All Configured Port Pins */
    for (u16PinIndex= (uint16)0U; u16PinIndex < u16NumPins; u16PinIndex++)
    {
        /** 
        * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
        * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        Pin = pConfigPtr->pUsedPadConfig[u16PinIndex].Pin;

        /** 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        u8LocalPDO = pConfigPtr->pUsedPadConfig[u16PinIndex].u8PDO;
        
        /** 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        eLocalPDDIR = pConfigPtr->pUsedPadConfig[u16PinIndex].ePDDir;
        
        /** 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        u32LocalPCR = pConfigPtr->pUsedPadConfig[u16PinIndex].u32PCR;

        /**
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4
        */
        if (pConfigPtr->pUsedPadConfig[u16PinIndex].bGPIO)
        {
            /* Check if the direction of the pin is OUTPUT. In this case the driver needs to set the output level too */
            if(PORT_PIN_OUT == eLocalPDDIR)
            {
                /* Set pin to High value */
                if (PORT_PIN_LEVEL_HIGH_U8 == u8LocalPDO)
                {
                    /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
                    /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                    REG_WRITE32(GPIO_PSOR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
                }
                /* Set pin to Low value */
                else if (PORT_PIN_LEVEL_LOW_U8 == u8LocalPDO)
                {
                    /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
                    /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                    REG_WRITE32(GPIO_PCOR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
                }
                else
                {
                    /* No action to be done */
                }
                /* Configure the pin direction as output in the PDDR register of GPIO IP */
                /** 
                * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
                * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
                */
                REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
            }
            else
            {
                /* Configure the pin direction as input in the PDDR register of GPIO IP */
                /** 
                * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
                * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
                */
                REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
            }
        }
        /**
        * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(PORT_PCR_ADDR32(Pin), u32LocalPCR);
    }
}

/*=================================================================================================
                                       GLOBAL FUNCTIONS
=================================================================================================*/

/**
* @brief        Initializes the PORT IP Driver
* @details      The function Port_Port_Ci_Init will initialize ALL ports and port pins with the
*               configuration set pointed to by the parameter ConfigPtr.
*
* @param[in]    pConfigPtr  A pointer to the structure which contains initialization parameters
*
* @return none
*
* @pre    none
* @post   No function of the driver is executed without the initialisation of the module.
*
*
*/
FUNC(void, PORT_CODE) Port_Port_Ci_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC,  PORT_APPL_CONST) pConfigPtr
)
{
    VAR(uint16, AUTOMATIC) u16PinIndex;

    VAR(uint8,  AUTOMATIC) u8NumDigFilterPorts          = (uint8)(pConfigPtr->u8NumDigitalFilterPorts);
    VAR(uint8,  AUTOMATIC) u8Port;

    /* Initialize all configured digital filter ports. Use u16PinIndex variable as counter, even if we loop on a uint8 variable */
    for (u16PinIndex = (uint16)0U; u16PinIndex < (uint16)u8NumDigFilterPorts; u16PinIndex++)
    {
        /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
        u8Port = pConfigPtr->pDigitalFilterConfig[u16PinIndex].u8Port;
        
        /* Set digital filter clock for the current port */
        /** 
        * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer 
        * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        REG_WRITE32(PORT_DFCR_ADDR32(u8Port), (uint32)(pConfigPtr->pDigitalFilterConfig[u16PinIndex].u8Clock));
        /* Set digital filter width for the current port */
        /** 
        * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer 
        * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        REG_WRITE32(PORT_DFWR_ADDR32(u8Port), (uint32)(pConfigPtr->pDigitalFilterConfig[u16PinIndex].u8Width));
        /* Enable digital filter for the pins selected by the user for the current port */
        /** 
        * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer 
        * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
        * @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 
        */
        REG_WRITE32(PORT_DFER_ADDR32(u8Port), (uint32)(pConfigPtr->pDigitalFilterConfig[u16PinIndex].u32PinMask));
    }

    /* Initialize All Unused Port Pins */
    Port_Port_Ci_Init_UnusedPins(pConfigPtr);

    /* Initialize All Configured Port Pins */
    Port_Port_Ci_Init_ConfiguredPins(pConfigPtr);

#if (STD_ON == PORT_DEV_ERROR_DETECT)    
#if ((STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) ||         \
     (defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API))  \
    )
    /* Port_Port_Ci_au16GpioDirChangeability is only used by Port_Port_Ci_SetPinDirection, Port_Port_Ci_Set2PinsDirection 
       and Port_Port_Ci_SetPinMode functions */
    /* Initialize the Array with Change Direction Flags for GPIO */
    for (u16PinIndex=(uint16)0U; u16PinIndex < PAD_16BLOCK_NO_U8; u16PinIndex++)
    {
        Port_Port_Ci_au16GpioDirChangeability[u16PinIndex] = (uint16)0UL;
    }
#endif /* ((STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) ||         \
           (defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API))  \
          ) */
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

}


#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin direction
* @details Sets the pin direction at runtime, changing it only if the pin is configured as
*          changeable.
*
* @param[in]     PinIndex      Pin ID number
* @param[in]     eDirection      Port Pin direction
* @param[in]     pConfigPtr      A pointer to the structure which contains initialization parameters
*
* @return Error code after execution
* @retval 0   No error occured
* @retval 1   Pin direction cannot be changed
*
* @pre Port_Init must have been called
* @post none
*
*
*/
FUNC (Std_ReturnType, PORT_CODE) Port_Port_Ci_SetPinDirection
(
    VAR     (Port_PinType,          AUTOMATIC)                  PinIndex,
    VAR     (Port_PinDirectionType, AUTOMATIC)                  eDirection,
    P2CONST (Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /* Point to the Port Pin PCR register address */
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    VAR(Port_InternalPinIdType, AUTOMATIC) Pin = pConfigPtr->pUsedPadConfig[PinIndex].Pin;

    /* Return value */
    VAR(Std_ReturnType, AUTOMATIC) PinDirError             = (Std_ReturnType)E_OK;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* Bit Offset and Table value for change direction flag word*/
    VAR(uint8,          AUTOMATIC) u8PinDescBitOffset       = (uint8)(Pin & PORT_BIT_OFFSET_MASK_U8);
    VAR(uint16,         AUTOMATIC) u16PinChangeDirFlagWord  = Port_Port_Ci_au16GpioDirChangeability[(uint8)(Pin>>4)];
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

#if (STD_ON == PORT_DEV_ERROR_DETECT) 
    /* Check the Direction changeability option */
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    if (((boolean)TRUE == pConfigPtr->pUsedPadConfig[PinIndex].bDC) || ((uint16)0 != (u16PinChangeDirFlagWord & (uint16)(1UL<<u8PinDescBitOffset))))
    {
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
        /* Enter critical region */
        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03();
        /* Configures Port Pin as Output */
        if (PORT_PIN_OUT == eDirection)
        {
            /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
        }
        /* Configures Port Pin as Input */
        else if (PORT_PIN_IN == eDirection)
        {
            /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
        }
        else
        {
            /* Do nothing */ 
        }
        /* Exit critical region */
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03();
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    }
    /* Direction changeability is NOT supported */
    else
    {
        PinDirError = (Std_ReturnType)E_NOT_OK;
    }
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

    return PinDirError;
}
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#if defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/**
* @brief   Sets the port direction for 2 pins
* @details Sets the pin direction at runtime, changing it only if the pins are configured as
*          changeable.
*
* @param[in]     Pin1Index       Pin1 ID number
* @param[in]     Pin2Index       Pin2 ID number
* @param[in]     eDirection      Port Pin direction
* @param[in]     pConfigPtr      A pointer to the structure which contains initialization parameters
*
* @return Error code after execution
* @retval 0   No error occured
* @retval 1   Pin direction cannot be changed
*
* @pre Port_Init must have been called
* @post none
*
*
*/
FUNC(Std_ReturnType, PORT_CODE) Port_Port_Ci_Set2PinsDirection
(
    VAR    (Port_PinType,          AUTOMATIC                 ) Pin1Index,
    VAR    (Port_PinType,          AUTOMATIC                 ) Pin2Index,
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) eDirection,
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /* Point to the Port Pin PCR register address */
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    VAR(Port_InternalPinIdType, AUTOMATIC) Pin1 = pConfigPtr->pUsedPadConfig[Pin1Index].Pin;
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    VAR(Port_InternalPinIdType, AUTOMATIC) Pin2 = pConfigPtr->pUsedPadConfig[Pin2Index].Pin;

    /* Return value */
    VAR(Std_ReturnType, AUTOMATIC) PinDirError             = (Std_ReturnType)E_OK;

#if (STD_ON == PORT_DEV_ERROR_DETECT)    
    /* Bit Offsets and Table values for change direction flag words */
    VAR(uint8,          AUTOMATIC) u8PinDescBitOffset1       = (uint8)(Pin1 & PORT_BIT_OFFSET_MASK_U8);
    VAR(uint16,         AUTOMATIC) u16PinChangeDirFlagWord1  = Port_Port_Ci_au16GpioDirChangeability[(uint8)(Pin1>>4)];

    VAR(uint8,          AUTOMATIC) u8PinDescBitOffset2       = (uint8)(Pin2 & PORT_BIT_OFFSET_MASK_U8);
    VAR(uint16,         AUTOMATIC) u16PinChangeDirFlagWord2  = Port_Port_Ci_au16GpioDirChangeability[(uint8)(Pin2>>4)];
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* Check the Direction changeability option */
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    if ((((boolean)TRUE == pConfigPtr->pUsedPadConfig[Pin1Index].bDC) || ((uint16)0 != (u16PinChangeDirFlagWord1 & (uint16)(1UL<<u8PinDescBitOffset1)))) && \
        (((boolean)TRUE == pConfigPtr->pUsedPadConfig[Pin2Index].bDC) || ((uint16)0 != (u16PinChangeDirFlagWord2 & (uint16)(1UL<<u8PinDescBitOffset2))))    \
       )
    {
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
        /* Enter critical region */
        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03();
        /* Check if the pins belong to the same port. In this case, we need to write the PDDR register once to set direction of both pins in the same time */
        if(GPIO_PORT_U32(Pin1) == GPIO_PORT_U32(Pin2))
        {
            /* Configures Port Pins as Output */
            if (PORT_PIN_OUT == eDirection)
            {
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin1)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin1)) | (uint32)(1UL << GPIO_CHANNEL_U32(Pin2)));
            }
            /* Configures Port Pins as Input */
            else if (PORT_PIN_IN == eDirection)
            {
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin1)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin1)) | (uint32)(1UL << GPIO_CHANNEL_U32(Pin2)));
            }
            else
            {
                /* Do nothing */ 
            }
        }
        else
        {
            /* Configures Port Pins as Output */
            if (PORT_PIN_OUT == eDirection)
            {
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin1)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin1)));
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin2)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin2)));
            }
            /* Configures Port Pins as Input */
            else if (PORT_PIN_IN == eDirection)
            {
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin1)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin1)));
                /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(Pin2)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin2)));
            }
            else
            {
                /* Do nothing */ 
            }
        }
        /* Exit critical region */
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03();
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    }
    /* Direction changeability is NOT supported */
    else
    {
        PinDirError = (Std_ReturnType)E_NOT_OK;
    }
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

    return PinDirError;
}
#endif /* defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin mode.
* @details The function will set the port pin mode of the referenced pin during runtime
*
* @param[in]     PinCfgRegIndex         Index of Register PCR
* @param[in]     PinCfgRegValue         Value of Register PCR
*
* @return Error code after execution
* @retval 0   No error occured
* @retval PORT_E_MODE_UNCHANGEABLE   Pin mode cannot be changed
* @retval PORT_E_PARAM_INVALID_MODE  Invalid mode
*
* @pre Port_Init must have been called
* @post none
*
*
*/
FUNC (void, PORT_CODE) Port_Port_Ci_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,  AUTOMATIC) PinCfgRegValue
)
{
    /* Variable used to clear and updated PCR register */
    VAR(uint32, AUTOMATIC) u32LocalPCR;
    
    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
    
    /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
    /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
    u32LocalPCR  = REG_READ32(PORT_PCR_ADDR32(PinCfgRegIndex));
    u32LocalPCR &= ~(PORT_PCR_ALT_MODE_U32);
 
    u32LocalPCR |= ((uint32)PinCfgRegValue << PORT_PCR_ALT_MODE_OFFSET_U32);
    /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
    /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PORT_PCR_ADDR32(PinCfgRegIndex), u32LocalPCR);
    
    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
}
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
#if (STD_ON == PORT_DEV_ERROR_DETECT)
/**
* @brief    Sets or resets the direction changeability for pads in GPIO mode.
* @details  The function will update the direction changeability for the pads whose mode is changed
*
* @param[in] PadID          Pin ID number.
* @param[in] bStatus        The new value true or false for direction changeability.
*
* @return    None
*
* @pre  none
* @post none
*
*
*/
FUNC (void, PORT_CODE) Port_Port_Ci_SetGpioDirChangeability
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PadID,
    VAR(boolean,            AUTOMATIC) bStatus
)
{
    /* Pin description variables */
    VAR(uint8,  AUTOMATIC) u8PinBitOffset;
    VAR(uint16, AUTOMATIC) u16PinDirFlagWord;

    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();
    /* Bit offset of Pin index inside the pin description matrix */
    u8PinBitOffset      = (uint8)((uint8)PadID & PORT_BIT_OFFSET_MASK_U8);
    u16PinDirFlagWord   = Port_Port_Ci_au16GpioDirChangeability[(uint8)((uint8)PadID>>4)];

    if ((boolean)TRUE == bStatus)
    {
        /* Set the change direction flag */
        u16PinDirFlagWord |= (uint16)(1UL<<u8PinBitOffset);
    }
    else
    {   /* Reset the change direction flag */
        u16PinDirFlagWord &= (uint16)(~((uint16)(1UL<<u8PinBitOffset)));
    }
    Port_Port_Ci_au16GpioDirChangeability[(uint8)((uint8)PadID>>4)] = u16PinDirFlagWord;
    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();
}
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
/**
* @brief    Sets the output status of the pads in GPIO mode.
* @details  The function will update the output for the pads whose mode is changed
*
* @param[in] PinIndex     Pin ID number.
* @param[in] pConfigPtr     A pointer to the structure which contains initialization parameters
*
*
* @return    None
*
* @pre  none
* @post none
*
*
*/
FUNC (void, PORT_CODE) Port_Port_Ci_SetGpioPadOutput
(
    VAR    (Port_PinType,       AUTOMATIC)                  PinIndex,
    P2CONST(Port_ConfigType,    AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    VAR(Port_InternalPinIdType, AUTOMATIC) Pin = pConfigPtr->pUsedPadConfig[PinIndex].Pin;
    /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
    VAR(uint8, AUTOMATIC) u8LocalPDO = pConfigPtr->pUsedPadConfig[PinIndex].u8PDO;

    /* Set pin to High value */
    if (PORT_PIN_LEVEL_HIGH_U8 == u8LocalPDO)
    {
        /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.*/
        /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(GPIO_PSOR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
    }
    /* Set pin to Low value */
    else if (PORT_PIN_LEVEL_LOW_U8 == u8LocalPDO)
    {
        /* @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.*/
        /* @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(GPIO_PCOR_ADDR32(GPIO_PORT_U32(Pin)), (uint32)(1UL << GPIO_CHANNEL_U32(Pin)));
    }
    else
    {
        /* No action to be done */
    }
}
#endif /* (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL) */ 
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */


/**
* @brief   Refreshes port direction.
* @details This service shall refresh the direction of all configured ports to the configured
*          direction. The PORT driver shall exclude from refreshing those port pins that are
*          configured as pin direction changeable during runtime.
*
* @param[in]     pConfigPtr    Pointer to configuration containing pins to be refreshed
* @return none
*
* @pre Port_Init must have been called
* @post none
*
*/
FUNC (void, PORT_CODE) Port_Port_Ci_RefreshPortDirection
(
    P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST) pConfigPtr
)
{
    VAR(uint16, AUTOMATIC) u16NumPins = pConfigPtr->u16NumPins;
    /* Index of the port table */
    VAR(uint16, AUTOMATIC) u16PinIndex;
    VAR(Port_InternalPinIdType, AUTOMATIC) PinPad;

    /* Initialize All Configured Port Pins that aren't direction changable */
    for (u16PinIndex = (uint16)0U; u16PinIndex < u16NumPins; u16PinIndex++)
    {
        /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
        if ((boolean)FALSE == pConfigPtr->pUsedPadConfig[u16PinIndex].bDC)
        {
            /* On this platform we can only determine direction for the pins initialy configured as GPIOs */
            /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
            if ((boolean)TRUE == pConfigPtr->pUsedPadConfig[u16PinIndex].bGPIO)
            {
                /* Point to the Port Pin MSCR register address*/
                /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
                PinPad = pConfigPtr->pUsedPadConfig[u16PinIndex].Pin;

                /* Enter critical region */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
            
                /* Configures Port Pin as Output */
                /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
                if (PORT_PIN_OUT == pConfigPtr->pUsedPadConfig[u16PinIndex].ePDDir)
                {
                    /* Configure the pin direction as output in the PDDR register of GPIO IP */
                    /**
                    * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                    * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
                    */
                    REG_BIT_SET32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(PinPad)), (uint32)(1UL << GPIO_CHANNEL_U32(PinPad)));
                }
                /* @violates @ref Port_Port_Ci_C_REF_7 Violates MISRA 2004 Required Rule 17.4 */
                else if (PORT_PIN_IN == pConfigPtr->pUsedPadConfig[u16PinIndex].ePDDir)
                {
                    /* Configure the pin direction as input in the PDDR register of GPIO IP */
                    /**
                    * @violates @ref Port_Port_Ci_C_REF_5 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                    * @violates @ref Port_Port_Ci_C_REF_10 A cast should not be performed between a pointer type and an integral type. 
                    */
                    REG_BIT_CLEAR32(GPIO_PDDR_ADDR32(GPIO_PORT_U32(PinPad)), (uint32)(1UL << GPIO_CHANNEL_U32(PinPad)));
                }
                else
                {
                    /* Do nothing. Else branch present in order to avoid MISRA warning */
                }
                /* Exit critical region */
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
            }
        }
    }
}

#define PORT_STOP_SEC_CODE
/* @violates @ref Port_Port_Ci_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' */
/* @violates @ref Port_Port_Ci_C_REF_3 Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
