#====================================================================================================
#
#    @file        Modules.mak
#    @version     1.0.1
#
#    @brief       Integration Framework - Files used to define all components required to be build
#
#    Platform        : ARM
#    Build Version   : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
#
#   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
#       Copyright 2017 - 2018 NXP
#       All Rights Reserved.
#
#    This file contains sample code only. It is not part of the production code deliverables.
#
#====================================================================================================
#
# specify modules which will be compiled and linked
MCAL_MODULE_LIST :=   Adc Base Dio Gpt Mcu Mcl Ocu Port Pwm Rte Dem Det Ecum 

APP_BSW_LIST := IoDal SysDal

APP_SWC_LIST := Actuators Lighting Rte Sensors	

SAMPLE_APP_NAME := IntegrationFramework
