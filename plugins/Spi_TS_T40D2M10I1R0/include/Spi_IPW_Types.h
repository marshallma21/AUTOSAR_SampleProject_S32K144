/**
*   @file    Spi_IPW_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
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

#ifndef SPI_IPW_TYPES_H
#define SPI_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_TYPES_MODULE_ID                       83
#define SPI_IPW_TYPES_VENDOR_ID                       43
#define SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2
#define SPI_IPW_TYPES_SW_MAJOR_VERSION                1
#define SPI_IPW_TYPES_SW_MINOR_VERSION                0
#define SPI_IPW_TYPES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief Internal structure used to manage the channel attributes.
*/
typedef struct
{
    VAR(uint32, SPI_VAR) u32CMD; /**< @brief Channel attributes for CMD in TCR register. */
    VAR(uint32, SPI_VAR) u32FCR; /**< @brief Channel attributes for FIFO control in FCR register. */
    VAR(uint8, SPI_VAR)  u8DataWidth;       /**< @brief Channel attributes for data width. */
} Spi_Ipw_ChannelAttributesConfigType;

/**
* @brief Internal structure used to manage the LPSPI unit attributes.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) u32TCR[2];     /**< @brief Device attributes for TCRs. */
    VAR(uint32, SPI_VAR) u32CCR[2];     /**< @brief Device configuration for timing in CCR. */
    VAR(uint8, SPI_VAR)  u8DualClk;     /**< @brief Device attributes for Dual Clock Mode. */
#else
    VAR(uint32, SPI_VAR) u32TCR;        /**< @brief Device attributes for TCRs. */
    VAR(uint32, SPI_VAR) u32CCR;        /**< @brief Device configuration for timing in CCR. */
#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */
    VAR(uint32, SPI_VAR) u32CFGR1;      /**< @brief Device CS idle setting. */
} Spi_Ipw_DeviceAttributesConfigType;

/**
* @brief Internal structure used to manage LLD attributes.
*/
typedef struct
{
    /**< @brief Array of configuration channel attributes. */
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, SPI_VAR, SPI_APPL_CONST) pcChannelAttributesConfig;
    /**< @brief Array of LPSPI units attributes. */
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) pcDeviceAttributesConfig;
} Spi_AttributesConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_IPW_TYPES_H*/

/** @} */
