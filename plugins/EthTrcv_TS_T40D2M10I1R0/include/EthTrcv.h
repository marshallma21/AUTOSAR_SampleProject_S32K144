/**
*   @file             EthTrcv.h
*   @version          1.0.1
*
*   @brief            AUTOSAR EthTrcv callbacks header file stub
*   @details          File containing prototypes needed by the Ethernet driver
*                     This file contains sample code only. It is not part of the production code deliverables.
*   @warning          This is only a stub file. It does not fully comply to AUTOSAR standard.
*
*   @addtogroup       ETHIF_SECTION
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
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

#ifndef ETHTRCV_H
  #define ETHTRCV_H
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Common types for all communication modules*/
#include "Eth.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_VENDOR_ID                    43
#define ETHTRCV_MODULE_ID                    66
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION     4
#define ETHTRCV_AR_RELEASE_MINOR_VERSION     2
#define ETHTRCV_AR_RELEASE_REVISION_VERSION  2
#define ETHTRCV_SW_MAJOR_VERSION             1
#define ETHTRCV_SW_MINOR_VERSION             0
#define ETHTRCV_SW_PATCH_VERSION             1
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

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
    
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

extern FUNC(void, ETHTRCV_CODE)EthTrcv_ReadMiiIndication  (
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) TrcvIdx, \
                                VAR(uint8, AUTOMATIC) RegIdx, \
                                VAR(uint16, AUTOMATIC) RegVal \
                                                        );

extern FUNC(void, ETHTRCV_CODE)EthTrcv_WriteMiiIndication (
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) TrcvIdx, \
                                VAR(uint8, AUTOMATIC) RegIdx \
                                                        );

#ifdef __cplusplus
}
#endif                                              

#endif /* ETHTRCV_H */
/** @} */
