  
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_flash_const_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
* 
* @section fls_flash_const_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_Flash_Types.h"
#include "Reg_eSys_FLASHC.h"
  
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_FLASH_CONST_VENDOR_ID_C                           43
#define FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C            4
#define FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C            2
#define FLS_FLASH_CONST_AR_RELEASE_REVISION_VERSION_C         2
#define FLS_FLASH_CONST_SW_MAJOR_VERSION_C                    1
#define FLS_FLASH_CONST_SW_MINOR_VERSION_C                    0
#define FLS_FLASH_CONST_SW_PATCH_VERSION_C                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls.h header file are of the same vendor */
#if (FLS_FLASH_CONST_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Flash_Const.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls.h header file are of the same Software version */
#if ((FLS_FLASH_CONST_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_FLASH_CONST_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash_Const.c and Fls.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C != FLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash_Const.c and Fls.h are different"
    #endif
#endif


/* Check if current file and Fls_Flash_Types.h header file are of the same vendor */
#if (FLS_FLASH_CONST_VENDOR_ID_C != FLS_FLASH_TYPES_VENDOR_ID)
    #error "Fls_Flash_Const.c and Fls_Flash_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash_Types.h header file are of the same Software version */
#if ((FLS_FLASH_CONST_SW_MAJOR_VERSION_C != FLS_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_SW_MINOR_VERSION_C != FLS_FLASH_TYPES_SW_MINOR_VERSION) || \
     (FLS_FLASH_CONST_SW_PATCH_VERSION_C != FLS_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash_Const.c and Fls_Flash_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C != FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C != FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash_Const.c and Fls_Flash_Types.h are different"
    #endif
#endif 


/* Check if current file and Reg_eSys_FLASHC.h header file are of the same vendor */
#if (FLS_FLASH_CONST_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Flash_Const.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC.h header file are of the same Software version */
#if ((FLS_FLASH_CONST_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_FLASH_CONST_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash_Const.c and Reg_eSys_FLASHC.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash_Const.c and Reg_eSys_FLASHC.h are different"
    #endif
#endif 
  
  
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/  

  
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define FLS_START_SEC_CONST_UNSPECIFIED
/* 
* @violates @ref fls_flash_const_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

/**
    @brief FLASH array description
*/
CONST(Fls_Flash_ArrayInfoType, FLS_CONST) Fls_Flash_aArrayList0[1U]=
{
    {    /* FLS_CODE_ARRAY_0_A */
        (boolean)TRUE,
        (boolean)TRUE
    }
};

#define FLS_STOP_SEC_CONST_UNSPECIFIED
/* 
* @violates @ref fls_flash_const_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_const_c_REF_2 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif
