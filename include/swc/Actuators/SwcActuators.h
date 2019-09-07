/**
*   @file    SwcActuators.h
*   @version 1.0.1
*
*   @brief   Integration Framework - SW component actuators header file
*
*   @details This file implements SwcActuators header file.     
*
*   @addtogroup SWCACTUATORS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef SWCACTUATORS_H
#define SWCACTUATORS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "SwcRte.h"
/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCACTUATORS_VENDOR_ID                          43

#define SWCACTUATORS_SW_MAJOR_VERSION                   1
#define SWCACTUATORS_SW_MINOR_VERSION                   0
#define SWCACTUATORS_SW_PATCH_VERSION                   1
/*==================================================================================================
*                                     FILE VERSION CHECKS
===================================================================================================*/
/* Check if header file and SwcRte.h header file are of the same vendor */
#if (SWCACTUATORS_VENDOR_ID != SWCRTE_VENDOR_ID)
    #error "SwcActuators.h and SwcRte.h have different vendor ids"
#endif


/* Check if header file and SwcRte.h header file are of the same Software version */
#if ((SWCACTUATORS_SW_MAJOR_VERSION != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCACTUATORS_SW_MINOR_VERSION != SWCRTE_SW_MINOR_VERSION) || \
     (SWCACTUATORS_SW_PATCH_VERSION != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcActuators.h and SwcRte.h are different"
#endif



/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
extern void SwcActuators_Init(const SwcRte_GlobalConfigType * ConfigPtr);
extern void SwcActuators_MainRunnable(void);


/*================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*SWCACTUATORS_H*/
/** @} */