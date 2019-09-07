/**
*   @file    Adc_Adc12bsarv2.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver source file.
*   @details This is the low level driver source file,mainly implemented for the ADC12BSARV2 hardware IP.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Adc12bsarv2_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Adc12bsarv2_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file .
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Adc12bsarv2_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Adc12bsarv2_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_Adc12bsarv2_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This is used for the Speed optimization of the memory access.
*
* @section Adc_Adc12bsarv2_c_REF_6
* Violates MISRA 2004 Required Rule 10.3, Cast from unsign interger to sign interger
* This is used for calculate the dma source last
*
* @section Adc_Adc12bsarv2_c_REF_7
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters significance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Adc12bsarv2_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is due to the code complexity.
*
* @section Adc_Adc12bsarv2_c_REF_9
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro computes the
* address of any register by using the hardware offset of the controller. The address calculated as an
* unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Adc12bsarv2_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by IPV layer.
*
* @section Adc_Adc12bsarv2_c_REF_14
* Violates MISRA 2004 Advisory Rule 16.7, A pointer parameter in a function prototype should be
* declared as 'pointer to const' if the pointer is not used to modify the addressed object.
* The pointer is used to modify the addressed object.
*
* @section Adc_Adc12bsarv2_c_REF_15
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
* 
* @section Adc_Adc12bsarv2_c_REF_16
* Violates MISRA 2004 Required Rule 1.2, place reliance on undefined or unspecified behaviour
* This is used for the code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc_Ipw.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#endif
#include "SilRegMacros.h"
/** @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file  */
#include "Adc_Reg_eSys_Adc12bsarv2.h"
/** @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file  */
#include "Adc_Adc12bsarv2_CfgEx.h"
#include "SchM_Adc.h"
#include "Adc_Adc12bsarv2.h"
#include "Adc_Pdb.h"
/** @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file  */
#include "Mcal.h"

#ifdef ADC_DMA_SUPPORTED
#include "CDD_Mcl.h"
#endif
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/** @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file  */
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_AR_VENDOR_ID_ADC12BSARV2_C                 43
/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C     4
/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C     2
/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_C  2
/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_SW_MAJOR_VERSION_ADC12BSARV2_C             1
/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_SW_MINOR_VERSION_ADC12BSARV2_C             0
/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_SW_PATCH_VERSION_ADC12BSARV2_C             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC IPW header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_C != ADC_VENDOR_ID_IPW_H)
    #error "Adc_Adc12bsarv2.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC IPW header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_C != ADC_SW_MAJOR_VERSION_IPW_H) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_C != ADC_SW_MINOR_VERSION_IPW_H) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_C != ADC_SW_PATCH_VERSION_IPW_H) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2.c and Adc_Ipw.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_C != ADC_VENDOR_ID_REG)
    #error "Adc_Adc12bsarv2.c and Adc_Reg_eSys_Adc12bsarv2.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_C != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_C != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_C != ADC_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2.c and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and Adc_Adc12bsarv2_CfgEx header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_C != ADC_VENDOR_ID_ADC12BSARV2_CFGEX)
    #error "Adc_Adc12bsarv2.c and Adc_Adc12bsarv2_CfgEx.h have different vendor ids"
#endif

/* Check if source file and Adc_Adc12bsarv2_CfgEx header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_CFGEX) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Adc_Adc12bsarv2_CfgEx.h are different"
#endif

/* Check if source file and Adc_Adc12bsarv2_CfgEx header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_C != ADC_SW_MAJOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_C != ADC_SW_MINOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_C != ADC_SW_PATCH_VERSION_ADC12BSARV2_CFGEX) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2.c and Adc_Adc12bsarv2_CfgEx.h are different"
#endif

/* Check if source file and Adc_Adc12bsarv2 header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_C != ADC_VENDOR_ID_ADC12BSARV2)
    #error "Adc_Adc12bsarv2.c and Adc_Adc12bsarv2.h have different vendor ids"
#endif

/* Check if source file and Adc_Adc12bsarv2 header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Adc_Adc12bsarv2.h are different"
#endif

/* Check if source file and Adc_Adc12bsarv2 header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_C != ADC_SW_MAJOR_VERSION_ADC12BSARV2) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_C != ADC_SW_MINOR_VERSION_ADC12BSARV2) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_C != ADC_SW_PATCH_VERSION_ADC12BSARV2) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2.c and Adc_Adc12bsarv2.h are different"
#endif

/* Check if source file and Adc_Pdb header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_C != ADC_VENDOR_ID_PDB)
    #error "Adc_Adc12bsarv2.c and Adc_Pdb.h have different vendor ids"
#endif

/* Check if source file and Adc_Pdb header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MAJOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_MINOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_C != ADC_AR_RELEASE_REVISION_VERSION_PDB) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Adc_Pdb.h are different"
#endif

/* Check if source file and Adc_Pdb header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_C != ADC_SW_MAJOR_VERSION_PDB) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_C != ADC_SW_MINOR_VERSION_PDB) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_C != ADC_SW_PATCH_VERSION_PDB) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2.c and Adc_Pdb.h are different"
#endif

/** @violates @ref Adc_Adc12bsarv2_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != DEM_AR_RELEASE_MINOR_VERSION) \
     )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Dem.h are different"
 #endif
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

 /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and SilRegMacros.h are different"
 #endif

 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and Mcal.h are different"
 #endif

 #ifdef ADC_DMA_SUPPORTED
  /* Check if source file and DMA header file are of the same Autosar version */
  #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_C != MCL_AR_RELEASE_MINOR_VERSION)  \
      )
      #error "AutoSar Version Numbers of Adc_Adc12bsarv2.c and CDD_Mcl.h are different"
  #endif
 #endif
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
#define ADC_START_SEC_CONST_32
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

/**
* @brief          Start address of ADC hardware units
*/
/** @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage*/
CONST(uint32, ADC_CONST) ADC12BSARV2_BASE_ADDR32[ADC_MAX_HW_UNITS] =
{
#ifdef ADC0_BASEADDR
    ADC0_BASEADDR,
#else
    ((uint32)0x00000000UL),
#endif
#if (ADC_MAX_HW_UNITS > 1U)
#ifdef ADC1_BASEADDR
    ADC1_BASEADDR
#endif
#endif
};

#define ADC_STOP_SEC_CONST_32
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#ifdef ADC_DMA_SUPPORTED
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps
* @violates @ref Adc_Adc12bsarv2_c_REF_10 External linkage
*/
VAR(Adc_ValueGroupType, ADC_VAR) Adc_Adc12bsarv2_aDmaInternalResultBuffer[ADC_MAX_HW_UNITS];
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
/**
* @brief          The array to store the Dma configuration for each Adc hardware unit.
*/
/** @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage*/
VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) Adc_Adc12bsarv2_aDmaTcdConfig[ADC_MAX_HW_UNITS];
/**
* @brief          The array to store the address of TCD which configured for each Adc hardware unit.
*/
/** @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage*/
P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) Adc_Adc12bsarv2_aTcdAddress[ADC_MAX_HW_UNITS];

#ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
#if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
/** @violates @ref Adc_Adc12bsarv2_c_REF_15 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
static VAR(uint16, ADC_CODE) Adc_Adc12bsarv2_aDraftBufferDMA[2];
#endif
#endif

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
#endif /* ADC_DMA_SUPPORTED */

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#if (ADC_DUAL_CLOCK_MODE == STD_ON) && (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          Clock mode in use
*/
extern VAR(Adc_DualClockModeType, AUTOMATIC) Adc_eClockMode;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) && (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_InitUnitHardware
(
    VAR(Adc_HwUnitType,AUTOMATIC) Unit,
    P2CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
);

#if (ADC_DEINIT_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DeInitHardware
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_StopConversionCheckTimeout
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#ifdef ADC_DMA_SUPPORTED
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StartDmaOperation
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(uint8, AUTOMATIC) u8NumChannel
);
#endif /* ADC_DMA_SUPPORTED */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Initializes the ADC hardware.
* @details        Initializes the ADC hardware as per configuration.
*
* @param[in]      Unit         The hardware Unit.
* @param[in]      pConfigPtr   Pointer to the hardware configuration structure to be used.
*
* @return         void
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_InitUnitHardware
(
    VAR(Adc_HwUnitType,AUTOMATIC) Unit,
    P2CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
)
{
    /* Hardware index in the structure*/
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = (Adc_HwUnitType)0;

    /* Counter for SC1 registers */
    VAR(uint8, AUTOMATIC) u8SC1n = 0U;

    /* Get the logical id of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];

    /* Disable ADC hardware units */
    for (u8SC1n = 0U; u8SC1n < ADC_NUM_SC1n_REGISTER; u8SC1n++)
    {
        /* Clear conversion complete flag (0b) and disable input channel selection (11111b) in SC1 registers*/
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SC1n), ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
    }

    /* Initialize ADC registers as the configuration */

    /* Configuration for clock divide, conversion mode and input clock selection */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_WRITE32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), pConfigPtr[HwIndex].u32AdcCfg1Register);

#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
    /* Sample time duration configuration */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), pConfigPtr[HwIndex].u32AdcCfg2Register);

    /* Default: Oneshot conversion, enable hardware average function */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), pConfigPtr[HwIndex].u32AdcSc3Register);

#else
    /* Disable hardware average function */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), pConfigPtr[HwIndex].u32AdcSc3Register & (~ADC12BSARV2_SC3_AVG_MASK_U32));

#endif
    /* Default: enable hardware trigger
     * Voltage reference selection as user configuration
     */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_WRITE32(ADC12BSARV2_SC2_REG_ADDR32(Unit), pConfigPtr[HwIndex].u32AdcSc2Register);

    /* Reset compare value registers */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CVn_REG_ADDR32(Unit, (uint32)0), ADC12BSARV2_CV_RESET_VALUE_U32);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CVn_REG_ADDR32(Unit, (uint32)1), ADC12BSARV2_CV_RESET_VALUE_U32);

    /* Clear user offset register value */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC12BSARV2_USR_OFS_REG_ADDR32(Unit), (ADC12BSARV2_USR_OFS_U32 & (uint32)(pConfigPtr[HwIndex].u32AdcOfsRegister)));

    /* Initialize the PRESCALER and MULT settings of the associated PDB unit */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Adc_Pdb_Init(Unit, pConfigPtr[HwIndex].u32AdcPdbClockSettings);
}

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function deinitializes the ADC hardware.
*
* @param[in]      Unit      The hardware Unit.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DeInitHardware
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /* Counter for SC1 registers */
    VAR(uint8, AUTOMATIC) u8SC1n = 0U;

    /* Disable ADC hardware unit */
    for (u8SC1n = 0U; u8SC1n < ADC_NUM_SC1n_REGISTER; u8SC1n++)
    {
        /* Clear conversion complete flag (0b) and disable input channel selection (11111b) in SC1 registers*/
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SC1n), (ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32));
    }

    /* Reset ADC registers to default value */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_RESET_VALUE_U32);

    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), ADC12BSARV2_CFG2_RESET_VALUE_U32);

    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_SC2_REG_ADDR32(Unit), ADC12BSARV2_SC2_RESET_VALUE_U32);

    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_RESET_VALUE_U32);

    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CVn_REG_ADDR32(Unit, (uint32)0), ADC12BSARV2_CV_RESET_VALUE_U32);

    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CVn_REG_ADDR32(Unit, (uint32)1), ADC12BSARV2_CV_RESET_VALUE_U32);

#ifdef ADC_DMA_SUPPORTED
    if((uint8)ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        /* Disable DMA interrupt */
        Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
    #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        /* Disable DMA notification */
        Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
    #endif
    }
#endif /* ifdef ADC_DMA_SUPPORTED */
}
#endif /* ADC_DEINIT_API == STD_ON */

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
/**
* @brief          This function stops the current conversion.
* @details        This function stops the current conversion and checks if the hardware has responded to the command.
*
* @param[in]      Unit      The hardware Unit.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            If the conversion has stopped as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc hardware to stop a conversion.
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_StopConversionCheckTimeout
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(uint8, AUTOMATIC) u8SCRegister;

    /* Stop PDB hardware trigger unit */
    Adc_Pdb_StopConversion(Unit);

    /* Check if ADC is in continuous mode */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(((uint8)STD_ON == Adc_pCfgPtr->pGroups[Group].u8AdcWithoutInterrupt) && (ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode))
    {
        /* Set to Oneshot mode */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_CONTINUOUS_U32);
    }

    /* Check all of SC1 register disabled */
    for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /* Stop conversion in SC1n register */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);

        /* Wait until conversion is aborted */
        /* Because some channels in chain are not converted yet */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        while((REG_READ32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister)) & ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32) != ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32)
        {
            if(u32Timeout > 0UL)
            {
                u32Timeout--;
            }
            else
            {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
                {
                    /* Report production error and return from function. */
                    Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_4 Return statement before end of function. */
                return (Std_ReturnType) E_NOT_OK;
            }
        }
    }
    return (Std_ReturnType) E_OK;
}
#endif /* ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)) */

#ifdef ADC_DMA_SUPPORTED
/**
* @brief          This function programs the DMA transfers involved in the ADC conversion process.
* @details        This function should be called with the ADC Unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      Unit            ADC hardware unit
* @param[in]      Group           Group to be converted
* @param[in]      pGroupPtr       Pointer of group configuration
* @param[in]      u8NumChannel    Number of channels in group
*
* @return         void
*
* @pre ADC Unit is not running anything.
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StartDmaOperation
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(uint8, AUTOMATIC) u8NumChannel
)
{
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, ADC_APPL_CONST) pDmaConfig = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32SourceOffset;
    VAR(uint32, AUTOMATIC) u32DestAddr;
    VAR(uint32, AUTOMATIC) u32Iter;
    VAR(uint16, AUTOMATIC) u16DestNextOffset;
    VAR(uint8, AUTOMATIC) u8DmaTcdFlags;
#if ((STD_ON == ADC_OPTIMIZE_ONESHOT_HW_TRIGGER) || (ADC_ENABLE_DOUBLE_BUFFERING == STD_ON))
    VAR(sint32, AUTOMATIC) s32DmaTcdDlast = (sint32) 0;
    VAR(sint32, AUTOMATIC) s32DmaTcdSlast = (sint32) 0;
#endif /* ((STD_ON == ADC_OPTIMIZE_ONESHOT_HW_TRIGGER) || (ADC_ENABLE_DOUBLE_BUFFERING == STD_ON)) */
#ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
#if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
    VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) DmaTcdConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) TcdAddress;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaLinkChannel = 255U; /* Invalid DMA channel*/
#endif
#endif
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;

    if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
    {
        DmaChannel = (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit];
        /* Disable DMA interrupt */
        Mcl_DmaDisableHwRequest(DmaChannel);
#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        Mcl_DmaDisableNotification(DmaChannel);
#endif
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        pResult = pGroupPtr->pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex;
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        if ((boolean) TRUE == pGroupPtr->bAdcDoubleBuffering)
        {
        #ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
        #if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
            if (u8NumChannel > 1U)
            {
                u32SourceOffset = (uint32) DMA_OFFSET_32_BITS;
                /** Compiler_Warning: It is intended for the address of the element to be stored in another non pointer element. */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32DestAddr = (uint32)(pResult);
                u32Iter = u8NumChannel;
                u16DestNextOffset = (uint16)((pGroupPtr->NumSamples) << (uint16)1); /* use a << 1 instead of a*2*/
                u8DmaTcdFlags = 0U;
                /** @violates @ref Adc_Adc12bsarv2_c_REF_6 cast from unsigned int to signed int */
                s32DmaTcdSlast = -(sint32)((uint32)u8NumChannel << 2U); /* use a<<2 instead of a*4*/
                /** @violates @ref Adc_Adc12bsarv2_c_REF_6 cast from unsigned int to signed int */
                s32DmaTcdDlast = -(sint32)((((uint32)pGroupPtr->NumSamples*(uint32)u8NumChannel)-1U)<<1); /* use a << 1 instead of a*2*/
                /* Caculate TCD config for DMA channel linking */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                DmaTcdConfig.u32saddr = (uint32) &Adc_Adc12bsarv2_aDraftBufferDMA[0];
                DmaTcdConfig.u32ssize = (uint32) DMA_SIZE_2BYTES;
                DmaTcdConfig.u32dsize = (uint32) DMA_SIZE_2BYTES;
                DmaTcdConfig.u32soff = (uint32) 0;
                DmaTcdConfig.u32num_bytes = 2UL;
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                DmaTcdConfig.u32daddr = (uint32) &Adc_Adc12bsarv2_aDraftBufferDMA[1];
                DmaTcdConfig.u32iter = (uint32) (uint32) pGroupPtr->NumSamples;
                DmaTcdConfig.u32doff = (uint32) 0;
                DmaTcdConfig.u32smod = (uint32) 0;
                DmaTcdConfig.u32dmod = (uint32) 0;
                
                DmaLinkChannel=(Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaDoubleBuffer[Unit];
                TcdAddress = Mcl_DmaGetChannelTcdAddress(DmaLinkChannel);
                /** @violates @ref Adc_Adc12bsarv2_c_REF_16 It is needed for calculation value of go back space for source address.*/
                Mcl_DmaConfigTcd(TcdAddress, &DmaTcdConfig);
                if ((boolean) TRUE == pGroupPtr->bHalfInterrupt)
                {
                    Mcl_DmaTcdSetFlags(TcdAddress, DMA_TCD_INT_MAJOR_U8 | DMA_TCD_INT_HALF_U8);
                }
                else
                {
                    Mcl_DmaTcdSetFlags(TcdAddress, DMA_TCD_INT_MAJOR_U8 );
                }
                
            }
            else
        #endif
        #endif
            {
                u32SourceOffset = (uint32) 0;
                /** Compiler_Warning: It is intended for the address of the element to be stored in another non pointer element. */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32DestAddr = (uint32)(pResult);
                u32Iter = (uint32) pGroupPtr->NumSamples;
                u16DestNextOffset = 2U;
                if ((boolean) TRUE == pGroupPtr->bHalfInterrupt)
                {
                    u8DmaTcdFlags = DMA_TCD_INT_MAJOR_U8 | DMA_TCD_INT_HALF_U8;
                }
                else
                {
                    u8DmaTcdFlags = DMA_TCD_INT_MAJOR_U8 ;
                }
                
                s32DmaTcdSlast = (sint32) 0;
                /** @violates @ref Adc_Adc12bsarv2_c_REF_6 cast from unsigned int to signed int */
                s32DmaTcdDlast = -(sint32)((uint32)((uint32)pGroupPtr->NumSamples << 1U)); /* use a << 1 instead of a*2*/
            }
        }
        else
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
        {
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            if ((boolean)TRUE == pGroupPtr->bAdcGroupLimitcheck)
            {
                u32SourceOffset = (uint32) 0;
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32DestAddr = (uint32)(&(Adc_Adc12bsarv2_aDmaInternalResultBuffer[Unit]));
                u32Iter = (uint32) 1;
                u16DestNextOffset = 0U;
            }
            else
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
            {
                u32SourceOffset = (uint32) DMA_OFFSET_32_BITS;
                /** Compiler_Warning: It is intended for the address of the element to be stored in another non pointer element. */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32DestAddr = (uint32)(pResult);
                u32Iter = (uint32) u8NumChannel;
                u16DestNextOffset = (uint16)((pGroupPtr->NumSamples) << (uint16)1);
            }
            u8DmaTcdFlags = DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_INT_MAJOR_U8;
        }
        /* Update the Tcd configuration */
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32saddr = (uint32) ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)0);
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32ssize = (uint32) DMA_SIZE_2BYTES;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32dsize = (uint32) DMA_SIZE_2BYTES;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32soff = (uint32) u32SourceOffset;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32num_bytes = 2UL;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32daddr = (uint32) u32DestAddr;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32iter = (uint32) u32Iter;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32doff = (uint32) u16DestNextOffset;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32smod = (uint32) 0;
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32dmod = (uint32) 0;
        pDmaConfig = &(Adc_Adc12bsarv2_aDmaTcdConfig[Unit]);

        Adc_Adc12bsarv2_aTcdAddress[Unit] = Mcl_DmaGetChannelTcdAddress(DmaChannel);
    #ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
    #if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
        if (((boolean) TRUE == pGroupPtr->bAdcDoubleBuffering)&&(u8NumChannel > 1U))
        {
            Mcl_DmaConfigLinkedChannel(DmaChannel,pDmaConfig,DmaLinkChannel);
        }
        else
    #endif
    #endif
        {
            Mcl_DmaConfigTcd(Adc_Adc12bsarv2_aTcdAddress[Unit], pDmaConfig);
            Mcl_DmaTcdSetFlags(Adc_Adc12bsarv2_aTcdAddress[Unit], u8DmaTcdFlags);
        }

#if (STD_ON == ADC_OPTIMIZE_ONESHOT_HW_TRIGGER)
        /** @violates @ref Adc_Adc12bsarv2_c_REF_6 cast from unsigned int to signed int */
        s32DmaTcdSlast = -(sint32)((uint32)u8NumChannel << 2U);
        /** @violates @ref Adc_Adc12bsarv2_c_REF_6 cast from unsigned int to signed int */
        s32DmaTcdDlast = -(sint32)((uint32)u8NumChannel << 1U);
#endif /* (STD_ON == ADC_OPTIMIZE_ONESHOT_HW_TRIGGER) */

#if ((STD_ON == ADC_OPTIMIZE_ONESHOT_HW_TRIGGER) || (ADC_ENABLE_DOUBLE_BUFFERING == STD_ON))
        Mcl_DmaTcdSetSlast(Adc_Adc12bsarv2_aTcdAddress[Unit], s32DmaTcdSlast);
        Mcl_DmaTcdSetDlast(Adc_Adc12bsarv2_aTcdAddress[Unit], s32DmaTcdDlast);
#endif /* ((STD_ON == ADC_OPTIMIZE_ONESHOT_HW_TRIGGER) || (ADC_ENABLE_DOUBLE_BUFFERING == STD_ON)) */

        /* Start the DMA channel0 */
        Mcl_DmaEnableHwRequest(DmaChannel);
    }
}
#endif /* ADC_DMA_SUPPORTED */

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          This function initializes the ADC hardware module, and the ADC driver.
* @details        This function initializes the ADC hardware module, and the ADC driver.
*
* @param[in]      pCfgPtr      Configuration data pointer.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    /* Hardware Unit index */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = (Adc_HwUnitType)0;

    /* ADC hardware unit config pointer */
    P2CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr = pCfgPtr->pAdc;

    /* Initialize Unit Status structures */
    /* Initialize for each ADC hardware unit (eg: ADC0, ADC1...) */
    for(Unit = (Adc_HwUnitType)0; Unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; Unit++)
    {
        /* Check if unit is available */
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            Adc_Adc12bsarv2_InitUnitHardware(Unit, pConfigPtr);
        }
    }
}

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function deinitializes the ADC driver, and the ADC hardware.
* @details        This function deinitializes the ADC driver, and ensures that the ADC hardware
*                 will be in the power on after reset state.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DeInit(void)
{
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(Adc_GroupType,AUTOMATIC) GroupIdx = 0U;
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U; /* Hardware Unit index */

    /* Enter critical region to avoid ISRs during register reset */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();

    /* De-initialize each ADC hardware unit */
    for(;Unit<(Adc_HwUnitType)ADC_MAX_HW_UNITS;Unit++)
    {
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            Adc_Adc12bsarv2_DeInitHardware(Unit);
        }
    }

    /* De-initialize PDB hardware trigger unit */
    Adc_Pdb_DeInit();

    /* Disable notification of all available groups */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    for(GroupIdx=(Adc_GroupType)0U;GroupIdx<(Adc_GroupType)ADC_MAX_GROUPS;GroupIdx++)
    {
        Adc_aGroupStatus[GroupIdx].eNotification = ADC_NOTIFICATION_DISABLED;
    }
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
}
#endif /* #if (ADC_DEINIT_API == STD_ON) */

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
/**
* @brief          This function stops the current conversion of a group.
* @details        This function stops the current conversion of a group.
*
* @param[in]      Unit      The hardware Unit.
* @param[in]      Group     The group id.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            If the conversion has stopped as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc hardware to stop a conversion.
*
*/
/** @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_StopCurrentConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* Variable for checking timeout status */
    VAR(Std_ReturnType, AUTOMATIC) Test = (Std_ReturnType)E_OK;

    /* Counter for SC registers */
    VAR(uint8, AUTOMATIC) u8SCRegister;

    /* Disable Adc hardware unit and clear all of COCO flag by reading Rn register */
    for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)u8SCRegister));
    }

    /* Disable DMA requests and notifications */
#ifdef ADC_DMA_SUPPORTED
    if((uint8)ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
    #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
    #endif
    }
#endif /* ADC_DMA_SUPPORTED */

    /* Reset current channel status to 0 */
    Adc_aGroupStatus[Group].CurrentChannel = 0U;

    /* Stop the conversion and abort the current group conversion */
#if (ADC_BYPASS_CONSISTENCY_LOOP == STD_ON)
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if((uint8)STD_OFF == Adc_pCfgPtr->pGroups[Group].u8AdcWithoutInterrupt)
    {
        Test = Adc_Adc12bsarv2_StopConversionCheckTimeout(Unit, Group);
    }
    else
    {
        /* If group is continuous and configured without interrupts, clear the CONTINUOUS bit */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode)
        {
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
            Adc_Pdb_StopConversion(Unit);
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
        }
    }
#else /* (ADC_BYPASS_CONSISTENCY_LOOP == STD_ON) */
    Test = Adc_Adc12bsarv2_StopConversionCheckTimeout(Unit, Group);
#endif /* (ADC_BYPASS_CONSISTENCY_LOOP == STD_OFF) */

    return Test;
}
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function performs starting a hardware trigger conversion.
* @details        This function performs starting a hardware trigger conversion.
*
* @param[in]      Unit        The hardware Unit.
* @param[in]      Group       The group of which conversion will be started.
*
* @return         void
* @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StartHwTrigConversion
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(uint8, AUTOMATIC) u8NumChannel;
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);

    /* Calculate the number of channels for current configuration */
#if (ADC_SETCHANNEL_API == STD_ON)
    u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(Adc_aRuntimeGroupChannel[Group].ChannelCount);
#else
    u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(pGroupPtr->AssignedChannelCount);
#endif

    /* If it is the first group, u8Sc1Used is assigned as the number channels of group */
    if(0U == Adc_aUnitStatus[Unit].u8Sc1Used)
    {
        Adc_aUnitStatus[Unit].u8Sc1Used = u8NumChannel;
    }
    Adc_aGroupStatus[Group].CurrentChannel = 0U;

#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            /* Enable DMA interrupt incase of Group configured with interrupt */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_SET32(ADC12BSARV2_SC2_REG_ADDR32(Unit), ADC12BSARV2_SC2_DMA_EN_U32);

            /* Setting for DMA transfer */
            Adc_Adc12bsarv2_StartDmaOperation(Unit, Group, pGroupPtr, u8NumChannel);
        }

        /* Ensure that PDB does not run when ADC configured */
        Adc_Pdb_StopConversion(Unit);

        /* Setting for ADC in case of DMA transfer was selected, in the first time DMA should not be re-configured */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_Adc12bsarv2_ConfigureDmaPartialConversion(Unit, Group, pGroupPtr, (Adc_HwTriggerTimerType)pGroupPtr->pHwResource[0], u8NumChannel, (boolean)FALSE);
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
        /* Setting for ADC hardware in case of DMA transfer was not selected */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, pGroupPtr, pGroupPtr->pHwResource[0], u8NumChannel);
    }
}
#endif

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function reads the converted data for the requested group.
* @details        Reads the converted data for the requested group.
*
* @param[in]      Group           The group number.
* @param[in]      pDataPtr        Pointer to a buffer which will be filled by the
*                                 conversion results.
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successfull read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_ReadGroup
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataPtr,
    P2VAR(boolean, AUTOMATIC, ADC_APPL_DATA) pFlag
)
{
    VAR(Std_ReturnType, AUTOMATIC) ReadGroupRet = (Std_ReturnType)E_OK;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Index;
    /* Pointer to AdcGroup */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = NULL_PTR;

    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = pGroupPtr->AssignedChannelCount;
#endif

    /* If the group is configured for without interrupts*/
    if((uint8)STD_ON == pGroupPtr->u8AdcWithoutInterrupt)
    {
        VAR(uint32, AUTOMATIC) u32HsValue;
        VAR(uint16, AUTOMATIC) u16R0Value;
        VAR(Adc_HwUnitType, AUTOMATIC) Unit;
        VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
        VAR(uint32, AUTOMATIC) u32AdcDataMask;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
        /* Flag to set if ADC results are in the selected range */
        VAR(boolean, AUTOMATIC) bWriteFlag = (boolean)TRUE;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = Adc_pCfgPtr->pGroups[Group].HwUnit;

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();

        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32HsValue = REG_READ32(ADC12BSARV2_SC1_REG_ADDR32(Unit, ((uint32)ChannelCount - 1UL)));
        if(0UL == (u32HsValue & ADC12BSARV2_SC1n_CONV_COMPLETE_U32))
        {
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
            /** @violates @ref Adc_Adc12bsarv2_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType)E_NOT_OK;
        }

        /* Get the logical id from hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        u32AdcDataMask = Adc_pCfgPtr->pAdc[HwIndex].u32AdcDataMask;
#if (ADC_ENABLE_LIMIT_CHECK == STD_OFF)
        (*pFlag) = (boolean)TRUE;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) */

        for(Index = 0U; Index < ChannelCount; Index++)
        {
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u16R0Value = (uint16)(REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)Index)));

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            /* there is only one channel in the group - the first channel */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            ChIndex = pGroupPtr->pAssignment[0];
            if ((boolean)TRUE == pGroupPtr->bAdcGroupLimitcheck)
            {
                (*pFlag) = (boolean)Adc_CheckConversionValuesInRange(u16R0Value, Unit, ChIndex);
                if ((boolean)FALSE == (*pFlag))
                {
                    /* ADC448, ADC449, ADC450 */
                    ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                    bWriteFlag = (boolean)FALSE;
                }
            }
            if((boolean)TRUE == bWriteFlag)
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
            {
                /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                pDataPtr[Index] = (uint16)(u16R0Value & u32AdcDataMask);
            }
        }
    }
    /* If the group is configured for with interrupts*/
    else
    {
        P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResultPtr = NULL_PTR;
        VAR(uint32, AUTOMATIC) u32DestOffset = 0UL;
        VAR(Adc_StreamNumSampleType, AUTOMATIC) ResultIndex = (Adc_StreamNumSampleType)0;

        /* Enter critical region */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();
        if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
        {
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
            /** @violates @ref Adc_Adc12bsarv2_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType)E_NOT_OK;
        }

        /* Get index of last completed sample */
        ResultIndex = Adc_aGroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1;
        if ((Adc_StreamNumSampleType)0 == Adc_aGroupStatus[Group].ResultIndex)
        {
            ResultIndex = pGroupPtr->NumSamples - (Adc_StreamNumSampleType)1;
        }

        /**
        * @violates @ref Adc_Adc12bsarv2_c_REF_5 Cast from pointer to pointer.
        * @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        */
        pResultPtr = (Adc_ValueGroupType *)(pGroupPtr->pResultsBufferPtr[Group]+ResultIndex);
        u32DestOffset = pGroupPtr->NumSamples;

        /* Copy results of last conversion from streaming buffer to internal buffer */
        for(Index = 0U; Index < ChannelCount; Index++)
        {
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pDataPtr[Index] = (*pResultPtr);
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pResultPtr += u32DestOffset;
        }
    }

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
    return(ReadGroupRet);
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function enables the hardware triggers for the specified group.
* @details        This function enables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint8, AUTOMATIC) u8SCRegister;
#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */

    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#endif
    /* Enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10();

    Adc_aGroupStatus[Group].ResultIndex = 0U;

    /* Clear all of COCO flag by reading Rn registers */
    for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)u8SCRegister));
    }

#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
    /* If conversion time once disabled, either normal or alternate clock mode can be configured at runtime */
    #if (ADC_DUAL_CLOCK_MODE == STD_ON)
    if(ADC_ALTERNATE == Adc_eClockMode)
    {
        /* Set clock division for alternate clock mode */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32, (pGroupPtr->u32ClockDivideSelectAlternate & ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32));

        /* Setting for alternate conversion timing in CFG2 and SC3 register */
        /* Set alternate sample time */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), (pGroupPtr->u32SampleTimeAlternate & ADC12BSARV2_CFG2_SAMPLE_TIME_MASK_U32));

        /* Enable hardware average and set average samples */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_AVG_MASK_U32, (pGroupPtr->u32AvgSelectAlternate & ADC12BSARV2_SC3_AVG_MASK_U32));
    }
    else
    #endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    {
        /* Set clock division for normal clock mode */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32, (pGroupPtr->u32ClockDivideSelect & ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32));

        /* Setting for conversion timing in CFG2 and SC3 register */
        /* Set normal sample time */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), (pGroupPtr->u32SampleTime & ADC12BSARV2_CFG2_SAMPLE_TIME_MASK_U32));

        /* Enable hardware average and set average samples */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_AVG_MASK_U32, (pGroupPtr->u32AvgSelect & ADC12BSARV2_SC3_AVG_MASK_U32));
    }
#endif /*end (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)*/

    Adc_Adc12bsarv2_StartHwTrigConversion(Unit, Group);

    /* Exit critical section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
}

/**
* @brief          This function disables the hardware triggers for the specified group.
* @details        This function disables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint8, AUTOMATIC) u8SCRegister;

    /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11();

    (void)Group;
#ifdef ADC_DMA_SUPPORTED
    /* Disable DMA */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
        {
            /* Disable DMA interrupt */
            Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
        #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
            Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
        #endif
        }
    }
#endif /* ADC_DMA_SUPPORTED */

    Adc_Pdb_StopConversion(Unit);

    /* Disable Adc hardware unit */
    for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
    }

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/**
* @brief          This function starts the conversion on the specified hardware Unit.
* @details        This function starts the conversion on the specified hardware Unit.
*                 This function should be called with the ADC Unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      Unit            the used hw Unit.
*
* @return         void
*
* @violates @ref Adc_Adc12bsarv2_c_REF_10 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StartNormalConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */
    VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0; /* Active group in the Queue */
    VAR(uint8, AUTOMATIC) u8SCRegister;
    VAR(uint8, AUTOMATIC) u8NumChannel;

    /* If software normal queue is empty (i.e no conversion requests) then return without any action */
    if ((Adc_QueueIndexType)0 == Adc_aUnitStatus[Unit].SwNormalQueueIndex)
    {
        /** @violates @ref Adc_Adc12bsarv2_c_REF_4 Return statement before end of function. */
        return;
    }

    /* Load the first group in the queue */
    Group = Adc_aUnitStatus[Unit].SwNormalQueue[0];

    /* Load the group configuration */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Group configured as one-shot mode and limit checking failed then return without any action */
    if(((boolean)TRUE == Adc_aGroupStatus[Group].bLimitCheckFailed) && (ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode))
    {
        /** @violates @ref Adc_Adc12bsarv2_c_REF_4 Return statement before end of function. */
        return;
    }
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
    /* Check the clock mode (and config if needed) every start conversion if conversion time once is disabled */
    #if (ADC_DUAL_CLOCK_MODE == STD_ON)
    if(ADC_ALTERNATE == Adc_eClockMode)
    {
        /* Clock divide select for alternate mode */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32, (pGroupPtr->u32ClockDivideSelectAlternate & ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32));

        /* Setting for alternate conversion timing in CFG2 and SC3 register */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), (pGroupPtr->u32SampleTimeAlternate & ADC12BSARV2_CFG2_SAMPLE_TIME_MASK_U32));

        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_AVG_MASK_U32, (pGroupPtr->u32AvgSelectAlternate & ADC12BSARV2_SC3_AVG_MASK_U32));
    }
    else
    #endif /* (ADC_DUAL_CLOCK_MODE == STD_ON)*/
    {
        /* Clock divide select for normal mode */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32, (pGroupPtr->u32ClockDivideSelect & ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32));

        /* Setting for conversion timing in CFG2 and SC3 register */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), (pGroupPtr->u32SampleTime & ADC12BSARV2_CFG2_SAMPLE_TIME_MASK_U32));

        /* Select average samples */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_AVG_MASK_U32, (pGroupPtr->u32AvgSelect & ADC12BSARV2_SC3_AVG_MASK_U32));
    }
#endif /*end (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)*/

    /* Reset to start conversion from channel logical index 0 */
    Adc_aGroupStatus[Group].CurrentChannel = 0U;

    /* Calculate the number of channels for current configuration */
#if (ADC_SETCHANNEL_API == STD_ON)
    /* Channel enabled at runtime */
    u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(Adc_aRuntimeGroupChannel[Group].ChannelCount);
#else
    /* Channel enabled from initialzing */
    u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(pGroupPtr->AssignedChannelCount);
#endif

    /* Update u8Sc1Used for the first time */
    if(0U == Adc_aUnitStatus[Unit].u8Sc1Used)
    {
        Adc_aUnitStatus[Unit].u8Sc1Used = u8NumChannel;
    }

#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
    /* If the continuous group is configured without interrupts then PDB will be configured as continuous mode */
    if((ADC_CONV_MODE_CONTINUOUS == pGroupPtr->eMode) && ((uint8)STD_ON == pGroupPtr->u8AdcWithoutInterrupt))
    {
        /* PDB operation in Continuous mode */
        Adc_Pdb_SetPdbMode(Unit, (boolean)TRUE);
    }
    else
    {
        /* PDB operation in One-Shot mode */
        Adc_Pdb_SetPdbMode(Unit, (boolean)FALSE);
    }
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */

#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        /* If the group is configured for with interrupts*/
        if ((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            /* Enable DMA interrupt in case of Group configured with interrupt */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_SET32(ADC12BSARV2_SC2_REG_ADDR32(Unit), ADC12BSARV2_SC2_DMA_EN_U32);

            /* Setting for DMA transfer */
            Adc_Adc12bsarv2_StartDmaOperation(Unit, Group, pGroupPtr, u8NumChannel);
        }

        /* Ensure that PDB does not run when ADC configured */
        Adc_Pdb_StopConversion(Unit);

        /* Setting for Adc in case of DMA transfer was selected, in the first time DMA should not be re-configured */
        Adc_Adc12bsarv2_ConfigureDmaPartialConversion(Unit, Group, pGroupPtr, PDB_SOFTWARE_TRIGGER_U32, u8NumChannel, (boolean)FALSE);
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
        /* Clear all of COCO flag by reading Rn registers */
        for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
        {
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)u8SCRegister));
        }

        /* Enable hardware trigger */
        /* Both software and hardware trigger will be implemented through PDB */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADC12BSARV2_SC2_REG_ADDR32(Unit), ADC12BSARV2_SC2_ADTRG_HW_U32);

        /* Update group configuration to registers and start conversion */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, pGroupPtr, PDB_SOFTWARE_TRIGGER_U32, u8NumChannel);
    }
}

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          This function sets the clock prescaler and conversion timing registers.
* @details        This function sets the clock prescaler and conversion timing registers.
*
* @param[in]      eClockMode       ADC_NORMAL, ADC_ALTERNATE.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful set mode.
* @retval         E_NOT_OK        In case of unsuccessful set mode.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_SetClockMode
(
    VAR(Adc_DualClockModeType, AUTOMATIC) eClockMode
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U; /* Hardware Unit index */
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U; /* Index of hardware Unit */
    P2CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pUnitConfigPtr; /* Pointer to Hw Unit config */

    for (Unit = 0U; Unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; Unit++)
    {
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            /* Get the logical id of hardware Unit*/
            HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];

            /* Pointer for configure clock mode */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pUnitConfigPtr = &(Adc_pCfgPtr->pAdc[HwIndex]);

            if ((Adc_DualClockModeType)ADC_NORMAL == eClockMode)
            {
                /* Normal clock mode */
                /* Configure clock divide select and input clock select */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_RMW32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_SET_CLOCKMODE_MASK_U32, (pUnitConfigPtr->u32AdcCfg1Register & ADC12BSARV2_CFG1_SET_CLOCKMODE_MASK_U32));

                /* Sampling time and hardware average configuration */
                #if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), pUnitConfigPtr->u32AdcSc3Register);
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), pUnitConfigPtr->u32AdcCfg2Register);
                #endif
            }
            else  /* ADC_ALTERNATE == eClockMode */
            {
                /* Alternate clock mode */
                /* Configure clock divide select and input clock select */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_RMW32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_SET_CLOCKMODE_MASK_U32, (pUnitConfigPtr->u32AdcCfg1RegisterAlternate & ADC12BSARV2_CFG1_SET_CLOCKMODE_MASK_U32));

                /* Configure clock divide select and input clock select */
                #if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), pUnitConfigPtr->u32AdcSc3RegisterAlternate);
                /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADC12BSARV2_CFG2_REG_ADDR32(Unit), pUnitConfigPtr->u32AdcCfg2RegisterAlternate);
                #endif
            }
        }
    }

    return (Std_ReturnType)E_OK;
}
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief          Executes high accuracy calibration of a ADC HW Unit.
* @details        This function calibrates the ADC HW Unit and updates calibration related registers
*
* @param[in]      Unit      ADC Unit Id.
* @param[in]      Status    Status of the ADC HW Unit calibration and
*                           list of failed/passed tests.
*
* @return         void
*  @violates @ref Adc_Adc12bsarv2_c_REF_14 Pointer parameter.
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_Calibrate
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2VAR(Adc_CalibrationStatusType , AUTOMATIC, ADC_APPL_DATA) pStatus
)
{
    VAR(uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) u32Sc3Status;
    VAR(uint32, AUTOMATIC) u32Cfg1Status;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
    /* Back up SC3 status */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32Sc3Status = REG_READ32(ADC12BSARV2_SC3_REG_ADDR32(Unit));
    /* Back up CFG1 status */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32Cfg1Status = REG_READ32(ADC12BSARV2_CFG1_REG_ADDR32(Unit));
    /* Clear ADTRG bit to ensure that calibrate success */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADC12BSARV2_SC2_REG_ADDR32(Unit), ADC12BSARV2_SC2_ADTRG_HW_U32);

    /* Set the clock to half the maximum specified frequency */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), ADC12BSARV2_CFG1_CLOCK_DIV2_U32);

    /* Write zero to these register: CLPS, CLP3, CLP2, CLP1, CLP0, CLPX, and CLP9 */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLPS_REG_ADDR32(Unit), (uint32)0x0);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLP3_REG_ADDR32(Unit), (uint32)0x0);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLP2_REG_ADDR32(Unit), (uint32)0x0);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLP1_REG_ADDR32(Unit), (uint32)0x0);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLP0_REG_ADDR32(Unit), (uint32)0x0);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLPX_REG_ADDR32(Unit), (uint32)0x0);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CLP9_REG_ADDR32(Unit), (uint32)0x0);

    /* Set hardware averaging to maximum */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_AVGE_EN_U32 | ADC12BSARV2_SC3_AVGS_32_SAMPLES_U32);

    /* Start calibration */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_CAL_EN_U32);
    pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType) E_OK;

    /* Waiting for calibrate success */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    while(ADC12BSARV2_SC1n_CONV_COMPLETE_U32 != (REG_READ32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)0)) & ADC12BSARV2_SC1n_CONV_COMPLETE_U32))
    {
        if(u32Timeout > 0UL)
        {
            u32Timeout--;
        }
        else
        {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType) E_NOT_OK;
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADC12BSARV2_SC3_REG_ADDR32(Unit), ADC12BSARV2_SC3_CAL_EN_U32);
            break;
        }
    }

    /* Clear the COCO flag */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)0));
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADC12BSARV2_SC2_REG_ADDR32(Unit), ADC12BSARV2_SC2_ADTRG_HW_U32);
    /* Reconfigure for SC3 and CFG1 register */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_SC3_REG_ADDR32(Unit), u32Sc3Status);
    /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADC12BSARV2_CFG1_REG_ADDR32(Unit), u32Cfg1Status);

    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
}
#endif /* ADC_CALIBRATION == STD_ON */

/**
* @brief          Configure channels of a group
* @details        This function configure channels of a group
*                   if number of channels in group excess maximum channels allowed for a conversion,
*                   a part of channels of group (= max allowed channels) will be configured in start conversion in the first time.
*                   the remaining channels of group will be seperated into other parts which are configured and converted in group interrupt.
*
* @param[in]      Unit          ADC Unit Id.
* @param[in]      Group         The group number.
* @param[in]      pGroupPtr     Group config pointer.
* @param[in]      Trigger       PDB trigger.
* @param[in]      u8NumChannel  Number of channels to be configured
*
* @return         void
*  @violates @ref Adc_Adc12bsarv2_c_REF_14 Pointer parameter.
*/

/** @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_ConfigurePartialConversion
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger,
    CONST(uint8, AUTOMATIC) u8NumChannel
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) CurrentChannel;
    VAR(Adc_ChannelType, AUTOMATIC) Channel;
    VAR(Adc_ChannelType, AUTOMATIC) HwChannel;
    VAR(uint8, AUTOMATIC) u8SCRegister;
    VAR(uint32, AUTOMATIC) u32RegValue;
    P2CONST(Adc_GroupDefType, ADC_VAR, ADC_APPL_CONST) pChannel = NULL_PTR;

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get status of channels are changed at runtime */
    VAR(uint32, AUTOMATIC) u32TempMask = Adc_aRuntimeGroupChannel[Group].u32Mask;
#endif

    /* Next channel will be converted */
    CurrentChannel = Adc_aGroupStatus[Group].CurrentChannel;

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get configured channels */
    /* At runtime */
    pChannel = Adc_aRuntimeGroupChannel[Group].pChannel;
#else
    /* Pre-configuration */
    pChannel = pGroupPtr->pAssignment;
#endif

    /* Configure channels from current to (last channel - 1) */
    for(u8SCRegister = 0U; u8SCRegister < (u8NumChannel - 1U); u8SCRegister++)
    {
        /* Logical channel ID */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Channel = pChannel[(CurrentChannel + u8SCRegister)];

#if (ADC_SETCHANNEL_API == STD_ON)
        /* Channel was changed? */
        if (1U == (u32TempMask & 1U))
#endif
        {
            /* Hardware channel ID */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            HwChannel = Adc_pCfgPtr->pChannels[Unit][Channel].ChId;

            /* Disable interrupt all channels not the last channel */
            u32RegValue = ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | (HwChannel & ADC12BSARV2_ADCH_MASK_U32);
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), u32RegValue);
        }
#if (ADC_SETCHANNEL_API == STD_ON)
        u32TempMask = u32TempMask >> 1U;
        /* There are no channels changed then break out the loop */
        if (0U == u32TempMask)
        {
            break;
        }
#endif
    }

    /* Configure last channel */
#if (ADC_SETCHANNEL_API == STD_ON)
    /* Last channel was changed? */
    if (1U == (u32TempMask & 1U))
#endif
    {
        /* Get channel ID */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Channel = pChannel[(CurrentChannel + u8SCRegister)];
        /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        HwChannel = Adc_pCfgPtr->pChannels[Unit][Channel].ChId;

        /* In case of group is configured with interrupt, the complete int bit of the last channel must be enabled */
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            u32RegValue = ADC12BSARV2_CONV_COMPLETE_INT_EN_U32 | (HwChannel & ADC12BSARV2_ADCH_MASK_U32);
        }
        else
        {
            u32RegValue = ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | (HwChannel & ADC12BSARV2_ADCH_MASK_U32);
        }

        /* Update register */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), u32RegValue);
    }

#if ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) || (ADC_SETCHANNEL_API == STD_ON))
    /* Disable others SC1 register */
    for(u8SCRegister = u8NumChannel; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
    }
    /* If optimize one-shot hardware trigger is enabled, there is just ONE channel in group so not need to disable remaining SC1 registers */
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) || (ADC_SETCHANNEL_API == STD_ON) */

     /* Save the Sc1Used register equal the number of channels configured */
     Adc_aUnitStatus[Unit].u8Sc1Used = u8NumChannel;

     /* Start software trigger through PDB or enable PDB hardware trigger */
     /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
     Adc_Pdb_ConfigurePartialConversion(Unit, Group, pGroupPtr, Trigger, CurrentChannel, u8NumChannel);

     /* Update current channel */
     Adc_aGroupStatus[Group].CurrentChannel += u8NumChannel;
}

#ifdef ADC_DMA_SUPPORTED

/** @violates @ref Adc_Adc12bsarv2_c_REF_10 internal linkage or external linkage */
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_ConfigureDmaPartialConversion
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger,
    CONST(uint8, AUTOMATIC) u8NumChannel,
    CONST(boolean, AUTOMATIC) bFromIsr
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) CurrentChannel;
    VAR(Adc_ChannelType, AUTOMATIC) Channel;
    VAR(Adc_ChannelType, AUTOMATIC) HwChannel;
    VAR(uint8, AUTOMATIC) u8SCRegister;
    VAR(uint32, AUTOMATIC) u32RegValue;
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)  */
    P2CONST(Adc_GroupDefType, ADC_VAR, ADC_APPL_CONST) pChannel = NULL_PTR;
#if (ADC_SETCHANNEL_API == STD_ON)
    VAR(uint32, AUTOMATIC) u32TempMask = Adc_aRuntimeGroupChannel[Group].u32Mask;
#endif

    CurrentChannel = Adc_aGroupStatus[Group].CurrentChannel;
#if (ADC_SETCHANNEL_API == STD_ON)
    pChannel = Adc_aRuntimeGroupChannel[Group].pChannel;
#else
    pChannel = pGroupPtr->pAssignment;
#endif

    /* Disable interrupt for all used channels */
    /* Interrupt will be generated through MCL module */
    for(u8SCRegister = 0U; u8SCRegister < u8NumChannel; u8SCRegister++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        /* Channel was changed? */
        if (1U == (u32TempMask & 1U))
#endif
        {
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Channel = pChannel[(CurrentChannel + u8SCRegister)];
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            HwChannel = Adc_pCfgPtr->pChannels[Unit][Channel].ChId;

            u32RegValue = ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | (HwChannel & ADC12BSARV2_ADCH_MASK_U32);
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), u32RegValue);
        }
#if (ADC_SETCHANNEL_API == STD_ON)
        u32TempMask = u32TempMask >> 1U;
        /* There are no channels changed then break out the loop */
        if (0U == u32TempMask)
        {
            break;
        }
#endif
    }
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING )
    if ((boolean)FALSE == pGroupPtr->bAdcDoubleBuffering)
#endif
    {
#if ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) || (ADC_SETCHANNEL_API == STD_ON))
        /* Disable others SC1 register */
        for(u8SCRegister = u8NumChannel; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
        {
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
        }
#endif

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
        /* If this is not the first segment of the group, TCD must be reconfigured also */
        if((boolean)TRUE == bFromIsr)
        {
            /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex + (CurrentChannel * pGroupPtr->NumSamples);
            Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32saddr = (uint32) ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)0);
            Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32num_bytes = 2UL;
            /** @violates @ref Adc_Adc12bsarv2_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32daddr = (uint32) pResult;
            Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32iter = (uint32) u8NumChannel;
            Mcl_DmaConfigTcd(Adc_Adc12bsarv2_aTcdAddress[Unit], &(Adc_Adc12bsarv2_aDmaTcdConfig[Unit]));
            Mcl_DmaTcdSetFlags(Adc_Adc12bsarv2_aTcdAddress[Unit], (uint8)(DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_INT_MAJOR_U8));
        }
#endif
    }

    /* Save the Sc1Used register equal the number of channels configured */
    Adc_aUnitStatus[Unit].u8Sc1Used = u8NumChannel;
    /** @violates @ref Adc_Adc12bsarv2_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Adc_Pdb_ConfigurePartialConversion(Unit, Group, pGroupPtr, Trigger, CurrentChannel, u8NumChannel);
    Adc_aGroupStatus[Group].CurrentChannel += u8NumChannel;
    /* Avoid compiler warning */
    (void)bFromIsr;
}
#endif
#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_Adc12bsarv2_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

