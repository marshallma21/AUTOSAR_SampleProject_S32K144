/**
*   @file             EthTrcv.c
*   @version          1.0.1
*
*   @brief            AUTOSAR Ethernet Interface callbacks stub file
*   @details          File containing function bodies needed
*                     for the Ethernet driver compilation. This file should
*                     be replaced by a complete version.
*   @warning          This is only a stub file. It does not fully comply to AUTOSAR standard.
*
*   @addtogroup       ETHIF_SECTION
*   @{
*/
/*==================================================================================================
*   Project            : AUTOSAR 4.2 MCAL
*   Platform           : ARM
*   Peripheral         : 
*   Dependencies       : 
*
*   AutosarVersion     : 4.2.2
*   AutosarRevision    : ASR_REL_4_2_REV_0002
*   AutosarConfVariant :
*   SW Version         : 1.0.1
*   BuildVersion       : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
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

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "EthTrcv.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_VENDOR_ID_C                      43
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION_C       4
#define ETHTRCV_AR_RELEASE_MINOR_VERSION_C       2
#define ETHTRCV_AR_RELEASE_REVISION_VERSION_C    2
#define ETHTRCV_SW_MAJOR_VERSION_C               1
#define ETHTRCV_SW_MINOR_VERSION_C               0
#define ETHTRCV_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETHIF header file are of the same vendor */
#if (ETHTRCV_VENDOR_ID_C != ETHTRCV_VENDOR_ID)
    #error "EthTrcv.c and EthTrcv.h have different vendor ids"
#endif
/* Check if current file and ETHIF header file are of the same Autosar version */
#if ((ETHTRCV_AR_RELEASE_MAJOR_VERSION_C    != ETHTRCV_AR_RELEASE_MAJOR_VERSION) || \
     (ETHTRCV_AR_RELEASE_MINOR_VERSION_C    != ETHTRCV_AR_RELEASE_MINOR_VERSION) || \
     (ETHTRCV_AR_RELEASE_REVISION_VERSION_C != ETHTRCV_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of EthTrcv.c and EthTrcv.h are different"
#endif
/* Check if current file and ETHIF header file are of the same Software version */
#if ((ETHTRCV_SW_MAJOR_VERSION_C != ETHTRCV_SW_MAJOR_VERSION) || \
     (ETHTRCV_SW_MINOR_VERSION_C != ETHTRCV_SW_MINOR_VERSION) || \
     (ETHTRCV_SW_PATCH_VERSION_C != ETHTRCV_SW_PATCH_VERSION))
    #error "Software Version Numbers of EthTrcv.c and EthTrcv.h are different"
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


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @note           The passed data buffer is no longer valid after the function
*                 is exited.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which read Mii.
* @param[in]      TrcvIdx The Id of transceiver was read Mii
* @param[in]      RegIdx The Id or Address of Register was read
* @param[in]      RegVal The value of register.
*
*/
FUNC(void, ETHTRCV_CODE)EthTrcv_ReadMiiIndication (
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) TrcvIdx, \
                                VAR(uint8, AUTOMATIC) RegIdx, \
                                VAR(uint16, AUTOMATIC) RegVal \
                                                )
{
    ; /* This is an empty stub function */
}

/*================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @note           The passed data buffer is no longer valid after the function
*                 is exited.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which write Mii.
* @param[in]      TrcvIdx The Id of transceiver was write Mii
* @param[in]      RegIdx The Id or Address of Register was write
*
*/
FUNC(void, ETHTRCV_CODE)EthTrcv_WriteMiiIndication    (
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) TrcvIdx, \
                                VAR(uint8, AUTOMATIC) RegIdx \
                                                    )
{
    ; /* This is an empty stub function */
}

#ifdef __cplusplus
}
#endif
/** @} */
