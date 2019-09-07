/**
*   @file    Eep_Types.h  
*   @implements Eep_Types.h_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Definitions of all Eeprom driver exported types.
*
*   @addtogroup EEP
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

#ifndef EEP_TYPES_H
#define EEP_TYPES_H

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
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by smcal coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to EEP.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Reg_eSys_Ftfc.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_TYPES_VENDOR_ID                    43
#define EEP_TYPES_MODULE_ID                    90
#define EEP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define EEP_TYPES_AR_RELEASE_MINOR_VERSION     2
#define EEP_TYPES_AR_RELEASE_REVISION_VERSION  2
#define EEP_TYPES_SW_MAJOR_VERSION             1
#define EEP_TYPES_SW_MINOR_VERSION             0
#define EEP_TYPES_SW_PATCH_VERSION             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Types.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemIf_Types.h file are of the same version */
    #if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_TYPES_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Types.h and MemIf_Types.h are different"
    #endif
#endif

/* Check if current file and Reg_eSys_Ftfc.h file are of the same vendor */
#if (EEP_TYPES_VENDOR_ID != ESYS_FLASHC_VENDOR_ID)
    #error "Eep_Types.h and Reg_eSys_Ftfc.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Reg_eSys_Ftfc.h file are of the same version */
    #if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_TYPES_AR_RELEASE_MINOR_VERSION != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Types.h and Reg_eSys_Ftfc.h are different"
    #endif
#endif
/* Check if current file and Reg_eSys_Ftfc.h header file are of the same Software version */
#if ((EEP_TYPES_SW_MAJOR_VERSION != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (EEP_TYPES_SW_MINOR_VERSION != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (EEP_TYPES_SW_PATCH_VERSION != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Types.h and Reg_eSys_Ftfc.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



/** 
    @brief Define pointer type of erase access code function
*/
typedef P2FUNC( void, EEP_CODE, Eep_Eeprom_AcErasePtrNoTOType )  (
                                                                      
                                                                    P2FUNC(void, EEP_CODE, CallBack)( void ),
                                                                    VAR(uint8, AUTOMATIC) u8PageSize
                                                                );

/**
    @brief Define pointer type of write access code function
*/
typedef P2FUNC( void, EEP_CODE, Eep_Eeprom_AcWritePtrNoTOType )  (
                                                                      
                                                                    P2FUNC(void, EEP_CODE, CallBack)( void ),
                                                                    VAR(uint8, AUTOMATIC) u8PageSize
                                                                );



/**
* @brief          Eep Address Type.
* @details        Address offset from the configured eeprom base address to access a certain eeprom 
*                 memory area.
*/
typedef uint32 Eep_AddressType;

/**
* @brief          Eep Length Type.
* @details        Number of bytes to read,write,erase,compare
*/
typedef uint32 Eep_LengthType;


/**
 * @brief Pointer type of Eep_AC_Callback function
*/
typedef P2FUNC( void, EEP_CODE, Eep_ACCallbackPtrType )  ( void );


/**
* @brief          Eep Job End Notification Pointer Type
* @details        Pointer type of Eep_JobEndNotification function
* 
*/
typedef P2FUNC(void, EEP_CODE, Eep_JobEndNotificationPtrType)(void);

/**
* @brief          Eep Job Error Notification Pointer Type
* @details        Pointer type of Eep_JobErrorNotification function
* 
*/
typedef P2FUNC(void, EEP_CODE, Eep_JobErrorNotificationPtrType)(void);  


/**
* @brief          Eep Start Eeprom Access Notification Pointer Type
* @details        Pointer type of Eep_StartEepromAccessNotif function
*
*/
typedef P2FUNC(void, EEP_CODE, Eep_StartEepromAccessNotifPtrType)(void);

/**
* @brief          Eep Finished Eeprom Access Notification Pointer Type
* @details        Pointer type of Eep_FinishedEepromAccessNotif function
* 
*/
typedef P2FUNC(void, EEP_CODE, Eep_FinishedEepromAccessNotifPtrType)(void);  


/**
* @brief          Eep CRC Type.
* @details        CRC computed over config set.
* 
*/
typedef uint16 Eep_CrcType;



#ifdef __cplusplus
}
#endif

#endif /* EEP_TYPES_H */

/** @}*/
