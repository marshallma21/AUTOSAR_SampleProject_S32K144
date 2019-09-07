/**
*   @file    Can.h
*   @implements Can.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface.
*   @details API header for CAN driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FLEXCAN
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


#ifndef CAN_H
#define CAN_H

#ifdef __cplusplus
extern "C"{
#endif

/*
(CAN043) The file Can.h contains the declaration of the Can module API.
(CAN037) The file Can.h only contains 'extern' declarations of constants, global data, type definitions and services
            that are specified in the Can module SWS.
*/

/**
* @file           Can.h
*/


/**
* @page misra_violations MISRA-C:2004 violations
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Can_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to the requirement that request to have empty APIs if polling is not used.
*
* @section Can_h_REF_2
* Violates MISRA 2004 Required Rule 8.7, Global variables containing the generated configuration
* shall be defined in a separate source file and can't be defined inside a function although it is accessed
* by a single function.
*
* @section Can_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_h_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Can.h
*/
#include "ComStack_Types.h"
#include "Can_Cfg.h"
#include "Can_GeneralTypes.h"
#include "Soc_Ips.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
/**
* @{
* @file           Can.h
*/
#define CAN_VENDOR_ID                   43
#define CAN_MODULE_ID                   80
#define CAN_AR_RELEASE_MAJOR_VERSION    4
#define CAN_AR_RELEASE_MINOR_VERSION    2
/*
* @violates @ref Can_h_REF_3 Violates MISRA 2004 Required Rule 1.4, identifier clash
*/
#define CAN_AR_RELEASE_REVISION_VERSION 2
#define CAN_SW_MAJOR_VERSION            1
#define CAN_SW_MINOR_VERSION            0
#define CAN_SW_PATCH_VERSION            1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_VENDOR_ID != CAN_VENDOR_ID_CFG)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can configuration header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION_CFG_H))
  #error "AutoSar Version Numbers of Can.h and Can_Cfg.h are different"
#endif

/* Check if current file and CAN configuration header file are of the same software version */
#if ((CAN_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of Can.h and Can_Cfg.h are different"
#endif
/* Check if current file and CAN configuration header file are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((CAN_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) )
  #error "Software Version Numbers of Can.h and ComStack_Types.h are different"
#endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief          Development errors.
* @details        (CAN104) The Can module shall be able to detect the following errors and exceptions depending on its configuration (development/production).
*                 (CAN026) Development Errors shall indicate errors that are caused by erroneous usage of the Can module API. This covers API
*                   parameter checks and call sequence errors.
*                 (CAN080) Development error values are of type uint8.
*
*/
#define CAN_E_PARAM_POINTER      ((uint8)0x01U)
#define CAN_E_PARAM_HANDLE       ((uint8)0x02U)
#define CAN_E_PARAM_DLC          ((uint8)0x03U)
#define CAN_E_PARAM_CONTROLLER   ((uint8)0x04U)
#define CAN_E_UNINIT             ((uint8)0x05U)
#define CAN_E_TRANSITION         ((uint8)0x06U)
#define CAN_E_DATALOST           ((uint8)0x07U)
#define CAN_E_DEFAULT            ((uint8)0x08U)
#define CAN_E_PARAM_BAUDRATE     ((uint8)0x08U)
#define CAN_E_ICOM_CONFIG_INVALID ((uint8)0x09U)
#define CAN_E_INVALID_CONTROLLER ((uint8)0x0AU)
/**@}*/

/**
* @{
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define CAN_SID_INIT                          ((uint8)0x00U)
#define CAN_SID_MAIN_FUNCTION_WRITE           ((uint8)0x01U)
#define CAN_SID_SET_CONTROLLER_MODE           ((uint8)0x03U)
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS ((uint8)0x04U)
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS  ((uint8)0x05U)
#define CAN_SID_WRITE                         ((uint8)0x06U)
#define CAN_SID_GET_VERSION_INFO              ((uint8)0x07U)
#define CAN_SID_MAIN_FUNCTION_READ            ((uint8)0x08U)
#define CAN_SID_MAIN_FUNCTION_BUS_OFF         ((uint8)0x09U)
#define CAN_SID_MAIN_FUNCTION_WAKEUP          ((uint8)0x0AU)
#define CAN_SID_CBK_CHECK_WAKEUP              ((uint8)0x0BU)
#define CAN_SID_MAIN_FUNCTION_MODE            ((uint8)0x0CU)
#define CAN_SID_CHANGE_BAUDRATE               ((uint8)0x0DU)
#define CAN_SID_CHECK_BAUDRATE                ((uint8)0x0EU)
#define CAN_SID_SET_BAUDRATE                  ((uint8)0x0FU)
#define CAN_SID_SETCLOCKMODE                  ((uint8)0x11U)
#define CAN_SID_SET_ICOM_CONFIG               ((uint8)0x0FU)
#define CAN_SID_ABORT_MB                      ((uint8)0x10U)
/**@}*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef CAN_MSCAN_SPECIFIC
/**
* @brief          Can_ObjType
* @details        Used for value received by Tressos interface configuration.
*                 Describe the MB configuration.
*
*/
typedef enum
    {
        CAN_2_32_BITS_FILTER = 0U,   /**< @brief Receive MB */
        CAN_4_16_BITS_FILTER,        /**< @brief Receive MB */
        CAN_8_8_BITS_FILTER,         /**< @brief Receive MB */
        CAN_FILTER_CLOSED            /**< @brief Receive MB */
    } Can_AcceptanceType;
#endif

/**
* @brief          Can_ObjType
* @details        Used for value received by Tressos interface configuration.
*                 Describe the MB configuration.
*
*/
typedef enum
    {
        CAN_RECEIVE = 0U,   /**< @brief Receive MB */
        CAN_TRANSMIT        /**< @brief Transmit MB */
    } Can_ObjType;


/**
* @brief          CanIdType
* @details        Used for value received by Tressos interface configuration.
*                 Used to diferentiate Extended, Mixed or Standard Id type.
*
*/
typedef enum
    {
        CAN_EXTENDED = 0U,  /**< @brief Extended ID (29 bits) */
        CAN_STANDARD,       /**< @brief Standard ID (11 bits) */
        CAN_MIXED           /**< @brief Mixed ID (29 bits) */
    } CanIdType;


/**
* @brief          Can_StatusType
* @details        CAN Driver status used for checking and preventing double driver intialization.
*                 CAN_UNINIT = The CAN controller is not initialized. The CAN Controller is not participating on the CAN bus.
*                              All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                 CAN_READY = Controller has initialized: static variables, including flags;
*                             Common setting for the complete CAN HW unit; CAN controller specific settings for each CAN controller.
*
*/
typedef enum
    {
        CAN_UNINIT = 0U, /**< @brief Driver not initialized */
        CAN_READY       /**< @brief Driver ready */
    } Can_StatusType;
/**
* @brief          CAN Controller states.
* @details        States that defines the controllers.
*
*/
typedef enum
    {
        CAN_STOPPED = 0U, /**< @brief Controller in state STOPPED */
        CAN_STARTED,      /**< @brief Controller in state STARTED */
        CAN_SLEEPED       /**< @brief Controller in state SLEEPED */
    } Can_ControllerStateType;

/**
* @brief          Can_ClockModeType
* @details        CAN source clock selection used in Can_SetClockMode Non-Autosar API.
*
*/
typedef enum
    {
        CAN_NORMAL = 0U, /**< @brief Standard configuration (default) */
        CAN_ALTERNATE    /**< @brief Second configuration (special) */
    } Can_ClockModeType;
   
/**
* @brief          Can_FdType
* @details        Used for value received by Tressos interface configuration.
*                 Describe the MB payload.
*
*/
typedef enum
    {
        CAN_8_BYTES_PAYLOAD =0U ,    /**< @maximum 8 bytes payload */
#ifdef CAN_MCAN_SPECIFIC
  #if (CAN_MCAN_SPECIFIC == STD_ON)
        CAN_12_BYTES_PAYLOAD,      /**< @maximum 16 bytes payload */
        CAN_16_BYTES_PAYLOAD,    /**< @maximum 32 bytes payload */
        CAN_20_BYTES_PAYLOAD,    /**< @maximum 64 bytes payload */
        CAN_24_BYTES_PAYLOAD,    /**< @maximum 64 bytes payload */
        CAN_32_BYTES_PAYLOAD,    /**< @maximum 64 bytes payload */
        CAN_48_BYTES_PAYLOAD,    /**< @maximum 64 bytes payload */
  #else
    #error undefine IPV
  #endif
#else
        CAN_16_BYTES_PAYLOAD,      /**< @maximum 16 bytes payload */
        CAN_32_BYTES_PAYLOAD,    /**< @maximum 32 bytes payload */
#endif
        CAN_64_BYTES_PAYLOAD     /**< @maximum 64 bytes payload */
    } Can_FdType;

#ifdef CAN_MCAN_SPECIFIC
 typedef enum
     {
        CAN_FIFO_0,
        CAN_FIFO_1
     } Can_FIFOChannelType;
#endif
 /**
* @brief          Can_IcomLevelype
* @details        Defines the level of Pretended Networking.This parameter is reserved for future implementations (Pretended Networking level 2).
*
*/      
typedef enum
    {
        AND =0U ,
        EQUAL,
        GREATER,
        SMALLER,
        XOR
    } Can_IcomSignalOperationType;      

    
 /**
* @brief          Can_IcomLevelype
* @details        Defines the level of Pretended Networking.This parameter is reserved for future implementations (Pretended Networking level 2).
*
*/      
typedef enum
    {
        EXACTLY =0U,
        GREATER_MINNUM,
        SMALLER_MAXNUM,
        INSIDE_RANGE
    } Can_IcomIdOperationType;  

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
typedef struct
{
    CONST(uint32, CAN_CONST) CanIcomSignalMaskLow;
    CONST(uint32, CAN_CONST) CanIcomSignalMaskHigh;
    CONST(Can_IcomSignalOperationType, CAN_CONST) CanIcomSignalOperation;
    CONST(uint32, CAN_CONST) CanIcomSignalValueLow;
    CONST(uint32, CAN_CONST) CanIcomSignalValueHigh;
    CONST(uint8, CAN_CONST) DLCLowValue;
    CONST(uint8, CAN_CONST) DLCHighValue;
    CONST(uint32, CAN_CONST) CanIcomSignalRef;
} Can_IcomRxMessageSignalType;

typedef struct
{
    
    CONST(uint32, CAN_CONST) CanIcomCounterValue;
    CONST(uint32, CAN_CONST) CanIcomMessageId;
    CONST(uint32, CAN_CONST) CanIcomMessageIdMask;
    CONST(uint32, CAN_CONST) CanIcomMissingMessageTimerValue;
    CONST(Can_IcomIdOperationType, CAN_CONST) CanIcomIdOperation;
    CONST(uint8, CAN_CONST) u8NumCanIcomRxMessageSignal;
    CONST(boolean, CAN_CONST) CanFiltPayload;
    P2CONST(Can_IcomRxMessageSignalType, CAN_CONST, CAN_APPL_CONST) pCanIcomRxMessageSignalConfigs;
} Can_IcomRxMessageConfigsType;    

typedef struct
{
    CONST(uint8, CAN_CONST) u8CanIcomConfigId;
    CONST(boolean, CAN_CONST) CanIcomWakeOnBusOff;
    CONST(uint8, CAN_CONST) u8NumberCanIcomRxMessage;
    P2CONST(Can_IcomRxMessageConfigsType, CAN_CONST, CAN_APPL_CONST) pCanIcomRxMessageConfigs;
} Can_IcomConfigsType;    

#endif
/**
* @brief          Configuration of FlexCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_ChangeBaudrate() API to set the default baudrate after initialization.
*                 and to change the baudrate when the FlexCAN is in stopped mode.
*
*/
#if (CAN_FD_MODE_ENABLE == STD_ON)
typedef struct
    {
        CONST(uint32, CAN_CONST) u32CanFdEnable;
        CONST(uint32, CAN_CONST) u32CanFdBaudRate;
        CONST(uint32, CAN_CONST) u32CanFdCbtRegister;
        CONST(uint32, CAN_CONST) u32CanControllerTrcvDelayCompensation;
        CONST(uint32, CAN_CONST) u32CanControllerTxBitRateSwitch;
#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC))
        #if ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON))
            CONST(uint32, CAN_CONST) u32CanFdCTRL2Register;
        #endif
#endif
    } Can_ControllerFdConfigType;
#endif



/**
* @brief          Configuration of FlexCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_ChangeBaudrate() API to set the default baudrate after initialization.
*                 and to change the baudrate when the FlexCAN is in stopped mode.
*
*/
#if (CAN_CBT_ENABLE == STD_ON)
typedef struct
    {
        CONST(uint32, CAN_CONST) u32CanCbtEnable;
        CONST(uint32, CAN_CONST) u32CanCbtBaudRate;
        CONST(uint32, CAN_CONST) u32CanCbtRegister;


    } Can_ControllerCbtConfigType;
#endif
/**
* @brief          Configuration of FlexCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_ChangeBaudrate() API to set the default baudrate after initialization.
*                 and to change the baudrate when the FlexCAN is in stopped mode.
*
*/
typedef struct
    {
#ifndef CAN_MSCAN_SPECIFIC        
        CONST(uint32, CAN_CONST) u32ControlRegister; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
#else        
        CONST(Can_HwWidth, CAN_CONST) u8CanBtr0Register; /**< @brief Content of MSCAN Bus Timing Register 0 (CANBTR0) fields: SJW, BRP. */
        
        CONST(Can_HwWidth, CAN_CONST) u8CanBtr1Register; /**< @brief Content of MSCAN Bus Timing Register 1 (CANBTR1) fields: SAMP, TSEG1, TSEG2. */
        
        CONST(Can_HwWidth, CAN_CONST) u8CanCtl1Register; /**< @brief Content of the MSCAN Control Register 1 (CANCTL1) fields: CLKSRC, LOOPB, LISTEN, BORM. */
#endif        

#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC))
        CONST(uint8, CAN_CONST) u8TxArbitrationStartDelay; /**< @brief The value of the Tx Arbitration Start Delay (TASD) bit field. */
#endif

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
  #ifdef CAN_MSCAN_SPECIFIC
        CONST(Can_HwWidth, CAN_CONST) u8CanBtr0RegisterAlternate; /**< @brief Content of MSCAN Bus Timing Register 0 (CANBTR0) fields: SJW, BRP. */
        
        CONST(Can_HwWidth, CAN_CONST) u8CanCtl1RegisterAlternate; /**< @brief Content of the MSCAN Control Register 1 (CANCTL1) fields: CLKSRC, LOOPB, LISTEN, BORM. */
  #else
        CONST(uint32, CAN_CONST) u32ControlRegisterAlternate; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
  #endif
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */

        CONST(uint16, CAN_CONST) u16ControllerBaudRate; /**< @brief Configured BaudRate in kbps. */
#if (CAN_FD_MODE_ENABLE == STD_ON)
        CONST(Can_ControllerFdConfigType, CAN_CONST) ControllerFD; /*FD settings */
#endif

#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC))
  #if (CAN_CBT_ENABLE == STD_ON)
        CONST(Can_ControllerCbtConfigType, CAN_CONST) ControllerCbtRegister; /* CBT settings */
  #endif
#endif
#if (CAN_SET_BAUDRATE_API == STD_ON)
        CONST(uint16, CAN_CONST) u16ControllerBaudRateConfigID;
#endif
    } Can_ControllerBaudrateConfigType;
    
#ifndef CAN_MCAN_SPECIFIC
/**
* @brief          Configuration of FlexCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_ChangeBaudrate() API to set the default baudrate after initialization.
*                 and to change the baudrate when the FlexCAN is in stopped mode.
*
*/
typedef struct
    {
#ifndef CAN_MSCAN_SPECIFIC         
        CONST(uint32, CAN_CONST) u32ControlRegister; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
#else  
        CONST(Can_HwWidth, CAN_CONST) u8CanCtl1Register; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
        CONST(Can_HwWidth, CAN_CONST) u8CanBtr1Register; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
#endif    
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
  #ifndef CAN_MSCAN_SPECIFIC
        CONST(uint32, CAN_CONST) u32ControlRegisterAlternate; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
  #endif
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */
    } CanStatic_ControllerBaudrateConfigType;
#endif

#ifdef CAN_MSCAN_SPECIFIC  
/**
* @brief          Configuration of filters on MSCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_Mscan_ProcessRx() API to set the filters for receive buffers
*
*/

#ifdef CAN_EXTENDEDID
    #if (CAN_EXTENDEDID == STD_ON)
/**
* @{
* @brief          Can_FilterConfigType
* @details        Type for storing the Identifier Length Type: Normal or Extended.
*                   - used by "Can_MessageBufferConfigObjectType" structure.
*                 The driver does not distinguish between Extended and Mixed transmission modes.
*                 Extended transmission mode of operation behaves the same as Mixed mode.
*/
    typedef  uint32 Can_FilterConfigType;
    #else /* (CAN_EXTENDEDID == STD_OFF) */
    typedef  uint16 Can_FilterConfigType;
    #endif /* (CAN_EXTENDEDID == STD_ON/STD_OFF) */
#else
    typedef  uint16 Can_FilterConfigType;
#endif

/*
* @{
* @brief          Can_FilterConfigType
* @details        Type for storing pointer to the Identifier Filter Mask.
*                 
*
*/
typedef CONSTP2CONST(Can_FilterConfigType, CAN_CONST, CAN_APPL_CONST) Can_FilterConfigPtrType;
/**@}*/    
    
#endif    
    
/*
* @{
* @brief          Can_IdPtrType
* @details        Type for storing pointer to the Identifier Lenght Type.
*                 - used by "Can_ConfigType" structure (pointer to the FilterMasks).
*
*/
typedef CONSTP2CONST(Can_IdType, CAN_CONST, CAN_APPL_CONST) Can_IdPtrType;
/**@}*/

/**
* @brief          Type for pointer to function.
* @details        Type for pointer to function. Used for user handlers from plugin.
*
*/
typedef void (*Can_PCallBackType)( void);


#ifndef CAN_MCAN_SPECIFIC
#if (CAN_RXFIFO_ENABLE == STD_ON)
/**
* @brief          Rx Fifo Table IDs and Filter Masks
* @details        Rx Fifo Table IDs and Filter Masks
*
*/
typedef struct
    {
        CONST(uint32, CAN_CONST) u32TableId; /**< @brief Table with the IDs specific for Rx Fifo */

        CONST(uint32, CAN_CONST) u32TableFilterMask; /**< @brief Table with the Filter masks */

    } Can_RxFiFoTableIdConfigType;

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
#endif

#ifdef CAN_MCAN_SPECIFIC
#if (CAN_MCAN_SPECIFIC == STD_ON)
/**
* @brief          Rx Filter Table
* @details        Rx Filter Table Type
*/
typedef struct
    {
        CONST(uint8, CAN_CONST)     u8ControllerOffset; /**< @brief Hardware Offset for Can controller: FLEXCAN_A = Offset[0], FLEXCAN_B = Offset[1], ... */
        CONST(CanIdType, CAN_CONST) eRxFilterMbType; /**< @brief Table Count */
        CONST(uint8, CAN_CONST)     u8RxFilterOffset; /**< @brief Table Count */
        CONST(uint8, CAN_CONST)     u8RxFilterConfig; /**< @brief Table Count */
        CONST(uint8, CAN_CONST)     u8RxFilterType; /**< @brief Table Count */
        CONST(uint32, CAN_CONST)    u32RxFilterId1Value; /**< @brief Table Count */
        CONST(uint32, CAN_CONST)    u32RxFilterId2Value; /**< @brief Table Count */
    } Can_RxFilterTableType;

/**
* @brief          Controller Rx Fifo Configuration
* @details        Controller Rx Fifo Configuration
*/
typedef struct
    {
        /* Selects the receive FIFO (FIFO 0, FIFO 1). */
        CONST(Can_FIFOChannelType, CAN_CONST) FIFOChannel;
        /* Configures the FIFO depth. */
        CONST(uint8, CAN_CONST)  FIFODepth;
        /* WaterMask level */
        CONST(uint8, CAN_CONST) FIFOWaterMaskLevel;
        /* WaterMask Processing Type */
        CONST(boolean, CAN_CONST) FIFOWaterMaskPolling;
        /* FIFO WaterMask Notification */
        CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoWarningNotification;
        /* OverFlow Processing Type */
        CONST(boolean, CAN_CONST) FIFOOverflowPolling;
        /* OverFlow Notification */
        CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoOverflowNotification;  
    } Can_ControllerRxFifoConfigType;
        
/**
* @brief          Controller Sections Address Offset
* @details        Controller Sections Address Offset
*/
typedef struct
    {
        CONST(uint16, CAN_CONST) StandardFilterOffset;
        CONST(uint16, CAN_CONST) ExtendedFilterOffset;
        CONST(uint16, CAN_CONST) RxFifo0Offset;
        CONST(uint16, CAN_CONST) RxFifo1Offset;
        CONST(uint16, CAN_CONST) RxBufferOffset;
        CONST(uint16, CAN_CONST) TxBufferOffset;
    } Can_ControllerSectionOffsetType;
#endif /* (CAN_MCAN_SPECIFIC == STD_ON) */
#endif

/**
* @brief          Can_MBConfigObjectType
* @details        Type for storing information about Message Buffers (CAN hardware objs).
*                 Used by Can_MBConfigContainerType.
*
*/
typedef struct
    {
#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC)) 
        VAR(Can_HwHandleType, CAN_VAR) uIdMaskIndex; /**< @brief Index into array of Can_FilterMaskType values (uint8/uint16), Current MB and the coresponding filter mask. */
#endif

        CONST(uint8, CAN_CONST) u8ControllerId; /**< @brief Controller ID (index into controller address array containing Can_ControllerPtrType). */

        VAR(CanIdType, CAN_VAR) uIdType; /**< @brief ID type: CAN_EXTENDED, CAN_STANDARD, CAN_MIXED. */

        VAR(Can_ObjType, CAN_VAR) eMBType; /**< @brief Receive/Transmit */

        VAR(Can_IdType, CAN_VAR) uMessageId; /**< @brief (extended identifier) (uint16/uint32). configurable by CanHardwareObject/CanIdValue. */

        CONST(uint8, CAN_CONST) u8LocalPriority; /**< @brief Local priority bits used for arbitration. */

        VAR(uint32, CAN_VAR) u32HWObjID; /**< @brief HW Obiect ID */
        
#if (CAN_FD_MODE_ENABLE == STD_ON)
        VAR(uint8, CAN_VAR) u8FdPaddingValue; /**< @brief Padding value for MB > 8 bytes */
#endif

#ifdef CAN_MCAN_SPECIFIC
#if (CAN_MCAN_SPECIFIC == STD_ON)
        CONST(uint8, CAN_CONST) u8StoredRxMb; /**< @brief read write period reference */
#endif
#endif

#ifdef CAN_MSCAN_SPECIFIC
        CONST(uint32, CAN_CONST) u32CanIdAcceptance;  /**< @brief The value for identifier acceptance filter registers*/
        CONST(uint32, CAN_CONST) u32CanFilterMask;  /**< @brief The value for The filter mask registers*/
        CONST(uint8, CAN_CONST)  u8HWMBIndex;               /**< @brief The index of filter for HRH or the index of transmit buffer for HTH */
        CONST(uint8, CAN_CONST)  u32CanMainFuncRWPeriodRef; /**< @brief read write period reference */
#else
        CONST(uint8, CAN_CONST) u32CanMainFuncRWPeriodRef; /**< @brief read write period reference */
        CONST(uint16, CAN_CONST) u16MBOffsetAddr;          /**< @brief offset address of MB */
        CONST(uint8, CAN_CONST)  u8MBPayloadLength;        /**< @brief MB data size */
        CONST(uint8, CAN_CONST)  u8HWMBIndex;              /**< @brief The index of MB in message buffer memory */
#endif
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
        CONST(boolean, CAN_CONST) CanTriggerTransmitEnable; /**< @brief The parameter is used to detect the MB which run with trigger transmit feature*/
#endif
    } Can_MBConfigObjectType;


/**
* @brief          Type for storing Message Buffer configurations.
* @details        The MessageBufferConfigs array is sorted according to:
*                 - HRHs first, HTHs next (AutoSAR requirement)
*                 - Controller ID (HRHs and HTHs belonging to all controllers must be grouped together)
*                 - Message ID (to ensure top priority IDs are first which means they will be serviced first)
*
*/
typedef struct
    {
        CONSTP2CONST(Can_MBConfigObjectType, CAN_CONST, CAN_APPL_CONST) pMessageBufferConfigsPtr; /**< @brief Pointer to the MB array . */

        CONST(Can_HwHandleType, CAN_CONST) uMessageBufferConfigCount; /**< @brief Number of elements in the array -( having 6 controllers with 64MBs each uint8 is not enough to store this value -> the type is extended to uint16). */

    } Can_MBConfigContainerType;


/**
* @brief          Structure for describing individual FlexCAN controllers on the chip.
* @details        HRH = Hardware Receive Handle (HRH) is defined and provided by the CAN driver.
*                       Each HRH represents exactly one hardware object.
*                       The HRH can be used to optimize software filtering.
*                 HTH = The Hardware Transmit Handle (HTH) is defined and provided by the CAN driver.
*                       Each HTH represents one or several hardware objects, that are
*                       configured as hardware transmit pool.
*
*/
typedef struct
    {
#ifdef CAN_MSCAN_SPECIFIC
          CONST(Can_AcceptanceType, CAN_CONST) CanFilterAcceptance;
          CONST(uint8, CAN_CONST) CanMaxFilterAvaiable; /**< @brief Specifies the maximum of the Id acceptance filters supported. */
#endif           

#ifndef CAN_MCAN_SPECIFIC
        CONST(uint8, CAN_CONST) u8MaxMBCount; /**< @brief Max Message Buffer number. */
#else
#if (CAN_MCAN_SPECIFIC == STD_ON)
        CONST(uint8, CAN_CONST) u8MaxMbRxCount; /**< @brief Max Rx Message Buffer number. */

        CONST(uint8, CAN_CONST) u8MaxMbTxCount; /**< @brief Max Message Buffer number for Tx Buffer. */
        
        CONSTP2CONST(Can_ControllerRxFifoConfigType, CAN_CONST, CAN_APPL_CONST) pControllerRxFifo0ConfigsPtr;
        
        CONSTP2CONST(Can_ControllerRxFifoConfigType, CAN_CONST, CAN_APPL_CONST) pControllerRxFifo1ConfigsPtr;
        
        CONSTP2CONST(Can_ControllerSectionOffsetType, CAN_CONST, CAN_APPL_CONST) pControllerSectionOffsetPtr;        
#endif
#endif
        CONST(uint8, CAN_CONST) u8MaxBaudRateCount; /**< @brief Max BaudRate number. */
        CONST(uint8, CAN_CONST) u8DefaultBaudRateIndex; /**< @brief Default baudrate index. */
        CONSTP2CONST(Can_ControllerBaudrateConfigType, CAN_CONST, CAN_APPL_CONST) pControllerBaudrateConfigsPtr; /**< @brief Pointer to the Configuration of Baudrate timing parameter for FlexCAN baudrate controller ( CTRL value register). */

#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC))
  #if (CAN_RXFIFO_ENABLE == STD_ON)
        CONST(uint32, CAN_CONST) u32RxFifoGlobalMask; /**< @brief Rx Fifo Global mask value */

        CONST(uint8, CAN_CONST) u8RxFiFoUsedMb; /**< @brief Number of MBs used by Rx Fifo */
        
        CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoOverflowNotification; /**< @brief Pointer to RX FIFO Overflow notification function. */

        CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoWarningNotification; /**< @brief Pointer to RX FIFO Warning notification function. */
        
  #endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */
  #if (CAN_FD_MODE_ENABLE == STD_ON)
        CONST(uint32, CAN_CONST) u32MBBlockSize; /**< @brief This parameter is used to configure for three MBDSR fields in CAN_FDCTRL register */
  #endif
#endif/* CAN_MCAN_SPECIFIC */
        
        CONST(uint32, CAN_CONST) u32Options; /**< @brief Interrupt line */
 
    } Can_ControlerDescriptorType;
    

    /**
* @brief          Structure for describing individual FlexCAN controllers on the chip.
* @details        HRH = Hardware Receive Handle (HRH) is defined and provided by the CAN driver.
*                       Each HRH represents exactly one hardware object.
*                       The HRH can be used to optimize software filtering.
*                 HTH = The Hardware Transmit Handle (HTH) is defined and provided by the CAN driver.
*                       Each HTH represents one or several hardware objects, that are
*                       configured as hardware transmit pool.
*
*/
typedef struct
    {
#ifdef CAN_ENABLE_WAKEUP_SUPPORT
  #if (CAN_ENABLE_WAKEUP_SUPPORT == STD_ON)
        CONST(uint32, CAN_CONST) u32ECUMWakeupSourceId; /* ID source Wakeup of EcuM*/
  #endif
#endif
        CONST(uint8, CAN_CONST) u8ControllerOffset; /**< @brief Hardware Offset for Can controller: FLEXCAN_A = Offset[0], FLEXCAN_B = Offset[1], ... */

#ifndef CAN_MCAN_SPECIFIC
        CONSTP2CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST, CAN_APPL_CONST) pStaticControllerBaudrateConfigsPtr; /**< @brief Pointer to the Configuration of Baudrate timing parameter for FlexCAN baudrate controller ( CTRL value register). */
#endif
  
#ifdef CAN_MCAN_SPECIFIC
  #if (CAN_MCAN_SPECIFIC == STD_ON)
    #ifdef CAN_SUPPORT_MRAF_EVENT
      #if (CAN_SUPPORT_MRAF_EVENT == STD_ON)
        CONST(Can_PCallBackType, CAN_CONST) Can_SupportMRAFNotification; /*< @brief Pointer to RX FIFO Overflow notification function. */
      #endif /* (CAN_SUPPORT_MRAF_EVENT == STD_ON) */
    #endif /* define CAN_SUPPORT_MRAF_EVENT */
  #endif /* define CAN_MCAN_SPECIFIC */
#endif /* CAN_MCAN_SPECIFIC */ 

#if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
        CONST(Can_PCallBackType, CAN_CONST) Can_ErrorNotification; /*< @brief Pointer to Error interrupt notification function (ESR[ERR_INT]). */
#elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
        CONST(Can_PCallBackType, CAN_CONST) Can_ErrorNotification; /*< @brief Pointer to Error interrupt notification function (ESR[ERR_INT]). */
#endif

#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC))
        CONST(uint8, CAN_CONST) u8NumberOfMB; /*< @brief Number of message Buffers available for FlexCan unit. */
#endif /* CAN_MCAN_SPECIFIC */
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        CONST(boolean, CAN_CONST) bPnSupported;
#endif
        CONST(uint32, CAN_CONST) u32Options; /*< @brief BusOff Sw Recovery, RXFifo En, IDAM Type,  Event Trigger Mode TxProcessing/RxProcessing/BusoffProcessing. */
    } CanStatic_ControlerDescriptorType;
    
/**
* @brief          Top Level structure containing all Driver configuration.
* @details        A pointer to this structure is transmitted to Can_Init() to initalize the driver at startup.
*                 The application selects one of the configurations by using a pointer to one of the elements
*                 of this array as a parameter of the Can_Init function.
*
*/
typedef struct
    {
        VAR(uint8, CAN_VAR) u8ControllersConfigured; /**< @brief Number of Can Controllers configured in Tresos plugin. */

        P2CONST(CanStatic_ControlerDescriptorType, CAN_CONST, CAN_APPL_CONST) StaticControlerDescriptors; /**< @brief Pointer to the first FlexCAN Controller description. */
        /*Maximum Object IDs configured */
        VAR(uint32, CAN_VAR) u32CanMaxObjectId;
        
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
        CONST(uint8, CAN_CONST) u8NumCanIcomConfigs;
    
        P2CONST(Can_IcomConfigsType, CAN_CONST, CAN_APPL_CONST) pCanIcomConfigs;

 #endif
     } CanStatic_ConfigType;
    
    
/**
* @brief          Top Level structure containing all Driver configuration.
* @details        A pointer to this structure is transmitted to Can_Init() to initalize the driver at startup.
*                 The application selects one of the configurations by using a pointer to one of the elements
*                 of this array as a parameter of the Can_Init function.
*
*/
typedef struct
    {
#if !(defined(CAN_MCAN_SPECIFIC) || defined(CAN_MSCAN_SPECIFIC))
        VAR(Can_IdPtrType, CAN_VAR) pFilterMasks; /**< @brief Pointer to the first FilterMask value - any controller can have many filter masks for Can messages. */
#endif
        CONST(Can_MBConfigContainerType, CAN_CONST) MBConfigContainer; /**< @brief Pointer to the first MB configuration of this Controller. */
        P2CONST(Can_ControlerDescriptorType, CAN_CONST, CAN_APPL_CONST) ControlerDescriptors; /**< @brief Pointer to the first FlexCAN Controller description. */
   
#ifndef CAN_MCAN_SPECIFIC
#if (CAN_RXFIFO_ENABLE == STD_ON)
        CONSTP2CONST(Can_RxFiFoTableIdConfigType, CAN_CONST, CAN_APPL_CONST) pRxFiFoTableIdConfig; /**< @brief Pointer to the Table IDs for the RxFifo. */
    #ifdef  CAN_MSCAN_SPECIFIC
        CONST(uint8, CAN_CONST) u8NumberRxFilterTable; /**< @brief the number of filter element in the Rx Filter Table. */
    #endif 
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
#endif /* (CAN_MCAN_SPECIFIC) */

#ifdef CAN_MCAN_SPECIFIC
#if (CAN_MCAN_SPECIFIC == STD_ON)
        CONST(uint8, CAN_CONST) u8NumberRxFilterTable; /**< @brief: the number of filter element in the Rx Filter Table */
        CONSTP2CONST(Can_RxFilterTableType, CAN_CONST, CAN_APPL_CONST) pRxFilterTableConfig; /**< @brief: The Rx Filter Table */
#endif /* (CAN_MCAN_SPECIFIC == STD_ON) */
#endif/*CAN_MCAN_SPECIFIC*/
        /* The index of the first HTH configured */
        CONST(Can_HwHandleType, CONST) uCanFirstHTHIndex;
    } Can_ConfigType;    

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

/*
    Holds current status/run-time of CAN driver: CAN_UNINIT or CAN_READY (declared as global variable in "Can.c" file).
    (CAN103) After power-up/reset, the Can module shall be in the state CAN_UNINIT.
    Covers CAN103
*/
extern VAR(Can_StatusType, CAN_VAR) Can_eDriverStatus;

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"


#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_Init(). */
extern P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_pCurrentConfig;
extern P2CONST(Can_ControlerDescriptorType, CAN_VAR, CAN_APPL_CONST) Can_pControlerDescriptors;

extern P2CONST(CanStatic_ConfigType, CAN_VAR, CAN_APPL_CONST) CanStatic_pCurrentConfig;
extern P2CONST(CanStatic_ControlerDescriptorType, CAN_VAR, CAN_APPL_CONST) CanStatic_pControlerDescriptors;
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#if (CAN_PRECOMPILE_SUPPORT == STD_OFF)
    /* Export Driver configuration */
    /* @violates @ref Can_h_REF_2 Violates MISRA 2004 Required Rule 8.7, Required*/
    CAN_CONF_PB
#endif /* (<MODULE>_PRECOMPILE_SUPPORT == STD_OFF) */

/* @violates @ref Can_h_REF_2 Violates MISRA 2004 Required Rule 8.7, Required*/
extern CONST(CanStatic_ConfigType, CAN_CONST) CanStatic_ConfigSet;

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define CAN_START_SEC_CODE
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"


extern FUNC(void, CAN_CODE) Can_Init( P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config);


#if (CAN_VERSION_INFO_API == STD_ON)

extern FUNC(void, CAN_CODE) Can_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo);

#endif /* (CAN_VERSION_INFO_API == STD_ON) */
#if (CAN_SET_BAUDRATE_API == STD_ON)
extern FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                       CONST(uint16, AUTOMATIC) BaudRateConfigID
                                                     );
#endif /* (CAN_SET_BAUDRATE_API == STD_ON) */
#if (CAN_CHANGE_BAUDRATE_API == STD_ON)

extern FUNC(Std_ReturnType, CAN_CODE) Can_ChangeBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                          CONST(uint16, AUTOMATIC) Baudrate
                                                        );



extern FUNC(Std_ReturnType, CAN_CODE) Can_CheckBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                         CONST(uint16, AUTOMATIC) Baudrate
                                                       );

#endif /* (CAN_CHANGE_BAUDRATE_API == STD_ON) */

extern FUNC(Can_ReturnType, CAN_CODE) Can_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                             VAR(Can_StateTransitionType, AUTOMATIC) Transition
                                                           );



extern FUNC(void, CAN_CODE) Can_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);



extern FUNC(void, CAN_CODE) Can_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);


extern FUNC(Can_ReturnType, CAN_CODE) Can_Write( VAR(Can_HwHandleType, AUTOMATIC) Hth,
                                                 P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo
                                               );

#ifdef CAN_ENABLE_WAKEUP_SUPPORT                                             
    #if (CAN_ENABLE_WAKEUP_SUPPORT == STD_ON)
        
    extern FUNC (Can_ReturnType, CAN_CODE) Can_CheckWakeup( VAR(uint8, AUTOMATIC) controller);

    #endif /* (CAN_ENABLE_WAKEUP_SUPPORT == STD_ON) */
#endif

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, CAN_CODE) Can_SetIcomConfiguration( VAR(uint8, AUTOMATIC) u8Controller, 
                                                                VAR(IcomConfigIdType, AUTOMATIC) u8ConfigurationId 
                                                              );
#endif



#if (CAN_TXPOLL_SUPPORTED == STD_ON)

extern FUNC(void, CAN_CODE) Can_MainFunction_Write( void );

#ifdef CAN_MAINFUNCTION_MULTIPLE_WRITE
#if (CAN_MAINFUNCTION_MULTIPLE_WRITE==STD_ON)

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_0
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_0( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_1
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_1( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_2
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_2( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_3
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_3( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_4
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_4( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_5
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_5( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_6
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_6( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_7
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_7( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_8
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_8( void );
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_9
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_9( void );
#endif

/* @violates @ref Can_h_REF_3 Violates MISRA 2004 Required Rule 1.4, identifier clash */
#ifdef CAN_MAINFUNCTION_PERIOD_WRITE_10
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_10( void );
#endif


#endif /* (CAN_MAINFUNCTION_MULTIPLE_WRITE==STD_ON) */
#endif /* (ifdef CAN_MAINFUNCTION_MULTIPLE_WRITE) */

#else /* (CAN_TXPOLL_SUPPORTED == STD_OFF) */

/* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Can_MainFunction_Write()

#endif /* (CAN_TXPOLL_SUPPORTED == STD_OFF) */

#if (CAN_RXPOLL_SUPPORTED == STD_ON)


extern FUNC(void, CAN_CODE) Can_MainFunction_Read( void);

#ifdef CAN_MAINFUNCTION_MULTIPLE_READ
#if (CAN_MAINFUNCTION_MULTIPLE_READ == STD_ON)
    
#ifdef CAN_MAINFUNCTION_PERIOD_READ_0  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_0( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_1  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_1( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_2  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_2( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_3  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_3( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_4  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_4( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_5  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_5( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_6  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_6( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_7  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_7( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_8  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_8( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_9  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_9( void); 
#endif

#ifdef CAN_MAINFUNCTION_PERIOD_READ_10  
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_10( void); 
#endif

#endif /* (CAN_MAINFUNCTION_MULTIPLE_READ == STD_ON) */
#endif /* ifdef CAN_MAINFUNCTION_MULTIPLE_READ */

#else /* (CAN_RXPOLL_SUPPORTED == STD_OFF) */
/* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Can_MainFunction_Read()

#endif /* (CAN_RXPOLL_SUPPORTED == STD_OFF) */



#if (CAN_BUSOFFPOLL_SUPPORTED == STD_ON)

extern FUNC(void, CAN_CODE) Can_MainFunction_BusOff( void);

#else /* (CAN_BUSOFFPOLL_SUPPORTED == STD_OFF) */

/* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Can_MainFunction_BusOff()

#endif /* (CAN_BUSOFFPOLL_SUPPORTED == STD_OFF) */

#ifdef CAN_WAKEUPPOLL_SUPPORTED
    #if (CAN_WAKEUPPOLL_SUPPORTED  == STD_ON) 
        
    extern FUNC(void, CAN_CODE) Can_MainFunction_Wakeup( void); 

    #else /* (CAN_WAKEUPPOLL_SUPPORTED  == STD_ON) */

    /* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define Can_MainFunction_Wakeup()

    #endif /* (CAN_WAKEUPPOLL_SUPPORTED == STD_OFF) */
#endif 
#ifdef CAN_SUPPORT_MRAF_EVENT
  #if (CAN_SUPPORT_MRAF_EVENT == STD_ON)
    #if (CAN_MRAFPOLL_SUPPORTED == STD_ON)
extern FUNC(void, CAN_CODE) Can_MainFunction_CheckMRAF( void);
    #else /* (CAN_MRAFPOLL_SUPPORTED == STD_OFF) */
#define Can_MainFunction_CheckMRAF()
    #endif
  #endif /* (CAN_SUPPORT_MRAF_EVENT == STD_OFF) */
#endif /* defined(CAN_SUPPORT_MRAF_EVENT) */
#ifdef ERR_IPV_MCAN_0002 
  #if (ERR_IPV_MCAN_0002 == STD_ON)
extern FUNC(void, CAN_CODE) Can_DummyRead(VAR(uint8, AUTOMATIC) u8Controller);
  #endif
#endif
extern FUNC(void, CAN_CODE) Can_MainFunction_Mode( void);


#if (CAN_API_ENABLE_ABORT_MB == STD_ON)


extern FUNC(void, CAN_CODE) Can_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth);

#endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */

#if (CAN_DUAL_CLOCK_MODE == STD_ON)


extern FUNC(Std_ReturnType, CAN_CODE) Can_SetClockMode( VAR(uint8, AUTOMATIC) can_controller, VAR(Can_ClockModeType, AUTOMATIC) can_clk_mode);

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */


#define CAN_STOP_SEC_CODE
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*CAN_H*/

/** @} */
