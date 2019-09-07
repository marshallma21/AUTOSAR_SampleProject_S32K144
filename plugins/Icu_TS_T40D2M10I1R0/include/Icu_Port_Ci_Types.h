/**
*     @file    Icu_Port_Ci_Types.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Port_Ci low level driver exported structures.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
*
*     *     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : FTM PORT_CI LPIT LPTMR
*     Dependencies        : none
*
*     Autosar Version     : 4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_PORT_CI_TYPES_H
#define ICU_PORT_CI_TYPES_H

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_PORT_CI_Types_h_1
*        Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*        that 31 character significance and case sensitivity are supported for external identifiers.
*        The defines are validated.
*
* @section [global]
*        Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*        on the significance of more than 31 characters. The used compilers use more than 31 chars
*        for identifiers.
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_PORT_CI_TYPES_VENDOR_ID                   43
/* @violates @ref Icu_PORT_CI_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_PORT_CI_TYPES_AR_RELEASE_MAJOR_VERSION    4
/* @violates @ref Icu_PORT_CI_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_PORT_CI_TYPES_AR_RELEASE_MINOR_VERSION    2
/* @violates @ref Icu_PORT_CI_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_PORT_CI_TYPES_AR_RELEASE_REVISION_VERSION 2
#define ICU_PORT_CI_TYPES_SW_MAJOR_VERSION            1
#define ICU_PORT_CI_TYPES_SW_MINOR_VERSION            0
#define ICU_PORT_CI_TYPES_SW_PATCH_VERSION            1
/**@}*/


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief Port_Ci's External Interrupt defines
*/
#define     PORT_CI_IRQ_A_CH_0      ((uint8)0U)
#define     PORT_CI_IRQ_B_CH_0      ((uint8)1U)
#define     PORT_CI_IRQ_C_CH_0      ((uint8)2U)
#define     PORT_CI_IRQ_D_CH_0      ((uint8)3U)
#define     PORT_CI_IRQ_E_CH_0      ((uint8)4U)
#define     PORT_CI_IRQ_F_CH_0      ((uint8)5U)
#define     PORT_CI_IRQ_G_CH_0      ((uint8)6U)
#define     PORT_CI_IRQ_H_CH_0      ((uint8)7U)
#define     PORT_CI_IRQ_J_CH_0      ((uint8)9U)
#define     PORT_CI_IRQ_K_CH_0      ((uint8)10U)
#define     PORT_CI_IRQ_L_CH_0      ((uint8)11U)

/**@}*/
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint16  Icu_Port_Ci_ChannelType;

typedef uint16 Icu_Port_Ci_ControlType;

typedef struct
{
    /** @brief Assigned Port_Ci channel id*/
    CONST(Icu_Port_Ci_ChannelType,  ICU_CONST) nHwChannel;
    /** @brief Port_Ci Default Start Edge */
    CONST(uint8,  ICU_CONST) nDefaultStartEdge;
} Icu_Port_Ci_ChannelConfigType;

/**
* @brief      Port_Ci IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of Port_Ci channels in the Icu configuration */
    CONST(Icu_Port_Ci_ChannelType,       ICU_CONST) nNumChannels;
    /** @brief Pointer to the configured channels for Port_Ci */
    CONST(Icu_Port_Ci_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[];
} Icu_Port_Ci_IpConfigType;
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* ICU_PORT_CI_TYPES */
/** @} */

