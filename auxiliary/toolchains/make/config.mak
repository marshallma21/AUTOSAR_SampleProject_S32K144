#====================================================================================================
#
#    @file        config.mak
#    @version     1.0.1
#
#    @brief       Integration Framework - Build configuration file
#    @details     This file contains specific macro's for make system
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
# Setup default paths and settings if local_config.mak not defined
################################################################################

################################################################################
# Disable error logging by default
################################################################################
ifeq ($(strip $(BUILD_LOG)),)
BUILD_LOG = None
endif


################################################################################
# Path to the root directory of development structure
################################################################################
BUILD_DIR := $(ROOT_DIR)/bin

################################################################################
# Setup output directory
################################################################################
DEV_DIR := ../$(ROOT_DIR)

TOOLCHAIN_DEV_DIR := $(DEV_DIR)/toolchains
#
GENERATE_DIR      := $(TRESOS_WORKSPACE_DIR)/generated

DEV_STARTUP_DIR   :=  $(DEV_DIR)/toolchains/startup

-include $(GENERATE_DIR)/specific_config.mak
################################################################################
# Setup default paths and settings if local_config.mak not defined
################################################################################

################################################################################
# Disable error logging by default
################################################################################
ifeq ($(strip $(BUILD_LOG)),)
BUILD_LOG = None
endif

################################################################################
# Compiler used (default is GHS)
################################################################################
ifeq ($(TOOLCHAIN),)
# GHS used
TOOLCHAIN := ghs
endif

$(shell echo Using $(TOOLCHAIN) toolchain: TOOLCHAIN_DIR= $(TOOLCHAIN_DIR) 1>&2)

################################################################################
# Module version information (this numbering is module vendor specific, and it
# is recommended to follow these rules: update SW_VERSION_MAJOR in case of major
# change of module, update SW_VERSION_MINOR in case of minor change of module,
# update SW_VERSION_PATCH in case of bug-fix of module
################################################################################
SW_VERSION_MAJOR = 1
SW_VERSION_MINOR = 0
SW_VERSION_PATCH = 1


################################################################################
# AUTOSAR package name (i.e. tresos plugin name: TS_T11D3M2I0R0, etc.)
# - use the "M" section for coding major and minor version number
# - use "I" section for coding the patch number, this can contain 1 or more digits.
# - major version number will be left out, if it is "0", in this case the "M" section contains 1 digit only, otherwise it contains 2 digits
################################################################################
ifeq ($(SW_VERSION_MAJOR),0)
    AR_PKG_NAME = TS_T$(TRESOS_TARGET_ID)D$(TRESOS_DERIVATIVE_ID)M$(SW_VERSION_MINOR)I$(SW_VERSION_PATCH)R0
else
    AR_PKG_NAME = TS_T$(TRESOS_TARGET_ID)D$(TRESOS_DERIVATIVE_ID)M$(SW_VERSION_MAJOR)$(SW_VERSION_MINOR)I$(SW_VERSION_PATCH)R0
endif


################################################################################
# MCU family name (S12X, MPC etc.)
################################################################################
MCU_FAMILY = ARM

BUILD_SOURCE=Plugin
TOOLCHAIN_VERSION=OFF


