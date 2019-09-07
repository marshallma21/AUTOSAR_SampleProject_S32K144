/**
*   @file    Fls_Flash_Types.h   
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of Flash IP exported types.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
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

#ifndef FLS_FLASH_TYPES_H
#define FLS_FLASH_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and 
* case sensitivity are supported for external identifiers.
* The used compilers use more than 31 chars for identifiers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_FLASH_TYPES_VENDOR_ID                    43
#define FLS_FLASH_TYPES_MODULE_ID                    92
#define FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION     2
#define FLS_FLASH_TYPES_AR_RELEASE_REVISION_VERSION  2
#define FLS_FLASH_TYPES_SW_MAJOR_VERSION             1
#define FLS_FLASH_TYPES_SW_MINOR_VERSION             0
#define FLS_FLASH_TYPES_SW_PATCH_VERSION             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module doesn't feel responsible (e.g. address does not belong to its current job,
*                 there is no current pending read/compare job, the syndrome is different).
*
*/
#define FLS_UNHANDLED       (0U)

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module feels responsible, but wants to repeat the  causing instruction. 
*                 Maybe: it still uses information in MCM or ECSM module, but they are outdated 
*                (e.g. due to an erroneous DMA transfer in the meantime)
*
*/
#define FLS_HANDLED_RETRY   1U

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module feels responsible, the current job is marked as failed,
*                 processing may continue, skipping the causing instruction.
*
*/
#define FLS_HANDLED_SKIP    (2U)  

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module  feels responsible, but the only reaction is to stop the system 
*                 (e.g.: try to shut-down in a quite safe way)
*
*/
#define FLS_HANDLED_STOP    3U

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** 
    @brief FLASH physical sector description
*/
typedef struct
{
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) pSectorStartAddressPtr; /**< @brief FLASH physical sector start address */
    uint32 u32SectorId;    /**< @brief corresponding number in sector location to calc cfgCRC */   
} Fls_Flash_InternalSectorInfoType;

/** 
    @brief FLASH array description
*/
typedef struct
{
    boolean bProgramSuspPossible; /**< @brief is Program suspend operation possible within FLASH array */
    boolean bEraseSuspPossible; /**< @brief is Erase suspend operation possible within FLASH array */
} Fls_Flash_ArrayInfoType;

/**
* @brief          Return value of Fls handler function.
* @details        Fls_DsiHandler and Fls_MciHandler can return the following value:
*                 - FLS_UNHANDLED    Fls driver is not responsable for this situation
*                 - FLS_HANDLED_SKIP Fls driver is responsable for this exception and want to skip this job
*                 .
*/ 
typedef uint8_least Fls_CompHandlerReturnType;

typedef const uint8 * Fls_InstructionAddressType;
typedef const void * Fls_DataAddressType;

/**
* @brief          Detailed information on the exception.
* @details        The following information will be checked by the driver:
*                 - if there is a pending read, compare, 
*                 - data_pt matches address currently accessed by pending flash read or flash compare job, 
*                 - if the exception syndrome register indicates DSI or MCI reason, 
*                 .
*
*/
typedef struct
{
    Fls_InstructionAddressType instruction_pt; /**< @brief pointer to the instruction that generated the ECC */
    Fls_DataAddressType        data_pt;        /**< @brief data address that caused the ECC error */
    uint32                     syndrome_u32;   /**< @brief details on the type of exception */
} Fls_ExceptionDetailsType;

typedef const Fls_ExceptionDetailsType *ExceptionDetailsPtrType;

typedef uint32 Fls_Flash_DataBusWidthType;

#ifdef __cplusplus
}
#endif

#endif /* FLS_FLASH_TYPES_H */

/** @}*/
