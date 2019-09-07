/**
*   @file    Port_Ipw.c
*
*   @version 1.0.1
*   @brief   AUTOSAR Port - PORT driver midle level driver.
*   @details Implementation of the AutoSar midle level PORT driver.
*
*   @addtogroup Port
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
*   Dependencies         : none
*
*   Autosar Version      : 4.2.
*                          2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_IPW_C_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'. 
*          MemMap.h is included after each section define in order to set the current 
*          memory section as defined by AUTOSAR.
*
* @section PORT_IPW_C_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_IPW_C_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported for external identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_IPW_C_REF_4
*          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
*          of pointer. The violation is FALSE: the quantity is unsigned.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
*
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_Ipw.h"
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
*
*/
#define PORT_VENDOR_ID_IPW_C                    43

/**
* @violates @ref PORT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_IPW_C     4

/**
* @violates @ref PORT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_IPW_C     2

/**
* @violates @ref PORT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_IPW_C  2

#define PORT_SW_MAJOR_VERSION_IPW_C             1
#define PORT_SW_MINOR_VERSION_IPW_C             0
#define PORT_SW_PATCH_VERSION_IPW_C             1


/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if source file and Port_Ipw.h file are of the same vendor */
#if (PORT_VENDOR_ID_IPW_C != PORT_VENDOR_ID_IPW_H)
    #error "Port_Ipw.c and Port_Ipw.h have different vendor ids"
#endif

/* Check if the source file and Port_Ipw.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_C    != PORT_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_C    != PORT_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_C != PORT_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
   #error "AutoSar Version Numbers of Port_Ipw.c and Port_Ipw.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_C != PORT_SW_MAJOR_VERSION_IPW_H) || \
     (PORT_SW_MINOR_VERSION_IPW_C != PORT_SW_MINOR_VERSION_IPW_H) || \
     (PORT_SW_PATCH_VERSION_IPW_C != PORT_SW_PATCH_VERSION_IPW_H)    \
    )
  #error "Software Version Numbers of Port_Ipw.c and Port_Ipw.h are different"
#endif

/* Check if source file and Port header file are of the same vendor */
#if (PORT_VENDOR_ID_IPW_C != PORT_VENDOR_ID)
    #error "Port_Ipw.c and Port.h have different vendor ids"
#endif

/* Check if source file and Port header file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
   #error "AutoSar Version Numbers of Port_Ipw.c and Port.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_IPW_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_IPW_C != PORT_SW_PATCH_VERSION)    \
    )
  #error "Software Version Numbers of Port_Ipw.c and Port.h are different"
#endif

/*=================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL FUNCTIONS
=================================================================================================*/

#define PORT_START_SEC_CODE
/**
* @violates @ref PORT_IPW_C_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL FUNCTIONS
=================================================================================================*/

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin mode.
* @details The function @p Port_Ipw_SetPinMode will set the port pin mode of the
*          referenced pin during runtime.
* @pre     @p Port_Init() must have been called first.

* @param[in] PinIndex       Pin ID number.
* @param[in] PinMode        New Port Pin mode to be set on port pin.
* @param[in] pConfigPtr     Pointer to the initialization data structure
*
* @implements PORT_IPW_SetPinMode_Activity
* @api
*/
FUNC(Std_ReturnType, PORT_CODE) Port_Ipw_SetPinMode
( 
    VAR    (Port_PinType,     AUTOMATIC                 ) PinIndex,
    VAR    (Port_PinModeType, AUTOMATIC                 ) PinMode,
    P2CONST(Port_ConfigType,  AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    VAR(Std_ReturnType,     AUTOMATIC) PinModeError = (Std_ReturnType)0UL;
    /** @violates @ref PORT_IPW_C_REF_4 MISRA 2004 Required Rule 17.4 */
    VAR(Port_InternalPinIdType, AUTOMATIC) PinPad = pConfigPtr->pUsedPadConfig[PinIndex].Pin;

    VAR(uint8,                 AUTOMATIC) u8PinDescBitOffset;
    VAR(uint16,                AUTOMATIC) u16PinDescWord;
    
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex = (Port_InternalPinIdType)PinPad;
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue = (Port_RegValueType)PinMode;

    if (PAD_MODE_OPTIONS_U8 <= PinMode)
    {
        PinModeError = PORT_E_PARAM_INVALID_MODE;
    }
    else
    {
        VAR(Port_PinDirectionType, AUTOMATIC) ePadDirection = (Port_PinDirectionType)0UL;

        /* Bit offset of Pin index inside the pin description matrix */
        u8PinDescBitOffset = (uint8)(PinPad & PORT_MODE_BIT_OFFSET_MASK_U8);
        /* Selected word inside the pin description matrix */
        u16PinDescWord = (uint16)Port_au16PinDescription[(uint8)PinMode][PinPad>>4U];

        /* Check if desired mode is valid for selected pin */
        if (u16PinDescWord & (uint16)(1UL<<u8PinDescBitOffset))
        {
            switch(PinMode)
            {
                case PORT_GPIO_MODE:
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                    Port_Port_Ci_SetGpioDirChangeability(PinPad, (boolean)TRUE);
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
                    /** @violates @ref PORT_IPW_C_REF_4 MISRA 2004 Required Rule 17.4 */
                    ePadDirection = pConfigPtr->pUsedPadConfig[PinIndex].ePDDir;
#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
                    if(PORT_PIN_IN != ePadDirection)
                    {
                        Port_Port_Ci_SetGpioPadOutput(PinIndex, pConfigPtr);
                    }
#endif /* (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL) */                   
                    (void)Port_Port_Ci_SetPinDirection(PinIndex, ePadDirection, pConfigPtr);
                    break;

                default:
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                    /* All the ALT modes except GPIO*/
                    Port_Port_Ci_SetGpioDirChangeability(PinPad,(boolean)FALSE);
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
                    break;
            }
            /* Sets the port pin mode */
            Port_Port_Ci_SetPinMode(PinCfgRegIndex, PinCfgRegValue);
        }
        else
        {
                PinModeError = PORT_E_PARAM_INVALID_MODE; 
        }
    }
    return (PinModeError);
}
#endif /* PORT_SET_PIN_MODE_API */

#define PORT_STOP_SEC_CODE
/**
* @violates @ref PORT_IPW_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor
*                 statements and comments before '#include'
* @violates @ref PORT_IPW_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include
*                 file MemMap.h
*/
#include "Port_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
