/**
*   @file    Lin_NonASR.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Lin NonAutosar high level interface implementation.
*   @details Lin NonAutosar high level interface implementation.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_NonASR_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_NonASR_c_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_NonASR_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Casting operation to a pointer.
* This violation is due to the Casting pointers to other types used in macros
* for Reading or writing data from address location of controller register
*
* @section Lin_NonASR_c_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_NonASR_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_NonASR_c_REF_6
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The code is not dynamically linked. An absolute stack address is obtained when taking the address of the near auto variable.
* A source of error in writing dynamic code is that the stack segment may be different from the data segment.
*
* @section Lin_NonASR_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Lin_NonASR.c
*/
#include "Lin.h"
#include "Lin_NonASR.h"
#include "Lin_IPW.h"
#include "Lin_LPUART.h"
#include "StdRegMacros.h"
#include "Reg_eSys_LPUART.h"
#include "SchM_Lin.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_NonASR.c
*/
#define LIN_VENDOR_ID_NONASR_C                      43
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C       4
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MINOR_VERSION_NONASR_C       2
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_NONASR_C    2
#define LIN_SW_MAJOR_VERSION_NONASR_C               1
#define LIN_SW_MINOR_VERSION_NONASR_C               0
#define LIN_SW_PATCH_VERSION_NONASR_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID)
    #error "Lin_NonASR.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Lin.h are different"
#endif
/* Check if current file and Lin_Ipw header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_IPW_VENDOR_ID)
    #error "Lin_NonASR.c and Lin_NonASR.h have different vendor ids"
#endif
/* Check if current file and Lin_Ipw header file are of the same version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_Ipw.h are different"
#endif
/* Check if current file and Lin_Ipw header file are of the same version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_Ipw.h are different"
#endif
/* Check if current file and Lin_NonASR header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID_NONASR)
    #error "Lin_NonASR.c and Lin_NonASR.h have different vendor ids"
#endif
/* Check if current file and Lin_NonASR header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_NONASR) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_NONASR) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_NONASR) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_NonASR.h are different"
#endif
/* Check if current file and Lin_NonASR header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION_NONASR) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION_NONASR) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION_NONASR) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Lin_NonASR.h are different"
#endif
/* Check if current file and Lin_LPUART header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_LPUART_VENDOR_ID)
    #error "Lin_NonASR.c and Lin_LPUART.h have different vendor ids"
#endif
/* Check if current file and Lin_LPUART header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_LPUART_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_LPUART_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_LPUART_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_LPUART.h are different"
#endif
/* Check if current file and Lin_LPUART header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_LPUART_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_LPUART_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_LPUART_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Lin_LPUART.h are different"
#endif
/* Check if current file and Reg_eSys_LPUART header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != REG_ESYS_LPUART_VENDOR_ID)
    #error "Lin_NonASR.c and Lin_LPUART.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_LPUART header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != REG_ESYS_LPUART_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != REG_ESYS_LPUART_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != REG_ESYS_LPUART_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Reg_eSys_LPUART.h are different"
#endif
/* Check if current file and Reg_eSys_LPUART header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != REG_ESYS_LPUART_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != REG_ESYS_LPUART_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != REG_ESYS_LPUART_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Reg_eSys_LPUART.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
      )
      #error "AutoSar Version Numbers of Lin_NonASR.c and StdRegMacros.h are different"
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


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
/**
* @violates @ref Lin_NonASR_c_REF_4 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if LIN_DUAL_CLOCK_MODE == STD_ON

/**
* @brief          Lin_SetClockMode.
* @details        Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*
* @param[in]      ClockMode   New clock mode.
*
* @return                     The result of the switching clock operation.
* @retval E_OK                The switching operation was OK.
* @retval E_NOT_OK            The switching operation has failed caused by the
*                             wrong driver state.
*
* @api            Switch the clock mode to the alternate clock mode on all
*                 the Lin channels.
*
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @implements     Lin_SetClockMode_Activity
*
* @note           Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*/
/**
* @violates @ref Lin_NonASR_c_REF_5 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_SetClockMode(VAR(Lin_ClockModesType, AUTOMATIC) ClockMode)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_OK;
    VAR(uint8,AUTOMATIC) u8chLoop;
    VAR(uint32, AUTOMATIC) u32Counter = (uint32)0U;
    VAR(uint8,AUTOMATIC) u8LPUART_Channel;
    VAR(Lin_StatusType,AUTOMATIC) LinStatus = LIN_NOT_OK;
    VAR(uint8,AUTOMATIC) *pu8linSduPtr[1];
    VAR(uint8,AUTOMATIC) au8linSdu[8] = {(uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0};

    /* @violates @ref Lin_NonASR_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    pu8linSduPtr[0] = au8linSdu;

    for(u8chLoop=(uint8)0U; u8chLoop < LIN_HW_MAX_MODULES; u8chLoop++)
    {
        /* Get the hardware Lin channel from logical channel */
         u8LPUART_Channel = Lin_pChannelConfigPtr[u8chLoop]->pChannelConfigPC->u8LinHwChannel;
 
        /* @violates @ref Lin_NonASR_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        LinStatus = Lin_GetStatus(u8chLoop, pu8linSduPtr);

        switch (LinStatus)
        {
            case LIN_NOT_OK :

                /* If the LIN driver or some channels are not initialized it's not possible to
                change the baudrate */
                u8TempReturn = (uint8)E_NOT_OK;
                break;

            default :

                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_25();
                {
                    /* Disable LPUART Receiver and Transmitter */
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                    */
                    REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RE_MASK_U32 );
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                    */
                    REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TE_MASK_U32 );

                    /* Set the Baudrate */
                    if (LIN_NORMAL == ClockMode)
                    {
                        /**
                        * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                        */
                        REG_RMW32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_SBR_MASK_U32, LPUART_BAUD_SBR_U32(Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue));
                    }
                    else
                    {
                        /**
                        * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                        */
                        REG_RMW32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_SBR_MASK_U32, LPUART_BAUD_SBR_U32(Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue_Alternate));
                    }

                    /* Enable LPUART Transmitter */
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                    */
                    REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TE_MASK_U32 );
                    /* Enable LPUART Receiver */
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                    */
                    REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RE_MASK_U32 );

                    /* After LPUART Transmitter is enabled, a preamble character that is one full character frame of the idle state will be queued automatically */
                    while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
                    {
                        /**
                        * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_NonASR_c_REF_7 cast should not be performed
                        */
                        if( (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32) == ( REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32)))
                        {
                            break;
                        }
                        else
                        {
                            u32Counter++;
                        }
                    }
                }
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_25();
                break;
        }
    }
    return u8TempReturn;
}

#endif /* DUAL CLOCK MODE */

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*
* @violates @ref Lin_NonASR_c_REF_4 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
