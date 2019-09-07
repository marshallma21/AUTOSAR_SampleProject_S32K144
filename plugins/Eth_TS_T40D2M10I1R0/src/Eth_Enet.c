/**
*   @file    Eth_Enet.c
*   @version 1.0.1
*
*    @brief            ENET controller interface
*    @details          Implementation of the ENET controller interface for
*                      the Ethernet driver
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
* @section Eth_Enet_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Enet_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.3, A cast shall not be performed between a
* pointer type and an integral type. The usage of pointers loaded by a
* computed address violates advisory this rule, but this mechanism is used
* to access memory mapped registers and data areas where  another approach
* is not feasible.
*
* @section Eth_Enet_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for 
* external identifiers. Name length of the macros is unfortunately longer than 
* 31 characters which is required by  the agreed macro format and cannot be 
* changed. 
*
* @section Eth_Enet_c_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Enet_c_REF_5
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. Array indexing shall only be applied to objects defined as an array type however
* most buffers are passed as pointer therefore pointer arithmetic is used to access their data.
*
* @section Eth_Enet_c_REF_7
* Violates MISRA 2004 Required Rule 11.1, Pointer to a function shall not be converted to anything
* else than integral type. This rule is not violated however the tool used for checks reports it
* therefore it must be commented here.
*
* @section Eth_Enet_c_REF_8
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results
* are invariant shall not be permitted. This condition is invariant only for
* PreCompile variant where is this behavior expected.
*
* @section Eth_Enet_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. The APIs always require the external
* linkage. MISRA analysis tool does not see the linkage from upper layers
* therefore there is no violation.
*
* @section Eth_Enet_c_REF_11
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. The MISRA analysis tool reports this violation badly if array of pointers is accessed
* even with the array indexing arithmetics - this is used in a post build configuration variant
* to access the configuration parameters. It is no violation but the tool bug however it must be
* documented anyway.
*
* @section Eth_Enet_c_REF_12
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block
* scope if they are only accessed from within a single function. This violation 
* is wrongly reported because the varialbe here has been drop by compiler. Other
* config will use this variable.
*
* @section Eth_Enet_c_REF_15
* Violates MISRA 2004 Required Rule 12.4, The right-hand operand of a logical
* && or || operator shall not contain side effect. This violation is wrongly
* reported because there is no side effect inside read macro.
*
* @section Eth_Enet_c_REF_17
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed
* on undefined or unspecified behavior. No reliance on undefined
* or unspecified behavior was not identified. There is used pointer to stack
* passed into lower function, but is ensured that pointer is still valid
* during execution the lower one.
*
* @section Eth_Enet_c_REF_18
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_Enet_c_REF_20
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be implicitly 
* converted to a different unlerlying type is: it is not a conversion to a wider integer type of the same 
* signedness or the expression is complex of the expression is not a constant and is a function argument or 
* the expression is not a constant and is a return expression. The violation happen in 64 bits platform where the 
* address is 64 bits, however, there is only LSB bits are meaning, so this conversion is correct. 
*
* @section Eth_Enet_c_REF_22
* Violates MISRA 2004 Required Rule 10.3, the value of a complex expression of integer type may only be cast to 
* a type that is narrower and of the same signedness as the underlying type of the expression. At here we have to
* change the sign of integer in order to process the division of 64-bits parameter and change again the signed.
* We already check regarded the sign before do conversion.
*
* @section Eth_Enet_c_REF_24
* Violates MISRA 2004 Required Rule 14.1, This rule refers to code which cannot under any circumstances be reached, 
* and which can be identified as such at compile-time

* @section Eth_Enet_c_REF_25
* Violates MISRA 2004 Required Rule 12.2, The value of an expression shall be the same under any order of 
* evaluation that the standard permits.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth.h" /* Includes also Eth_GeneralTypes.h, Eth_Cfg.h, Eth_ENET_Counters.h,
                    Eth_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "SchM_Eth.h" /* RTE module header for critical sections protection */
#include "Eth_Enet.h" /* Own interface */
#include "StdRegMacros.h"   /* Macros for register access abstraction */
#include "Eth_Enet_Counters.h" /* counter register for ENET IP */
/* Note Soc_Ips.h is included through Reg_eSys.h - Mcal.h - Eth_Cfg.h - Eth.h */
#include "EthIf_Cbk.h" /* EthIf callbacks to be called from Eth driver */

#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
#include "Mcl.h" /* Includes MCL for cache instruction workaround */
  #endif
#endif
#ifdef ETH_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ETH_ENABLE_USER_MODE_SUPPORT)
        #ifdef ETH_ENET_REG_PROT_AVAILABLE
            #ifndef USER_MODE_REG_PROT_ENABLED        
                #define USER_MODE_REG_PROT_ENABLED   (STD_ON)
            #endif
            #include "RegLockMacros.h"
        #endif
    #endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_C    2
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if(ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth_Enet.c and ETH.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eth_Enet.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Eth_Enet.c and Eth.h are different"
#endif
/* Check if current file and Eth_ENET_LLD header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION_ENET) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION_ENET) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION_ENET) \
    )
    #error "AutoSar Version Numbers of Eth_Enet.c and Eth_Enet.h are different"
#endif
/* Check if current file and Eth_ENET_LLD header file are of the same Software version */
#if( (ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION_ENET) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION_ENET) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION_ENET)    \
   )
    #error "Software Version Numbers of Eth_Enet.c and Eth_Enet.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros header file are of the same version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) ||   \
         (ETH_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION)      \
        )
        #error "AutoSar Version Numbers of Eth_Enet.c and StdRegMacros.h are different"
    #endif
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != ETHIF_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_C != ETHIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Fec.c and EthIf_Cbk.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15 */
#include "Eth_MemMap.h"
/**
 * @brief       Item definition of multicast MAC address pool.
 * @details     This structure define an entry of MAC address pool which
 *              allows reception of multiple MAC address defined in
 *              Eth_ENET_rMulticastPool array. Active parameter denote
 *              entries of MACAddress which will passed to receive
 *              callback function.
 */
typedef struct
{
    VAR(boolean, ETH_VAR) bActive;
    VAR(uint8, ETH_VAR) au8PhysAddr[6];
} Eth_Enet_McastPoolItem;

/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
*/
#include "Eth_MemMap.h"
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/**
* @brief   Generation polynomial value
* @details Value of generation polynomial register for CRC32 calculation.
*          Correspond to active elements of generation polynomial function
*          x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8
*          + x^7 + x^5 + x^4 + x^2 + x^1 + 1 written from right to left
*          without base element x^32.
*/
#define ETH_ENET_LLD_CRC32_POLYVAL 0xEDB88320U
/**
* @brief   Initial value of CRC32 calculation register
*/
#define ETH_ENET_LLD_CRC32_INITVAL 0xFFFFFFFFU

/**
* @brief   Size of one buffer descriptor in bytes
*/
#define ETH_ENET_LLD_BD_SIZE 32U

/**
* @brief Define the number of stats will be read
*/
#define ETH_ENET_NUMBEROFETHERSTAT   17U
#define ETH_ENET_MAXERRORCHECKS      8U
#define ETH_ENET_MAX_DROPLIST        14U

/* RX Frame status bits - frame reception mode */
#define ETH_ENET_RXF_PROMISCUOUS     0x01000000U /* Frame received in promiscuous
                           mode (would not be received if not promiscuous) */
#define ETH_ENET_RXF_BROADCAST       0x00800000U /* Frame received as broadcast */
#define ETH_ENET_RXF_MULTICAST       0x00400000U /* Frame received as multicast but
                                                             not broadcast */
#define ETH_ENET_RXF_MODE_MASK       0x01C00000U /* Mask for previous bits */
/* RX Frame status bits - errors and failures notification */
#define ETH_ENET_RXF_LENGTH_ERROR    0x00200000U /* Frame longer than configured
                                                      maximum of RX buffer */
#define ETH_ENET_RXF_NONOCTET_ERROR  0x00100000U /* Non octet aligned frame */
#define ETH_ENET_RXF_CRC_ERROR       0x00040000U /* CRC error */
#define ETH_ENET_RXF_OVERFLOW_ERROR  0x00020000U /* FIFO overrun during reception */
#define ETH_ENET_RXF_TRUNCATED       0x00010000U /* Frame had been longer than 2047B
                                               and therefore was truncated */
#define ETH_ENET_RXF_MAC_ERROR       0x80000000U /* MAC Error
                                                   (CRC, length error, etc.) */
#define ETH_ENET_RXF_PHY_ERROR       0x04000000U /* Invalid frame received, PHY Error */
#define ETH_ENET_RXF_COLLISION       0x02000000U /* Collision detected at reception */
#define ETH_ENET_RXF_ERRORS_MASK     0x86370000U /* Mask for previous bits */


#define ETH_ENET_RXF_VLAN_PRIORITY   0x0000E000U /* VLAN Priority Code Point */
#define ETH_ENET_RXF_VLAN_DETECTED   0x00000004U /* Received frame has a VLAN tag */
#define ETH_ENET_RXF_IP_HEADER_ERROR 0x00000020U /* IP header checksum error
                                               - bit is set for non IP
                                                 frames and for IP frames
                                                 with invalid header CRC */

#define ETH_ENET_RXF_PROTO_CRC_ERORR 0x00000010U /* Protocol CRC Error */
#define ETH_ENET_RXF_IPV6_FRAME      0x00000002U /* IPV6 Frame received */
#define ETH_ENET_RXF_IPV4_FRAGMENT   0x00000001U /* IPV4 Fragment */


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ETH_START_SEC_CONST_32
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/**
* @details Store Base Address of controller which is in used
*/
static CONST(uint32, ETH_VAR) Eth_u32BaseAddr[ETH_MAXCTRLS_SUPPORTED] =
{
#ifdef ENET_0_BASEADDR
    (VAR(uint32, AUTOMATIC))ENET_0_BASEADDR,
#else
    #error There must be at always least one controller but the base address not defined (plugin inconsistency)
#endif
#if ETH_MAXCTRLS_SUPPORTED > 1U
  #ifdef ENET_1_BASEADDR
    (VAR(uint32, AUTOMATIC))ENET_1_BASEADDR
  #else     
    #error The base address for the second controller is not configured (plugin inconsistency)
  #endif
#endif
/* Additional controllers may be added here */

};
#define ETH_STOP_SEC_CONST_32
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#define ETH_START_SEC_CONST_16
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#if STD_ON == ETH_GET_ETHERSTATS_API
/**
* @brief List of Address for checking EtherStats
*/
/** @violates @ref Eth_Enet_c_REF_12 MISRA rule 8.7 */
static CONST(uint16, ETH_CONST) u16EtherStatsArray[] =   { \
                                ENET_IEEE_R_DROP_ADDR16, \
                                ENET_RMON_R_OCTETS_ADDR16, \
                                ENET_RMON_R_PACKETS_ADDR16, \
                                ENET_RMON_R_BC_PKT_ADDR16, \
                                ENET_RMON_R_MC_PKT_ADDR16, \
                                ENET_RMON_R_CRC_ALIGN_ADDR16, \
                                ENET_RMON_R_UNDERSIZE_ADDR16, \
                                ENET_RMON_R_OVERSIZE_ADDR16, \
                                ENET_RMON_R_FRAG_ADDR16, \
                                ENET_RMON_R_JAB_ADDR16, \
                                ENET_RMON_T_COL_ADDR16, \
                                ENET_RMON_R_P64_ADDR16, \
                                ENET_RMON_R_P65TO127_ADDR16, \
                                ENET_RMON_R_P128TO255_ADDR16, \
                                ENET_RMON_R_P256TO511_ADDR16, \
                                ENET_RMON_R_P512TO1023_ADDR16, \
                                ENET_RMON_R_P1024TO2047_ADDR16 \
                                                    };
#endif

#if STD_ON == ETH_GETDROPCOUNTAPI
/**
* @brief List of Dropcounts
*/
/** @violates @ref Eth_Enet_c_REF_12 MISRA rule 8.7 */
static CONST(uint16, ETH_CONST) u16DropCountArray[] =  { \
                                ENET_IEEE_R_MACERR_ADDR16, \
                                ENET_IEEE_R_CRC_ADDR16, \
                                ENET_RMON_R_UNDERSIZE_ADDR16, \
                                ENET_RMON_R_OVERSIZE_ADDR16, \
                                ENET_RMON_R_CRC_ALIGN_ADDR16, \
                                ENET_IEEE_T_SQE_ADDR16, \
                                ENET_IEEE_R_MACERR_ADDR16, \
                                ENET_IEEE_R_DROP_ADDR16, \
                                0xFFFFU, \
                                ENET_RMON_T_DROP_ADDR16, \
                                ENET_IEEE_T_1COL_ADDR16, \
                                ENET_IEEE_T_MCOL_ADDR16, \
                                ENET_IEEE_T_DEF_ADDR16, \
                                ENET_IEEE_T_LCOL_ADDR16, \
                                0XFFFFU \
                                                };
#endif

#define ETH_STOP_SEC_CONST_16
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ETH_START_SEC_VAR_INIT_BOOLEAN
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#ifdef ERR_IPV_ENET_0001
  #if STD_ON == ERR_IPV_ENET_0001
    /**
    * @details Signals whether a TDAR write is needed as workaround
    *          for the errata 6358.
    */
    static VAR(boolean, ETH_VAR) Eth_ENET_bMoreDataForTx[ETH_MAXCTRLS_SUPPORTED] = {(VAR(boolean, AUTOMATIC))FALSE};
  #endif /* STD_ON == ERR_IPV_ENET_0001 */
#endif /* ERR_IPV_ENET_0001 */

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    /**
    * @brief        Variable indicating multicast pool overflow
    * @details      Any time whenever count of active items in
    *               Eth_ENET_rMulticastPool could be greater than
    *               ETH_MULTICAST_POOL_SIZE this variable is set to TRUE
    *               and keeps TRUE until Eth_ControllerInit is called.
    */
    static VAR(boolean, ETH_VAR) Eth_ENET_bMcastPoolOvf[ETH_MAXCTRLS_SUPPORTED] = {(VAR(boolean, AUTOMATIC))FALSE};

    /**
    * @brief        Multicast filter OPEN for all frames
    * @details      Multicast filtering is disabled and ALL frames are received.
    *               Means that all bytes of GAUR/GALR registers
    *               are set to 0xff and multicast filtering accept all frames
    *               at reception if the value is TRUE.
    */
    static VAR(boolean, ETH_VAR) Eth_ENET_bMcastFullOpen[ETH_MAXCTRLS_SUPPORTED] = {(VAR(boolean, AUTOMATIC))FALSE};
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#define ETH_STOP_SEC_VAR_INIT_BOOLEAN
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT_16
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER

    /**
    * @brief          Number of active items inside multicast filter pool
    * @details        This variable is incremented with each added item to pool
    *                 and decremented with remove. Value is set to zero at pool
    *                 clean function.
    */
    static VAR(uint16, ETH_VAR) Eth_ENET_u16McastItemsCnt[ETH_MAXCTRLS_SUPPORTED] = {0U};

#endif  /* ETH_UPDATE_PHYS_ADDR_FILTER */
/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
#define ETH_STOP_SEC_VAR_INIT_16
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_INIT_32
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/**
* @brief    Address of Tx buffers ring start
* @details  Used for optimization of buffer address computation.
*           It is initialized during TX buffers initialization.
*/
static VAR(uint32, ETH_VAR) Eth_ENET_u32TxBufStartAddr[ETH_MAXCTRLS_SUPPORTED]={0U};

/**
* @brief    Address of Tx buffers ring start
* @details  Used for optimization of buffer address computation.
*           It is initialized during TX buffers initialization.
*/
static VAR(uint32, ETH_VAR) Eth_ENET_u32RxBufStartAddr[ETH_MAXCTRLS_SUPPORTED]={0U};


/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
#define ETH_STOP_SEC_VAR_INIT_32
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_INIT_8
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/**
* @brief        Index of buffer where to continue search for free buffers
* @details      This variable is used to reduce buffer memory fragmentation.
*               Algorithm tries to allocate new buffers right after previously
*               allocated buffers.
*/
static VAR(uint8, ETH_VAR) Eth_ENET_u8SearchTxBufFrom[ETH_MAXCTRLS_SUPPORTED] = {0U};
/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_INIT_8
/**
* @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

/**
* @brief        Array of references to BD for each buffer.
* @details      Use buffer index for indexing this array.
*               It contains index of buffer descriptor this buffer belongs to.
*               The value is valid only if at least this flags are set on the
*               buffer: ENET_TXB_LOCK_U8 | ENET_TXB_LINK_U8 | ENET_TXB_FIRST_U8.
*               Otherwise the buffer is not linked with any BD or is not first
*               buffer of frame. */
static VAR(uint8, ETH_VAR) Eth_au8TxBdOfBuf[ETH_MAXCTRLS_SUPPORTED][ETHTXBUFNUM];

/**
* @brief        An array containing buffer flags.
* @details      Use buffer index for indexing this array.
*               It contains 4 flags for each buffer:
*               TXB_LOCK 8, TXB_CONF 4, TXB_LINK 2, TXB_FIRST 1 */
static VAR(volatile uint8, ETH_VAR) Eth_au8TxBufFlags[ETH_MAXCTRLS_SUPPORTED][ETHTXBUFNUM];

#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    /**
    * @brief        Number of buffers allocated together for one frame
    * @details      Use buffer index for indexing this array.
    *               Value is valid only if at least following flags are set on the
    *               buffer: ENET_TXB_LOCK_U8 | ENET_TXB_FIRST_U8
    */
/** @violates @ref Eth_Enet_c_REF_12 MISRA rule 8.7 */
static VAR(uint8, ETH_VAR) Eth_ENET_au8TxBufGroup[ETH_MAXCTRLS_SUPPORTED][ETHTXBUFNUM];
#endif /* STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES */

/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
#define ETH_STOP_SEC_VAR_NO_INIT_8
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    /**
     * @brief        Pool multicast MAC address
     * @details      This is an array of structure of allowed MAC address
     *               for multicast frame reception.
     */
static VAR(Eth_Enet_McastPoolItem, ETH_VAR) Eth_ENET_rMulticastPool[ETH_MAXCTRLS_SUPPORTED][ETH_MULTICAST_POOL_SIZE] = \
    {{ {(VAR(boolean, AUTOMATIC))FALSE, {0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U}} }};

#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_START_SEC_VAR_INIT_8
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/**
* @brief          Active receive buffer descriptor index
* @details        This variable contains number of the buffer descriptor which
*                 will be used  for the first reception from the time of the
*                 last call of the receive function.
* @implements     Eth_u8ActiveRxBuf_Object
* @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 
*/
VAR(volatile uint8, ETH_VAR) Eth_u8ActiveRxBuf[ETH_MAXCTRLS_SUPPORTED] = {0U};

/**
* @brief          Active transmit buffer descriptor index
* @details        This variable contains index of the buffer descriptor which
*                 will be used for transmission after the TDAR register is
*                 written.
* @implements     Eth_u8ActiveTxBD_Object
* @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 
*/
VAR(volatile uint8, ETH_VAR) Eth_u8ActiveTxBD[ETH_MAXCTRLS_SUPPORTED] = {0U};

/**
* @brief          DA locked because it is being confirmed
* @details        This variable is used to store the DA number of the currently
*                 being confirmed buffer. It then prevents providing the same
*                 buffer if the confirmation function is interrupted by the
*                 Eth_ProvideTxBuffer.
*/
/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
VAR(uint8, ETH_VAR) Eth_u8LockedBuffer[ETH_MAXCTRLS_SUPPORTED] = {0U};


/**
* @brief          Counter of the locked TX buffers
* @details        This variable is incremented with each buffer to be confirmed
*                 transmission and decremented by confirmation of such buffer
*                 thus it holds number of the buffers to be confirmed. It is
*                 used for optimization of the buffers search algorithm.
*/
/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
VAR(uint8, ETH_VAR) Eth_u8LockedTxBufCount[ETH_MAXCTRLS_SUPPORTED] = {0U};

#define ETH_STOP_SEC_VAR_INIT_8
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT_BOOLEAN
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/**
* @brief          LockedBuffer variable usage flag.
* @details        If this variable is set to FALSE then the value in the
*                 variable LockedBuffer is invalid and shall not be used.
*/
/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
VAR(boolean, ETH_VAR) Eth_bLockedBufferUsed[ETH_MAXCTRLS_SUPPORTED] = {(VAR(boolean, ETH_VAR))FALSE};

#define ETH_STOP_SEC_VAR_INIT_BOOLEAN
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/**
* @brief          Used for internal storage of configuration pointer
* @details        This variable is used to store the pointer to the instance
*                 of the Eth_ConfigType containing the configuration parameter,
*                 which is passed to the Eth_Init function, for the subsequent
*                 accesses.
*
* @note           This variable exists only if the Pre-Compile variant is not
*                 selected.
*
*/
    /** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
    P2CONST(Eth_ConfigType, ETH_VAR, ETH_APPL_CONST) Eth_InternalCfgPtr = NULL_PTR;

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
/**
* @brief          Used for internal storage of local time
* @details        This variable is used to store the value for current time including 48 bits for second 
*                 and 32 bits for nanosecond part. 
*
* @note           This variable exists only if the the time stamp is used.
*
*/
VAR(Eth_TimeStampType, ETH_VAR) Eth_LocalTime[ETH_MAXCTRLS_SUPPORTED] = {{0U,0U,0U}};
#endif

/** @violates @ref Eth_Enet_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Enet_c_REF_18 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_START_SEC_CODE
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/* General memory access functions */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_Write16TxBufMem  ( \
                    CONST(uint32, AUTOMATIC) u32Base, \
                    CONST(uint32, AUTOMATIC) u8BufIdx, \
                    CONST(uint16, AUTOMATIC) u16Data \
                                                            );
/* CRC functions */
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
static FUNC(uint32, ETH_CODE) Eth_Enet_GetCRC32Hash ( \
                       CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pData, \
                       VAR(uint32, AUTOMATIC) u32Length \
                                                    );
static FUNC(boolean, ETH_CODE) Eth_Enet_ComparePhysAddr ( \
                       CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhyAddrA, \
                       CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhyAddrB \
                                                        );
static FUNC(boolean, ETH_CODE) Eth_Enet_IsAddrInMcastPool ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
                CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pPoolItemIdx \
                                                          );
static FUNC(boolean, ETH_CODE) Eth_Enet_McastPoolAddItem ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                         );
static FUNC(boolean, ETH_CODE) Eth_Enet_McastPoolRmvItem  ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                          );
static FUNC(void, ETH_CODE) Eth_Enet_McastPoolClean (CONST(uint8, AUTOMATIC) u8CtrlIdx);
static FUNC(void, ETH_CODE) Eth_Enet_McastGAAdd ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONSTP2CONST (uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                );
static FUNC(void, ETH_CODE) Eth_Enet_McastGARecalculate (CONST(uint8, AUTOMATIC) u8CtrlIdx);
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_McastGAClean (CONST(uint8, AUTOMATIC) u8CtrlIdx);
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
/* RX buffer descriptor WRITE functions */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteRxBDBitsA   ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum, \
                CONST(uint32, AUTOMATIC) u32Data \
                                                            );
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteRxBDBufPtr  ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum, \
                CONST(uint32, AUTOMATIC) u32Data \
                                                            );
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteRxBDBitsB   ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum, \
                CONST(uint32, AUTOMATIC) u32Data \
                                                            );
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteTxBDBitsB   ( \
                                    CONST(uint32, AUTOMATIC) u32Base, \
                                    CONST(uint8, AUTOMATIC) u8BufNum, \
                                    CONST(uint32, AUTOMATIC) u32Data \
                                                            );
/* TX buffer descriptor WRITE functions */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteTxBDBufPtr  ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum, \
                CONST(uint32, AUTOMATIC) u32Data \
                                                            );
/* RX buffer descriptor READ functions */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadRxBDBitsA  ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum \
                                                            );
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadRxBDBitsB  ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum \
                                                            );
#if STD_ON == ETH_GLOBALTIME_SUPPORT
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadTxBDBitsB  ( \
                CONST(uint32, AUTOMATIC) u32Base, \
                CONST(uint8, AUTOMATIC) u8BufNum \
                                                            );
#endif
/*Compute Tx_BufAddr*/
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ComputeTxBufAddr   ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONST(uint8, AUTOMATIC) u8BufIdx \
                                                                );
/*Compute Rx_BufAddr*/
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ComputeRxBufAddr   ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONST(uint8, AUTOMATIC) u8BufIdx \
                                                                );
#if STD_ON == ETH_GLOBALTIME_SUPPORT
/* Get timer value, nanoseconds part of timestamps */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadTimerValue ( CONST(uint8, AUTOMATIC) u8CtrlIdx);
/* Set timer value, nanoseconds part of timestamps */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_SetTimerValue ( \
                                                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                                    CONST(uint32, AUTOMATIC) u32TimerValue \
                                                          );
/* Correct the frequency ratio */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_CorrectRate ( \
                                                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                                    CONST(uint32, AUTOMATIC) u32CorrectCycle, \
                                                    CONST(uint8, AUTOMATIC) u8CorrectValue \
                                                          );

/* Get the timestamp from TxBD */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadTxBDTimestampPtr ( \
                                                    CONST(uint32, AUTOMATIC) u32BdAddress, \
                                                    CONST(uint8, AUTOMATIC) u8BufIdx \
                                                          );
/* Get the timestamp from RxBD */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadRxBDTimestampPtr ( \
                                                    CONST(uint32, AUTOMATIC) u32BdAddress, \
                                                    CONST(uint8, AUTOMATIC) u8BufIdx \
                                                          );
/* Do sint64 division */
static FUNC(sint64, ETH_CODE) Eth_Enet_Divsint64(sint64 s64Nume, sint64 s64Deno);
#endif
#if(STD_ON == ETH_DEM_EVENT_DETECT)
static FUNC(void, ETH_CODE) Eth_Enet_CheckDemStatus ( \
                            VAR(uint32, AUTOMATIC) u32Addr, \
                            VAR(uint32, AUTOMATIC) u32DemConfig, \
                            VAR(uint16, AUTOMATIC)DemId \
                                                    );
#endif

/* Endian agnostic supported functions */
static FUNC(uint16, ETH_CODE) Eth_Enet_Htons(CONST(uint16, AUTOMATIC) u16HostShort);

static FUNC(void, ETH_CODE)Eth_Enet_ClearRxBuffer ( \
                        CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                        CONST(uint8, AUTOMATIC) u8Buf \
                                                  );
static FUNC(void, ETH_CODE) Eth_Enet_GetRxBufferData ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONST(uint8, AUTOMATIC) u8Buf, \
                    CONST(uint8, AUTOMATIC) u8MultiEnd, \
                    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pLength, \
                    P2P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) pDataPtr, \
                    CONSTP2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pStatusPtr \
                                                     );
static FUNC(Eth_Enet_enRxBufferType, ETH_CODE) Eth_Enet_GetRxBufferType ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONST(uint8, AUTOMATIC) u8Buf, \
                    CONST(uint8, AUTOMATIC) u8BufCtrMax, \
                    CONSTP2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pMultiEnd \
                                                                            );

static FUNC(void, ETH_CODE) Eth_Enet_GiveBackTxBuffer ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    VAR(uint8, AUTOMATIC) u8Buf
                                                      );
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    static FUNC(boolean, ETH_CODE) Eth_Enet_IsPhysAddrAllowed   ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                                );
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
static FUNC(void, ETH_CODE) Eth_Enet_WriteTxBDBitsA ( \
                 CONST(uint32, AUTOMATIC) u32Base, \
                 CONST(uint8, AUTOMATIC) u8BufNum, \
                 CONST(uint32, AUTOMATIC) u32Data \
                                                    );
static FUNC(uint32, ETH_CODE) Eth_Enet_ReadTxBDBitsA    ( \
                        CONST(uint32, AUTOMATIC) u32Base, \
                        CONST(uint8, AUTOMATIC) u8BufNum \
                                                        );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
/**
 * @brief       Calculation of CRC32 hash
 * @details     This function calculates a CRC32 checksum of data of specified
 *              length.
 * @param[in]   pData Pointer to data array of bytes which CRC checksum has
 *              to be calculated.
 * @param[in]   u32Length Specifies the number of bytes of data array.
 * @return      CRC32 checksum.
 */
static FUNC(uint32, ETH_CODE) Eth_Enet_GetCRC32Hash ( \
                                CONSTP2CONST(uint8, AUTOMATIC, ETH_VAR) pData, \
                                VAR(uint32, AUTOMATIC) u32Length \
                                                    )
{
    VAR(uint32, AUTOMATIC) u32CRC32Hash;    /* CRC hash output register */
    VAR(uint32, AUTOMATIC) u32CRC32ByteIdx; /* Index of data byte */
    VAR(uint8, AUTOMATIC) u8CRC32BitIdx;    /* Index of bit inside
                                               CRC32 calculated byte */

    u32CRC32Hash = ETH_ENET_LLD_CRC32_INITVAL;
    /* Loop over all bytes */
    for(u32CRC32ByteIdx = 0U; u32CRC32ByteIdx < u32Length; u32CRC32ByteIdx++)
    {
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32CRC32Hash ^= *(pData + u32CRC32ByteIdx);
        /* Loop over bits */
        for(u8CRC32BitIdx = 0U; 8U > u8CRC32BitIdx; u8CRC32BitIdx++)
        {
            u32CRC32Hash = (u32CRC32Hash >> 1) ^ ((~(u32CRC32Hash & 0x1U) + 0x1U) & ETH_ENET_LLD_CRC32_POLYVAL);
        }
    }
    return u32CRC32Hash;
}

/**
 * @brief       Compare two input physical addresses
 * @details     This function compares physical address pPhyAddrA
 *              against pPhyAddrB. In case that addresses match the TRUE
 *              is returned and FALSE otherwise.
 * @param[in]   pPhyAddrA Pointer to the first physical address array.
 * @param[in]   pPhyAddrB Pointer to the second physical address array.
 * @caution     Length of physical address is restricted to 6B!
 * @return      TRUE - addresses matches
 *              FALSE - otherwise
 */
static FUNC(boolean, ETH_CODE) Eth_Enet_ComparePhysAddr ( \
                       CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhyAddrA, \
                       CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhyAddrB \
                                                        )
{
    /* Return variable */
    VAR(boolean, ETH_VAR) bReturn = (VAR(boolean, ETH_VAR))TRUE;
    VAR(uint8, AUTOMATIC) u8Count;
    
    for (u8Count=0U; u8Count<6U; u8Count++)
    {
        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        if (pPhyAddrA[u8Count] != pPhyAddrB[u8Count])
        { 
            /* Addresses are the same */
            bReturn = (VAR(boolean, ETH_VAR))FALSE;
            break;
        }
    }
    return bReturn;
}

/**
 * @brief       Add item into multicast pool
 * @details     This function checks if the added address is not already in the
 *              pool and if not add it.
 * @note        This function does not take care about overflow flag.
 * @param[in]   u8CtrlIdx Index of controller which will be added item
 * @param[in]   pPhysAddrPtr Pointer to Physical address which shall be
 *              added
 * @return      TRUE - item/addresses was added successfully or item is already
 *                     in the table
 *              FALSE - table is full
 */
static FUNC(boolean, ETH_CODE) Eth_Enet_McastPoolAddItem ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                         )
{
    /* Temporary return variable / Matching entry found */
    VAR(boolean, AUTOMATIC) bReturnVariable = (VAR(boolean, AUTOMATIC))FALSE;
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) u16PoolIdx = 0U;
    VAR(uint8, AUTOMATIC) u8Count = 0U;

    /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
    if ((VAR(boolean, AUTOMATIC))TRUE == Eth_Enet_IsAddrInMcastPool(u8CtrlIdx, pPhysAddrPtr, &u16PoolIdx))
    { /* Item already in the table */
        bReturnVariable = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    { /* Item is not in the table - Look for empty position*/
        while (ETH_MULTICAST_POOL_SIZE > u16PoolIdx)
        { /* Loop over table items */
            if ((VAR(boolean, AUTOMATIC))FALSE == Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].bActive)
            { /* First empty item in table */
                /* Mark found item as used - active */
                Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].bActive = (VAR(boolean, AUTOMATIC))TRUE;
                for (u8Count=0U;u8Count<6U;u8Count++)
                {
                    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
                    Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].au8PhysAddr[u8Count]=pPhysAddrPtr[u8Count];
                }
                /* Increment the count of used items */
                Eth_ENET_u16McastItemsCnt[u8CtrlIdx]++;
                /* Set return variable */
                bReturnVariable = (VAR(boolean, AUTOMATIC))TRUE;
                break;
            } /* Active item check */
            u16PoolIdx++;
        } /* Items loop */
    } /* Table check */
    return bReturnVariable;
}

/**
* @brief         Remove the physical address from the pool.
* @details       This function goes over multicast pool and is checking
*                if the specified physical address is located and activated
*                in the multicast pool.
* @param[in]     u8CtrlIdx Index of controller in which item will be removed
* @param[in]     pPhysAddrPtr Pointer to physical address which shall be
*                removed
* @note          This function does not take care about overflow flag.
* @return        TRUE - address was removed from the pool
*                FALSE - address was not found in the pool
*/
static FUNC(boolean, ETH_CODE) Eth_Enet_McastPoolRmvItem ( \
                                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                         )
{
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) u16PoolIdx = 0U;
    /* Return variable */
    VAR(boolean, AUTOMATIC) bReturnVariable;

    /* Look for item in the table */
    /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
    if ((VAR(boolean, AUTOMATIC))TRUE ==  Eth_Enet_IsAddrInMcastPool(u8CtrlIdx, pPhysAddrPtr, &u16PoolIdx))
    { /* Item was found in the table at position u16PoolIdx */
        /* Deactivate it */
        Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].bActive = (VAR(boolean, AUTOMATIC))FALSE;
        /* Decrement count of used pool items */
        Eth_ENET_u16McastItemsCnt[u8CtrlIdx]--;
        /* Set return variable */
        bReturnVariable = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    { /* Item is not in the table */
        bReturnVariable = (VAR(boolean, AUTOMATIC))FALSE;
    }
    return bReturnVariable;
}

/**
* @brief         Check whenever the specified physical address is in
*                multicast pool.
* @details       This function goes over multicast pool and is checking
*                if the specified physical address is located and activated
*                in the multicast pool.
* @param[in]     u8CtrlIdx Index of controller in which the address will be checked
* @param[in]     pPhysAddrPtr This parameter is a pointer at tested
*                physical address.
* @param[out]    pPoolItemIdx Index of found Eth_ENET_rMulticastPool
*                item. This value is valid only if TRUE is returned.
* @return        TRUE - address is in the pool and active
*                FALSE - address is not in the pool
*/
static FUNC(boolean, ETH_CODE) Eth_Enet_IsAddrInMcastPool   ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
                CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pPoolItemIdx \
                                                            )
{
    /* Temporary return variable / Matching entry found */
    VAR(boolean, AUTOMATIC) bAddressFound = (VAR(boolean, AUTOMATIC))FALSE;
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) u16PoolIdx = 0U;
    /* Used for counting of found active items in loop */
    VAR(uint16, AUTOMATIC) u16TmpActiveFound = 0U;

    /* Loop over multicast pool */
    while( (ETH_MULTICAST_POOL_SIZE > u16PoolIdx) && (u16TmpActiveFound !=  Eth_ENET_u16McastItemsCnt[u8CtrlIdx]) )
    {
        /* Filter only active entries */
        if((VAR(boolean, AUTOMATIC))TRUE == Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].bActive)
        { /* Item is active */
            if ((VAR(boolean, AUTOMATIC))TRUE == Eth_Enet_ComparePhysAddr(pPhysAddrPtr, Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].au8PhysAddr))
            { /* Item matches with requested */
                bAddressFound = (VAR(boolean, AUTOMATIC))TRUE;
                *pPoolItemIdx = u16PoolIdx;
                break;
            }
            u16TmpActiveFound++;
        }
        u16PoolIdx++;
    }
    return bAddressFound;
}

/**
* @brief         Wipe all items of the pool.
* @details       This function goes over all items in the pool and sets
*                the active flag to FALSE
* @param[in]     u8CtrlIdx Index of controller which will be cleaned
* @note          This function does not take care about pool overflow
*/
static FUNC(void, ETH_CODE) Eth_Enet_McastPoolClean (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) u16PoolIdx = 0U;

    while (ETH_MULTICAST_POOL_SIZE > u16PoolIdx)
    {
        Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].bActive = (VAR(boolean, AUTOMATIC))FALSE;
        u16PoolIdx++;
    }
    Eth_ENET_u16McastItemsCnt[u8CtrlIdx] = 0U;
}

/**
* @brief         Enables Group Address reception for requested Physical Address
* @details       This function decides which register of GAUR/GALR is affected
*                and sets related bit for requested Physical Address reception
*                enablement.
* @param[in]     u8CtrlIdx Index of controller which will be updated GAA
* @param[in]     pPhysAddrPtr Pointer to Physical Address which group
*                shall be enabled.
*/
static FUNC(void, ETH_CODE) Eth_Enet_McastGAAdd (CONST(uint8, AUTOMATIC) u8CtrlIdx, CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr)
{
    /* Storage of CRC32 hash of Physical Address */
    VAR(uint32,AUTOMATIC) u32TmpCRC32Hash;
    /* Manipulation variable */
    VAR(uint32,AUTOMATIC) u32ManipulationVar;

    /* Once pool overflow was detected the recalculation of
    * the GAUR/GALR registers can not be used anymore.
    * Only new group reception bit can be enabled. */
    /* Calculate CRC32 hash */
    u32TmpCRC32Hash = Eth_Enet_GetCRC32Hash(pPhysAddrPtr, 6U);
    /* Estimate address group number
    * NOTE: Destination hash group is in GAUR/GALR register
    *       Group number is in six most significant bits
    *       in CRC32MacHash without MSB which decide about
    *       GAUR/GALR
    */
    if(1U == (u32TmpCRC32Hash >> 31U))
    { /* Address is in group located in GAUR register */
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        u32ManipulationVar = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GAUR_ADDR16);
        u32ManipulationVar |= (((VAR(uint32,AUTOMATIC))1U << ((u32TmpCRC32Hash >> 26U) & (VAR(uint32,AUTOMATIC))0x1FU)));
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GAUR_ADDR16, u32ManipulationVar);
    }
    else
    { /* Address is in group located in GALR register */
         /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
             @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        u32ManipulationVar = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GALR_ADDR16);
        u32ManipulationVar |= (((VAR(uint32,AUTOMATIC))1U << ((u32TmpCRC32Hash >> 26U) & (VAR(uint32,AUTOMATIC))0x1FU)));
         /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
             @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GALR_ADDR16, u32ManipulationVar);
    }
}

/**
* @brief         Recalculates and updates the values of GALR/GAUR registers.
* @details       This function goes over active multicast pool items
*                and calculates the values of GAUR/GALR registers.
* @param[in]     u8CtrlIdx Index of controller in which GA will be recalculated
*/
static FUNC(void, ETH_CODE) Eth_Enet_McastGARecalculate (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /* Used for counting of found active items in loop */
    VAR(uint16, AUTOMATIC) u16TmpActiveFound = 0U;
    /* Temporary storage of CRC32 hash  */
    VAR(uint32, AUTOMATIC) u32TmpCRC32Hash;
    /* Used for calculation of value for ENET_GALR_ADDR16 register */
    VAR(uint32, AUTOMATIC) u32TmpGALR = 0U;
    /* Used for calculation of value for ENET_GAUR_ADDR16 register */
    VAR(uint32, AUTOMATIC) u32TmpGAUR = 0U;
    /* Current item index */
    VAR(uint16, AUTOMATIC) u16PoolIdx = 0U;

    while ( (ETH_MULTICAST_POOL_SIZE > u16PoolIdx) && (u16TmpActiveFound != Eth_ENET_u16McastItemsCnt[u8CtrlIdx]) )
    { /* Go over pool till ends or all active items were processed  */
        if ((VAR(boolean, AUTOMATIC))TRUE == Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].bActive)
        { /* Filter only active items */
            /* Calculate CRC32 hash */
            u32TmpCRC32Hash = Eth_Enet_GetCRC32Hash(Eth_ENET_rMulticastPool[u8CtrlIdx][u16PoolIdx].au8PhysAddr, 6U);
            /* Estimate address group number
             * NOTE: Destination hash group is in GAUR/GALR register
             *       Group number is in six most significant bits
             *       in CRC32MacHash without MSB which decide about
             *       GAUR/GALR
             */
            if(1U == (u32TmpCRC32Hash >> 31U))
            { /* Address is in group located in GAUR register */
                u32TmpGAUR |= (((VAR(uint32,AUTOMATIC))1U << ((u32TmpCRC32Hash >> 26U) & (VAR(uint32,AUTOMATIC))0x1FU)));
            }
            else
            { /* Address is in group located in GALR register */
                u32TmpGALR |= (((VAR(uint32,AUTOMATIC))1UL << ((u32TmpCRC32Hash >> 26U) & (VAR(uint32,AUTOMATIC))0x1FU)));
            }
            u16TmpActiveFound++;
        }
        u16PoolIdx++;
    }
    /* Write GAUR register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GAUR_ADDR16, u32TmpGAUR);
    /* Write GALR register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GALR_ADDR16, u32TmpGALR);
}

/**
* @brief         Clean GALR/GAUR registers.
* @details       This function disable reception of all multicast address groups
*                by seting of 0x00U to GAUR and GALR registers.
* @param[in]     u8CtrlIdx Index of controller in which GA will be cleaned
*/
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_McastGAClean (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /* Clear group address upper register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GAUR_ADDR16, 0U);
    /* Clear group address lower register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GALR_ADDR16, 0U);
}


#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

/* Access to the buffer descriptor status bits, the data pointer and the timestamp: */
/*================================================================================================*/
/**
* @brief          Writes the Receive buffer descriptor status bits.
* @details        32 bit long value containing status bits in upper 16 bits and
*                 buffer length in lower 16 bits is written into the given
*                 buffer descriptor.
* @param[in]      u32Base Starting address of the Receive buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be written
* @param[in]      u32Data Status bits and buffer length to be written into
*                 the descriptor
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteRxBDBitsA   ( \
                                CONST(uint32, AUTOMATIC) u32Base, \
                                CONST(uint8, AUTOMATIC) u8BufNum, \
                                CONST(uint32, AUTOMATIC) u32Data \
                                                            )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA))(u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE))) = u32Data;
}

/*================================================================================================*/
/**
* @brief          Writes the second bank of Receive buffer descriptor status bits.
* @param[in]      u32Base Starting address of the Receive buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be written
* @param[in]      u32Data Data to be written into the descriptor at 8B offset
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteRxBDBitsB   ( \
                                CONST(uint32, AUTOMATIC) u32Base, \
                                CONST(uint8, AUTOMATIC) u8BufNum, \
                                CONST(uint32, AUTOMATIC) u32Data \
                                                            )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA))(u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))32U) + 8U)) = u32Data;
}

/*================================================================================================*/
/**
* @brief          Writes a data buffer address into the Receive buffer
*                 descriptor pointer.
* @param[in]      u32Base Starting address of the Receive buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be written
* @param[in]      u32Data Address to be written into the buffer pointer.
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteRxBDBufPtr  ( \
                                CONST(uint32, AUTOMATIC) u32Base, \
                                CONST(uint8, AUTOMATIC) u8BufNum, \
                                CONST(uint32, AUTOMATIC) u32Data \
                                                            )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE) + 4U)) = u32Data;
}

/*================================================================================================*/
/**
* @brief          Writes the second bank of Transmit buffer descriptor status bits.
* @param[in]      u32Base Starting address of the Transmit buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be written
* @param[in]      u32Data Data to be written into the descriptor at offset 8B
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteTxBDBitsB   ( \
                                    CONST(uint32, AUTOMATIC) u32Base, \
                                    CONST(uint8, AUTOMATIC) u8BufNum, \
                                    CONST(uint32, AUTOMATIC) u32Data \
                                                            )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA))(u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))32U) + 8U)) = u32Data;
}

/*================================================================================================*/
/**
* @brief          Writes a data buffer address into the Transmit buffer
*                 descriptor pointer.
* @param[in]      u32Base Starting address of the Transmit buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be written
* @param[in]      u32Data Address to be written into the buffer pointer.
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_WriteTxBDBufPtr  ( \
                                CONST(uint32, AUTOMATIC) u32Base, \
                                CONST(uint8, AUTOMATIC) u8BufNum, \
                                CONST(uint32, AUTOMATIC) u32Data \
                                                            )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE) + 4U)) = u32Data;
}
/*================================================================================================*/
/**
* @brief          Reads the status bits from the Receive buffer descriptor
* @param[in]      u32Base Starting address of the Receive buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be read
* @return         Read status bits (upper 16 bits) and buffer length
*                 (lower 16 bits)
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadRxBDBitsA  (CONST(uint32, AUTOMATIC) u32Base, CONST(uint8, AUTOMATIC) u8BufNum)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE)));
}
/*================================================================================================*/
/**
* @brief          Reads the status bits from the Receive buffer descriptor
* @param[in]      u32Base Starting address of the Receive buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be read
* @return         Read status bits, third word of DB
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadRxBDBitsB (CONST(uint32, AUTOMATIC) u32Base, CONST(uint8, AUTOMATIC) u8BufNum)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE) + 8U));
}
#if STD_ON == ETH_GLOBALTIME_SUPPORT
/*================================================================================================*/
/**
* @brief          Reads the status bits from the Transmit buffer descriptor
* @param[in]      u32Base Starting address of the Transmit buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be read
* @return         Read status bits, third word of DB
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadTxBDBitsB (CONST(uint32, AUTOMATIC) u32Base, CONST(uint8, AUTOMATIC) u8BufNum)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE) + 8U));
}
#endif

/* Access to the buffer data functions: */
/*================================================================================================*/
/**
* @brief          Writes the 16 bit long data into the memory
* @details        This function abstracts the write access into the transmit
*                 buffer memory. The transmit buffer is identified by its
*                 beginning i.e. base address and the offset specifies where to
*                 write the data.
* @param[in]      u32Base Base address where to write
* @param[in]      u8BufIdx Offset to be added to base address before the write
* @param[in]      u16Data The 16 bit long data to be written into the buffer.
* @note           This function is an inline function. It is used to ensure
*                 aligned accesses into the buffer on all target platforms.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_Write16TxBufMem  ( \
                                CONST(uint32, AUTOMATIC) u32Base, \
                                CONST(uint32, AUTOMATIC) u8BufIdx, \
                                CONST(uint16, AUTOMATIC) u16Data \
                                                            )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint16, AUTOMATIC, ETH_APPL_DATA))(u32Base + (u8BufIdx))) = u16Data;
}


/*============================================================================*/
/**
* @brief        Compute address of TX buffer with given index
* @details      Type of the value of this macro is uint32
* @param[in]    u8CtrlIdx Index of controller we are working with
* @param[in]    u8BufIdx Index of buffer we need address of.
* @return       Address of beginning of given TX buffer.
*/
/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ComputeTxBufAddr   ( \
                                            CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                            CONST(uint8, AUTOMATIC) u8BufIdx \
                                                                )
{
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    return ( Eth_ENET_u32TxBufStartAddr[u8CtrlIdx] + ((VAR(uint32, AUTOMATIC))ETH_CFG_CTRLTXBUFLENBYTE( u8CtrlIdx) * u8BufIdx));
}

/*============================================================================*/
/**
* @brief        Compute address of RX buffer with given index
* @details      Type of the value of this macro is uint32
* @param[in]    u8CtrlIdx Index of controller we are working with
* @param[in]    u8BufIdx Index of buffer we need address of.
* @return       Address of beginning of given RX buffer.
*/
/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ComputeRxBufAddr   ( \
                                            CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                            CONST(uint8, AUTOMATIC) u8BufIdx \
                                                                )
{
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    return ( Eth_ENET_u32RxBufStartAddr[u8CtrlIdx] + ((VAR(uint32, AUTOMATIC))ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx) * u8BufIdx));
}

#if STD_ON == ETH_GLOBALTIME_SUPPORT
/*============================================================================*/
/**
* @brief        Read the current value of timer
* @details      Get the nanosecond part for timestamps
* @param[in]    u8CtrlIdx Index of controller we are reading
* @return       The current timestamps value.
*/
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadTimerValue ( CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32CaptValue;
    VAR(volatile uint32, AUTOMATIC) u32TimeOut;
    
    /* Issue the Capture command :
       - note that no Read-Modify-Write operation is needed for command writes
         (configuration fields will not be affected) */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */       
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCR_ADDR16, ENET_ATCR_CAPTURE_U32);
    /* Wait until the command execution is finished to avoid reading
       a value captured previously (if SW is fast enough) */
    u32TimeOut = 1000U;
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */       
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_15 MISRA rule 12.4 */
    while ((ENET_ATCR_CAPTURE_U32 == (REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCR_ADDR16) & ENET_ATCR_CAPTURE_U32) ) && (u32TimeOut > 0U))
    {
        u32TimeOut--;
    }
    /* Read the current time value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */       
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    u32CaptValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATVR_ADDR16);
    return u32CaptValue;
}

/*============================================================================*/
/**
* @brief        Set the current value to timer register
* @details      Set the nanosecond part of timestamps into register
* @param[in]    u8CtrlIdx Index of controller we are reading
* @param[in]    u32TimerValue The timer value used to write to register.
*/
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_SetTimerValue ( \
                                                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                                    CONST(uint32, AUTOMATIC) u32TimerValue \
                                                          )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */       
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATVR_ADDR16, u32TimerValue);
}
/*============================================================================*/
/**
* @brief        Correct the frequency rate to synchronize with grandmaster clock
* @details      Adjust local frequency to synchronize with grandmaster clock
* @param[in]    u8CtrlIdx Index of controller we are correcting
* @param[in]    u32CorrectCycle Period for correction.
* @param[in]    u8CorrectValue Value to be loaded at correct cycle
*/
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Enet_CorrectRate ( \
                                                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                                    CONST(uint32, AUTOMATIC) u32CorrectCycle, \
                                                    CONST(uint8, AUTOMATIC) u8CorrectValue \
                                                          )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */       
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCOR_ADDR16, u32CorrectCycle & ENET_ATCOR_COR_U32);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */       
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_RMW32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATINC_ADDR16, (VAR(uint32, AUTOMATIC))ENET_ATINC_INC_CORR_U32, ((VAR(uint32, AUTOMATIC))u8CorrectValue << (VAR(uint32, AUTOMATIC))8U) );
}

/*============================================================================*/
/**
* @brief        Readout the timestamp from specific TxBD
* @details      Readout the timestamp of transmit package from BD
* @param[in]    u8CtrlIdx Index of controller we are correcting
* @param[in]    u8BufIdx Index of transmit buffer to be read
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadTxBDTimestampPtr   ( \
                                                    CONST(uint32, AUTOMATIC) u32BdAddress, \
                                                    CONST(uint8, AUTOMATIC) u8BufIdx \
                                                                    )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32BdAddress + (u8BufIdx * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE) + ENET_TXBD_TS_ADDR16));
}
/*============================================================================*/
/**
* @brief        Readout the timestamp from specific TxBD
* @details      Readout the timestamp of received package from BD
* @param[in]    u8CtrlIdx Index of controller we are correcting
* @param[in]    u8BufIdx Index of received buffer to be read
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
LOCAL_INLINE FUNC(uint32, ETH_CODE) Eth_Enet_ReadRxBDTimestampPtr ( \
                                                    CONST(uint32, AUTOMATIC) u32BdAddress, \
                                                    CONST(uint8, AUTOMATIC) u8BufIdx \
                                                          )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32BdAddress + (u8BufIdx * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE) + ENET_RXBD_TS_ADDR16));
}
/*============================================================================*/
/**
@brief   Function to get the division of 64 bit signed integers.
@details This function returns the division value of 64 bit signed integers.
@param[in] s64Nume - Numerator
@param[in] s64Deno - Denominator
@return sint64 - division value of 64 bit signed integers.
*/
static FUNC(sint64, ETH_CODE) Eth_Enet_Divsint64(sint64 s64Nume, sint64 s64Deno)
{
    VAR(uint64, AUTOMATIC) u64Mask;
    VAR(uint64, AUTOMATIC) u64Temp;
    VAR(sint64, AUTOMATIC) s64RetNumeric;
    VAR(uint64, AUTOMATIC) u64TempReturn;
    VAR(uint64, AUTOMATIC) u64LocalDeno;
    VAR(uint64, AUTOMATIC) u64LocalNume;
    VAR(uint32, AUTOMATIC) u32TempDeno;
    VAR(uint8, AUTOMATIC)  u8Count = (uint8)0U;
    VAR(sint8, AUTOMATIC) s8TempSigned1 = (sint8)1;
    VAR(sint8, AUTOMATIC) s8TempSigned2 = (sint8)1;

    if (s64Nume < 0)
    {
        s8TempSigned1 = -1;
        /** @violates @ref Eth_Enet_c_REF_22 MISRA rule 10.3 */
        u64LocalNume = (VAR(uint64, AUTOMATIC))(-s64Nume);
    }
    else
    {
        u64LocalNume = (VAR(uint64, AUTOMATIC))s64Nume;
    }
        u64LocalDeno = (VAR(uint64, AUTOMATIC))s64Deno;   
        
    if (0ULL == u64LocalDeno) 
    {
        u64TempReturn = 0xFFFFFFFFFFFFFFFFULL;
    }
    else
    {
        if (0ULL == ((u64LocalDeno-1ULL) & u64LocalDeno))
        {
            /* Divide by power of 2. */
            u64TempReturn = u64LocalNume;
            if(0ULL == (u64LocalDeno & 0x00000000ffffffffULL))
            {
                u64LocalDeno >>= 32U;
                u64TempReturn >>= 32U;
            }
            u32TempDeno = (uint32)u64LocalDeno;
            if(0U == (u32TempDeno & 0xffffU))
            {
                u32TempDeno >>= 16U;
                u64TempReturn >>= 16U;
            }
            if(0U == (u32TempDeno & 0xffU))
            {
                u32TempDeno >>= 8U;
                u64TempReturn >>= 8U;
            }
            while (0U != (u32TempDeno >>= 1U))
            {
                u64TempReturn >>= 1U;
            }
        } 
        else
        {
            u64Temp = u64LocalNume | u64LocalDeno;
            if(0ULL == (u64Temp & 0xffffffff00000000ULL))
            {
                /** @violates @ref Eth_Enet_c_REF_22 MISRA rule 10.3 */
                u64TempReturn = (uint64)((uint32)u64LocalNume/(uint32)u64LocalDeno);
            }
            else
            {
                u64Mask = 0xff00000000000000ULL;
                while((0ULL == (u64Temp & u64Mask)) && (u8Count <3U))
                {
                    u64Mask >>= 8U;
                    u8Count++;
                }    
                u32TempDeno = 0U;
                while ((u64LocalDeno & u64Mask) == 0ULL) 
                {
                    u64LocalDeno <<= 8U;
                    u32TempDeno += 8U;
                }
                if(u64LocalNume & 0x8000000000000000ULL) 
                {
                    while (0ULL == (u64LocalDeno & 0x8000000000000000ULL)) 
                    {
                        u64LocalDeno <<= 1U;
                        u32TempDeno++;
                    }
                    u64TempReturn = 0ULL;
                    if (u64LocalNume >= u64LocalDeno) 
                    {
                        u64LocalNume -= u64LocalDeno;
                        u64TempReturn |= 1ULL;
                    }
                } 
                else 
                {
                    while (u64LocalDeno <= u64LocalNume) 
                    {
                        u64LocalDeno <<= 1U;
                        u32TempDeno++;
                    }
                    u64TempReturn = 0ULL;
                }
                while (u32TempDeno > 0U) 
                {
                    u32TempDeno--;
                    u64LocalDeno >>= 1U;
                    u64TempReturn <<= 1U;
                    if (u64LocalNume >= u64LocalDeno) 
                    {
                        u64LocalNume -= u64LocalDeno;
                        u64TempReturn |= 1ULL;
                    }
                }
                u32TempDeno--;
            }
        }
    }
    if ((0xFFFFFFFFFFFFFFFFULL != u64TempReturn) && (0 > (s8TempSigned1 * s8TempSigned2) ))
    {
        /** @violates @ref Eth_Enet_c_REF_22 MISRA rule 10.3 */
        s64RetNumeric = -(sint64)u64TempReturn;
    }
    else
    {
        s64RetNumeric = (sint64)u64TempReturn;
    }
    return s64RetNumeric;
}
#endif
/* Support function for endian agnostic: */
/*================================================================================================*/
/**
* @brief          Convert multi-byte short integer from host byte order
*                 to network byte order
* @param[in]      u16HostShort host short integer to be converted
* @return         Converted short integer in network order
*/
static FUNC(uint16, ETH_CODE) Eth_Enet_Htons( CONST(uint16, AUTOMATIC) u16HostShort)
{
#ifdef MCAL_PLATFORM_ARM
    VAR(uint16, AUTOMATIC) u16ReturnVal;       /* Return variable */

    u16ReturnVal = ((VAR(uint16,AUTOMATIC))(u16HostShort << 8U) & 0xFF00U) | ((VAR(uint16,AUTOMATIC))(u16HostShort >> 8U) & 0x00FFU);
    return u16ReturnVal;
#else
    return u16HostShort;
#endif
}

/*================================================================================================*/
/**
* @brief        Clears the receive buffer
* @details      Function sets the Empty bit in the given buffer descriptor, the
*               rest of the bits is cleared because they are anyway
*               written by the hardware or unused. The wrap bit value is determined
*               based on the descriptor number to avoid propagation of random  
*               failures from the hardware.
* @param[in]    u8CtrlIdx Index of the controller in which RxBuffer will be cleared
* @param[in]    u8Buf Index of the buffer to be cleared
*/

static FUNC(void, ETH_CODE)Eth_Enet_ClearRxBuffer (CONST(uint8, AUTOMATIC) u8CtrlIdx, CONST(uint8, AUTOMATIC) u8Buf)
{
    VAR(uint8, AUTOMATIC) u8BufNum;       /* Configured number of buffers */
    VAR(uint32, AUTOMATIC) u32ManipulationVar; /* Bits assembly variable */
    VAR(uint32, AUTOMATIC) u32BdAddress;   /* Stores buffer descriptor address */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    u32BdAddress=ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx);

    /* Get the number of configured buffers */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u8BufNum = ETH_CFG_RXBUFTOTAL( u8CtrlIdx);
    /* Clear the buffer */
    u32ManipulationVar = ENET_RXBD_E_U32;  /* Mark the buffer as empty and clear the rest of bitfields */
    /* Note - buffer length is set to 0 which is OK because HW only writes the value and
              SW reads it only after it was set. */
    /* Check whether it is the last buffer descriptor in the ring */
    if(u8BufNum  == (u8Buf + 1U))
    {   /* The last buffer in the ring */
        /* Set the wrap bit */
        u32ManipulationVar |= ENET_RXBD_W_U32;
    }
    /* Write the assembled value into the descriptor */
    Eth_Enet_WriteRxBDBitsA(u32BdAddress, u8Buf, u32ManipulationVar); 
    
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    if ((uint8)E_OK == Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx), ETH_RX_BUF_MEM_SIZE))
    {
    #endif
  #endif
#endif
        /* Write the RDAR register to notify the controller about a new buffer,
        written value is ignored, the write access is what matters */
        /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
            @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
        */
        REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RDAR_ADDR16, ENET_RDAR_R_DES_ACTIVE_U32);
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    }
    #endif
  #endif
#endif
}

/*================================================================================================*/
/**
* @brief         Returns pointer to received frame, frame length and status
*                bits of the receive buffer
* @param[in]     u8CtrlIdx Index of controller to be read
* @param[in]     u8Buf Buffer to be read
* @param[in]     u8MultiEnd Last buffer of the frame
* @param[out]    pLength  Frame length
* @param[out]    pDataPtr Pointer to the frame data
* @param[out]    pStatusPtr Buffer status bits
* @details       Function loads the copu16Statusptr argument with the buffer status
*                bits, the length argument is loaded by the frame length
*                and the pDataPtr is loaded with the beginning address of the
*                received frame data.
* @note          The returned buffer contains Ethernet frame header and its
*                payload. The CRC is not included and it is stripped by the hardware.
* @implements    Eth_Enet_GetRxBufferData_Activity
*/
static FUNC(void, ETH_CODE) Eth_Enet_GetRxBufferData   ( \
                        CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                        CONST(uint8, AUTOMATIC) u8Buf, \
                        CONST(uint8, AUTOMATIC) u8MultiEnd, \
                        CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pLength, \
                        P2P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) pDataPtr, \
                        CONSTP2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pStatusPtr \
                                                )
{
#if STD_ON == ETH_USE_RX_FRAMES_WRAP
    /* The maximum index of RX buffer */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    VAR(uint8, AUTOMATIC) u8BufCtrMax = ETH_CFG_RXBUFTOTAL( u8CtrlIdx) - 1U;
    /* Loop control variable */
    VAR(uint32, AUTOMATIC) u32ii;
    /* Temporary source and destination addresses */
    VAR(uint32, AUTOMATIC) u32srcAddr;
    VAR(uint32, AUTOMATIC) u32destAddr;
#endif /* ETH_USE_RX_FRAMES_WRAP */
    VAR(uint32, AUTOMATIC) u32ManipulationVar;
    VAR(uint16, AUTOMATIC) u16FrameLength;
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    VAR(uint32, AUTOMATIC) u32BDAddress = ETH_CFG_RXBDSTARTADDRESS( u8CtrlIdx);
    
    /* Read buf.status (A) */
    u32ManipulationVar = Eth_Enet_ReadRxBDBitsA(u32BDAddress, u8MultiEnd);
    /* Get and return frame length */
    u16FrameLength = (VAR(uint16, AUTOMATIC)) (u32ManipulationVar); /* It occupies lower 16bits */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
#if STD_ON == ETH_USE_MULTIBUFFER_RX_FRAMES
    if( u16FrameLength > 1522U )
    {   /* The length must be incorrect, it is greater than maximal allowed length */
        /* Return maximal length instead */
        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        *pLength = (VAR(uint16, AUTOMATIC)) 1522U;
    }
#else
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    if( u16FrameLength > ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx) )
    {   /* The length must be incorrect, it is greater than maximal allowed length */
        /* Return maximal length instead */
        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        *pLength = (VAR(uint16, AUTOMATIC)) (ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx));
    }
#endif
    else if( u16FrameLength < 14U )
    {   /* The length must be incorrect, minimal acceptable length is 14 (ethernet header only) */
        /* Return minimal length instead (avoid length underloop due to header length subtract) */
        *pLength = (VAR(uint16, AUTOMATIC)) (14U);
    }
    else
    {   /* The length seems correct, return it */
        /* CRC and padding is already truncated (CRCFWD & PADEN) == 1) */
        *pLength = u16FrameLength;
    }
    /* Note: Except MC and BC flags the status bits are valid only if L is set */
    /* Mask status flags A (maskset must be complementary to B) */
    u32ManipulationVar &= 0x01f70000U;
    /* Read buf.status (only error status flags) B (maskset must be complementary to A) */
    u32ManipulationVar |= Eth_Enet_ReadRxBDBitsB(u32BDAddress, u8Buf) & 0x8600E037U;
    /* Return the status bits */
    *pStatusPtr = u32ManipulationVar;
    if (u8Buf>u8MultiEnd)
    {
    /*Wrap occurred */
    #if STD_ON == ETH_USE_RX_FRAMES_WRAP
        /* Check whether data should be copied to leading or trailing area -
           chose which copy will be shorter: either buffer ring start to "u8MultiEnd",
           or "u8Buf" to buffer ring end. */
        if ((u8BufCtrMax-u8Buf) > u8MultiEnd)
        { /* Copy from the start of the buffer ring to the trailing area because it is shorter */
            /* Setup source address */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32srcAddr = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, 0U);
            /* Setup destination address */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32destAddr = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, u8BufCtrMax + 1U);
            /* Store the data pointer */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32ManipulationVar = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, u8Buf);
            /* Return the pointer */
            /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
            */
            /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
            *pDataPtr = (P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA)) u32ManipulationVar;
            
            /* Setup count. The 'length' value must be extended by 4 bytes of CRC */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*pLength) + 4U) \
                - ((ETH_CFG_RXBUFTOTAL( u8CtrlIdx) - (VAR(uint32, AUTOMATIC))u8Buf) \
                * ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx));
        }
        else
        { /* Copy from the end of the buffer ring to the leading area because it is shorter */
            /* Get source address */
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32srcAddr = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, u8Buf);
            /* Set destination address */
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32destAddr = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, 0U) \
                            - ((ETH_CFG_RXBUFTOTAL( u8CtrlIdx) - (VAR(uint32, AUTOMATIC))u8Buf) * ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx));
            /* Return the pointer */
            /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
            */
            /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
            *pDataPtr = (P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA)) u32destAddr;
            /* Setup count */
            /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
            u32ManipulationVar = (ETH_CFG_RXBUFTOTAL( u8CtrlIdx) - (VAR(uint32, AUTOMATIC))u8Buf) * ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx);
        }
        
        /* Perform the copy */
        for (u32ii=u32destAddr; u32ii<(u32destAddr+u32ManipulationVar); u32ii+=4U)
        {
        /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
            @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
        */
        /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
            *(P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA)) u32ii = (uint32)(*(P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA)) u32srcAddr);
            /* Move the source address */
            u32srcAddr+=4U;
        }
    #else
        /*Not receive this frame, setup the error flags */
        *pStatusPtr|=0x8600E037U;
    #endif
    }
#if STD_ON == ETH_USE_MULTIBUFFER_RX_FRAMES
    else
    { /* Use of multi-buffer RX frames is enabled, just receive the frame */

        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        u32ManipulationVar = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, u8Buf);
        /* Return the pointer */
        /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
            @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
        */
        /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
        *pDataPtr = (P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA)) u32ManipulationVar;
    }
#else
    else if (u8Buf == u8MultiEnd)
    {
        /* Receive the single-buffer frame */
        /* Store the data pointer */
        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        u32ManipulationVar = Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, u8Buf);
        /* Return the pointer */
        /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
        /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
            @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
        */
        *pDataPtr = (P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA)) u32ManipulationVar;
    }
    else
    {
        /* Do not receive the frame. Setup the error flags to ensure that frame
            will be rejected. */
        *pStatusPtr |= (VAR(uint16, AUTOMATIC)) 0x00200000U;
    }
#endif /* ETH_USE_MULTIBUFFER_RX_FRAMES */
}

/*================================================================================================*/
/**
* @brief         Determines the type of the given buffer
* @param[in]     u8CtrlIdx Index of examined controller
* @param[in]     u8Buf Index of the examined buffer
* @param[in]     u8BufCtrMax Number of the Rx buffers
* @param[out]    pMultiEnd Last found buffer of the multi-buffer frame
* @details       Function does the following
*                -# Checks the given buffer to be empty and returns RX_BUF_EMPTY
*                   if it is empty.
*                -# Otherwise it checks the buffer to be the last in the frame
*                   and returns RX_BUF_SINGLE if it is the last one.
*                -# Otherwise it goes through all  remaining buffers and
*                   searches for the full and last buffer or an empty buffer.
*                   Index of the found buffer is loaded into multi_end argument.
*                -# RX_BUF_MULTI_UNFINISHED is returned if the found buffer
*                   was empty.
*                -# RX_BUF_MULTI_FINISHED is returned if the found buffer was
*                   full and last.
*                -# RX_BUF_OVERFLOW when buffer is not found.
* @return        Type of the examined buffer
* @retval        RX_BUF_EMPTY - buffer is empty,
* @retval        RX_BUF_SINGLE - buffer contains received frame
* @retval        RX_BUF_MULTI_UNFINISHED - buffer contains part of the
*                frame which has not been received yet
* @retval        RX_BUF_MULTI_FINISHED - buffer contains part of the frame which
*                has been received
* @retval        RX_BUF_OVERFLOW - all buffers are full and frame being received
*                           cannot be stored
* Compiler_Warning: this warning due to behavior of compiler depend on configs. In PC, u8CtrlIdx is skipped in this function
*/

static FUNC(Eth_Enet_enRxBufferType, ETH_CODE) Eth_Enet_GetRxBufferType ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONST(uint8, AUTOMATIC) u8Buf, \
                    CONST(uint8, AUTOMATIC) u8BufCtrMax, \
                    CONSTP2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pMultiEnd \
                                                                     )
{
    VAR(uint32, AUTOMATIC) u32ManipulationVar;
    VAR(uint8, AUTOMATIC ) u8BufCtr;
    VAR(Eth_Enet_enRxBufferType, AUTOMATIC) eReturnStatus = RX_BUF_OVERFLOW;
    VAR(boolean, AUTOMATIC) bBreakLoop; /* Signal that the loop should end */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    VAR(uint32, AUTOMATIC) u32BDAddress = ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx);

    u32ManipulationVar = Eth_Enet_ReadRxBDBitsA(u32BDAddress, u8Buf);
    if(ENET_RXBD_E_U32 == (u32ManipulationVar & ENET_RXBD_E_U32))
    {
        /* Buffer is empty */
         eReturnStatus = RX_BUF_EMPTY;
    }
    else
    { /* Buffer is full */
        if(ENET_RXBD_LG_U32 == (u32ManipulationVar & ENET_RXBD_LG_U32))
        { /* Buffer contains truncated frame */
            /* It is expected to be discarded, because it is incomplete frame */
            *pMultiEnd = u8Buf; /* It is finished in current buffer,
                                         because the rest was discarded */
            eReturnStatus = RX_BUF_MULTI_FINISHED;
        }
        else if(ENET_RXBD_L_U32 == (u32ManipulationVar & ENET_RXBD_L_U32))
        { /* Buffer contains whole frame */
            eReturnStatus = RX_BUF_SINGLE;
            *pMultiEnd = u8Buf;
        }
        else
        {   /* Buffer contains only part of the frame */
            /* Search for the last buffer in that frame */
            u8BufCtr = u8Buf;
            bBreakLoop = ((VAR(boolean, AUTOMATIC))FALSE);/*Loop shall continue*/
            do
            {
                /* Continue with the next buffer */
                if(u8BufCtrMax == u8BufCtr) /* Check if the counter wraps */
                { /* Yes, it wraps  */
                    u8BufCtr = 0U;
                }
                else
                { /* No, it does not wrap */
                    u8BufCtr++;
                }
                /* Check the buffer properties to determine whether
                   it is the last buffer in the multi-buffer frame*/
                if(u8BufCtr == u8Buf) /* Check  the overflow */
                {   /* Search in the ring returned to the starting position
                       without finding the buffer. This means the ring is full
                       of full buffers and the last buffer which shall end
                       the multi-buffer frame cannot be written because there
                       is no space to write it.
                    */
                    eReturnStatus = RX_BUF_OVERFLOW; /* Signal an error */
                    /* Searching again should be avoided */
                    bBreakLoop = ((VAR(boolean, AUTOMATIC))TRUE);
                }
                else
                { /* No overflow detected */
                    u32ManipulationVar = Eth_Enet_ReadRxBDBitsA(u32BDAddress, u8BufCtr);
                    /* Check empty state */
                    if(ENET_RXBD_E_U32 == (u32ManipulationVar & ENET_RXBD_E_U32))
                    { /* Multi-buffer frame has not been finished yet -
                         last buffer has not been written,
                         only empty space for it has been found */
                        *pMultiEnd = u8BufCtr;
                        eReturnStatus = RX_BUF_MULTI_UNFINISHED;
                        /* Buffer cannot be found, stop search */
                        bBreakLoop = ((VAR(boolean, AUTOMATIC))TRUE);
                    }
                    /* Buffer is full, check whether it is also the last one */
                    else if(ENET_RXBD_L_U32 == (u32ManipulationVar & ENET_RXBD_L_U32))
                    {   /* This is the last buffer of the multi-buffer frame */
                        *pMultiEnd = u8BufCtr;
                        eReturnStatus = RX_BUF_MULTI_FINISHED;
                        /* Buffer has been found, stop search */
                        bBreakLoop = ((VAR(boolean, AUTOMATIC))TRUE);
                    }
                    else
                    {   /* This is the next but not the last buffer
                           of the multi-buffer frame -
                                       Continue search with the next buffer */
                        bBreakLoop = ((VAR(boolean, AUTOMATIC))FALSE);
                        /* This else is requested by MISRA otherwise
                           it could be removed */
                    }
                }
            }while(((VAR(boolean, AUTOMATIC))FALSE) == bBreakLoop);
        }
    }
    return eReturnStatus;
}

/*================================================================================================*/
/**
* @brief         Unlocks the transmit buffer and clears the Transmitted flag
* @param[in]     u8CtrlIdx Index of controller which will be release the buffer
* @param[in]     u8Buf DA index of the buffer to be unlocked
* @details       Function clears the Lock and the Transmitted bits of the given
*                buffer. Buffer becomes empty and can be reused for another
*                transmission.
* @note          All status bits and the length field are cleared.
*/


static FUNC(void, ETH_CODE) Eth_Enet_GiveBackTxBuffer (CONST(uint8, AUTOMATIC) u8CtrlIdx, VAR(uint8, AUTOMATIC) u8Buf)
{
    VAR(uint32, AUTOMATIC) u32ManipulationVar;
    VAR(uint8, AUTOMATIC) u8BDIdx; /* Index of linked BD (if any) */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    VAR(uint32, AUTOMATIC) u32BDAddress = ETH_CFG_TXBDSTARTADDRESS( u8CtrlIdx);
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    VAR(uint8, AUTOMATIC) u8BufNum; /* Number of buffers in current frame */
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */

    /* Is there a BD linked to this buffer? */
    if ( (ENET_TXB_FIRST_U8 | ENET_TXB_LINK_U8 | ENET_TXB_LOCK_U8) == Eth_au8TxBufFlags[u8CtrlIdx][u8Buf])
    {   /* Yes, unlink the BD */
        /* Remove it on the BD side: */
        u8BDIdx = Eth_au8TxBdOfBuf[u8CtrlIdx][u8Buf];
        /* Read the TXBD status */
        u32ManipulationVar = Eth_Enet_ReadTxBDBitsA(u32BDAddress, u8BDIdx);
        /* Clear BufLinked flag */
        u32ManipulationVar &= (VAR(uint32, AUTOMATIC))(~ENET_TXBD_TO1_U32);
        /* Write modified bits back */
        Eth_Enet_WriteTxBDBitsA(u32BDAddress, u8BDIdx, u32ManipulationVar);
        /* NOTE: on buffer side the link is removed below */
    }

#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    /* Unlock all buffers of frame */
    u8BufNum = Eth_ENET_au8TxBufGroup[u8CtrlIdx][u8Buf];
    while(0U != u8BufNum)
    {
        Eth_au8TxBufFlags[u8CtrlIdx][u8Buf] = 0U;
        u8BufNum--;
        u8Buf++; /* The memory must be continuous, wrap may not occur */
    }
#else /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    /* Unlock the buffer, there is only one */
    Eth_au8TxBufFlags[u8CtrlIdx][u8Buf] = 0U;
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
}

/*================================================================================================*/
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
/**
* @brief         Check whether the specified physical address
*                is allowed for reception.
* @details       This function checks the filter statuses and look into
*                multicast pool whether reception is allowed for specified
*                physical address.
* @param[in]     u8CtrlIdx Index of controller to be checked
* @param[in]     copu32PhysAddrPtr Pointer to physical address in network byte
*                order.
* @return        bReceptionAllowed Boolean value which defines that the frame
*                is contained in the pool (TRUE) or not (FALSE).
*/
static FUNC(boolean, ETH_CODE) Eth_Enet_IsPhysAddrAllowed (CONST(uint8, AUTOMATIC) u8CtrlIdx, CONSTP2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr)
{
    /* Return variable */
    VAR(boolean, AUTOMATIC) bReceptionAllowed;
    /* Multicast Pool table item index */
    VAR(uint16, AUTOMATIC) u16McastPoolIdx;

    if ((VAR(boolean, AUTOMATIC))TRUE == Eth_ENET_bMcastPoolOvf[u8CtrlIdx])
    { /* Multicast filter overflow detected */
        bReceptionAllowed = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else if ((VAR(boolean, AUTOMATIC))TRUE == Eth_ENET_bMcastFullOpen[u8CtrlIdx])
    { /* Filter is fully open */
        bReceptionAllowed = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    { /* No special case - look into multicast pool table  */
        /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
        bReceptionAllowed = Eth_Enet_IsAddrInMcastPool(u8CtrlIdx, pPhysAddrPtr, &u16McastPoolIdx);
    }
    return bReceptionAllowed;
}
#endif

/*================================================================================================*/
/**
* @brief          Writes the Transmit buffer descriptor status bits.
* @details        32 bit long value containing status bits in upper 16 bits and
*                 buffer length in lower 16 bits is written into the given
*                 buffer descriptor.
* @param[in]      u32Base Starting address of the Transmit buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be written
* @param[in]      u32Data Status bits and buffer length to be written into
*                 the descriptor
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
static FUNC(void, ETH_CODE) Eth_Enet_WriteTxBDBitsA    ( \
                        CONST(uint32, AUTOMATIC) u32Base, \
                        CONST(uint8, AUTOMATIC) u8BufNum, \
                        CONST(uint32, AUTOMATIC) u32Data \
                                                )
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE))) = u32Data;
}

/*================================================================================================*/
/**
* @brief          Reads the status bits from the Transmit buffer descriptor
* @param[in]      u32Base Starting address of the Transmit buffer descriptors ring
* @param[in]      u8BufNum Index of the buffer descriptor to be read
* @return         Read status bits (upper 16 bits) and buffer length
*                 (lower 16 bits)
* @note           This function is an inline function.
*/
/* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
static FUNC(uint32, ETH_CODE) Eth_Enet_ReadTxBDBitsA (CONST(uint32, AUTOMATIC) u32Base, CONST(uint8, AUTOMATIC) u8BufNum)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return *((P2VAR(volatile uint32, AUTOMATIC, ETH_APPL_DATA)) (u32Base + (u8BufNum * (VAR(uint32, AUTOMATIC))ETH_ENET_LLD_BD_SIZE)));
}
#if(STD_ON == ETH_DEM_EVENT_DETECT)
static FUNC(void, ETH_CODE) Eth_Enet_CheckDemStatus (VAR(uint32, AUTOMATIC) u32Addr, VAR(uint32, AUTOMATIC) u32DemConfig, VAR(uint16, AUTOMATIC)DemId)
{

    VAR(uint32, AUTOMATIC) u32TempRegValue;
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    u32TempRegValue = REG_READ32(u32Addr);
        if (u32TempRegValue>0U)
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            if((VAR(uint32, AUTOMATIC))STD_ON == u32DemConfig)
            {
                /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
                Dem_ReportErrorStatus   ( DemId, DEM_EVENT_STATUS_PREFAILED );
            }
        }
        else
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            if((VAR(uint32, AUTOMATIC))STD_ON == u32DemConfig)
            {
                /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
                Dem_ReportErrorStatus   ( DemId, DEM_EVENT_STATUS_PREPASSED );
            }
        }
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef ERR_IPV_ENET_0001
    #if STD_ON == ERR_IPV_ENET_0001

/**
* @brief        This function triggers the transmission in case when there is data in
*               the buffer descriptor ring which has not been transmitted because of
*               the errata 6358.
* @details      Due to errata 6358 a write to the TDAR during transmission in progress
*               is ignored.
*               Eth_Enet_ERR006358 is a part of workaround for this errata.
*               The variable Eth_ENET_bMoreDataForTx[u8CtrlIdx] is set whenever the new buffer
*               is committed for transmission and ongoing transmission of another buffer
*               is detected.
*               The Eth_Enet_ERR006358 is called during Eth_TxConfirmation call or
*               during the TX interrupt service routine and if there is already prepared
*               not transmitted data (Eth_ENET_bMoreDataForTx[u8CtrlIdx] is set to TRUE)
*               then the transmission is triggered again by write to TDAR.
* @param[in]    u8CtrlIdx Index of controller which will be process errata workaround
* @note         This function must be called only from protected TX area
*/
FUNC(void, ETH_CODE)Eth_Enet_ERR006358(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32TDARRegVal; /* Temporary variable for TDAR */

    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    u32TDARRegVal = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TDAR_ADDR16);
    /* Check whether there is a buffer which transmission has failed due to
       the errata and whether it is possible to trigger the transmission
       again i.e. no other buffer transmission is ongoing. */
    if (((VAR(boolean, AUTOMATIC))TRUE == Eth_ENET_bMoreDataForTx[u8CtrlIdx]) && (0U == (u32TDARRegVal & ENET_TDAR_X_DES_ACTIVE_U32)))
    { /* TX complete and still some data with (R)eady bit set in BD ring */
        /* Trigger the transmission again */
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
        REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TDAR_ADDR16, ENET_TDAR_X_DES_ACTIVE_U32);
        /* Clean indicator */
        Eth_ENET_bMoreDataForTx[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
    }
}
    #endif /* STD_ON == ERR_IPV_ENET_0001 */
#endif /* ERR_IPV_ENET_0001 */



/*================================================================================================*/
/**
* @brief         Finds empty Tx buffer and prepares it for loading with data
* @param[in]     u8CtrlIdx Index of controller to be borrowed buffer
* @param[out]    pBufIdx Granted buffer DA index
* @param[out]    pData Pointer to data area beginning is stored here (not data
*                area beginning but the pointer)
* @param[out]    pLength Granted buffer length
* @details       The user bit 1 in transmit buffer descriptors is used as
*                buffer Lock bit buffer is in use. Function searches all
*                available tx buffers for a buffer with the Lock bit and the
*                Ready bit cleared (if the Ready bit is set and the Lock bit is
*                cleared it means that buffer is being transmitted without
*                confirmation therefore both bits are checked).
*                The found buffer is then locked (Lock bit is set) and buffer
*                address in buffer descriptor is read and incremented
*                by 14 bytes which causes the address of payload being stored
*                there. Obtained value is returned as data address. The returned
*                length is always set to the configured length of all buffers
*                minus 14 bytes used for the header space. The configuration
*                tool must generate buffer lengths 14 bytes longer than
*                requested DA lengths.
* @return        The search status
* @retval        TRUE An empty buffer was found and granted.
* @retval        FALSE There is not empty buffer available at the moment.
* @implements    Eth_Enet_BorrowTxBuffer_Activity
*/

FUNC(boolean, ETH_CODE) Eth_Enet_BorrowTxBuffer ( \
                            CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                            CONSTP2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) pBufIdx, \
                            P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pData, \
                            CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pLength \
                                                )
{
    VAR(uint8, AUTOMATIC) u8BufNumNeed; /* Needed number of buffers */
    VAR(uint8, AUTOMATIC) u8BufNumFound; /* Number of free buffers found */
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    VAR(uint8, AUTOMATIC) u8IdxL; /* General purpose index to be used in loops */
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    VAR(uint32, AUTOMATIC) u32BDStatus;
    VAR(uint8, AUTOMATIC) u8Idx;  /* General purpose index to be used in loops */
    VAR(uint16, AUTOMATIC) u16SearchCnt; /* Countdown to limit search */
    VAR(boolean, AUTOMATIC) bDataAreaFound = ((VAR(boolean, AUTOMATIC))FALSE); /* Used to track if some free buffer was found */
    /* Local copies of configuration (optimization): */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    VAR(uint8, AUTOMATIC) u8TotalBufNum = ETH_CFG_TXBUFTOTAL( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    VAR(uint16, AUTOMATIC) u16BufSize = ETH_CFG_CTRLTXBUFLENBYTE( u8CtrlIdx);
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    VAR(uint32, AUTOMATIC) u32BDAddr = ETH_CFG_TXBDSTARTADDRESS( u8CtrlIdx);
    
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    /* Compute needed number of buffers. Add 14B for eth header, round up */
    u8BufNumNeed = (VAR(uint8, AUTOMATIC)) ((*pLength + (u16BufSize + (14U - 1U))) / u16BufSize);
    /* s16SearchCnt must be incremented by the number of needed buffers because
       we must check the buffers at the end again if we skipped them due to
       the fact that we started search in the middle of the continuous block
       just before the wrap (example: we need 4 buffers, and we start search
       from the 3rd buffer before the row end therefore we would end by
       examining the 4th buffer from the end (if no adjust was done) without
       discovering needed 4 buffers block at the end of the row). */
    u16SearchCnt = ((VAR(uint16, AUTOMATIC))u8TotalBufNum + (VAR(uint16, AUTOMATIC))u8BufNumNeed) - 1U;
#else /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    /* One buffer is always needed */
    u8BufNumNeed = 1U;
    u16SearchCnt = u8TotalBufNum;
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    /* Start at Eth_LLD_u8SearchFreeTxBufFrom (to minimize fragmentation) */
    u8Idx = Eth_ENET_u8SearchTxBufFrom[u8CtrlIdx];
    u8BufNumFound = 0U;
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    if ((uint8)E_OK == Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE))
    {
    #endif
  #endif
#endif
        while( ((VAR(boolean, AUTOMATIC))FALSE == bDataAreaFound) && (u16SearchCnt != 0U))
        {
            /* Check buffer status, whether the buffer may be unlocked now */
            if( (ENET_TXB_LOCK_U8 | ENET_TXB_LINK_U8 | ENET_TXB_FIRST_U8) == Eth_au8TxBufFlags[u8CtrlIdx][u8Idx]
            )
            {   /* According to buffer flags, it may be unlocked now */
                /* Now check BD status, whether Ready bit is cleared */
                u32BDStatus = ENET_TXBD_R_U32 & Eth_Enet_ReadTxBDBitsA(u32BDAddr, Eth_au8TxBdOfBuf[u8CtrlIdx][u8Idx]);
                if( 0U == u32BDStatus )
                {   /* Yes, the frame is in UNLOCKEDAT state and both BD and
                    buffers shall be unlocked and unlinked now */
                    Eth_Enet_GiveBackTxBuffer(u8CtrlIdx, u8Idx);
                }
            }
            /* Check buffer status. Is the buffer free ? */
            if(0U == Eth_au8TxBufFlags[u8CtrlIdx][u8Idx])
            {   /* Yes, it is free */
                u8BufNumFound++;
                if( u8BufNumFound == u8BufNumNeed )
                {   /* All needed buffers found */
                    bDataAreaFound = (VAR(boolean, AUTOMATIC))TRUE;
                    u8Idx++;
                    /* Next time continue search from here */
                    if( u8Idx >= u8TotalBufNum )
                    {
                        Eth_ENET_u8SearchTxBufFrom[u8CtrlIdx] = 0U;
                    }
                    else
                    {
                        Eth_ENET_u8SearchTxBufFrom[u8CtrlIdx] = u8Idx;
                    }
                    /* Compute index of the first buffer, u8Idx is behind allocated
                    buffers now. Continuous block => no wrap => no under-loop */
                    *pBufIdx = (Eth_BufIdxType)u8Idx - u8BufNumFound;              

                    /* Compute buffer pointer, skip 14 bytes for ethernet header */
                    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
                    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                    */
                    *pData = (void *)(14U + (Eth_Enet_ComputeTxBufAddr(u8CtrlIdx, (VAR(uint8, AUTOMATIC))(*pBufIdx))));
                    /* Return real length of buffers minus eth header length */
                    (*pLength) = (u16BufSize * u8BufNumNeed) - 14U;             
                    Eth_au8TxBufFlags[u8CtrlIdx][(VAR(uint8, AUTOMATIC))(*pBufIdx)] = ENET_TXB_LOCK_U8 | ENET_TXB_FIRST_U8; /* The 1st */
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
                    /* Write number of buffers belonging to this frame */
                    Eth_ENET_au8TxBufGroup[u8CtrlIdx][(VAR(uint8, AUTOMATIC))(*pBufIdx)] = u8BufNumNeed;
                    for( u8IdxL = (VAR(uint8, AUTOMATIC))(*pBufIdx) + 1U; u8IdxL < (*pBufIdx+u8BufNumNeed); u8IdxL++ ) /* Skip the first */
                    { 
                        Eth_au8TxBufFlags[u8CtrlIdx][u8IdxL] = ENET_TXB_LOCK_U8;
                    }
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
                }
            }
            else
            {   /* No, buffer is locked => continuity broken */
                u8BufNumFound = 0U;
            }
            u16SearchCnt--;
            u8Idx++;
            if( u8Idx >= u8TotalBufNum )
            {   /* Wrapped */
                u8Idx = 0U;
                u8BufNumFound = 0U; /* Wrap => continuity broken */
            }
        }

#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
        (void)Mcl_CacheFlushMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE);
    }
    #endif
  #endif
#endif
    return bDataAreaFound;
}

/*================================================================================================*/
/* TX Buffers status bits summary
   Buffer is in UNUSED state:
   - not locked (ENET_TXBD_TO1_U32 = 0)
   - not being transmitted (ENET_TXBD_R_U32 = 0),
   - not already transmitted (ENET_TXBD_TO2_U32 = 0)
   Buffer is in LOCKEDBT state:
   - locked (ENET_TXBD_TO1_U32 = 1)
   - not being transmitted (ENET_TXBD_R_U32 = 0),
   - not already transmitted (ENET_TXBD_TO2_U32 = 0)
   Buffer is in LOCKEDIT state:
   - locked (ENET_TXBD_TO1_U32 = 1)
   - being transmitted (ENET_TXBD_R_U32 = 1),
   - already transmitted (ENET_TXBD_TO2_U32 = 1)
   Buffer is in UNLOCKEDIT state:
   - not locked (ENET_TXBD_TO1_U32 = 0)
   - being transmitted (ENET_TXBD_R_U32 = 1),
   - not already transmitted (ENET_TXBD_TO2_U32 = 0)
   Buffer is in LOCKEDAT state:
   - locked (ENET_TXBD_TO1_U32 = 1)
   - not being transmitted (ENET_TXBD_R_U32 = 0),
   - already transmitted (ENET_TXBD_TO2_U32 = 1)
*/

/*================================================================================================*/
/**
* @brief         Checks whether the transmit buffer state is LOCKEDBT
* @param[in]     u8CtrlIdx Index of Controller to be checked
* @param[in]     u8Buf Checked buffer DA index
* @details       Function finds the BD assigned to given AD, reads status bits
*                from the found BD and examines them in order to determine
*                whether the current buffer state is LOCKEDBT (Locked before
*                transmission).
* @retval        TRUE Buffer is in LOCKEDBT state
* @retval        FALSE Buffer is in different state
*/
FUNC(boolean, ETH_CODE) Eth_Enet_IsTxBufLockedBT (
                          CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                          CONST(Eth_BufIdxType, AUTOMATIC) u8Buf
                          )
{
    VAR(boolean, AUTOMATIC) bResult; /* Result holder */ 

    if( (ENET_TXB_LOCK_U8|ENET_TXB_FIRST_U8)== Eth_au8TxBufFlags[u8CtrlIdx][u8Buf])
    {   /* OK, it is locked and first buffer of frame */
        bResult = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else 
    {
        bResult = (VAR(boolean, AUTOMATIC))FALSE;
    }
    return bResult;
}

/*================================================================================================*/
/**
* @brief         Triggers the transmission of the given buffer
* @param[in]     u8CtrlIdx Index of controller which will be triggered the transmission
* @param[in]     u8Buf DA Index of the buffer to be transmitted
* @param[in]     u16Type Type or length field value in the 802.3 frame header
* @param[in]     u16Length Payload length
* @param[in]     bConfirm Selects whether the frame transmission shall
*                be confirmed or not
* @param[in]     pDest Frame destination address
* @details       Function decrements the buffer address in the transmit buffer
*                descriptor assigned to the given DA by 14 bytes in order to get
*                the frame header beginning. The frame header is constructed
*                using the given destination address and type or length field
*                values. The source address is added by ENET natively.
*
*                - The Lock and bit is cleared if the transmission
*                  confirmation is disabled and buffer will become empty
*                  after the transmission.
*                - Transmitted bit (user bit 2) is set and Lock is bit left set
*                  if the transmission confirmation is enabled. Then the buffer
*                  will stay locked after the transmission but it can be
*                  recognized as already transmitted  because of the set
*                  Transmitted bit. Such buffer cannot be used until it is
*                  confirmed and bits are cleared.
*
*                The Ready bit is set to trigger the buffer transmission and the
*                controller is notified about the new buffer by a write into the
*                TDAR register.
* @implements    Eth_Enet_Transmit_Activity
*/

FUNC(void, ETH_CODE) Eth_Enet_Transmit  (
                        CONST(uint8, AUTOMATIC) u8CtrlIdx,
                        CONST(Eth_BufIdxType, AUTOMATIC) u8Buf,
                        CONST(Eth_FrameType, AUTOMATIC) u16Type,
                        CONST(uint16, AUTOMATIC) u16Length,
                        CONST(boolean, AUTOMATIC) bConfirm,
                        P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) pDest
#if STD_ON == ETH_BRIDGE_SUPPORT
                      , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) pSource
#endif /* ETH_BRIDGE_SUPPORT  */
                                        )
{
    VAR(uint32, AUTOMATIC) u32BufAddr; /* Address of (first) buffer */
    VAR(uint32, AUTOMATIC) u32ManipulationVar; /* Used for bit manipulations */
#ifdef ETH_ENABLE_CORE_A53_SUPPORT
    #if STD_ON == ETH_ENABLE_CORE_A53_SUPPORT
    VAR(uint16, AUTOMATIC) u16PacketCount = 0;
    #endif
#endif
    /* Local copies of configuration (optimization): */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    VAR(uint8, AUTOMATIC) u8TotalBufNum = ETH_CFG_TXBUFTOTAL( u8CtrlIdx);
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    VAR(uint32, AUTOMATIC) u32BDAddr = ETH_CFG_TXBDSTARTADDRESS( u8CtrlIdx);  
    /* Assemble frame header */
    /* Compute address of the buffer. */
    u32BufAddr = Eth_Enet_ComputeTxBufAddr(u8CtrlIdx, (VAR(uint8, AUTOMATIC))u8Buf);
    /* Copy destination MAC address - use a temporary variable to access 
       a given destination address because the pDest pointer is only of 8bit 
       type therefore the data may not have 16-bit alignment. The 16-bit 
       alignment of the buffer data is ensured by the buffer alignment 
       restrictions */
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    if ((uint8)E_OK == Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE))
    {
    #endif
  #endif
#endif
        u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*pDest) << 8U);
        /** @violates @ref Eth_Enet_c_REF_5 */
        u32ManipulationVar |= *(pDest + 1U);
        Eth_Enet_Write16TxBufMem(u32BufAddr, 0U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u32ManipulationVar)); /* Put first 2 bytes */
        /** @violates @ref Eth_Enet_c_REF_5 */
        u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*(pDest + 2U)) << 8U);
        /** @violates @ref Eth_Enet_c_REF_5 */
        u32ManipulationVar |= *(pDest + 3U);
        Eth_Enet_Write16TxBufMem(u32BufAddr, 2U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u32ManipulationVar)); /* Put second 2 bytes */
        /** @violates @ref Eth_Enet_c_REF_5 */
        u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*(pDest + 4U)) << 8U);
        /** @violates @ref Eth_Enet_c_REF_5 */
        u32ManipulationVar |= *(pDest + 5U);
        Eth_Enet_Write16TxBufMem(u32BufAddr, 4U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u32ManipulationVar)); /* Put third 2 bytes */
#if STD_ON == ETH_BRIDGE_SUPPORT
        if( NULL_PTR == pSource)
        {     
            /* Read source MAC address from registers and put it to header */
            /* Read first 4 bytes */
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
            */
            u32ManipulationVar = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PALR_ADDR16);
            Eth_Enet_Write16TxBufMem(u32BufAddr, 8U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))(u32ManipulationVar & 0xFFFFU))); /* Put second 2 bytes */
            u32ManipulationVar = u32ManipulationVar >> 16U; /* Put bits to right position */
            Eth_Enet_Write16TxBufMem(u32BufAddr, 6U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))(u32ManipulationVar & 0xFFFFU))); /* Prepend first 2 bytes */
            /* Read last 2 bytes */
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
            */
            u32ManipulationVar = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PAUR_ADDR16);
            u32ManipulationVar = u32ManipulationVar >> 16U; /* Put bits to right position */
            Eth_Enet_Write16TxBufMem(u32BufAddr, 10U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))(u32ManipulationVar & 0xFFFFU))); /* Append third 2 bytes */  
        }
        else
        {
            u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*pSource) << 8U);
            /** @violates @ref Eth_Enet_c_REF_5 */
            u32ManipulationVar |= *(pSource + 1U);
            Eth_Enet_Write16TxBufMem(u32BufAddr, 6U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u32ManipulationVar)); /* Put first 2 bytes */
            /** @violates @ref Eth_Enet_c_REF_5 */
            u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*(pSource + 2U)) << 8U);
            /** @violates @ref Eth_Enet_c_REF_5 */
            u32ManipulationVar |= *(pSource + 3U);
            Eth_Enet_Write16TxBufMem(u32BufAddr, 8U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u32ManipulationVar)); /* Put second 2 bytes */
            /** @violates @ref Eth_Enet_c_REF_5 */
            u32ManipulationVar = ((VAR(uint32, AUTOMATIC))(*(pSource + 4U)) << 8U);
            /** @violates @ref Eth_Enet_c_REF_5 */
            u32ManipulationVar |= *(pSource + 5U);
            Eth_Enet_Write16TxBufMem(u32BufAddr, 10U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u32ManipulationVar)); /* Put third 2 bytes */    
        } 
#endif
        /* Append the type field */
        Eth_Enet_Write16TxBufMem(u32BufAddr, 12U, (VAR(uint16, AUTOMATIC)) Eth_Enet_Htons((VAR(uint16, AUTOMATIC))u16Type));
        /* 14 bytes long header has been filled */
        /* Note: The link flags are set later below */
        Eth_au8TxBdOfBuf[u8CtrlIdx][u8Buf] = Eth_u8ActiveTxBD[u8CtrlIdx];
        
        /* Now write the buffer descriptor */
        /* Write pointer */
        Eth_Enet_WriteTxBDBufPtr(u32BDAddr, Eth_u8ActiveTxBD[u8CtrlIdx], u32BufAddr);
        /* Write status bits and frame length. Note that ENET_TXBD_R_U32 bit must be written
        last. It will be written last, together with other bits and length.
        14 bytes of ethernet header is added to the length.  */
        u32ManipulationVar = ENET_TXBD_LENGTH_U32 & ((uint32)u16Length + 14U);
        /* Set: ENET_TXBD_R_U32: buffer is ready for transmission
                ENET_TXBD_TO1_U32: buffers are linked to this BD
                ENET_TXBD_L_U32: This BD is last in frame
                ENET_TXBD_TC_U32: Compute and append CRC to frame */
        u32ManipulationVar |= ENET_TXBD_R_U32 | ENET_TXBD_TO1_U32 | ENET_TXBD_L_U32 | ENET_TXBD_TC_U32;
        /** @violates @ref Eth_Enet_c_REF_25 MISRA rule 12.2 
            @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2
        */
        if( Eth_u8ActiveTxBD[u8CtrlIdx] == (u8TotalBufNum - 1U) )
        {   /* It is the last BD in ring, it must have wrap bit set */
            u32ManipulationVar |= ENET_TXBD_W_U32;
        }
        /* Write the assembled value to BD to allow the frame transmission */
        Eth_Enet_WriteTxBDBitsA(u32BDAddr, Eth_u8ActiveTxBD[u8CtrlIdx], u32ManipulationVar);
        /* This BD is not active any more, increment to next (consider wrap) */
        Eth_u8ActiveTxBD[u8CtrlIdx]++;
        /** @violates @ref Eth_Enet_c_REF_25 MISRA rule 12.2
            @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2
        */
        if( Eth_u8ActiveTxBD[u8CtrlIdx] >= u8TotalBufNum )
        {
            Eth_u8ActiveTxBD[u8CtrlIdx] = 0U;
        }
        /* Write frame/buffer status bits */
        if( (VAR(boolean, AUTOMATIC))TRUE == bConfirm )
        {   /* TxConfirmation is requested, also set TxConfirmation bit */
            Eth_au8TxBufFlags[u8CtrlIdx][u8Buf] = ENET_TXB_LOCK_U8 | ENET_TXB_FIRST_U8 | ENET_TXB_LINK_U8 | ENET_TXB_CONF_U8;
            /* Update number of pending confirmations */
            /* Enter critical section for RMW access */
            SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_00();
            Eth_u8LockedTxBufCount[u8CtrlIdx]++;
            /* Exit Exclusive area */
            SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_00();
        }
        else
        {
            Eth_au8TxBufFlags[u8CtrlIdx][u8Buf] = ENET_TXB_LOCK_U8 | ENET_TXB_FIRST_U8 | ENET_TXB_LINK_U8;
        }
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        if ((uint8)E_OK == Mcl_CacheFlushMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE))
        {
    #endif
  #endif
#endif
    
        /* Write the TDAR register to notify the controller about a new buffer,
        written value is ignored, the write access is what matters. Note that
        this is the place when the Eth_u8ActiveTxBD[u8CtrlIdx] is moved by the controller however
        the it has already been updated at the function beginning because it
        is safer. */
    #ifdef ERR_IPV_ENET_0001
        #if STD_ON == ERR_IPV_ENET_0001
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
            if (0U != (REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TDAR_ADDR16) & ENET_TDAR_X_DES_ACTIVE_U32))
            { /* Transmission in progress */
                /* Remember that transmission must be triggered again after last ring finishing */
                Eth_ENET_bMoreDataForTx[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))TRUE;
            }
        #endif /* STD_ON == ERR_IPV_ENET_0001 */
    #endif /* ERR_IPV_ENET_0001 */
            /* Because of ERR0063358 the next action will be ignored if transmit is already in progress.
            * The workaround is to set variable Eth_ENET_LLD_bMoreDataForTX and trigger the TDAR at
            * EIR[TCF] or general at TXConfirmation.
            * Warning: TX interrupt must be passed into Eth_TxIrqHdlr_0 or transmitted buffers must call
            *          Eth_TxConfirmation, otherwise burst of TX packets may get stuck till next
            *          triggering of TDAR */
    #ifdef ETH_ENABLE_CORE_A53_SUPPORT
        #if STD_ON == ETH_ENABLE_CORE_A53_SUPPORT
            u16PacketCount = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RMON_TPACKET_ADDR16) & 0xFFFF;
            while (u16PacketCount == REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RMON_TPACKET_ADDR16) & 0xFFFF)
            {
        #endif
    #endif
                /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                    @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TDAR_ADDR16, (uint32) ENET_TDAR_X_DES_ACTIVE_U32);
    #ifdef ETH_ENABLE_CORE_A53_SUPPORT
        #if STD_ON == ETH_ENABLE_CORE_A53_SUPPORT
            }
        #endif
    #endif
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
        }
    }
    #endif
  #endif
#endif
}

/*================================================================================================*/
/**
* @brief         Resets the Ethernet controller
* @param[in]     u8CtrlIdx Index of controller which will be reset
* @details       Function masks all interrupts, issues a controller reset, waits
*                for a while to allow controller finish its initialization.
*                It clears all interrupt flags at the end.
* @implements    Eth_Enet_ResetController_Activity
*/

FUNC(void, ETH_CODE) Eth_Enet_ResetController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(volatile uint8, AUTOMATIC) u8WaitCtr; /* Waiting loop counter */

    #ifdef ETH_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ETH_ENABLE_USER_MODE_SUPPORT)
    #ifdef ETH_ENET_REG_PROT_AVAILABLE
        Mcal_Trusted_Call(Eth_Enet_SetUserAccessAllowed);
    #endif /* STD_ON == ETH_ENABLE_USER_MODE_SUPPORT */
    #endif
    #endif
    /* Disable all interrupts before the masks are cleared to
       avoid spurious interrupt generation */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIMR_ADDR16, 0U);
    /* Issue a reset */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ECR_ADDR16, ENET_ECR_RESET_U32 | ENET_ECR_DEFAULT_RESERVED_VALUE_U32);
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    /* Clear multicast pool buffer */
    Eth_Enet_McastPoolClean(u8CtrlIdx);
    /* Clear MulticastPool flags */
    Eth_ENET_bMcastPoolOvf[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
    Eth_ENET_bMcastFullOpen[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
    /* Wait until reset is finished - approximately 8 bus cycles */
    for(u8WaitCtr = 0U; u8WaitCtr <= ETH_RESET_WAIT_LOOP_COUNT; u8WaitCtr++)
    {
        ; /* This loop is intentionally empty. It  provides only necessary
             delay needed for controller internal re-initialization. */
    }
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    Eth_Enet_McastGAClean(u8CtrlIdx);
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
    /* Clear all interrupt flags - all interrupts are masked,
       no spurious interrupt can occur */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16, ENET_EIR_ALL_W1C);
}

/*================================================================================================*/
/**
* @brief         Checks the access to the controller
* @details       Function is intended to be used only after the Ethernet
*                controller reset. It checks the reset value of one register
*                and checks whether it agrees with the datasheet value.
*                Controller is claimed as accessible if the value agrees.
* @param[in]     u8CtrlIdx Index of controller which will be checked the access
* @return        Controller accessibility
* @retval        TRUE Controller is accessible, value in register agrees.
* @retval        FALSE Controller access failed, different value read.
*/

FUNC(boolean, ETH_CODE) Eth_Enet_CheckAccessToCtrl(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(boolean, AUTOMATIC) bControllerAvailable; /* Used to hold return value */

    /* Check if the RCR register contains the reset value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    if(ENET_RCR_INIT_VAL_U32 == REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16))
    {
        /* Yes, it contains  right number, controller is probably available */
        bControllerAvailable = ((VAR(boolean, AUTOMATIC))TRUE);
    }
    else
    {
        /* No, the value is wrong, controller is definitely not available. */
        bControllerAvailable = ((VAR(boolean, AUTOMATIC))FALSE);
    }
    return bControllerAvailable;
}

/*================================================================================================*/
/**
* @brief         Configures the controller
* @details       Function
*                -# enables/disables Received frame interrupts
*                -# enables/disables Transmitted frame interrupts
*                -# clears MAC addresses hash tables
*                -# configures the controller MAC address
*                -# configures the MII
*                -# configures RCR and TCR registers
*                -# configures the maximal received frame length
*                -# configures all other registers including unused ones
*                   to prevent corrupted values staying there forever
* @param[in]     u8CtrlIdx Index of controller which will be configured
* @note          The controller is ready for use after the function finishes
*                however the buffers configuration must be still done.
*/
FUNC(void, ETH_CODE) Eth_Enet_ConfigureCtrl (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to assemble register
               value before writing to register or to read the register value */

    /* Initialize interrupts */
    u32RegisterValue = 0U; /* All interrupts are disabled */
     /* Check whether the TX interrupt is enabled for this controller
        and multiple configuration */
    /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7
        @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 
        @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1
    */
    if(((VAR(boolean, AUTOMATIC))TRUE) == ETH_CFG_ENABLERXINTERRUPT( u8CtrlIdx))
    {
         u32RegisterValue = u32RegisterValue | ENET_EIMR_RXF_U32; /* Enable RX irq */
    }
    /* Check whether the RX interrupt is enabled for this controller and multiple configuration */
    /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7
        @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 
        @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1
    */
    if(((VAR(boolean, AUTOMATIC))TRUE) == ETH_CFG_ENABLETXINTERRUPT( u8CtrlIdx))
    {
        u32RegisterValue = u32RegisterValue | ENET_EIMR_TXF_U32; /* Enable TX irq */
    }
#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
    u32RegisterValue = u32RegisterValue | ENET_EIMR_TS_TIMER_U32; /* Enagle ENET timer flag */
#endif
    /* Write the assembled value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIMR_ADDR16, u32RegisterValue);
    /* Configure MAC address(es) */
    u32RegisterValue = 0U;
    /* Configure Multicast hash table - no multicast received */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GAUR_ADDR16, u32RegisterValue);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GALR_ADDR16, u32RegisterValue);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_IAUR_ADDR16, u32RegisterValue);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_IALR_ADDR16, u32RegisterValue);
    /* Configure device MAC address */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_MACADDRESSLOW( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PALR_ADDR16, u32RegisterValue);
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_MACADDRESSHIGH( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PAUR_ADDR16, u32RegisterValue);

    /* Configure MII management data clock speed */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_MSCR( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MSCR_ADDR16, u32RegisterValue);
    /* Configure Rx */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_RCR( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16, u32RegisterValue);
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MRBR_ADDR16, u32RegisterValue);
    /* Configure Frame Truncation Length, frames longer than this value are
       automatically discarded. The value includes CRC length */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_FTRL( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_FTRL_ADDR16, u32RegisterValue);
    /* Configure Tx */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_TCR( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCR_ADDR16, u32RegisterValue);
    /* Configure inter packet gap */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_TIPG( u8CtrlIdx);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TIPG_ADDR16, u32RegisterValue);
    /* Configure Receive Accelerator Functions. All options are forced disabled
       except ENET_RACC_ADDR16[LINEDIS] (invalid frames discarding by HW) which is
       configurable. */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u32RegisterValue = ETH_CFG_RACC( u8CtrlIdx);
    #if (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4)
      u32RegisterValue |= ENET_RACC_IPDIS_U32;
    #endif
    #if ( (STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP))
      u32RegisterValue |= ENET_RACC_PRODIS_U32;
    #endif
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RACC_ADDR16, u32RegisterValue);
    /****************************************************************/
    /* Write also registers initialized by hardware - avoid mismatch
       between documentation and hardware implementation */
    /* Write TFWR with value 3 (FIFO watermark = 192 bytes) to minimize
       chance of FIFO underflow, write STRFWD with value 0
       (store-and-forward disabled - cut-through operation selected) */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TFWR_ADDR16, 3U);
    /* Write the OPD register with pause duration of 15 slot times
    (1 slot time = 512 bit times  = approx 49us for 10BASE )*/
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_OPD_ADDR16, (0x00010000U|15U));
    /* Store and forward operation for Rx FIFO - needed for HW accelerations
       like discarding invalid frames on MAC level ENET_RACC_ADDR16[LINEDIS] */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RSFL_ADDR16, 0U);
    /* No pause frames generation */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RSEM_ADDR16, 0U);
    /* Minimal almost empty FIFO fill = 4 * 8 Bytes */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RAEM_ADDR16, 4U);
    /* Minimal space left in the almost full FIFO = 4 * 8 Bytes */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RAFL_ADDR16, 4U);
    /* Default value  */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TSEM_ADDR16, 0U);
    /* Minimal almost empty FIFO fill = 4 * 8 Bytes */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TAEM_ADDR16, 4U);
    /* Minimal space left in the almost full FIFO = 4 * 8 Bytes */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TAFL_ADDR16, 8U);
   /* Transmit protocol accelerations or payload shifts */
    u32RegisterValue=0U;
    #if (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4)
      u32RegisterValue |= ENET_TACC_IPCHK_U32;
    #endif
    #if ( (STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP))
      u32RegisterValue |= ENET_TACC_PROCHK_U32;
    #endif
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TACC_ADDR16, u32RegisterValue);
    /* Turn off all timer */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCR_ADDR16, 0U);
    /* Current time = 0 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATVR_ADDR16, 0U);
    /* Default value 0*/
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATOFF_ADDR16, 0U);
    /* Periodic event each 1e9 ticks/nanoseconds */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATPER_ADDR16, 0x3B9ACA00U);
    /* No timer correction at initialization*/
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCOR_ADDR16, 0U);
    /* Default value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATINC_ADDR16, 0U);
    /* Write 1 to clear operation - all flags cleared */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TGSR_ADDR16, 0x0fU);
    /* Default value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCCR0_ADDR16, 0U);
    /* Channel disabled */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCSR0_ADDR16, 0U);
    /* Default value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCCR1_ADDR16, 0U);
    /* Channel disabled */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCSR1_ADDR16, 0U);
    /* Default value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCCR2_ADDR16, 0U);
    /* Channel disabled */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCSR2_ADDR16, 0U);
    /* Default value */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCCR3_ADDR16, 0U);
    /* Channel disabled */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TCSR3_ADDR16, 0U);
#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
    /* Current time = 0 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATVR_ADDR16, 0U);
    /* Periodic event each 1e9 nanoseconds */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATPER_ADDR16, 0x3B9ACA00U);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATINC_ADDR16, ETH_CFG_TIMESTAMP_INC(u8CtrlIdx));
    /* No timer correction at initialization*/
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCOR_ADDR16, 0U);
    
    u32RegisterValue = (ENET_ATCR_PINPER_U32 | ENET_ATCR_EN_U32 | ENET_ATCR_PEREN_U32);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ATCR_ADDR16, u32RegisterValue);
#endif
    /* Write reset value to reserved bits of ECR */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ECR_ADDR16, ENET_ECR_DEFAULT_RESERVED_VALUE_U32);
}

/*================================================================================================*/
/**
* @brief         Configures all receive buffers
* @details       Function initializes all RX buffer descriptors - sets the Empty
*                bit and clears the rest. It computes all buffer addresses
*                and writes them into buffer descriptor pointers. The buffer
*                descriptors ring start is written to the appropriate register.
* @param[in]     u8CtrlIdx Index of controller in which Rx buffer will be configured
* @par
*                Buffers immediately follow the buffer descriptors area. All
*                buffers are of the same size, no space is between them.
*
* @warning       Buffer descriptors ring start address must be 64-bytes aligned.
*                All buffers must have length equal to multiple of 64 bytes.
*/

FUNC(void, ETH_CODE)  Eth_Enet_ConfigureRxBuffers(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32BdAddress;   /* Stores buffer descriptor address */
    VAR(uint32, AUTOMATIC) u32BufAddress;  /* Store the buffer address for ith
                                              RX buffers */
    VAR(uint32, AUTOMATIC) u32BDInit;   /* Initialization value for the BD bits */
    VAR(uint8, AUTOMATIC) u8BufCtr;    /* Counter used to loop over the buffers */
    VAR(uint32, AUTOMATIC) u32ClearAddress; /* Address of memory within BD to be
                                               cleared */
    VAR(uint8, AUTOMATIC) u8ClearCtr;  /* Counter used in loop to clear BDs */
    VAR(uint8, AUTOMATIC) u8BufNum;       /* Holds configured number of buffers */
    VAR(uint16, AUTOMATIC) u16BufLength;   /* Holds configured maximal length of
                                                                one Rx buffer */
    VAR(uint32, AUTOMATIC) u32BDValue = 0U;

    /* Get the length of one Rx buffer */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u16BufLength = ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx);
    /*Workaroand in this register value case is clear, After the function Eth_SetControllerMode is called to put the controller into DOWN state*/
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MRBR_ADDR16, (VAR(uint32,AUTOMATIC))u16BufLength);  
    /* Get the number of configured buffers */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    u8BufNum = ETH_CFG_RXBUFTOTAL( u8CtrlIdx);
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /* Get start address of Rx buffer descriptor rings */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    u32BdAddress = ETH_CFG_RXBDSTARTADDRESS( u8CtrlIdx);
    /* Store the value into register - select only necessary bits */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RDSR_ADDR16, (u32BdAddress & ENET_RDSR_R_DES_START_U32));
    /* Assemble the initial value of 1st 32bits of BDs */
    u32BDInit = ENET_RXBD_E_U32; /* Set only Empty bit, clear the rest */
    /* Compute address of the first receive buffer data area - it has to be 64
       bytes aligned which is granted by following:
       - Buffer descriptors start address is generated as 64-bytes aligned.
       - All new buffer descriptors are 32 bytes long and create continuous block
         so the end of the block is either 32 bytes or 64 bytes aligned.
       - Buffer descriptors area is extended by 32 bytes if the descriptors block end
         is aligned to 32 bytes only. (these 32 bytes are unused)
       - Buffer area follows immediately after the buffer descriptors area.
       - Buffer lengths are limited to be multiple of 64 bytes, they also create
         a continuous block so they all are 64 bytes aligned.
    */
    /* Leave space for buffer descriptors */
    u32BufAddress = u32BdAddress + (u8BufNum * (VAR(uint32, AUTOMATIC))32U);
    /* Check whether the number of buffers is odd */
    /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7 */
    if(0U != (u8BufNum & 0x01U))
    {/* Yes */
        u32BufAddress += 32U;
    }
#if STD_ON == ETH_USE_MULTIBUFFER_RX_FRAMES
#if STD_ON == ETH_USE_RX_FRAMES_WRAP
    /* Create a space for leading buffers 
       Payload(1500) + MAC(2*6) + VLAN(4) + TypeLength(2) + CRC(4) = 1522
       However, we should add 1536 for properly align and compute.
       Just add when the u16BufLength smaller than 1522, otherwise, the message should store in a single buffer only.
    */
/** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7 */
if (1522U > u16BufLength)
{
    u32BufAddress += (VAR(uint32, AUTOMATIC))((((1536U / 2U) + ((VAR(uint32, AUTOMATIC))u16BufLength - 1U)) / u16BufLength) * u16BufLength);
}
#endif /* ETH_USE_RX_FRAMES_WRAP */
#endif /* ETH_USE_MULTIBUFFER_RX_FRAMES */
    /* Store the start of RX buffers for the future use */
    Eth_ENET_u32RxBufStartAddr[u8CtrlIdx] = u32BufAddress;
    /* Write each buffer descriptor with u32BDInit value, the buffer pointer and clear the rest */
    for(u8BufCtr = 0U; u8BufCtr < u8BufNum; u8BufCtr++)
    {
        /* Write buffer descriptor control bits and length - buffer only needs
           to be marked as empty, all other fields will be updated
           during reception */
        Eth_Enet_WriteRxBDBitsA(u32BdAddress, u8BufCtr, u32BDInit);
        /* Write buffer address into descriptor */
        Eth_Enet_WriteRxBDBufPtr(u32BdAddress, u8BufCtr, u32BufAddress);
        /* Clear the rest 24 bytes of the buffer descriptor; start at offset 8U */
        u32ClearAddress = u32BdAddress + ((VAR(uint32, AUTOMATIC))32U * u8BufCtr) + 8U;
        for(u8ClearCtr = 0U; u8ClearCtr < 6U; u8ClearCtr++)
        {
            /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
            */
            REG_WRITE32(u32ClearAddress, (VAR(uint32, AUTOMATIC))0U);
            u32ClearAddress += 4U;
        }
        /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7 */
        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        /** @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1 */
        if((VAR(boolean, AUTOMATIC))TRUE == (VAR(boolean, AUTOMATIC))ETH_CFG_ENABLERXINTERRUPT( u8CtrlIdx))
        { 
            /* Prepare RX BD to invoke interrupt after reception */
            u32BDValue = ENET_RXBD_INT_U32;
        }
    #if (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4)
        u32BDValue |= ENET_RXBD_ICE_U32;
    #endif
    #if ( (STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP))
        u32BDValue |= ENET_RXBD_PCR_U32;
    #endif 
        Eth_Enet_WriteRxBDBitsB(u32BdAddress, u8BufCtr, u32BDValue);
        /* Compute address of the next buffer */
        u32BufAddress = u32BufAddress + u16BufLength;
    }
    /* Close the descriptor ring */
    u32BDInit = u32BDInit | ENET_RXBD_W_U32; /* This is the last descriptor, set also WRAP bit */
    Eth_Enet_WriteRxBDBitsA(u32BdAddress, (VAR(uint8, AUTOMATIC)) (u8BufNum - 1U), u32BDInit);  /* Mark the last one */
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    (void)Mcl_CacheFlushMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx), ETH_RX_BUF_MEM_SIZE);
    #endif
  #endif
#endif
}

/*================================================================================================*/
/**
* @brief         Configures all transmit buffers
* @details       Function marks all buffer descriptors as not ready for the
*                transmission (clears the Ready bit) and clears all user bits
*                (used as Lock, Transmitted flags). Then it computes all buffer
*                addresses and writes them into the buffer descriptor pointers.
*                The rest of buffer descriptor is cleared.
*                The buffer descriptors ring start address is written it the
*                appropriate register.
* @param[in]     u8CtrlIdx Index of controller in which Tx Buffer will be configured
* @par
*                All buffers of same size, immediately follow buffer descriptors
*                as a continuous block without empty spaces between buffers.
* @warning       Buffer descriptors ring start address must be 16-bytes aligned.
*                Buffer sizes are limited to be multiple of 16 bytes.
*/

FUNC(void, ETH_CODE) Eth_Enet_ConfigureTxBuffers(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32BdAddress;   /* Stores buffer descriptor address */
    VAR(uint32, AUTOMATIC) u32BufAddress;  /* Used to compute buffer address */
    VAR(uint32, AUTOMATIC) u32BDInit;    /* Initialization value for the BD bits */
    VAR(uint8, AUTOMATIC) u8BufCtr;    /* Counter used to loop over the buffers */
    VAR(uint32, AUTOMATIC) u32ClearAddress; /* Address of memory within BD to be
                                               cleared */
    VAR(uint8, AUTOMATIC) u8ClearCtr;  /* Counter used in loop to clear BDs */
    /* Access to local variable is faster than  via pointer in case of post-build
       or link-time configuration. Configured value should be somewhere stored in
       case of pre-compile configuration. */
    VAR(uint8, AUTOMATIC) u8BufNum;       /* Holds configured number of buffers */
    VAR(uint16, AUTOMATIC) u16BufLength;   /* Holds configured maximal length
                                                             of one Rx buffer */
    VAR(uint32, AUTOMATIC) u32BDValue = 0U;

    /* Get the length of one Rx buffer */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    u16BufLength = ETH_CFG_CTRLTXBUFLENBYTE( u8CtrlIdx);
    /* Get the number of configured buffers */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    u8BufNum = ETH_CFG_TXBUFTOTAL( u8CtrlIdx);
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /* Get start address of Rx buffer descriptor rings */
    /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    u32BdAddress = ETH_CFG_TXBDSTARTADDRESS( u8CtrlIdx);
    /* Store the value into register - select only necessary bits */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TDSR_ADDR16, (u32BdAddress & ENET_TDSR_X_DES_START_U32));
    /* Assemble the configuration value */
    /* All 16 control bits are cleared, length set with mask ENET_TXBD_LENGTH_U32 */
    u32BDInit = (VAR(uint32, AUTOMATIC))u16BufLength & ENET_TXBD_LENGTH_U32;
    /* Compute address of the first transmit buffer data area - it has to be 64
       bytes aligned which is granted by following:
       - Buffer descriptors start address is generated as 64-bytes aligned.
       - All new buffer descriptors are 32 bytes long and create continuous block
         so the end of the block is either 32 bytes or 64 bytes aligned.
       - Buffer descriptors area is extended by 32 bytes if the descriptors block end
         is aligned to 32 bytes only. (these 32 bytes are unused)
       - Buffer area follows immediately after the buffer descriptors area.
       - Buffer lengths are limited to be multiple of 64 bytes, they also create
         a continuous block so they all are 64 bytes aligned.
    */
    /* Leave space for buffer descriptors */
    /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7 */
    if(0U == (u8BufNum & 0x01U))
    {   /* Even number of descriptors - first data pointer is already aligned to 64 bytes */
        u32BufAddress = u32BdAddress + ((VAR(uint32, AUTOMATIC))32U * u8BufNum);
    }
    else
    {   /* Odd number of descriptors - leave 32 bytes to get the first data pointer aligned to 64 bytes */
        u32BufAddress = u32BdAddress + ((VAR(uint32, AUTOMATIC))32U * u8BufNum) + 32U;
    }
    /* Store the TX buffer start address for future use */
    Eth_ENET_u32TxBufStartAddr[u8CtrlIdx] = u32BufAddress;
    /* Write the buffer pointers to buffer descriptors and initialize
       status bits of all buffers */
    for(u8BufCtr = 0U; u8BufCtr < u8BufNum; u8BufCtr++)
    {
        /* Write buffer descriptor control bits and length - buffer only needs
           to be  marked not ready, all other fields will be updated
           before transmission */
        Eth_Enet_WriteTxBDBitsA(u32BdAddress, u8BufCtr, u32BDInit);
        /* Write buffer address into descriptor */
        Eth_Enet_WriteTxBDBufPtr(u32BdAddress, u8BufCtr, u32BufAddress);
        /* Clear the rest 24 bytes of the buffer descriptor; start at offset 8U */
        u32ClearAddress = u32BdAddress + ((VAR(uint32, AUTOMATIC))32U * u8BufCtr) + 8U;
        for(u8ClearCtr = 0U; u8ClearCtr < 6U; u8ClearCtr++)
        {
            /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
            */
            REG_WRITE32(u32ClearAddress, (VAR(uint32, AUTOMATIC))0U);
            u32ClearAddress += 4U;
        }
        /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7 */
        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
        /** @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1 */
        if  ((VAR(boolean, AUTOMATIC))TRUE == (VAR(boolean, AUTOMATIC))ETH_CFG_ENABLETXINTERRUPT( u8CtrlIdx))
        { 
            u32BDValue = ENET_TXBD_INT_U32;
        }
      #if (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4)
        u32BDValue |= ENET_TXBD_IINS_U32;
      #endif
      #if ( (STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP))
        u32BDValue |= ENET_TXBD_PINS_U32;
      #endif 
          #if (STD_ON == ETH_GLOBALTIME_SUPPORT)
            u32BDValue |= ENET_TXBD_TS_U32;
          #endif
        Eth_Enet_WriteTxBDBitsB(u32BdAddress, u8BufCtr, u32BDValue);
        /* Compute address of the next buffer */
        u32BufAddress = u32BufAddress + u16BufLength;
        /* Reset buffer flags */
        Eth_au8TxBufFlags[u8CtrlIdx][u8BufCtr] = 0U;
    }
    /* Close the descriptor ring */
    u32BDInit = u32BDInit | ENET_TXBD_W_U32; /* This is the last descriptor */
    Eth_Enet_WriteTxBDBitsA(u32BdAddress, (VAR(uint8, AUTOMATIC)) (u8BufNum - 1U), u32BDInit);  /* Mark the last one */
    /* Start free buffer search from beginning */
    Eth_ENET_u8SearchTxBufFrom[u8CtrlIdx] = 0U;
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    (void)Mcl_CacheFlushMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE);
    #endif
  #endif
#endif
}


/*================================================================================================*/
/**
* @brief         Starts the controller
* @param[in]     u8CtrlIdx Index of controller which will be enabled
* @details       Function enables the controller after that it activates receive
*                and transmit buffer descriptors rings.
*/

FUNC(void, ETH_CODE) Eth_Enet_EnableController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32TempRegisterValue;   /* Stores buffer descriptor address */
    
    /* Init the active Rx buffer descriptor pointer -
       the BDs are reset during controller reset or disablement */
    Eth_u8ActiveRxBuf[u8CtrlIdx] = 0U;
    Eth_u8ActiveTxBD[u8CtrlIdx] = 0U;
    Eth_u8LockedTxBufCount[u8CtrlIdx] = 0U;
    
    u32TempRegisterValue = ENET_ECR_ETHEREN_U32 | ENET_ECR_EN1588_U32 | ENET_ECR_DEFAULT_RESERVED_VALUE_U32;
    /* Enable the controller with enhanced functionality
       Needs to be done first */
#ifdef MCAL_PLATFORM_ARM
    /* Buffer descriptors are swapped - little endian platforms */
    u32TempRegisterValue |= ENET_ECR_DBSWP_U32;
#endif

#if (STD_ON == ETH_GIGABIT_SUPPORT)
    /** @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7
        @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1
    */
    if (((VAR(boolean, AUTOMATIC))TRUE) == ETH_CFG_GIGABITSUPPORT(u8CtrlIdx))
    {
        u32TempRegisterValue |= ENET_ECR_SPEED_U32;
    }
#endif
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ECR_ADDR16, u32TempRegisterValue);
    /* Tell the controller to check Rx buffer descriptors */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RDAR_ADDR16, ENET_RDAR_R_DES_ACTIVE_U32);
    /* Tell the controller to check Tx buffer descriptors  */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_TDAR_ADDR16, ENET_TDAR_X_DES_ACTIVE_U32);
}


/*================================================================================================*/
/**
* @brief         Immediately stops the controller
* @details       Function clears the ECR[ETHER_EN] bit which causes
*                - receiver to stop
*                - transmitter to append bad CRC and stop, descriptor of
*                  this frame is no updated
*                - DMA, FIFO control and buffer descriptors reset
* @param[in]     u8CtrlIdx Index of controller which will be disabled
* @par
*                Actions needed to recover:
*                - set ECR[ETHER_EN] (reenable the controller)
*                - write RDAR, TDAR (tell that some buffers are prepared)
*/
FUNC(void, ETH_CODE) Eth_Enet_DisableController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /* Clear the ECR[ETHER_EN] bit */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ECR_ADDR16, ENET_ECR_DEFAULT_RESERVED_VALUE_U32);
}


/*================================================================================================*/
/**
* @brief         Check whether the controller is running
* @details       Function checks the ECR[ETHER_EN] bit to determine whether
*                the controller has been stopped or whether it is running.
* @param[in]     u8CtrlIdx Index of controller which will be checked active status
* @return        The current controller mode.
* @retval        ETH_MODE_ACTIVE The controller is running.
* @retval        ETH_MODE_DOWN The controller is stopped.
*/

FUNC(Eth_ModeType, ETH_CODE) Eth_Enet_CheckCtrlIsActive (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(Eth_ModeType, AUTOMATIC) eReturnValue; /* Return value holder */
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to access register */

    /* Find whether the module is on by reading ECR[ETHER_EN]*/
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_ECR_ADDR16);
    if(ENET_ECR_ETHEREN_U32 == (u32RegisterValue & ENET_ECR_ETHEREN_U32))
    {    /* Module is on */
         eReturnValue = ETH_MODE_ACTIVE;
    }
    else
    {    /* Module is off */
         eReturnValue = ETH_MODE_DOWN;
    }
    return eReturnValue;
}


/*================================================================================================*/
/**
* @brief         Clears the RXF (received frame) flag
* @param[in]     u8CtrlIdx Index of controller in which RxIRQ flag will be cleared
*/

FUNC(void, ETH_CODE) Eth_Enet_ClearRxIrqFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16, ENET_EIR_RXF_W1C);
}

/*================================================================================================*/
/**
* @brief         Clears the TXF (transmitted frame) flag
* @param[in]     u8CtrlIdx Index of controller in which TxIRQ flag will be cleared
*/

FUNC(void, ETH_CODE) Eth_Enet_ClearTxIrqFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16, ENET_EIR_TXF_W1C);
}

/*================================================================================================*/
/**
* @brief         Checks whether the TXF flag is set
* @details       This function can be used to check whether the frame
*                transmitted interrupt flag is set.
* @param[in]     u8CtrlIdx Index of controller in which TxIRQ flag will be checked
* @retval        TRUE if the TXF flag is set
* @retval        FALSE if the TXF flag is cleared
*/
FUNC(boolean, ETH_CODE) Eth_Enet_IsTxIrqFlagSet(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to read register value */
    VAR(boolean, AUTOMATIC) bReturnValue; /* Stores the result */

    /* Read the register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16);
    /* Check whether the bit is set */
    if(ENET_EIR_TXF_W1C == (u32RegisterValue & ENET_EIR_TXF_W1C))
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))FALSE;
    }

    /* Define FJP for testing */
    MCAL_FAULT_INJECTION_POINT(ETH_FIP_1_ISTXIRQFLAGSET_RET);

    return bReturnValue;

}

/*================================================================================================*/
/**
* @brief         Checks whether the RXF flag is set
* @details       This function can be used to check whether the frame received
*                interrupt flag is set.
* @param[in]     u8CtrlIdx Index of controller in which RxIRQ flag will be checked
* @retval        TRUE if the RXF flag is set
* @retval        FALSE if the RXF flag is cleared
*/
FUNC(boolean, ETH_CODE) Eth_Enet_IsRxIrqFlagSet(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to read register value */
    VAR(boolean, AUTOMATIC) bReturnValue; /* Stores the result */

    /* Read the register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16);
    /* Check whether the bit is set */
    if(ENET_EIR_RXF_W1C == (u32RegisterValue & ENET_EIR_RXF_W1C))
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))FALSE;
    }

    /* Define FJP for testing */
    MCAL_FAULT_INJECTION_POINT(ETH_FIP_2_ISRXIRQFLAGSET_RET);

    return bReturnValue;
}

/*================================================================================================*/
/**
* @brief         Checks whether the transmit interrupt is enabled.
* @param[in]     u8CtrlIdx Index of controller in which TxIRQ mask will be checked
* @retval        TRUE the interrupt is enabled
* @retval        FALSE the interrupt is disabled
*/
FUNC(boolean, ETH_CODE) Eth_Enet_IsTxIrqEnabled(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to read register value */
    VAR(boolean, AUTOMATIC) bReturnValue; /* Stores the result */

    /* Read the register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIMR_ADDR16);
    /* Check whether the bit is set */
    if(ENET_EIMR_TXF_U32 == (u32RegisterValue & ENET_EIMR_TXF_U32))
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))FALSE;
    }
    return bReturnValue;
}

/*================================================================================================*/
/**
* @brief         Checks whether the receive interrupt is enabled.
* @param[in]     u8CtrlIdx Index of controller in which RxIRQ mask will be checked
* @retval        TRUE the interrupt is enabled
* @retval        FALSE the interrupt is disabled
*/
FUNC(boolean, ETH_CODE) Eth_Enet_IsRxIrqEnabled(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to read register value */
    VAR(boolean, AUTOMATIC) bReturnValue; /* Stores the result */

    /* Read the register */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIMR_ADDR16);
    /* Check whether the bit is set */
    if(ENET_EIMR_RXF_U32 == (u32RegisterValue & ENET_EIMR_RXF_U32))
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))FALSE;
    }
    return bReturnValue;
}
/*================================================================================================*/
/**
* @brief         Returns lower four bytes of the controllers MAC address
* @details       Function reads MAC address from the register and returns it.
*                0xAABBCCDD is returned if the controller MAC address
*                is AA:BB:CC:DD:EE:FF
* @param[in]     u8CtrlIdx Index of controller to get 4 low bytes of PhysAddress
* @return        First four bytes of the MAC address.
*/

FUNC(uint32, ETH_CODE) Eth_Enet_GetPhysAddressLow(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /* Return lower 32 bits of MAC address */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    return REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PALR_ADDR16);
}
#ifdef ETH_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == ETH_ENABLE_USER_MODE_SUPPORT)
#ifdef ETH_ENET_REG_PROT_AVAILABLE  
/** 
* @brief        Enable user mode support to access ENET registers
*
* @details      Set UAA bit in ETH_REG_PROT_GCR to allow user access locked registers in ENET module
*
* @param[in]    none
* @retval       none
*
* @pre         The user mode is enabled
*    
*/
/** @violates @ref Eth_Enet_c_REF_10 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_Enet_SetUserAccessAllowed(void)
{
   /* Set UAA bit in REG_PROT register */
   #ifdef ENET_0_UNDER_REG_PROT
    /* Note: the register protection user access allowed bit(REG_PROT_GCR[UAA]) is programmed
             when at least one supervisor-mode access is made to the ENET module */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */        
   (void)REG_READ32(Eth_u32BaseAddr[0] + ENET_MMFR_ADDR16);
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
        @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 
    */
       SET_USER_ACCESS_ALLOWED(ENET_0_BASEADDR, ENET_PROT_MEM_U32);
   #endif
   #ifdef ENET_1_UNDER_REG_PROT
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
      SET_USER_ACCESS_ALLOWED(ENET_1_BASEADDR, ENET_PROT_MEM_U32);
   #endif
}
#endif /* STD_ON == ETH_ENABLE_USER_MODE_SUPPORT */
#endif
#endif
/*================================================================================================*/
/**
* @brief         Returns upper four bytes of the controllers MAC address
* @details       Function reads MAC address from the register and returns it.
*                0xEEFF is returned if the controller MAC address is
*                AA:BB:CC:DD:EE:FF.
* @param[in]     u8CtrlIdx Index of controller to get 2 high bytes of PhysAddress
* @return        Last two bytes of the MAC address.
*/

FUNC(uint16, ETH_CODE) Eth_Enet_GetPhysAddressHigh(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegisterValue;

    /* Get upper 16 bits of MAC address and move them to appropriate position */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
    */
    u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PAUR_ADDR16);
    u32RegisterValue = u32RegisterValue >> 16U;
    /* Return the obtained value */
    return (VAR(uint16, AUTOMATIC)) u32RegisterValue;
}

/*================================================================================================*/
/**
* @brief         Update physical address of the controller.
* @param[in]     pPhysAddrPtr Pointer to MAC address which should set to
*                controller. The address in network byte order stored into 6
*                bytes of memory.
* @param[in]     u8CtrlIdx Index of controller to set the PhysAddr
* @caution       This function may be called only when the controller is down.
*                Call of function Eth_ControllerInit change MAC address
*                to the default value!
* @implements    Eth_Enet_SetPhysAddr_Activity
*/

FUNC(boolean, ETH_CODE) Eth_Enet_SetPhysAddr(CONST(uint8, AUTOMATIC) u8CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr)
{
    VAR(boolean, AUTOMATIC) bReturnStatus = (VAR(boolean, AUTOMATIC))FALSE;
    VAR(uint32, AUTOMATIC) u32RegisterValue = 0U;

    /* Change mac address only when the controller is down */
    if(ETH_MODE_DOWN == Eth_Enet_CheckCtrlIsActive(u8CtrlIdx))
    {
        /* Prepare lower bytes of MAC */
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32RegisterValue = (u32RegisterValue << 8U) | (uint32)(*(pPhysAddrPtr + 0U));
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32RegisterValue = (u32RegisterValue << 8U) | (uint32)(*(pPhysAddrPtr + 1U));
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32RegisterValue = (u32RegisterValue << 8U) | (uint32)(*(pPhysAddrPtr + 2U));
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32RegisterValue = (u32RegisterValue << 8U) | (uint32)(*(pPhysAddrPtr + 3U));
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PALR_ADDR16, u32RegisterValue);
        /* Prepare higher bytes of MAC */
        u32RegisterValue = 0U;
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32RegisterValue =  (u32RegisterValue << 8U) | (uint32)(*(pPhysAddrPtr + 4U));
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        u32RegisterValue =  (u32RegisterValue << 8U) | (uint32)(*(pPhysAddrPtr + 5U));
        u32RegisterValue = (u32RegisterValue << 16U) | 0x8808U;
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_PAUR_ADDR16, u32RegisterValue);
        /* Set return status */
        bReturnStatus = (VAR(boolean, AUTOMATIC))TRUE;
    }
    return bReturnStatus;
}

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
/*================================================================================================*/
/**
* @brief        Handle multicast addresses add or remove operations
* @details      This function handle add and remove operations with multicast
*               receive pool.
*               Handled pool of MAC address specifies the addresses which
*               will be pass to higher layers at frame reception.
* @param[in]    u8CtrlIdx Index of controller to be update the filter
* @param[in]    pPhysAddrPtr Pointer to the MAC address in network
*               byte order which will be added or removed to or from a pool.
* @param[in]    eAction This parameter defines the operation with a pool.
*               Value ETH_ADD_TO_FILTER behaves function to add new address into
*               a pool and ETH_REMOVE_FROM_FILTER means operation of removal
*               from the pool.
* @implements   Eth_Enet_UpdtePhysAddrFiltr_Activity
*/
FUNC(void, ETH_CODE) Eth_Enet_UpdtePhysAddrFiltr    ( \
            CONST(uint8, AUTOMATIC) u8CtrlIdx, \
            P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
            VAR(Eth_FilterActionType, AUTOMATIC) eAction \
                                                    )
{
    /* Indicator of full open filter action */
    VAR(boolean, AUTOMATIC) bFullFilterOpenRequest;
    /* Indicator of full close filter action */
    VAR(boolean, AUTOMATIC) bFullFilterCloseRequest;
    /* Pattern for full open filter request */
    VAR(uint8, AUTOMATIC) au8FullFilterOpenPattern[6U];
    /* Pattern for full close filter request */
    VAR(uint8, AUTOMATIC) au8FullFilterClosePattern[6U];
    VAR(uint32, AUTOMATIC) u32RegVal;
    VAR(uint32, AUTOMATIC) u32RegisterValue;
    
    u32RegisterValue =  ETH_CFG_RCR( u8CtrlIdx);
    /* The following arrays initialization is a workaround for 
       compilers bug (mixing of vle and non-vle instructions)
    */    
    au8FullFilterOpenPattern[0] = 0xFFU;
    au8FullFilterOpenPattern[1] = 0xFFU;
    au8FullFilterOpenPattern[2] = 0xFFU;
    au8FullFilterOpenPattern[3] = 0xFFU;
    au8FullFilterOpenPattern[4] = 0xFFU;
    au8FullFilterOpenPattern[5] = 0xFFU;
    au8FullFilterClosePattern[0] = 0U;
    au8FullFilterClosePattern[1] = 0U;
    au8FullFilterClosePattern[2] = 0U;
    au8FullFilterClosePattern[3] = 0U;
    au8FullFilterClosePattern[4] = 0U;
    au8FullFilterClosePattern[5] = 0U;    
    /* Fill full open filter indicator */
    /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
    bFullFilterOpenRequest = Eth_Enet_ComparePhysAddr( pPhysAddrPtr, au8FullFilterOpenPattern);
    /* Fill full close filter indicator */
    /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
    bFullFilterCloseRequest = Eth_Enet_ComparePhysAddr( pPhysAddrPtr, au8FullFilterClosePattern);
    switch(eAction)
    {
        case ETH_ADD_TO_FILTER:
            if ((VAR(boolean, AUTOMATIC))TRUE == bFullFilterOpenRequest)
            { /* Full open filter action (ETH_ADD_TO_FILTER) */
                /* Multicast filter will be bypassed at reception */
                Eth_ENET_bMcastFullOpen[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))TRUE;
                /* Open all groups in GALR register */
               /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                   @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GALR_ADDR16, 0xffffffffU);
                /* Open all groups in GAUR register */
                /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
                    @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_GAUR_ADDR16, 0xffffffffU);
            }
            else if ((VAR(boolean, AUTOMATIC))TRUE == bFullFilterCloseRequest)
            { /* Full close filter action (ETH_ADD_TO_FILTER) */
                /* Full close request excludes previous full open request */
                Eth_ENET_bMcastFullOpen[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
                /* Clean overflow flag */
                Eth_ENET_bMcastPoolOvf[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
                /* Clean the table */
                Eth_Enet_McastPoolClean(u8CtrlIdx);
                /* Reset the filter */
                Eth_Enet_McastGAClean(u8CtrlIdx);
                /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                    @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                */
                u32RegVal = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16);
                if ((uint32)0U!= (u32RegVal & ENET_RCR_PROM_U32))
                {
                    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                        @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                    */
                    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16, (~((uint32)ENET_RCR_PROM_U32)) & u32RegVal);
                }                
            }
            else
            { 
                /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                    @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                 */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16, u32RegisterValue);
                /* Regular adding of PhysAddr into the pool (ETH_ADD_TO_FILTER) */
                if ((VAR(boolean, AUTOMATIC))FALSE == Eth_Enet_McastPoolAddItem(u8CtrlIdx, pPhysAddrPtr))
                { /* Table is full */
                    /* Once table is full Overflow tag is set  */
                    Eth_ENET_bMcastPoolOvf[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))TRUE;
                }
                /* Open Group Address for requested Physical Address */
                Eth_Enet_McastGAAdd(u8CtrlIdx, pPhysAddrPtr);
            }
            break;
        case ETH_REMOVE_FROM_FILTER:
            if ((VAR(boolean, AUTOMATIC))TRUE == bFullFilterOpenRequest)
            { 
                /* Full open filter action (ETH_REMOVE_FROM_FILTER)  */
                Eth_ENET_bMcastFullOpen[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
                /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                    @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16, u32RegisterValue);
            }
            else if ((VAR(boolean, AUTOMATIC))TRUE == bFullFilterCloseRequest)
            { /* Full close filter action (ETH_REMOVE_FROM_FILTER) */
                /* Full close request excludes previous full open request */
                Eth_ENET_bMcastFullOpen[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
                /* Clean overflow flag */
                Eth_ENET_bMcastPoolOvf[u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
                /* Clean the table */
                Eth_Enet_McastPoolClean(u8CtrlIdx);
                /* NOTE: Filter Reset is done at recalculation */
                /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                    @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                 */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16, u32RegisterValue);
            }
            else
            { /* Regular removal of Physical Address from Pool */
                (VAR(void, AUTOMATIC))Eth_Enet_McastPoolRmvItem(u8CtrlIdx, pPhysAddrPtr);
                /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                    @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1
                 */
                REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_RCR_ADDR16, u32RegisterValue);
            }
            if (((VAR(boolean, AUTOMATIC))FALSE == Eth_ENET_bMcastPoolOvf[u8CtrlIdx]) && ((VAR(boolean, AUTOMATIC))FALSE == Eth_ENET_bMcastFullOpen[u8CtrlIdx]))
            { /* No Pool overflow or full open request */
                /* Recalculate the pool addresses */
                Eth_Enet_McastGARecalculate(u8CtrlIdx);
            }
            break;
        default:
            /* Required by MISRA but no action needed */
            break;
    }
}
#endif /* STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER */


/*================================================================================================*/
/**
* @brief         Clears all MIB Counters
* @details       Function disables the counters block, writes value 0 to all
*                counters and reenables the counters block.
* @param[in]     u8CtrlIdx Index of controller to be cleared the counters
*/

FUNC(void, ETH_CODE) Eth_Enet_ClearMIBCounters(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint32, AUTOMATIC) u32RegVal;

    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    u32RegVal = (VAR(uint32, AUTOMATIC))REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MIBC_ADDR16);
    /* Disable MIB updates */
    u32RegVal |= ENET_MIBC_MIB_DIS_U32;
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MIBC_ADDR16, u32RegVal);
    /* Set MIB_CLEAR bit to clear all counters */
    u32RegVal |= ENET_MIBC_MIB_CLEAR_U32;
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MIBC_ADDR16, u32RegVal);
    /* Clear MIB_CLEAR bit (it is not self clearing) */
    u32RegVal &= ~(ENET_MIBC_MIB_CLEAR_U32);
    /* Enable updates */
    u32RegVal &= ~(ENET_MIBC_MIB_DIS_U32);
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MIBC_ADDR16, u32RegVal);
}
#if STD_ON == ETH_CTRLENABLE_MII
/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     u8CtrlIdx Index of controller to be transferred
* @param[in]     u8Trcv Transceiver to communicate with
* @param[in]     u8Reg Register which shall be accessed
* @param[in,out] pData Written/read data
* @param[in]     u32Operation Selection between write and read access
* @details       Function assembles the management frame and issues the bus
*                transaction, then it waits until the transaction finishes
*                and read data is returned in case of read access.
*                Waiting loop can be  broken if it reaches configured
*                number of iterations.
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
* @note          Function is present only if the macro ETH_CTRLENABLE_MII value
*                is equal to STD_ON.
*/
FUNC(boolean, ETH_CODE) Eth_Enet_DoMiiMMF   ( \
                        CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                        CONST(uint8, AUTOMATIC) u8Trcv, \
                        CONST(uint8, AUTOMATIC) u8Reg, \
                        CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pData, \
                        CONST(uint32, AUTOMATIC) u32Operation \
                                            )
{
    VAR(uint32, AUTOMATIC) u32RegisterValue; /* Used to assemble
                register value before writing and for registers reads */
    VAR(uint32, AUTOMATIC) u32ManipulationVar; /* Used for bit manipulations */
    VAR(volatile uint32, AUTOMATIC) u32ProtectionCounter; /* The loop is
            claimed infinite when this counter reaches configured value */
    VAR(boolean, AUTOMATIC) bReturnStatus;

    /* Initialize the loop status variables - The loop works correctly */
    bReturnStatus = ((VAR(boolean, AUTOMATIC))TRUE);
    /* Write the initial value */
    u32ProtectionCounter = 0U;
    /* Clear the EIR[MII] flag by writing 1 to it */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16, ENET_EIR_MII_W1C);
    /* Start assembling the frame with ST, TA field and select operation */
    u32RegisterValue = (VAR(uint32, AUTOMATIC)) (ENET_MMFR_ST_VAL_U32 | u32Operation | ENET_MMFR_TA_VAL_U32);
    /* Add the PHY address */
    /* Move it to the right position */
    u32ManipulationVar = (VAR(uint32, AUTOMATIC))u8Trcv << 23U;
    /* Clear any inappropriate bits */
    u32ManipulationVar = u32ManipulationVar & ENET_MMFR_PA_U32;
    u32RegisterValue = u32RegisterValue | u32ManipulationVar; /* Apply it */
    /* Add the register address */
    /* Move it to the right position */
    u32ManipulationVar = (VAR(uint32, AUTOMATIC))u8Reg << 18U;
    /* Clear any inappropriate bits */
    u32ManipulationVar = u32ManipulationVar & ENET_MMFR_RA_U32;
    u32RegisterValue = u32RegisterValue | u32ManipulationVar; /* Apply it */
    /* Add data - ignored by read operation */
    u32RegisterValue = u32RegisterValue | (* pData);
    /* Write assembled value to the register - it
       triggers the MII MMF transaction */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MMFR_ADDR16, u32RegisterValue);
    /* Wait until transaction is finished */
    do
    {
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16);
        /* Infinite loop protection */
        /* Check whether the loop is infinite */
        if(u32ProtectionCounter >= ETH_INFINITE_LOOP_PROTECTION)
        {   /* Yes */
            /* Loop is infinite and has to be broken*/
            bReturnStatus = ((VAR(boolean, AUTOMATIC))FALSE);
            #if STD_ON == DEBUG_VARIABLES
                Eth_MiiFailed[u8CtrlIdx] = Eth_MiiFailed[u8CtrlIdx] + 1U;
            #endif
            break;                /* Break the loop */
        }
        u32ProtectionCounter = u32ProtectionCounter + 1U; /* Increment counter */

    }
    while(ENET_EIR_MII_W1C != (u32RegisterValue & ENET_EIR_MII_W1C));
    /* Check whether the previous code has been succesful */
    if(((VAR(boolean, AUTOMATIC))TRUE) == bReturnStatus)
    {   /* Everything OK, continue */
        /* Read the data value from register - should
           be ignored by write operation */
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        u32RegisterValue = REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_MMFR_ADDR16);
        * pData = (VAR(uint16, AUTOMATIC))(u32RegisterValue & ENET_MMFR_DATA_U32);
    }
    return bReturnStatus;
}
#endif /* ETH_CTRLENABLE_MII */

#if STD_ON == ETH_GETDROPCOUNTAPI
FUNC(void, ETH_CODE) Eth_Enet_GetDropCount  ( \
                              CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                              P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pCountValuesPtr, \
                              P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pDropCountPtr \
                                           )
{
    VAR(uint8, AUTOMATIC) u8Count;

    if (*pCountValuesPtr > ETH_ENET_MAX_DROPLIST)
    {
        *pCountValuesPtr=ETH_ENET_MAX_DROPLIST;
    }
    for (u8Count=0U; u8Count<*pCountValuesPtr; u8Count++)
    {
        if (0xFFFFU != u16DropCountArray[u8Count])
        {
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
                @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
                @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            *(pDropCountPtr + u8Count) = \
                REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))u16DropCountArray[u8Count]);
        }
        else
        {
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            *(pDropCountPtr + u8Count) = (VAR(uint8, AUTOMATIC))0U;
        }
    }
}
#endif

#if STD_ON == ETH_GET_ETHERSTATS_API
FUNC(void, ETH_CODE) Eth_Enet_GetEtherStats     ( \
                      CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                      P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pEtherStats \
                                               )
{
    VAR(uint8, AUTOMATIC) u8Count;
    
    for (u8Count=0U; u8Count<ETH_ENET_NUMBEROFETHERSTAT; u8Count++)
    {
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        *(pEtherStats + u8Count) = \
            REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))u16EtherStatsArray[u8Count]);
    }
}
#endif

FUNC(void, ETH_CODE) Eth_Enet_MainFunction(VAR(void, AUTOMATIC))
{
    static VAR(Eth_ModeType, AUTOMATIC) eOldMode[ETH_MAXCTRLS_SUPPORTED]={ETH_MODE_DOWN};
    VAR(Eth_ModeType, AUTOMATIC) eCurrentMode;
    VAR(uint8, AUTOMATIC) u8EthIfCtrlIdx;      
    VAR(uint8, AUTOMATIC) u8CtrlIdx;
    
    for (u8CtrlIdx=0U; u8CtrlIdx<ETH_MAXCTRLS_SUPPORTED; u8CtrlIdx++)
    {
        u8EthIfCtrlIdx=ETH_CFG_CTRLIDXINETHIF( u8CtrlIdx); /* Get the value */
        /* SWS_Eth_00240 - check mode changed and notified to EthIF*/
        eCurrentMode=Eth_Enet_CheckCtrlIsActive(u8CtrlIdx);
        if (eOldMode[u8CtrlIdx]!=eCurrentMode)
        {
            eOldMode[u8CtrlIdx]=eCurrentMode;
            EthIf_CtrlModeIndication(u8EthIfCtrlIdx, eCurrentMode);
        }

#if(STD_ON == ETH_DEM_EVENT_DETECT)
        /* ETH_E_ACCESS */
    #ifdef ETH_SUPPORT_CHECK_ACCESS_CTRL
      #if (STD_ON == ETH_SUPPORT_CHECK_ACCESS_CTRL)
        if ((VAR(boolean, AUTOMATIC))FALSE == (VAR(boolean, AUTOMATIC))Eth_Enet_CheckAccessToCtrl(u8CtrlIdx))
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4
                @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7
                @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1
            */
            if((VAR(uint32, AUTOMATIC))STD_ON == (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_ACCESS_ENABLED( u8CtrlIdx))
            {
                /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
                Dem_ReportErrorStatus   ( \
                    (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_ACCESS( u8CtrlIdx), DEM_EVENT_STATUS_PREFAILED \
                                        );
            }
        }
        else
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4
                @violates @ref Eth_Enet_c_REF_8 MISRA rule 13.7
                @violates @ref Eth_Enet_c_REF_24 MISRA rule 14.1
            */
            if((VAR(uint32, AUTOMATIC))STD_ON == (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_ACCESS_ENABLED( u8CtrlIdx))
            {
      #endif
    #endif
                /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
                Dem_ReportErrorStatus   ( \
                    (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_ACCESS( u8CtrlIdx), DEM_EVENT_STATUS_PREPASSED \
                                        );
    #ifdef ETH_SUPPORT_CHECK_ACCESS_CTRL
      #if (STD_ON == ETH_SUPPORT_CHECK_ACCESS_CTRL)
            }
        }
      #endif
    #endif
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_IEEE_R_DROP_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_FRAMELOST_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_FRAMELOST( u8CtrlIdx) \
                            );
     Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_IEEE_R_CRC_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_CRC_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_CRC( u8CtrlIdx) \
                            );
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_RMON_R_UNDERSIZE_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_UNDERSIZE_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_UNDERSIZE( u8CtrlIdx) \
                            );
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_RMON_R_OVERSIZE_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_OVERSIZE_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_OVERSIZE( u8CtrlIdx) \
                            );
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_IEEE_R_ALIGN_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_ALIGN_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_ALIGN( u8CtrlIdx) \
                            );
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_IEEE_T_1COL_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_1COL_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_1COL( u8CtrlIdx) \
                            );
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_IEEE_T_MCOL_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_MCOL_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_MCOL( u8CtrlIdx) \
                            );
    Eth_Enet_CheckDemStatus ( \
            Eth_u32BaseAddr[u8CtrlIdx] + (VAR(uint32, AUTOMATIC))ENET_IEEE_T_LCOL_ADDR16, \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_LCOL_ENABLED( u8CtrlIdx), \
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            (VAR(Dem_EventIdType, AUTOMATIC))ETH_CFG_DEM_E_LCOL( u8CtrlIdx) \
                            ); 
#endif
    }
}

#if STD_ON == ETH_GLOBALTIME_SUPPORT
FUNC(void, ETH_CODE) Eth_Enet_GetCurrentTime    ( \
                      VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                      P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                      P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                               )
{
    VAR(uint32, AUTOMATIC) u32Currentnanoseconds;
    VAR(uint32, AUTOMATIC) u32Nextnanoseconds;
    
    SuspendAllInterrupts();
    /* Read timer 2 times to check when the timer wrapped */
    u32Currentnanoseconds = Eth_Enet_ReadTimerValue(u8CtrlIdx);
    u32Nextnanoseconds = Eth_Enet_ReadTimerValue(u8CtrlIdx);
    ResumeAllInterrupts();
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    pTimeStampPtr[0].secondsHi = Eth_LocalTime[u8CtrlIdx].secondsHi;
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    pTimeStampPtr[0].seconds = Eth_LocalTime[u8CtrlIdx].seconds;
    /* If the wrap was between 2 reads, then decrease the value for second part. */
    if (u32Currentnanoseconds > u32Nextnanoseconds)
    {   
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        if ((VAR(uint32, AUTOMATIC))0U == pTimeStampPtr[0].seconds)
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].secondsHi--;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].seconds = 0xFFFFFFFFU;
        }
        else
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].seconds--;
        }
    }

    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    pTimeStampPtr[0].nanoseconds = u32Currentnanoseconds;
    *pTimeQualPtr = ETH_VALID;
}
/* Note: This function should be called within 1 second since the buffer was timestamped */
FUNC(void, ETH_CODE) Eth_Enet_GetEgressTimeStamp  ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                VAR(uint8, AUTOMATIC) u8BufIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                 )
{
    VAR(uint32, AUTOMATIC) u32TxBdTimeStamp;
    VAR(uint32, AUTOMATIC) u32CurrTimeStamp;
    /* 2 following variables to store current time for preventing timer-wrap event occurred */
    VAR(uint32, AUTOMATIC) u32CurrSeconds;
    VAR(uint16, AUTOMATIC) u16CurrSecondsHi;
    VAR(uint32, AUTOMATIC) u32BDEnhanceValue;
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    VAR(uint32, AUTOMATIC) u32BdAddress = ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx);
    
    /* store enhanced BD flags + timestamp */
    u32BDEnhanceValue = Eth_Enet_ReadTxBDBitsB(u32BdAddress, u8BufIdx);
    if ( ENET_TXBD_TS_U32 == (u32BDEnhanceValue & (ENET_TXBD_TS_U32)) )
    {
        /* Reading Time stamp from Buffer Descriptor */
        u32TxBdTimeStamp = Eth_Enet_ReadTxBDTimestampPtr(u32BdAddress, u8BufIdx);
        /* Reading ns of current time to check whether wrap occurred before or after buffer is timestamps */
        u32CurrTimeStamp = Eth_Enet_ReadTimerValue(u8CtrlIdx);
        u32CurrSeconds = Eth_LocalTime[u8CtrlIdx].seconds;
        u16CurrSecondsHi = Eth_LocalTime[u8CtrlIdx].secondsHi;
        
        /* Wrap was occurred before buffer was timestamps. */
        if (u32CurrTimeStamp > u32TxBdTimeStamp)
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].seconds = u32CurrSeconds;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].secondsHi = u16CurrSecondsHi;
        }
        else
        {
            if (0U == u32CurrSeconds)
            {
                u16CurrSecondsHi--;
            }
            u32CurrSeconds--;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].seconds = u32CurrSeconds;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].secondsHi = u16CurrSecondsHi;
        }
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        pTimeStampPtr[0].nanoseconds = u32TxBdTimeStamp;
        *pTimeQualPtr = ETH_VALID;
    }
}

FUNC(void, ETH_CODE) Eth_Enet_GetIngressTimeStamp ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) pDataPtr, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                 )
{
    VAR(uint32, AUTOMATIC) u32RxBdTimeStamp;
    VAR(uint32, AUTOMATIC) u32CurrTimeStamp;
    /* 2 following variables to store current time for preventing timer-wrap event occurred */
    VAR(uint32, AUTOMATIC) u32CurrSeconds;
    VAR(uint16, AUTOMATIC) u16CurrSecondsHi;
    VAR(uint8, AUTOMATIC) u8BufIdx = 0U;
    VAR(boolean, AUTOMATIC) bFoundBufIdx = (VAR(boolean, AUTOMATIC))FALSE;
    VAR(uint8, AUTOMATIC) u8CountBufIdx;
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */ 
    VAR(uint32, AUTOMATIC) u32BdAddress = ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx);

#if STD_ON == ETH_USE_RX_FRAMES_WRAP
    if (Eth_ENET_u32RxBufStartAddr[u8CtrlIdx] < (VAR(uint32, AUTOMATIC))(pDataPtr))
    {
#endif
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        for (u8CountBufIdx = 0U; u8CountBufIdx <= ETH_CFG_RXBUFTOTAL(u8CtrlIdx); u8CountBufIdx++)
        {
            /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
            /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */  
            /* Compiler_Warning: This is a cast from pointer type (can be 32bit or 64 bit) to uint32. Assuming the pointer value is always in range of uint32 type(MCAL limitation), the cast is safe.*/
            if ((Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, u8CountBufIdx) + 14U) == (VAR(uint32, AUTOMATIC))(pDataPtr))
            {
                bFoundBufIdx = (VAR(boolean, AUTOMATIC))TRUE;
                u8BufIdx = u8CountBufIdx;
                break;
            }
        }
#if STD_ON == ETH_USE_RX_FRAMES_WRAP
    }
    else
    {
        for (u8CountBufIdx = ETH_CFG_RXBUFTOTAL(u8CtrlIdx); u8CountBufIdx > 0U; u8CountBufIdx--)
        {
            if ( (  Eth_Enet_ComputeRxBufAddr(u8CtrlIdx, 0U) + 14U - \
                   ((ETH_CFG_RXBUFTOTAL( u8CtrlIdx) - (VAR(uint32, AUTOMATIC))u8CountBufIdx) * ETH_CFG_CTRLRXBUFLENBYTE( u8CtrlIdx)) \
                  ) == pDataPtr \
                )
            {
                bFoundBufIdx = (VAR(boolean, AUTOMATIC))TRUE;
                u8BufIdx = u8CountBufIdx;
                break;
            }
        }
    }
#endif
    if ((VAR(boolean, AUTOMATIC))TRUE ==  bFoundBufIdx)
    {
        /* Reading Time stamp from Buffer Descriptor */
        u32RxBdTimeStamp = Eth_Enet_ReadRxBDTimestampPtr(u32BdAddress, u8BufIdx);
        /* Reading ns of current time to check whether wrap occurred before or after buffer is timestamps */
        u32CurrTimeStamp = Eth_Enet_ReadTimerValue(u8CtrlIdx);
        u32CurrSeconds = Eth_LocalTime[u8CtrlIdx].seconds;
        u16CurrSecondsHi = Eth_LocalTime[u8CtrlIdx].secondsHi;
        
        /* Wrap was occurred before buffer was timestamps. */
        if (u32CurrTimeStamp > u32RxBdTimeStamp)
        {
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].seconds = u32CurrSeconds;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].secondsHi = u16CurrSecondsHi;
        }
        else
        {
            if (0U == u32CurrSeconds)
            {
                u16CurrSecondsHi--;
            }
            u32CurrSeconds--;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].seconds = u32CurrSeconds;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            pTimeStampPtr[0].secondsHi = u16CurrSecondsHi;
        }
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        pTimeStampPtr[0].nanoseconds = u32RxBdTimeStamp;
        *pTimeQualPtr = ETH_VALID;
    }
    #if STD_ON == ETH_DEV_ERROR_DETECT
    else
    {
        (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETINGRESSTIMESTAMP, ETH_E_PARAM_POINTER \
                                );
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

FUNC(void, ETH_CODE) Eth_Enet_SetCorrectionTime   ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETH_APPL_CONST) pTimeOffsetPtr, \
                                P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_APPL_CONST) pRateRatioPtr \
                                                 )
{
    VAR(uint8, AUTOMATIC) u8CarryNs=0U;
    VAR(uint8, AUTOMATIC) u8Carry=0U;
    VAR(sint32, AUTOMATIC) s32TempNanosecond;
    VAR(sint64, AUTOMATIC) s64IngNanosecond;
    VAR(sint64, AUTOMATIC) s64OriNanosecond;
    VAR(sint32, AUTOMATIC) s32Delta;
    VAR(sint32, AUTOMATIC) s32CorrectCycle;
    VAR(sint32, AUTOMATIC) s32CorrectValue;

    
    
    /* Changing Offset: Note: Current implementation seem time consuming because consume lots of u32 calculation */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    if (((VAR(boolean, AUTOMATIC))TRUE) == pTimeOffsetPtr[0].sign)
    {
        SuspendAllInterrupts();
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        s32TempNanosecond = (VAR(sint32, AUTOMATIC))Eth_Enet_ReadTimerValue(u8CtrlIdx) + (VAR(sint32, AUTOMATIC))pTimeOffsetPtr[0].diff.nanoseconds;
        if (1000000000 < s32TempNanosecond)
        {
            s32TempNanosecond = s32TempNanosecond - 1000000000;
            u8CarryNs = 1U;
        }
        /* TBD what need to be done with nanosecond parts, 
        Temporary, the change need to be added to the ENETx_ATPER and reset to default during processing of IRQ */
        Eth_Enet_SetTimerValue(u8CtrlIdx, (VAR(uint32, AUTOMATIC))s32TempNanosecond);
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        if ( ((VAR(uint32, AUTOMATIC))0xFFFFFFFFU - (pTimeOffsetPtr[0].diff.seconds + u8CarryNs)) < Eth_LocalTime[u8CtrlIdx].seconds )
        {
            u8Carry = 1U;
        }
        
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        Eth_LocalTime[u8CtrlIdx].seconds = Eth_LocalTime[u8CtrlIdx].seconds + pTimeOffsetPtr[0].diff.seconds + u8CarryNs;
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        Eth_LocalTime[u8CtrlIdx].secondsHi = Eth_LocalTime[u8CtrlIdx].secondsHi + pTimeOffsetPtr[0].diff.secondsHi + u8Carry;
        ResumeAllInterrupts();
    }
    else
    {
        SuspendAllInterrupts();
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        s32TempNanosecond = (VAR(sint32, AUTOMATIC))Eth_Enet_ReadTimerValue(u8CtrlIdx) - (VAR(sint32, AUTOMATIC))pTimeOffsetPtr[0].diff.nanoseconds;
        if (0 > s32TempNanosecond)
        {
            s32TempNanosecond = 1000000000 + s32TempNanosecond;
            u8CarryNs = 1U;
        }
        /* TBD what need to be done with nanosecond parts, 
        Temporary, the change need to be added to the ENETx_ATPER and reset to default during processing of IRQ */
        Eth_Enet_SetTimerValue(u8CtrlIdx, (VAR(uint32, AUTOMATIC))s32TempNanosecond);   
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        if ( (pTimeOffsetPtr[0].diff.seconds + u8CarryNs) > Eth_LocalTime[u8CtrlIdx].seconds )
        {
            u8Carry = 1U;
        }
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        Eth_LocalTime[u8CtrlIdx].seconds = (Eth_LocalTime[u8CtrlIdx].seconds - pTimeOffsetPtr[0].diff.seconds) - u8CarryNs;
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        Eth_LocalTime[u8CtrlIdx].secondsHi = (Eth_LocalTime[u8CtrlIdx].secondsHi - pTimeOffsetPtr[0].diff.secondsHi) - u8Carry;
        /* End of Exclusive area */
        ResumeAllInterrupts();
    }
    
    /* Changing rate ratio, limit the total diff to 4.3 seconds */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    s64IngNanosecond = ((VAR(sint64, AUTOMATIC))pRateRatioPtr[0].IngressTimeStampDelta.diff.seconds * (VAR(sint64, AUTOMATIC))1000000000) + (VAR(sint64, AUTOMATIC))pRateRatioPtr[0].IngressTimeStampDelta.diff.nanoseconds;
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    s64OriNanosecond = (((VAR(sint64, AUTOMATIC))pRateRatioPtr[0].OriginTimeStampDelta.diff.seconds) * (VAR(sint64, AUTOMATIC))1000000000) + (VAR(sint64, AUTOMATIC))pRateRatioPtr[0].OriginTimeStampDelta.diff.nanoseconds;
    if (s64IngNanosecond != s64OriNanosecond)
    {
        /* To be able to adjust, the frequency between 2 clock must not be too differents. Otherwise, unable to do correction. */
        s32Delta = (VAR(sint32, AUTOMATIC))(s64OriNanosecond - s64IngNanosecond);
        /* Convert s32Delta to PPB to synchronize */
        s32Delta = (VAR(sint32, AUTOMATIC))Eth_Enet_Divsint64( ((VAR(sint64, AUTOMATIC))1000000000 * s32Delta) , s64IngNanosecond );
        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
        s32CorrectCycle = ((VAR(sint32, AUTOMATIC)) ETH_CFG_TIMESTAMP_CLK(u8CtrlIdx)) / s32Delta;
        
        if (0 == s32CorrectCycle) 
        {
            /* The driff is too high, need to correct every cycle, although can not ultimately synchronize */
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            s32CorrectValue = ((VAR(sint32, AUTOMATIC))1000000000 + s32Delta) / ((VAR(sint32, AUTOMATIC)) ETH_CFG_TIMESTAMP_CLK(u8CtrlIdx));
            if (127 < s32CorrectValue)
            {
                s32CorrectValue = 127;
            }
            Eth_Enet_CorrectRate(u8CtrlIdx, 1U, (VAR(uint8, AUTOMATIC))s32CorrectValue);
        }
        else if (0 < s32CorrectCycle) 
        {
            /* The clock is slower than grand master, need to speed up */
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
            Eth_Enet_CorrectRate(u8CtrlIdx, (VAR(uint8, AUTOMATIC))s32CorrectCycle, (VAR(uint8, AUTOMATIC))(ETH_CFG_TIMESTAMP_INC(u8CtrlIdx) + 1U));
        }
        else
        {
            /* The clock is faster than grand master, need to slow down */
            s32CorrectCycle = -s32CorrectCycle;
            /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
            /** @violates @ref Eth_Enet_c_REF_20 MISRA rule 10.1 */
            Eth_Enet_CorrectRate(u8CtrlIdx, (VAR(uint8, AUTOMATIC))s32CorrectCycle, (VAR(uint8, AUTOMATIC))(ETH_CFG_TIMESTAMP_INC(u8CtrlIdx) - 1U));
        }
    }
    else
    {
        Eth_Enet_CorrectRate(u8CtrlIdx, 0U, 0U);
    }
}

FUNC(void, ETH_CODE)  Eth_Enet_SetGlobalTime     ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) pTimeStampPtr \
                                                )
{
    /* Setting time should be done in exclusive area to prevent other IRQs occurred. */
    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_02();
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    Eth_LocalTime[u8CtrlIdx].secondsHi = pTimeStampPtr[0].secondsHi;
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    Eth_LocalTime[u8CtrlIdx].seconds = pTimeStampPtr[0].seconds;
    Eth_Enet_ClearTimerWrapFlag(u8CtrlIdx);
    /* Write nanosecond to timer register */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    Eth_Enet_SetTimerValue(u8CtrlIdx, pTimeStampPtr[0].nanoseconds);
    /* End of Exclusive area */
    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_02();
}

FUNC(void, ETH_CODE) Eth_Enet_ClearTimerWrapFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */   
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    REG_WRITE32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16, ENET_EIR_TS_TIMER_W1C);
}

FUNC(boolean, ETH_CODE) Eth_Enet_IsTimerWrapEvent(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(boolean, AUTOMATIC) bReturnValue; /* Stores the result */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */   
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    if (ENET_EIR_TS_TIMER_W1C == (REG_READ32(Eth_u32BaseAddr[u8CtrlIdx] + ENET_EIR_ADDR16) & ENET_EIR_TS_TIMER_W1C))
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        bReturnValue = (VAR(boolean, AUTOMATIC))FALSE;
    }
    return(bReturnValue);
}
#endif

/*================================================================================================*/
/**
* @brief         Reports received frames to the upper layer
* @param[in]     u8CtrlIdx Index of the controller to report receptions
* @param[in]     bIrq Selects between the poll driven and interrupt driven
*                mode (algorithm). The value TRUE means interrupt driven mode.
* @details       Function examines type of receive buffers. It begins
*                from the empty buffer found by previous call or from the
*                first one if no call has been done since the controller has
*                been enabled or from the latest known full buffer containing
*                the single-buffer-error-free frame.
* @par
*                Each buffer is checked to be error-free, buffer type is
*                examined and the buffer is reported via the
*                EthIf_RxIndication function call if the buffer type
*                is RX_BUF_SINGLE. All buffers of multi-buffer frame are
*                discarded when such frame is detected i.e. buffer type is
*                RX_BUF_MULTI_FINISHED.
* @par
*                Search ends when empty buffer is found i.e. buffer type
*                is RX_BUF_MULTI_UNFINISHED or RX_BUF_EMPTY or in the poll
*                driven mode when a second single-buffer frame is found
*                (this frame is not reported to the EthIf_RxIndication).
*                Function silently discards all buffers when the receive
*                buffers ring overflow is detected i.e. RX_BUF_OVERFLOW value
*                of buffer type is found.
* @note          The function reports all found frames in the interrupt driven
*                mode. In the poll driven mode it reports only the first found
*                frame signals whether there is at least another frame to be
*                received (in the next call).
* @return        In the poll driven mode signalizes whether a frame has been
*                reported to the EthIf module and whether another frame is
*                available. It shall be ignored in the interrupt driven mode.
* @retval        ETH_RECEIVED Only one frame received
* @retval        ETH_NOT_RECEIVED No frame received
* @retval        ETH_RECEIVED_MORE_DATA_AVAILABLE More frames received
*                frame was discarded.
* @implements    Eth_Ipw_ReportReception_Activity
*/
/*
* The interrupt flag shall be cleared after each finished buffer which will.
* If a buffer reception is finished during the loop execution the flag will be
* set however it will be cleared after the buffer is processed and the loop
* continues with the next empty buffer. The algorithm continues until
* an empty buffer is found which ensures that no buffer can forgotten if
* the interrupt flag is cleared.
* If the flag was cleared at the beginning the buffer finished during the loop
* execution would cause the flag being set again but the loop would handle the
* buffer therefore the next interrupt would occur but no buffer would be found.
* If the flag was cleared at the end it could happen that a buffer is finished
* between the loop end and clearing the flag so the buffer would not be
* processed however no interrupt would come because flag would be cleared.
* NOTE: This is valid only for the interrupts, polling mode ignores the flag.
*/

FUNC(Eth_RxStatusType, ETH_CODE) Eth_Enet_ReportReception ( \
                                                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                                CONST(boolean, AUTOMATIC) bIrq \
                                                         )
{
    VAR(uint8, AUTOMATIC) u8BufCtr; /* Buffer referencing variable */
    VAR(Eth_Enet_enRxBufferType, AUTOMATIC) eBufferType; /* Used to obtain
                                             buffer type from lower layers */
    VAR(uint8, AUTOMATIC) u8MultiEnd = 0U; /* Used to obtain number of last buffer in
                                                     the multi-buffer frame */
    VAR(uint8, AUTOMATIC) u8BufCtrMax; /* Variable used to hold the buffers
        number - this should be faster than reading the configuration */
    VAR(uint32, AUTOMATIC) u32ProtectionCounter = 0U; /* Protection counter */
    /* --- Frame information storage temporary variables --- */
    VAR(uint32, AUTOMATIC) u32FrameStatus;
    VAR(uint16, AUTOMATIC) u16Length;
    P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) pu8DataPtr = NULL_PTR;
    VAR(Eth_FrameType, AUTOMATIC) u16EtherType;
    VAR(boolean, AUTOMATIC) bBroadcast;
    VAR(uint8, AUTOMATIC) u8EthIfCtrlIdx;  /* Controller which received it */
    /* --- Internal state machine state variables --- */
    VAR(boolean, AUTOMATIC) bFinishLoop; /* Decisions whether continue
                                              with buffer search stored here */
    VAR(boolean, AUTOMATIC) bFirstFrameFound; /* TRUE if some frame already
                                                found and reported to EthIf */
    VAR(Eth_RxStatusType, AUTOMATIC) eRetVal; /* Single return implementation
                                            needs to store the return value */
    /* The eRetVal could be used as a steering variable instead of the
       FirstFramFound but the readability would be decreased and the compiler
       will optimize it anyway */

    u8BufCtr = Eth_u8ActiveRxBuf[u8CtrlIdx];
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    u8EthIfCtrlIdx = ETH_CFG_CTRLIDXINETHIF(u8CtrlIdx); /* Get the value */
    /* No valid frames have been found yet */
    bFirstFrameFound = (VAR(boolean, AUTOMATIC))FALSE;
    eRetVal = ETH_NOT_RECEIVED;
    /* Initialize the loop-control variable */
    bFinishLoop = (VAR(boolean, AUTOMATIC)) FALSE;
    /* Get number of buffers */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    u8BufCtrMax = (VAR(uint8, AUTOMATIC))(ETH_CFG_RXBUFTOTAL(u8CtrlIdx) - 1U);
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    if ((uint8)E_OK == Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx), ETH_RX_BUF_MEM_SIZE))
    {
    #endif
  #endif
#endif
        do
        {
            /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
            eBufferType = Eth_Enet_GetRxBufferType(u8CtrlIdx, u8BufCtr, u8BufCtrMax, &u8MultiEnd);
            if((RX_BUF_SINGLE == eBufferType) || (RX_BUF_MULTI_FINISHED == eBufferType))
            {   /* Single buffer frames are the only to be reported */
                /* Get the buffer length and pointer to it */
                /** @violates @ref Eth_Enet_c_REF_17 MISRA rule 1.2 */
                Eth_Enet_GetRxBufferData(u8CtrlIdx, u8BufCtr, u8MultiEnd, &u16Length, &pu8DataPtr, &u32FrameStatus);
                /* Check whether the frame has been received without any error
                * and if is multicast check if is in the multicast pool */
                /* Regular broadcast and unicast address which is not multicast */
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
                if ((0U == (u32FrameStatus & (ETH_ENET_RXF_ERRORS_MASK|ETH_ENET_RXF_MULTICAST))) \
                    /* Frame received in promiscuous mode */
                    || (ETH_ENET_RXF_PROMISCUOUS == (u32FrameStatus & (ETH_ENET_RXF_ERRORS_MASK | ETH_ENET_RXF_PROMISCUOUS))) \
                    /* Multicast address contained in pool */
                    || (((0U == (u32FrameStatus & ETH_ENET_RXF_ERRORS_MASK))) && ((VAR(boolean, AUTOMATIC))TRUE == Eth_Enet_IsPhysAddrAllowed(u8CtrlIdx, pu8DataPtr))) \
                )
#else
                if((0U == (u32FrameStatus & (ETH_ENET_RXF_ERRORS_MASK))))
#endif /* STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER */
                {   /* No error, frame can be passed to upper layers */
                    /* Check whether there is already a frame to pass */
                    if((VAR(boolean, AUTOMATIC))FALSE == bFirstFrameFound)
                    {   /* No, this is the first found received valid frame */
                        /* Pass the received frame to the upper layer */
                        /* Parse the u16EtherType from the frame header */
                        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */                                                        
                        u16EtherType = ((VAR(uint16, AUTOMATIC))(*(pu8DataPtr + 12U)) << 8U);
                        /** @violates @ref Eth_Enet_c_REF_11 MISRA rule 17.4 */
                        u16EtherType |= *(pu8DataPtr + 13U);
                        /* Check whether the frame is sent to a broadcast
                        address */
                        if(ETH_ENET_RXF_BROADCAST == (u32FrameStatus & ETH_ENET_RXF_BROADCAST))
                        {   /* bBroadcast */
                            bBroadcast = (VAR(boolean, AUTOMATIC))TRUE;
                        }
                        else
                        {   /* Unicast or multicast */
                            bBroadcast = (VAR(boolean, AUTOMATIC))FALSE;
                        }
                        /* Notify the EthIf - pass the Ethernet controller index,
                        u16EtherType, broadcast indication, frame source address,
                        pointer to the payload and the payload length */
                        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
                        EthIf_RxIndication(u8EthIfCtrlIdx, u16EtherType, bBroadcast, (pu8DataPtr + 6U), (pu8DataPtr + 14U), (u16Length - 14U));
                        /* Forget that the frame was found if the interrupt
                        mode is used so all frames will be reported. In the
                        poll driven mode on the other hand remember that the
                        first frame has been already reported so only one frame
                        will be reported. */
                        eRetVal = ETH_RECEIVED;
                        if((VAR(boolean, AUTOMATIC))FALSE == bIrq)
                        {   /* Poll driven mode - remember */
                            bFirstFrameFound = (VAR(boolean, AUTOMATIC))TRUE;
                        }
                    }
                    else
                    {   /* Another valid received frame has already been found */
                        /* Remember that there is another frame to be read and
                        stop the search */
                        eRetVal = ETH_RECEIVED_MORE_DATA_AVAILABLE;
                        bFinishLoop = ((VAR(boolean, AUTOMATIC))TRUE);
                        /* The processing shall start with this buffer when the
                        function is called next time */
                        Eth_u8ActiveRxBuf[u8CtrlIdx] = u8BufCtr;
                    }
                }
                /* Clear the buffers */
                if ((VAR(boolean, AUTOMATIC))FALSE == bFinishLoop)
                {
                    /* Clear the interrupt flags */
                    Eth_Enet_ClearRxIrqFlag(u8CtrlIdx);
                    /* Clear all the first buffer */
                    Eth_Enet_ClearRxBuffer(u8CtrlIdx, u8BufCtr);
                    /* Clear all others belong to frame */
                    while(u8BufCtr != u8MultiEnd)
                    {
                        u8BufCtr++;
                        if(u8BufCtr > u8BufCtrMax)
                        {
                            u8BufCtr = 0U;
                        }
                        Eth_Enet_ClearRxBuffer(u8CtrlIdx, u8BufCtr);
                    }
                    /* Continue with the next buffer */
                    u8BufCtr++;
                    if(u8BufCtr > u8BufCtrMax)
                    {
                        u8BufCtr = 0U;
                    }
                    Eth_u8ActiveRxBuf[u8CtrlIdx] = u8BufCtr;
                }
            }
            else /* RX_BUF_MULTI_UNFINISHED || RX_BUF_EMPTY || RX_BUF_OVERFLOW */
            {
                /* Other states mean that loop has to end */
                bFinishLoop = ((VAR(boolean, AUTOMATIC))TRUE);
            }
            /* Protection against newerendless loop */
            u32ProtectionCounter++;
            if ((2U * (VAR(uint32, AUTOMATIC))(u8BufCtrMax)) <= u32ProtectionCounter)
            { /* Buffer ring was processed twice in a loop without exit */
            /* Note that this condition is unreachable at normal HW conditions */
                /* Terminate the loop */
                bFinishLoop = ((VAR(boolean, AUTOMATIC))TRUE);
            }
        }
        while(((VAR(boolean, AUTOMATIC))FALSE) == bFinishLoop);
        /* Handler of buffers overflow - discard all buffers */
        if(RX_BUF_OVERFLOW == eBufferType)
        {
            #if STD_ON == DEBUG_VARIABLES /* Only if debug variables are used */
                /* Increment the debug variable */
                Eth_RxBuffersOverflow[u8CtrlIdx] = Eth_RxBuffersOverflow[u8CtrlIdx] + 1U;
            #endif
            for(u8BufCtr = 0U; u8BufCtr <= u8BufCtrMax; u8BufCtr++)
            {
                Eth_Enet_ClearRxBuffer(u8CtrlIdx, u8BufCtr);
            }
        }
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        (void)Mcl_CacheFlushMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_RXBDSTARTADDRESS(u8CtrlIdx), ETH_RX_BUF_MEM_SIZE);
    }
    #endif
  #endif
#endif
    /* Return information about availability of more buffers */
    return eRetVal;
}
/*================================================================================================*/
/**
* @brief         Confirms transmission of all transmitted buffers
* @param[in]     u8CtrlIdx Index of the controller to report transmissions
* @details       Function examines all transmit buffers whether some of them
*                have been already sent and whether they should be confirmed.
*                EthIf_TxConfirmation is called for each such buffer.
* @return        Error report
* @retval        TRUE No error has occurred.
* @retval        FALSE Some error has occurred.
* @implements    Eth_Ipw_ReportTransmission_Activity
*/

FUNC(boolean, ETH_CODE) Eth_Enet_ReportTransmission(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(uint8, AUTOMATIC) u8BufIdx; /* Counter used for buffer referencing */
    VAR(uint8, AUTOMATIC) u8TotalBufNum; /* Variable used to hold the buffs number
     - this should be faster than reading the configuration */
    VAR(uint8, AUTOMATIC) u8EthIfCtrlIdx; /* Copy of the configured parameter
       EthCtrlIdxInEthIf  - this should improve execution time (multiple
       access to memory is slower than access to register) */
    VAR(uint32, AUTOMATIC) u32BDAddr; /* BD addr. used by lower driver layers
     - to avoid its re-initializations during function calls in the loop
       it is placed here. Reading value from (ROM) memory through pointer is
       slower than local variable access (register or stack). */
    VAR(uint8, AUTOMATIC) u8BDIdx; /* Index of linked BD */
    VAR(uint32, AUTOMATIC) u32BDStatus; /* Status bits of linked BD */
    VAR(uint8, AUTOMATIC) u8TxBufFlag; /* Temporary Tx buffer flag */
    
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    u8EthIfCtrlIdx = ETH_CFG_CTRLIDXINETHIF(u8CtrlIdx); /* Get the value needed
                                  for EthIf_TxConfirmation callback call */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    u8TotalBufNum = ETH_CFG_TXBUFTOTAL(u8CtrlIdx); /* Get number of buffers */
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 */
    /** @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3 */
    u32BDAddr = ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx); /* Get TXBDs base
                  memory address value to pass it to lower drivers layers*/
    
#ifdef ERR_IPV_ENET_0001

    #if STD_ON == ERR_IPV_ENET_0001
    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_01();
    Eth_Enet_ERR006358(u8CtrlIdx);  /* Process the errata 6358 workaround */
    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_01();
    #endif /* STD_ON == ERR_IPV_ENET_0001 */
#endif /* ERR_IPV_ENET_0001 */

    /* Search through all buffers */
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
    /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
        @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
    */
    if ((uint8)E_OK == Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE))
    {
    #endif
  #endif
#endif
        for(u8BufIdx = 0U; u8BufIdx < u8TotalBufNum; u8BufIdx++)
        {
            SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_01();
            if(Eth_u8LockedTxBufCount[u8CtrlIdx] > 0U)
            {
                SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_01();
                /* At first check status bits of buffer */
                u8TxBufFlag = Eth_au8TxBufFlags[u8CtrlIdx][u8BufIdx];
                if(  (ENET_TXB_LOCK_U8 | ENET_TXB_CONF_U8 | ENET_TXB_FIRST_U8) == \
                    ((ENET_TXB_LOCK_U8 | ENET_TXB_CONF_U8 | ENET_TXB_FIRST_U8) & u8TxBufFlag) \
                )
                {   /* The frame is in LOCKEDAT or LOCKEDIT state */
                    /* If there is link to BD, try to remove it */
                    if(ENET_TXB_LINK_U8 == (ENET_TXB_LINK_U8 & u8TxBufFlag))
                    {
                    u8BDIdx = Eth_au8TxBdOfBuf[u8CtrlIdx][u8BufIdx];
                        /* There is link, may be removed only if ENET_TXBD_R_U32=0 and ENET_TXBD_TO1_U32=1
                        (if ENET_TXBD_TO1_U32 would be 0 it might be frame being turned into
                        LockedIT state with BD not written yet) */
                    u32BDStatus = Eth_Enet_ReadTxBDBitsA(u32BDAddr, u8BDIdx);
                    if(ENET_TXBD_TO1_U32 == ((ENET_TXBD_R_U32 | ENET_TXBD_TO1_U32) & u32BDStatus) )
                    {    /* Ready bit is zero -> frame was sent -> remove the link */
                        u8TxBufFlag &= (VAR(uint8, AUTOMATIC))(~ ENET_TXB_LINK_U8);
                                /*Enter exclusive area before update software flag to prevent interfere */
                        SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_01();
                        Eth_au8TxBufFlags[u8CtrlIdx][u8BufIdx] = u8TxBufFlag;
                        SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_01();
                        /* Clear BufLinked flag */
                        u32BDStatus &= (VAR(uint32, AUTOMATIC))(~ENET_TXBD_TO1_U32);
                        /* Write modified bits back */
                        Eth_Enet_WriteTxBDBitsA(u32BDAddr, u8BDIdx, u32BDStatus);
                    }
                    }
                    /* Call TxConfirmation and free buffers only if the link is gone */
                    if(0U == (ENET_TXB_LINK_U8 & u8TxBufFlag))
                    {
                        /* The link was removed -> LOCKEDAT state, call confirmation */
                        /** @violates @ref Eth_Enet_c_REF_5 MISRA rule 17.4 */
                        EthIf_TxConfirmation(u8EthIfCtrlIdx, u8BufIdx);
                        Eth_Enet_GiveBackTxBuffer(u8CtrlIdx, u8BufIdx);
                        /* At last free the buffers */
                        /* Update number of pending confirmations, need critical section because this is RMW access */
                        SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_01();
                        /* Update number of pending confirmations */
                        Eth_u8LockedTxBufCount[u8CtrlIdx]--;
                        SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_01();
                    }
                }
            }
            else
            {
                SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_01();
            }
        }
#ifdef MCAL_CACHE_RUNTIME_MNGMNT
  #if STD_ON == MCAL_CACHE_RUNTIME_MNGMNT
    #if (MCL_SYNCRONIZE_CACHE == STD_ON)
        /** @violates @ref Eth_Enet_c_REF_7 MISRA rule 11.1 
            @violates @ref Eth_Enet_c_REF_2 MISRA rule 11.3
        */
        (void)Mcl_CacheFlushMultiLines(MCL_LMEM_CACHE_PS, ETH_CFG_TXBDSTARTADDRESS(u8CtrlIdx), ETH_TX_BUF_MEM_SIZE);
    }
    #endif
  #endif
#endif
    return (VAR(boolean, AUTOMATIC))TRUE; /*No error detection implemented yet*/
}


#define ETH_STOP_SEC_CODE
/**
 * @violates @ref Eth_Enet_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Enet_c_REF_4 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
