/**
*   @file    LinIf.c
*   @version 1.0.1
*
*   @brief   AUTOSAR LinIf - LinIf module interface.
*   @details LinIf module interface.
*
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
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
* @section LinIf_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section LinIf_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section LinIf_c_REF_3
* Violates MISRA 2004 Advisory Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           LinIf.c
* @requirements   LINIF247, LINIF434, LINIF589, LINIF590, LINIF497, LINIF498, 
*                 LINIF499, LINIF638, LINIF561, LINIF555, LINIF556
*/
#include "Lin.h"
#include "LinIf.h"
#include "Dem.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           LinIf.c
* @requirements   LINIF383
*/
#define LIN_IF_VENDOR_ID_C                      43
#define LIN_IF_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_IF_AR_RELEASE_MINOR_VERSION_C       2
#define LIN_IF_AR_RELEASE_REVISION_VERSION_C    2
#define LIN_IF_SW_MAJOR_VERSION_C               1
#define LIN_IF_SW_MINOR_VERSION_C               0
#define LIN_IF_SW_PATCH_VERSION_C               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and LinIf header file are of the same vendor */
#if (LIN_IF_VENDOR_ID_C != LIN_IF_VENDOR_ID)
    #error "LinIf.c and LinIf.h have different vendor ids"
#endif
/* Check if current file and LinIf header file are of the same Autosar version */
#if ((LIN_IF_AR_RELEASE_MAJOR_VERSION_C    != LIN_IF_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IF_AR_RELEASE_MINOR_VERSION_C    != LIN_IF_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IF_AR_RELEASE_REVISION_VERSION_C != LIN_IF_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of LinIf.c and LinIf.h are different"
#endif
/* Check if current file and LinIf header file are of the same Software version */
#if ((LIN_IF_SW_MAJOR_VERSION_C != LIN_IF_SW_MAJOR_VERSION) || \
     (LIN_IF_SW_MINOR_VERSION_C != LIN_IF_SW_MINOR_VERSION) || \
     (LIN_IF_SW_PATCH_VERSION_C != LIN_IF_SW_PATCH_VERSION))
#error "Software Version Numbers of LinIf.c and LinIf.h are different"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_IF_AR_RELEASE_MAJOR_VERSION_C != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IF_AR_RELEASE_MINOR_VERSION_C != LIN_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of LinIf.c and Lin.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if current file and Dem header file are of the same version */
  #if ((LIN_IF_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_IF_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of LinIf.c and Dem.h are different"
  #endif
#endif

#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Det header file are of the same Autosar version */
    #if ((LIN_IF_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_IF_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LinIf.c and Det.h are different"
    #endif
  #endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/* End of File */

/** @}*/
