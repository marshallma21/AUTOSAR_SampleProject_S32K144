/**
*    @file    Icu_Ftm_Types.h
*    @version 1.0.1
*
*    @brief   AUTOSAR Icu - Ftm header file support for ICU driver.
*    @details Ftm header file, containing the variables and functions that are exported by the IP driver.
*
*    @addtogroup ICU_MODULE
*    @{
*/
/*==================================================================================================
*    Project               : AUTOSAR 4.2 MCAL
*    Platform              : ARM
*    Peripheral            : FTM PORT_CI LPIT LPTMR
*    Dependencies          : none
*
*    Autosar Version       : 4.2.2
*    Autosar Revision      : ASR_REL_4_2_REV_0002
*    Autosar Conf.Variant  :
*    SWVersion             : 1.0.1
*    BuildVersion          : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*    All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_FTM_TYPES_H
#define ICU_FTM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*       Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*       on the significance of more than 31 characters. The used compilers use more than 31 chars
*       for identifiers
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/* */
#define ICU_FTM_TYPES_VENDOR_ID                       43
#define ICU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_FTM_TYPES_AR_RELEASE_MINOR_VERSION        2
#define ICU_FTM_TYPES_AR_RELEASE_REVISION_VERSION     2
#define ICU_FTM_TYPES_SW_MAJOR_VERSION                1
#define ICU_FTM_TYPES_SW_MINOR_VERSION                0
#define ICU_FTM_TYPES_SW_PATCH_VERSION                1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief   Maximum value of  FTM counter
* @details define maximum value for FTM counter
*/
#define FTM_MAX_VAL_COUNTER_U32 ((uint32)0xFFFFUL)


/**
* @{
* @brief   Ftm ICU dependent mask
* @details Specific bitfields masks for Ftm registers
*/
#define FTM_CTRL1_PRIS_RISING_EDGE_U16    ((uint16)((uint16)0x1U << (FTM_CTRL1_CNTMODE_SHIFT)))
#define FTM_CTRL1_PRIS_BOTH_EDGES_U16     ((uint16)((uint16)0x2U << (FTM_CTRL1_CNTMODE_SHIFT)))

#define FTM_STATUS_FLAGS_IN_USE_U16       ((uint16)(FTM_STS_ICF1_MASK_U16))
#define FTM_CAPT_FIFO_DEPTH_U16           ((uint16)8U)
/**@}*/

/**
* @{
* @brief Specific Ftm Channel parameters
* @remarks defines for bitfields used in Icu_ParamValue member for ICU Ftm Channels
*/
#define ICU_FTM_FILTER_MASK_U32             ((uint32)(BIT4|BIT3|BIT2|BIT1))
#define ICU_FTM_FILTER_SHIFT_U32                ((uint32)1U)

#define ICU_FTM_DMA_ENABLE_U32              ((uint32)(1U))
#define ICU_FTM_DMA_ENABLE_MASK_U32         ((uint32)(BIT0))
#define ICU_FTM_DMA_ENABLE_SHIFT_U32            ((uint32)0U)

#define ICU_FTM_FREEZE_MASK_U32             ((uint32)(BIT5))
#define ICU_FTM_FREEZE_SHIFT_U32                ((uint32)5U)

#define ICU_FTM_PRESCALER_DIVIDE_1_U32       ((uint32)0x00)
#define ICU_FTM_PRESCALER_DIVIDE_2_U32       ((uint32)0x01)
#define ICU_FTM_PRESCALER_DIVIDE_4_U32       ((uint32)0x02)
#define ICU_FTM_PRESCALER_DIVIDE_8_U32       ((uint32)0x03)
#define ICU_FTM_PRESCALER_DIVIDE_16_U32      ((uint32)0x04)
#define ICU_FTM_PRESCALER_DIVIDE_32_U32      ((uint32)0x05)
#define ICU_FTM_PRESCALER_DIVIDE_64_U32      ((uint32)0x06)
#define ICU_FTM_PRESCALER_DIVIDE_128_U32     ((uint32)0x07)

#define ICU_INDEX_NULL                   (0xFFU)

#define ICU_FTM_SRC_CLK_MASK_U16         ((uint16)(BIT1|BIT0))
#define ICU_FTM_PRESCALER_MASK_U32       ((uint32)(BIT2|BIT1|BIT0))

#define ICU_FTM_PRES_CONFIG_WIDTH_U32        ((uint32)(3U))
#define ICU_FTM_CLK_CONFIG_WIDTH_U32         ((uint32)(2U))


#define ICU_FTM_SYSTEM_CLOCK_U32                ((uint32)(1U))
#define ICU_FTM_FIXED_FREQUENCY_CLOCK_U32       ((uint32)(2U))
#define ICU_FTM_EXTERNAL_CLOCK_U32              ((uint32)(3U))
#define ICU_FTM_NO_CLOCK_U32                    ((uint32)(0U))
/**@}*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief          This gives the numeric ID (hardware channel number) of an ICU channel
 * @implements Icu_ChannelType_typedef
 * */
typedef uint8                           Ftm_IcuChannelType;

typedef uint32                          Icu_Ftm_ControlType;

typedef const struct
{
    CONST(uint16,  ICU_CONST) Icu_Ftm_GlobalConfigClkSrc;
    CONST(uint32,  ICU_CONST) Icu_Ftm_GlobalConfigPrescale;
#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
    CONST(uint32,  ICU_CONST) Icu_Ftm_GlobalConfigAltPrescale;
#endif /* ICU_DUAL_CLOCK_MODE_API == STD_ON */
} Icu_Ftm_GlobalConfigurationType;

typedef struct
{
    /** @brief Assigned FTM channel id*/
    CONST(Ftm_IcuChannelType,     ICU_CONST) nHwChannel;
    /** @brief FTM channel parameters */
    CONST(Icu_Ftm_ControlType,     ICU_CONST) nControlValue;
    /** @brief FTM Default Start Edge */
    CONST(uint8,  ICU_CONST) nDefaultStartEdge;
    /** @brief FTM MeasurementMode */
    CONST(uint8,  ICU_CONST) nMeasurementModeType;
} Icu_Ftm_ChannelConfigType;

/**
* @brief      FTM IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of FTM channels in the Icu configuration */
    CONST(Ftm_IcuChannelType,       ICU_CONST) nNumChannels;
    /** @brief Configured FTM global configuration */
    P2CONST(Icu_Ftm_GlobalConfigurationType, AUTOMATIC, ICU_APPL_CONST) IcuFtmGlobalConfiguration;
    /** @brief Pointer to the configured channels for FTM */
    CONST(Icu_Ftm_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[];
} Icu_Ftm_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* ICU_FTM_TYPES_H */

/** @} */
