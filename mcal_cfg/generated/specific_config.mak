#====================================================================================================
#
#    @file        specific_config.mak
#    @version     1.0.1
#
#    @brief       Integration Framework - Specific tools and make commands file
#    @details     This file contains specific command for make system ('delete' file command)
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

################################################################################
# Tresos target ID (see the Encoding of Architecture and Derivative document for details)
# Target    Manufacturer    Architecture ID ("T")
#   PA      Freescale       2
################################################################################
TRESOS_TARGET_ID=40

################################################################################
# Tresos derivative ID (see the Encoding of Architecture and Derivative document for details)
#   Derivative ID ("D")
#       13          14          11           15          17
#    XPC560XB    XPC563XM    XPC560XP     XPC560XS     XPC56XXL
#    (Bolero)    (Monaco)    (Pictus)    (Spectrum)   (Leopard)
################################################################################
TRESOS_DERIVATIVE_ID=2

################################################################################
# Release type
################################################################################
 
SW_VERSION_SUFFIX = RTM   
################################################################################
# Platform, derivative, package
################################################################################
ifeq ($(DERIVATIVE),)
DERIVATIVE := S32K144
endif
PLATFORM := S32K1x

$(shell echo Running for $(DERIVATIVE) derivative, on $(PLATFORM) platform 1>&2)

################################################################################
# MCU derivative name (s12xep100, 5516 etc.) Used in pathname to product specific files.
################################################################################
MCU_DERIVATIVE = S32K144

