#====================================================================================================
#
#    @file        files.mak
#    @version     1.0.1
#
#    @brief       Integration Framework - files to be build for the current application.
#    @details     List of files to be built for the Leds Sample Application.
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
# List of all source directories (test, dependency, and generated .c files)
################################################################################
# specify modules which will be compiled and linked
MODULES_MAK_FILE := $(GENERATE_DIR)/Modules.mak

# Including local configuration file
-include  $(MODULES_MAK_FILE)


# paths for building installed plugins
SRC_DIRS    +=  $(GENERATE_DIR)/src \
                $(foreach mod,$(MCAL_MODULE_LIST),$(PLUGINS_DIR)/$(mod)_$(AR_PKG_NAME)/src) \
                $(foreach swc_comp,$(APP_SWC_LIST),../../src/swc/$(swc_comp)) \
                $(foreach bsw_comp,$(APP_BSW_LIST),../../src/bsw/$(bsw_comp))

################################################################################
# List of all include directories (test, dependency, and generated .h files)
################################################################################
#
INCLUDE_DIRS+=      $(GENERATE_DIR)/include \
                    $(foreach mod,$(MCAL_MODULE_LIST),$(PLUGINS_DIR)/$(mod)_$(AR_PKG_NAME)/include) \
                    $(foreach swc_comp,$(APP_SWC_LIST),../../include/swc/$(swc_comp)) \
                    $(foreach bsw_comp,$(APP_BSW_LIST),../../include/bsw/$(bsw_comp))

################################################################################
# Additional test specific C compiler options
################################################################################
CCOPT           +=

################################################################################
# Additional test specific linker options
################################################################################
LDOPT           +=

################################################################################
# Custom libraries
################################################################################
LIBS            +=

################################################################################
# Path to the linker definition file
################################################################################
ifeq ($(DERIV),118)
LINKER_DEFS_GHS_FLASH     :=    $(TOOLCHAIN_DEV_DIR)/linkfiles/autosar_flash_118.ld
LINKER_DEFS_LINARO_FLASH  :=    $(TOOLCHAIN_DEV_DIR)/linkfiles/autosar_flash_118.gld
LINKER_DEFS_IAR_FLASH     :=    $(TOOLCHAIN_DEV_DIR)/linkfiles/autosar_flash_118.icf
else
LINKER_DEFS_GHS_FLASH     :=    $(TOOLCHAIN_DEV_DIR)/linkfiles/autosar_flash_144.ld
LINKER_DEFS_LINARO_FLASH  :=    $(TOOLCHAIN_DEV_DIR)/linkfiles/autosar_flash_144.gld
LINKER_DEFS_IAR_FLASH     :=    $(TOOLCHAIN_DEV_DIR)/linkfiles/autosar_flash_144.icf
endif

ifeq ($(TOOLCHAIN),ghs)
    LINKER_DEFS          :=    $(LINKER_DEFS_GHS_FLASH)
else
    ifeq ($(TOOLCHAIN),linaro)
        LINKER_DEFS      :=    $(LINKER_DEFS_LINARO_FLASH)
    else
        LINKER_DEFS      :=    $(LINKER_DEFS_IAR_FLASH)
    endif
endif
################################################################################
# Add Platform specific statup and vector files
################################################################################
SRC_STATUP_FILES   +=  $(DEV_STARTUP_DIR)/src/sys_init.c
SRC_STATUP_FILES   +=  $(DEV_STARTUP_DIR)/src/nvic.c
SRC_STATUP_FILES   +=  $(DEV_STARTUP_DIR)/src/main.c

ifeq ($(DERIV),118)
    ifeq ($(TOOLCHAIN),iar)
        SRC_STATUP_FILES   += $(DEV_STARTUP_DIR)/src/m0/exceptions_iar.c
    else
        SRC_STATUP_FILES   += $(DEV_STARTUP_DIR)/src/m0/exceptions.c
    endif
    
    ifeq ($(TOOLCHAIN),iar)
        SRC_STATUP_FILES       += $(DEV_STARTUP_DIR)/src/m0/Startup_iar.s
    else
        SRC_STATUP_FILES       += $(DEV_STARTUP_DIR)/src/m0/Startup.s
    endif
    
    ifeq ($(TOOLCHAIN),iar)
        SRC_STATUP_FILES       += $(DEV_STARTUP_DIR)/src/m0/Vector_core_iar.s
    else
        SRC_STATUP_FILES       += $(DEV_STARTUP_DIR)/src/m0/Vector_core.s
    endif
else
    ifeq ($(TOOLCHAIN),iar)
        SRC_STATUP_FILES   += $(DEV_STARTUP_DIR)/src/m4/exceptions_iar.c
    else
        SRC_STATUP_FILES   += $(DEV_STARTUP_DIR)/src/m4/exceptions.c
    endif
    
    ifeq ($(TOOLCHAIN),iar)
        SRC_STATUP_FILES      += $(DEV_STARTUP_DIR)/src/m4/Startup_iar.s
    else
        SRC_STATUP_FILES       += $(DEV_STARTUP_DIR)/src/m4/Startup.s
    endif
    
    ifeq ($(TOOLCHAIN),iar)
        SRC_STATUP_FILES      += $(DEV_STARTUP_DIR)/src/m4/Vector_core_iar.s
    else
        SRC_STATUP_FILES       += $(DEV_STARTUP_DIR)/src/m4/Vector_core.s
    endif
endif

INCLUDE_DIRS    +=  $(DEV_STARTUP_DIR)/include/

ifeq ($(DERIV),118)
    INCLUDE_DIRS    += $(DEV_STARTUP_DIR)/include/S32K118/
else
    INCLUDE_DIRS    += $(DEV_STARTUP_DIR)/include/S32K144/
endif

ifeq ($(TOOLCHAIN),iar)
    INCLUDE_DIRS    +=  $(TOOLCHAIN_DIR)/inc/c/
endif
