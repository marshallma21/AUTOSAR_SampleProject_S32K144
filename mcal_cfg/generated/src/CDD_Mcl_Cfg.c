/**
*   @file    CDD_Mcl_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Data structures for the Mcl driver.
*   @details Precompile structure configuration for the driver initalization.
*
*   @addtogroup MCL
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Cfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_Cfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcl_Cfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcl_Cfg_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope should have internal linkage unless external linkage is required.
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file             CDD_Mcl_Cfg.c
* @requirements     
*/
#define MCL_CFG_VENDOR_ID_C                     43
/** @violates @ref Mcl_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCL_CFG_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Mcl_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCL_CFG_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Mcl_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCL_CFG_AR_RELEASE_REVISION_VERSION_C   2
#define MCL_CFG_SW_MAJOR_VERSION_C              1
#define MCL_CFG_SW_MINOR_VERSION_C              0
#define MCL_CFG_SW_PATCH_VERSION_C              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if config source file and MCL header file are of the same vendor */
#if (MCL_CFG_VENDOR_ID_C != MCL_VENDOR_ID)
#error "CDD_Mcl_Cfg.c and CDD_Mcl.h have different vendor IDs"
#endif
/* Check if config source file and MCL header file are of the same Autosar version */
#if ((MCL_CFG_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_CFG_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) || \
     (MCL_CFG_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl_Cfg.c and CDD_Mcl.h are different"
#endif
/* Check if config source file and MCL header file are of the same Software version */
#if ((MCL_CFG_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION) || \
     (MCL_CFG_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION) || \
     (MCL_CFG_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl_Cfg.c and CDD_Mcl.h are different"
#endif



/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                      LOCAL MACROS
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

#define MCL_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_Cfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_Cfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
    
     
    

#include "Mcl_MemMap.h"



#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)


/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType. */


/** @violates @ref Mcl_Cfg_c_REF_10 MISRA 2004 Required Rule 8.10, all declarations must be static */
CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config =

{

    /** MCL_DMA_E_BUS error code */ 
    {
            (uint32)STD_OFF,
                (uint16)0U
    
    },

    /** MCL_DMA_E_DESCRIPTOR  error code */
    {
            (uint32)STD_OFF,
                (uint16)0U
    
    },
    /** MCL_DMA_E_PRIORITY error code */ 
    {
            (uint32)STD_OFF,
                (uint16)0U
    
    },
    
    /** MCL_DMA_E_UNRECOGNIZED error code */
    {
            (uint32)STD_OFF,
                (uint16)0U
    
    },
    
    /** MCL_DMA_E_INCONSISTENCY error code */
    {
            (uint32)STD_OFF,
                (uint16)0U
    
    }
};


#endif

#define MCL_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_Cfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_Cfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*                            statements and comments before '#include'
*/

#include "Mcl_MemMap.h"

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

/** @} */

