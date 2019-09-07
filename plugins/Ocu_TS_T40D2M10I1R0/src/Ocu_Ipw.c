/**
*   @file           Ocu_Ipw.c
*
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - OCU Ipw API implementation.
*   @details        OCU IWP API implementation.
*
*   @addtogroup     OCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
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
=====================================================================================================*/
/*===================================================================================================
======================================================================================================*/



#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section OCU_IPW_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* Ocu_MemMap.h included after each section define in order to set the current memory section
*
* @section OCU_IPW_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section OCU_IPW_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section OCU_IPW_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section OCU_IPW_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Ocu_Ipw.c
*/
#include "Ocu_Ipw_Types.h"
#include "Ocu_Ipw.h"
#include "Ocu_Ftm.h"
#include "Ocu_Ipw_Irq.h"


/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Ocu_Ipw.c
*/
#define OCU_IPW_VENDOR_ID_C                     43
/** @violates @ref OCU_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref OCU_IPW_C_REF_4 Identifier exceeds 31 chars. */
#define OCU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref OCU_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref OCU_IPW_C_REF_4 Identifier exceeds 31 chars. */
#define OCU_IPW_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref OCU_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref OCU_IPW_C_REF_4 Identifier exceeds 31 chars. */
#define OCU_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define OCU_IPW_SW_MAJOR_VERSION_C              1
#define OCU_IPW_SW_MINOR_VERSION_C              0
#define OCU_IPW_SW_PATCH_VERSION_C              1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#if (OCU_IPW_VENDOR_ID_C != OCU_IPW_VENDOR_ID)
    #error "Ocu_Ipw.c and Ocu_Ipw.h have different vendor ids"
#endif

#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != OCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION_C    != OCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION_C != OCU_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.c and Ocu_Ipw.h are different"
#endif

#if ((OCU_IPW_SW_MAJOR_VERSION_C != OCU_IPW_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION_C != OCU_IPW_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION_C != OCU_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.c and Ocu_Ipw.h are different"
#endif

#if (OCU_IPW_VENDOR_ID_C != OCU_IPW_TYPES_VENDOR_ID)
    #error "Ocu_Ipw.c and Ocu_Ipw_Types.h have different vendor ids"
#endif

#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION_C    != OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION_C != OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.c and Ocu_Ipw_Types.h are different"
#endif

#if ((OCU_IPW_SW_MAJOR_VERSION_C != OCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION_C != OCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION_C != OCU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.c and Ocu_Ipw_Types.h are different"
#endif


#if (OCU_IPW_VENDOR_ID_C != OCU_FTM_VENDOR_ID)
    #error "Ocu_Ipw.c and Ocu_Ftm.h have different vendor ids"
#endif

#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != OCU_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION_C    != OCU_FTM_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION_C != OCU_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.c and Ocu_Ftm.h are different"
#endif

#if ((OCU_IPW_SW_MAJOR_VERSION_C != OCU_FTM_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION_C != OCU_FTM_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION_C != OCU_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.c and Ocu_Ftm.h are different"
#endif

#if (OCU_IPW_VENDOR_ID_C != OCU_IPW_IRQ_VENDOR_ID)
    #error "Ocu_Ipw.c and Ocu_Ipw_Irq.h have different vendor ids"
#endif

#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != OCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION_C    != OCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION_C != OCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.c and Ocu_Ipw_Irq.h are different"
#endif

#if ((OCU_IPW_SW_MAJOR_VERSION_C != OCU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION_C != OCU_IPW_IRQ_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION_C != OCU_IPW_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.c and Ocu_Ipw_Irq.h are different"
#endif

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/
 
/*===============================================================================================
*                                       CONSTANTS
===============================================================================================*/

/* @violates @ref OCU_IPW_C_REF_4 Identifier exceeds 31 chars. */
#define OCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref OCU_IPW_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref OCU_IPW_C_REF_2 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*
* @violates @ref OCU_IPW_C_REF_5 external ... could be made static
*/
P2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpwGlobalConfig;

/* @violates @ref OCU_IPW_C_REF_4 Identifier exceeds 31 chars. */
#define OCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref OCU_IPW_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref OCU_IPW_C_REF_2 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
#define OCU_START_SEC_CODE
/*
* @violates @ref OCU_IPW_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref OCU_IPW_C_REF_2 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*================================================================================================*/
/**
* @brief            Ocu_Ipw_Init
* @details          This function call the supported IP initialization functions.
*
* @param[in]        pIpConfig - Pointer to OCU top configuration structure
* @param[in]        eCountDir - Direction of counter
*
* @return           void
*
*
*/
FUNC (void, OCU_CODE) Ocu_Ipw_Init
(   
    CONSTP2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpConfig
)
{
    if(NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        /* Call FTM IP init function */
        pIpwGlobalConfig = pIpConfig;
        
        Ocu_Ftm_Init(
                        pIpwGlobalConfig->pFtmIpConfig
                    );
    }
}


/*===============================================================================================*/
#if (OCU_DEINIT_API == STD_ON)
/**
* @brief            Ocu_Ipw_DeInit
* @details          This function call the supported IP de-initialization functions.
*
* @param[in]        void
*
* @return           void
*/
FUNC (void, OCU_CODE) Ocu_Ipw_DeInit
(
    CONSTP2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpConfig
)
{
    if(NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        /* Call FTM IP DeInit function */
        pIpwGlobalConfig = pIpConfig;
        
        Ocu_Ftm_DeInit(pIpwGlobalConfig->pFtmIpConfig);
    }
}
#endif /* OCU_DEINIT_API */


/*===============================================================================================*/
/**
* @brief            Ocu_Ipw_StartChannel
* @details          This function will call StartChannel function for the corresponding IP of OcuChannel
*
* @param[in]        u8ChannelNumber  Ocu channel id in top configuration structure
*
* @return           void
*/
FUNC (void, OCU_CODE) Ocu_Ipw_StartChannel
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */
    
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;    
    Ocu_Ftm_StartChannel(
                            u8ChannelIndex,
                            pIpwGlobalConfig->pFtmIpConfig
                        );
}


/*===============================================================================================*/

/**
* @brief            Ocu_Ipw_StopChannel
* @details          This function will call StopChannel function for the corresponding IP of OcuChannel
*
* @param[in]        u8ChannelNumber  Ocu channel id in top configuration structure
*
* @return           void
*/
FUNC (void, OCU_CODE) Ocu_Ipw_StopChannel
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */    
    
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;
    
    Ocu_Ftm_StopChannel(
                        u8ChannelIndex,
                        pIpwGlobalConfig->pFtmIpConfig
                       );
}


/*===============================================================================================*/
#if (OCU_SET_PIN_STATE_API == STD_ON)
/**
* @brief            Ocu_Ipw_SetPinState
* @details          This function will call SetPinState function for the corresponding IP of OcuChannel
*
* @param[in]        u8ChannelNumber  Ocu channel id in top configuration structure
* @param[in]        ePinState        Expected Pin State for the given channel
*
* @return           void
*/
FUNC (void, OCU_CODE) Ocu_Ipw_SetPinState
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_PinStateType, AUTOMATIC) ePinState
)
{  
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */
    
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;
    Ocu_Ftm_SetPinState(
                        u8ChannelIndex,
                        ePinState,                        
                        pIpwGlobalConfig->pFtmIpConfig
                       );
}
#endif /* OCU_SET_PIN_STATE_API */


/*===============================================================================================*/
#if (OCU_SET_PIN_ACTION_API == STD_ON)
/**
* @brief            Ocu_Ipw_SetPinAction
* @details          This function will call SetPinAction function for the corresponding IP of OcuChannel
*
* @param[in]        u8ChannelNumber  Ocu channel id in top configuration structure
* @param[in]        ePinAction       Expected Pin Action for the given channel
*
*/
FUNC(void, OCU_CODE) Ocu_Ipw_SetPinAction
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_PinActionType, AUTOMATIC) ePinAction,
    VAR(boolean,           AUTOMATIC) bIsRunning
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */    
    
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;
    Ocu_Ftm_SetPinAction(
                            u8ChannelIndex,
                            ePinAction, 
                            bIsRunning,
                            pIpwGlobalConfig->pFtmIpConfig
                        );    
}
#endif /* OCU_SET_PIN_ACTION_API */

#if (OCU_GET_COUNTER_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Ocu_Ipw_GetCounter
* @details          This function will call GetCounter function for the corresponding IP of OcuChannel
*
* @param[in]        u8ChannelNumber  Ocu channel id in top configuration structure
*
* @return           Ocu_ValueType
*/
FUNC (Ocu_ValueType, OCU_CODE) Ocu_Ipw_GetCounter
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber
)
{
    VAR(Ocu_ValueType, AUTOMATIC) CounterValue = (Ocu_ValueType)0;
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */    
    
    
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;
    CounterValue = Ocu_Ftm_GetCounter(
                                        u8ChannelIndex,
                                        pIpwGlobalConfig->pFtmIpConfig
                                     );
    
    return CounterValue;
}
#endif /* OCU_GET_COUNTER_API */


#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Ocu_Ipw_SetAbsoluteThreshold
* @details          This function will change the compare match interval for the given timer channel
*
* @param[in]        u8ChannelNumber     Ocu channel id in top configuration structure
* @param[in]        ReferenceValue    Reference value for the counting interval
* @param[in]        AbsoluteValue     Absolute value for the counting interval
*
* @return          Ocu_ReturnType - Tells the caller whether the compare match will occur 
*                                   (or has already occurred) during the current Reference
*                                   Interval, as a result of setting the new threshold value.
*/
FUNC (Ocu_ReturnType, OCU_CODE) Ocu_Ipw_SetAbsoluteThreshold
(
    VAR(Ocu_ChannelType,        AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_ValueType,          AUTOMATIC) ReferenceValue,
    VAR(Ocu_ValueType,          AUTOMATIC) AbsoluteValue
    
)
{
    VAR(Ocu_ReturnType, AUTOMATIC)  StatusValue = OCU_CM_OUT_REF_INTERVAL;
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */    
    
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;
    StatusValue = Ocu_Ftm_SetAbsoluteThreshold(
                                                    u8ChannelIndex, 
                                                    ReferenceValue, 
                                                    AbsoluteValue,
                                                    pIpwGlobalConfig->pFtmIpConfig
                                              );
    return StatusValue;
}
#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API */

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Ocu_Ipw_SetRelativeThreshold
* @details          This function will change the compare match interval for the given timer channel
*
* @param[in]        u8ChannelNumber     Ocu channel id in top configuration structure
* @param[in]        RelativeValue     Reference value for the counting interval
*
* @return          Ocu_ReturnType - Tells the caller whether the compare match will occur 
*                                   (or has already occurred) during the current Reference
*                                   Interval, as a result of setting the new threshold value.
*/
FUNC (Ocu_ReturnType, OCU_CODE) Ocu_Ipw_SetRelativeThreshold
(
    VAR(Ocu_ChannelType,        AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_ValueType,          AUTOMATIC) RelativeValue
)
{
    VAR(Ocu_ReturnType, AUTOMATIC)  StatusValue = OCU_CM_OUT_REF_INTERVAL;
    VAR(uint8, AUTOMATIC) u8ChannelIndex; /* assigned HW channel id code */    
        
    u8ChannelIndex = (*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig;
    StatusValue = Ocu_Ftm_SetRelativeThreshold(
                                                    u8ChannelIndex,
                                                    RelativeValue,
                                                    pIpwGlobalConfig->pFtmIpConfig
                                                 );    
    return StatusValue;
}
#endif /*OCU_SET_RELATIVE_THRESHOLD_API*/

/*===============================================================================================*/
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief            Ocu_Ipw_SetClockMode
* @details          This function will call SetClockMode function of all configured Hw IPs
*
* @param[in]        pIpConfig - Pointer to OCU top configuration structure
* @param[in]        ePrescaler      OCU_PRIMARY_PRESCALER for normal clock mode or 
*                                   OCU_ALTERNATIVE_PRESCALER for a different prescaler for the driver
*/
FUNC (void, OCU_CODE) Ocu_Ipw_SetClockMode
(
    CONSTP2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpConfig,
    VAR(Ocu_SelectPrescalerType,   AUTOMATIC) ePrescaler
)
{
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    { 
        /* Call Ftm IP function */
        Ocu_Ftm_SetClockMode(pIpConfig->pFtmIpConfig, (Ocu_Ftm_SelectPrescalerType)ePrescaler);
    }
    else
    {
        /* do nothing */
    }
}
#endif
/*===============================================================================================*/
#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
* @brief            Ocu_Ipw_GetMaxCountValue
* @details          This function will return max counter value for given channel
*
* @param[in]        u8ChannelNumber - Logic channel
* @return           Ocu_ValueType   - Max counter value for given channel
*/
/* @violates @ref OCU_IPW_C_REF_5 external ... could be made static */
FUNC (Ocu_ValueType, OCU_CODE) Ocu_Ipw_GetMaxCountValue
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber
)
{
    VAR(Ocu_ValueType, AUTOMATIC)  ReturnMaxCountValue;
    
    ReturnMaxCountValue = Ocu_Ftm_GetMaxCountValue((Ocu_ChannelType)((*pIpwGlobalConfig->pIpChannelsConfig)[u8ChannelNumber].u8IdxChannelConfig));    
    return ReturnMaxCountValue;
}
#endif

#define OCU_STOP_SEC_CODE
/*
* @violates @ref OCU_IPW_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref OCU_IPW_C_REF_2 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
