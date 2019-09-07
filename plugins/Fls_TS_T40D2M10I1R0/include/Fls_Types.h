/**
*   @file    Fls_Types.h   
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Flash driver exported types.
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

#ifndef FLS_TYPES_H
#define FLS_TYPES_H

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
#include "Std_Types.h"
#include "MemIf_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_TYPES_VENDOR_ID                    43
#define FLS_TYPES_MODULE_ID                    92
#define FLS_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLS_TYPES_AR_RELEASE_MINOR_VERSION     2
#define FLS_TYPES_AR_RELEASE_REVISION_VERSION  2
#define FLS_TYPES_SW_MAJOR_VERSION             1
#define FLS_TYPES_SW_MINOR_VERSION             0
#define FLS_TYPES_SW_PATCH_VERSION             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fls_Types.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemIf_Types.h file are of the same version */
    #if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_TYPES_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fls_Types.h and MemIf_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
    @brief Physical flash sectors type, unique identifier for each configured sector.
*/
typedef uint32 Fls_PhysicalSectorType;

/**
    @brief Flash sector channel type.
*/
typedef enum
{
    FLS_CH_INTERN = 0,
    FLS_CH_QSPI = 1
} Fls_HwChType;

/**
* @brief          Type of job currently executed by Fls_MainFunction.
*/
typedef enum
{
    /**
    * @brief erase one or more complete flash sectors
    */
    FLS_JOB_ERASE = 0,    
    /**
    * @brief write one or more complete flash pages 
    */
    FLS_JOB_WRITE,        
    /**
    * @brief read one or more bytes from flash memory 
    */
    FLS_JOB_READ,     
    /**
    * @brief compare data buffer with content of flash memory
    */
    FLS_JOB_COMPARE 
    /**
    * @brief check content of erased flash memory area
    */
    ,FLS_JOB_BLANK_CHECK

} Fls_JobType;


/**
* @brief          Result of low-level flash operation.
*/
typedef enum 
{
    FLASH_E_OK = 0,                 /**< @brief operation succeeded */
    FLASH_E_FAILED,                 /**< @brief operation failed due to hardware error */
    FLASH_E_BLOCK_INCONSISTENT,     /**< @brief data buffer doesn't match with content of flash memory */
    FLASH_E_PENDING,                /**< @brief operation is pending */
    FLASH_E_PARTITION_ERR           /**< @brief FlexNVM partition ratio error */
} Fls_LLDReturnType;

/**
* @brief          Type of job currently executed by Fls_LLDMainFunction.
*/
typedef enum
{
    /**
    * @brief no job executed by Fls_LLDMainFunction 
    */    
    FLASH_JOB_NONE = 0, 
    /**
    * @brief erase one flash sector 
    */    
    FLASH_JOB_ERASE, 
    /**
    * @brief complete erase and start an interleaved erase flash sector 
    */
    FLASH_JOB_ERASE_TEMP,
    /**
    * @brief write one or more complete flash pages 
    */
    FLASH_JOB_WRITE, 
    /**
    * @brief erase blank check of flash sector
    */    
    FLASH_JOB_ERASE_BLANK_CHECK 
    
} Fls_LLDJobType;

/**
* @brief    Type of job executed in interrupt context.
*/
typedef enum
{
    /**
    * @brief no job scheduled to be executed in interrupt context 
    */    
    FLASH_IRQ_JOB_NONE = 0, 
    /**
    * @brief read one or more flash bytes, in interrupt context.
    */    
    FLASH_IRQ_JOB_READ, 
    /**
    * @brief read and compare one or more flash bytes, in interrupt context.
    */    
    FLASH_IRQ_JOB_COMPARE, 
    /**
    * @brief read and compare against erased value one or more flash bytes, in interrupt context.
    */    
    FLASH_IRQ_JOB_BLANK_CHECK,
    /**
    * @brief erase one flash sector, in interrupt context. 
    */    
    FLASH_IRQ_JOB_ERASE, 
    /**
    * @brief read the external memory status, in interrupt context. 
    */
    FLASH_IRQ_JOB_GET_STATUS, 
    /**
    * @brief read the external memory status for the parallel device, in interrupt context. 
    */
    FLASH_IRQ_JOB_GET_STATUS_PAR, 
    /**
    * @brief send the first sequence of the hyperflash get status command, enter read status register mode.
    */
    FLASH_IRQ_JOB_HYPER_GET_STATUS_1, 
    /**
    * @brief send the second sequence of the hyperflash get status command, read the status register.
    */
    FLASH_IRQ_JOB_HYPER_GET_STATUS_2,  
    /**
    * @brief send the first sequence of the hyperflash write command, write the first unlock sequence.
    */
    FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1,  
    /**
    * @brief send the second sequence of the hyperflash write command, write the second unlock sequence.
    */
    FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_2,  
    /**
    * @brief send the third sequence of the hyperflash write command, write the word program command id.
    */
    FLASH_IRQ_JOB_HYPER_WRITE_WORD_ID,  
    /**
    * @brief send the forth sequence of the hyperflash write command, write the actual data.
    */
    FLASH_IRQ_JOB_HYPER_WRITE_WORD_DATA,
    /**
    * @brief set the write enable bit, in interrupt context.
    */
    FLASH_IRQ_JOB_WRITE_EN, 
    /**
    * @brief write one or more complete flash pages, in interrupt context.
    */
    FLASH_IRQ_JOB_WRITE
    
} Fls_LLDIrqJobType;

/**
* @brief          Size of data to be processeed by CRC.
*
* @implements     Fls_CrcDataSizeType_enumeration
*/
typedef enum 
{
    FLS_CRC_8_BITS = 0,
    FLS_CRC_16_BITS
} Fls_CrcDataSizeType;

/** 
    @brief Enumeration of physical flash sectors program size
*/ 
typedef enum
{
    FLS_WRITE_DOUBLE_WORD = 8U,
    FLS_WRITE_PAGE = 32U,
    FLS_WRITE_QUAD_PAGE = 128U,
    FLS_WRITE_128BYTES_PAGE = 128U,
    FLS_WRITE_256BYTES_PAGE = 256U,
    FLS_WRITE_512BYTES_PAGE = 512U
} Fls_ProgSizeType;

/**
* @brief          Logical sector index.
*/
typedef uint32 Fls_SectorIndexType;

/**
* @brief          Fls CRC Type.
* @details        CRC computed over config set.
* @implements     Fls_CrcType_typedef
*/
typedef uint16 Fls_CrcType;

/**
* @brief          Fls Address Type.
* @details        Address offset from the configured flash base address to access a certain flash 
*                 memory area.
* @implements     Fls_AddressType_typedef
*/
typedef uint32 Fls_AddressType;

/**
* @brief          Fls Length Type.
* @details        Number of bytes to read,write,erase,compare
* @implements     Fls_LengthType_typedef
*/
typedef uint32 Fls_LengthType;

/**
* @brief          Fls Sector Count Type
* @details        Number of configured sectors
*/
typedef uint32 Fls_SectorCountType;

/**
 * @brief Pointer type of Fls_AC_Callback function
*/
typedef P2FUNC( void, FLS_CODE, Fls_ACCallbackPtrType )  ( void );


/**
* @brief          Fls Job End Notification Pointer Type
* @details        Pointer type of Fls_JobEndNotification function
* @implements     Fls_JobEndNotificationPtrType_typedef
*/
typedef P2FUNC(void, FLS_CODE, Fls_JobEndNotificationPtrType)(void);

/**
* @brief          Fls Job Error Notification Pointer Type
* @details        Pointer type of Fls_JobErrorNotification function
* @implements     Fls_JobErrorNotificationPtrType_typedef
*/
typedef P2FUNC(void, FLS_CODE, Fls_JobErrorNotificationPtrType)(void);  


/**
* @brief          Fls Start Flash Access Notification Pointer Type
* @details        Pointer type of Fls_StartFlashAccessNotif function
*
*/
typedef P2FUNC(void, FLS_CODE, Fls_StartFlashAccessNotifPtrType)(void);

/**
* @brief          Fls Finished Flash Access Notification Pointer Type
* @details        Pointer type of Fls_FinishedFlashAccessNotif function
* 
*/
typedef P2FUNC(void, FLS_CODE, Fls_FinishedFlashAccessNotifPtrType)(void);  

/** 
    @brief Define pointer type of erase access code function
*/
typedef P2FUNC( void, FLS_CODE, Fls_AcErasePtrTOType )    (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void ), 
                                                                    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pTimerCounterAC
                                                                );
typedef P2FUNC( void, FLS_CODE, Fls_AcErasePtrNoTOType )  (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void )
                                                                );

/**
    @brief Define pointer type of write access code function
*/
typedef P2FUNC( void, FLS_CODE, Fls_AcWritePtrTOType )    (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void ), 
                                                                    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) pTimerCounterAC
                                                                );
typedef P2FUNC( void, FLS_CODE, Fls_AcWritePtrNoTOType )  (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void )
                                                                );
                                     
#ifdef __cplusplus
}
#endif

#endif /* FLS_TYPES_H */

/** @}*/
