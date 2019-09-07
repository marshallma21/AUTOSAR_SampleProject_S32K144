/**
*   @file    Eth_Buffers.c
*   @implements Eth_Buffers.c_Artifact
*   @version 1.0.1
*
*  @brief    AUTOSAR Eth driver buffers
*  @details  Definition of memory blocks used for storage of data buffers and related
*            buffer descriptors.
*
*   @addtogroup ETH_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ENET
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*
* @section Eth_Buffers_c_REF_1
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for 
* external identifiers. Name length of the macros is unfortunately longer than 
* 31 characters which is required by  the agreed macro format and cannot be 
* changed. 
*
* @section Eth_Buffers_c_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_Buffers_c_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions
* shall be taken in order to prevent the contents of a header file being
* included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Buffers_c_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be
* preceded by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Buffers_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. The variable always require the external
* linkage. MISRA analysis tool does not see the linkage from upper layers
* therefore there is no violation.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Eth_Buffers_c_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Buffers_c_REF_2 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_C    2
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if (ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth_Buffers.c and Eth.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Eth_Buffers.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_Buffers.c and Eth.h are different"
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
/* Start of the cache disabled memory section */
/** @violates @ref Eth_Buffers_c_REF_1 MISRA rule 1.4 */
/** @violates @ref Eth_Buffers_c_REF_2 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE

/** @violates @ref Eth_Buffers_c_REF_3 MISRA rule 19.15 */
#include "Eth_MemMap.h"

/**
* @var Eth_Buffers
* @brief Memory space used for the Ethernet driver buffers
* @details The memory space occupied by this array is internally divided into the receive
*          buffers and their descriptors. Its size, @c ETH_TX_BUF_MEM_SIZE, is computed by
*          the configuration tool based on the number and sizes of the buffers.
*/
/* Make the variable properly aligned */
ALIGNED_VARS_START(dummy_section, ETH_TX_BUF_ALIGNMENT)
/** @violates @ref Eth_Buffers_c_REF_5 MISRA rule 8.10 */
    VAR_ALIGN(VAR(uint8, ETH_VAR) Eth_TxBuffers[ETH_MAX_CONTROLLER_CFG][ETH_TX_BUF_MEM_SIZE], ETH_TX_BUF_ALIGNMENT)
ALIGNED_VARS_STOP()

/**
* @var Eth_Buffers
* @brief Memory space used for the Ethernet driver transmit buffers
* @details The memory space occupied by this array is internally divided into the transmit
*          buffers and their descriptors. Its size, @c ETH_RX_BUF_MEM_SIZE, is computed by
*          the configuration tool based on the number and sizes of the buffers.
*/
/* Make the variable properly aligned */
ALIGNED_VARS_START(dummy_section, ETH_RX_BUF_ALIGNMENT)
/** @violates @ref Eth_Buffers_c_REF_5 MISRA rule 8.10 */
    VAR_ALIGN(VAR(uint8, ETH_VAR) Eth_RxBuffers[ETH_MAX_CONTROLLER_CFG][ETH_RX_BUF_MEM_SIZE], ETH_RX_BUF_ALIGNMENT)
ALIGNED_VARS_STOP()

/* End of the cache disabled memory section */
/** @violates @ref Eth_Buffers_c_REF_1 MISRA rule 1.4 */
/** @violates @ref Eth_Buffers_c_REF_2 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/** @violates @ref Eth_Buffers_c_REF_3 MISRA rule 19.15 */
/** @violates @ref Eth_Buffers_c_REF_4 MISRA rule 19.1 */
#include "Eth_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
