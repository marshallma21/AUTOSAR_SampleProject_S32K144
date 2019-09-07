#====================================================================================================
#
#    @file        Makefile
#    @version     1.0.1
#
#    @brief       Integration Framework - Internal build application Makefile.
#    @details     File used to build the the framework application.
#
#===================================================================================================
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
# Command separator
################################################################################
#
	# running on windows command prompt
	COMMAND_SEPARATOR = &&
	COMMAND_INTERPRETER = cmd
#
################################################################################
# Load and check the configuration
################################################################################
CFG_MAK_FILE := ../toolchains/make/config.mak

################################################################################
# Path to the root directory of the project
################################################################################
ifeq ($(ROOT_DIR),)
ROOT_DIR :=  .
endif

ifeq ($(DERIV),118)
DERIVATIVE := S32K118
else
DERIVATIVE := S32K144
endif

#
#
# Including local configuration file
#
-include $(CFG_MAK_FILE)

# Check the dev dir



#
# Including cygwin environment tools (absolute paths)
#
TOOLS_DEFS := ../toolchains/make/tools.mak



-include $(TOOLS_DEFS)

# Check the dev dir
ifeq ($(strip $(DEV_DIR)),)
$(error Development directory path (DEV_DIR) is empty)
endif


#current_dir = $(shell pwd)


# Check the Build dir
ifeq ($(strip $(BUILD_DIR)),)
$(error Build directory path (BUILD_DIR) is empty)
endif

# Check the AUTOSAR package name
ifeq ($(strip $(AR_PKG_NAME)),)
$(error AUTOSAR package name (AR_PKG_NAME) is empty)
endif

# Check the device name
ifeq ($(strip $(DERIVATIVE)),)
$(error Device name (DERIVATIVE) is empty)
endif

# Check the platform name
ifeq ($(strip $(PLATFORM)),)
$(error Device name (PLATFORM) is empty)
endif

# Check the toolchain name
ifeq ($(strip $(TOOLCHAIN)),)
$(error Toolchain name (TOOLCHAIN) is empty)
endif


ifeq ($(TOOLCHAIN),ghs)
    ifeq ($(GHS_DIR),)
    $(error Toolchain name GHS_DIR is empty)
    endif
    TOOLCHAIN_DIR := $(GHS_DIR)
endif

ifeq ($(TOOLCHAIN),iar)
    ifeq ($(IAR_DIR),)
    $(error Toolchain name IAR_DIR is empty)
    endif
    TOOLCHAIN_DIR := $(IAR_DIR)
endif
	
ifeq ($(TOOLCHAIN),linaro)
    ifeq ($(LINARO_DIR),)
    $(error Toolchain name LINARO_DIR is empty)
    endif
	TOOLCHAIN_DIR := $(LINARO_DIR)
endif

# Check the Toolchain dir
ifeq ($(strip $(TOOLCHAIN_DIR)),)
$(error TOOLCHAIN directory path (TOOLCHAIN_DIR) is empty)
endif
#
# Check the dev dir
ifeq ($(strip $(GENERATE_CMD)),)
GENERATE_CMD = generate
endif

# Check log file
ifeq ($(strip $(BUILD_LOG)),)
BUILD_LOG = build.log
$(shell echo Using default BUILD_LOG: $(BUILD_LOG). Other options - file_name or None 1>&2)
endif

ifneq ($(strip $(BUILD_LOG)),None)
CAPTURE_OUTPUT = 2>&1 | $(TEE) -a $(OUT_DIR)/$(BUILD_LOG); \
if test ! "$${PIPESTATUS[0]}" -eq 0 ; then  \
 $(ECHO) ERROR: Build of $(SAMPLE_APP_NAME) has failed >>$(OUT_DIR)/$(BUILD_LOG); \
 $(DO_BEFORE_BUILD_FAIL) \
 exit 1; fi;
else
CAPTURE_OUTPUT :=
endif

# Flags used for M4 and compiler to define macros from CMD line
ifeq ($(MODE),)
#enable supervisor mode
USED_RUNMODE = SUPR
DEFINE_FLAG_SPECIFIC := -DMCAL_ENABLE_SUPERVISOR_MODE
endif

ifeq ($(MODE),USER)
    USED_RUNMODE =  USER
    DEFINE_FLAG_SPECIFIC:= -DMCAL_ENABLE_USER_MODE_SUPPORT
     $(shell echo Using runmode USER 1>&2)
else
    USED_RUNMODE =  SUPR 
    DEFINE_FLAG_SPECIFIC := -DMCAL_ENABLE_SUPERVISOR_MODE
    $(shell echo Using runmode SUPERVISOR 1>&2)
endif

# Flags used for M4 and compiler to define macros from CMD line
ifeq ($(CORE),)
CORE_SET=0
else
CORE_SET:=CORE
endif

$(shell echo building for core $(CORE_SET) 1>&2)

################################################################################
# Path conversion utilities
################################################################################
winpath = $(patsubst /cygdrive/$(word 2,$(subst /, , $(1)))%,$(word 2,$(subst /, ,$(1))):%,$(1))
cygpath = $(if $(findstring :,$(1)),/cygdrive/$(subst :,,$(1)),$(1))
cmdpath = $(subst /,\,$(1))

#


#

AR_PKG_REG_EXP		:= "TS_T[0-9]\{1,2\}D[0-9]\{1,2\}M[0-9]\{1,2\}I[0-9]\{1,2\}R[0-9]\{1,2\}"


ifeq ($(PLUGINS_DIR),)
	PLUGINS_DIR		:= $(TRESOS_DIR)/plugins
endif

################################################################################
# Builder specific options defined in the included make
#
#	CC; LD; AS ... 			generators
#	CCOPT; LDOPT; ASOPT		their options
#	LIBS; INCLUDE_DIRS; SRC_FILES	system libs, inlude dirs, and sourceinclude files
#
#	EXE_EXT				test file extentions
#	COMPILE_C_FILE			macro called for "C -> OBJ" rule
#	COMPILE_S_FILE			macro called for "S -> OBJ" rule (could be blank)
#	LINK_O_FILES			macro called for "OBJ -> $(EXE_EXT)" rule
#
################################################################################

#include toolchain options
BUILD_CFG_FILE := $(TOOLCHAIN_DEV_DIR)/make/$(TOOLCHAIN)/build_cfg.mak


# Include the sample specification make file
BUILD_FILES_LIST := $(TOOLCHAIN_DEV_DIR)/make/files.mak


#
#
################################################################################
# Add Non-OS Options
################################################################################
include $(BUILD_FILES_LIST)

include $(BUILD_CFG_FILE)

SRC_FILES += $(SRC_STATUP_FILES)

OUT_DIR			= $(BUILD_DIR)

# List of all source file names (.c files in SRC_DIRS directories and SRC_FILES)
ALL_SRC_FILES := $(foreach DIR,$(SRC_DIRS), $(wildcard $(call winpath, $(DIR))/*.c)) $(foreach FILE, $(SRC_FILES), $(call winpath, $(FILE)))
OUT_FILES := $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.c))) $(notdir $(SRC_FILES))
PARSE_FILES := $(OUT_FILES:.c=.par)
OUT_FILES := $(OUT_FILES:.c=.o)
OUT_FILES := $(OUT_FILES:.C=.o)
OUT_FILES := $(OUT_FILES:.s=.o)
OUT_FILES := $(sort $(OUT_FILES))

# Append directories of the SRC_FILES
SRC_DIRS += $(dir $(SRC_FILES))

# List of include files (must be in the cygwin path format since they are used in prerequisities)
INCLUDE_FILES := $(foreach DIR, $(INCLUDE_DIRS), $(wildcard $(DIR)/*.h))

# List of include directories (must be in the windows path format since it's passed to the compiler)
INCLUDE_DIRS := $(foreach DIR, $(INCLUDE_DIRS), $(call winpath, $(DIR)))
# print path to used linker script files
$(shell echo Linker command file = $(LINKER_DEFS) 1>&2)


$(shell echo Basic Include PATH: $(INCLUDE_DIRS) 1>&2)

# Print a delimiter line after the make header log
$(shell echo --------------------------------------------------------------------------------- 1>&2)

################################################################################
# Build targets
################################################################################
.PHONY: build
build: $(OUT_DIR)/$(SAMPLE_APP_NAME).$(EXE_EXT)

vpath %.c $(addsuffix :, $(SRC_DIRS))
vpath %.C $(addsuffix :, $(SRC_DIRS))
vpath %.s $(addsuffix :, $(SRC_DIRS))
vpath %.o $(OUT_DIR)

$(OUT_DIR)/$(SAMPLE_APP_NAME).$(EXE_EXT): $(OUT_FILES) $(LIBS) $(LINKER_DEF)
	$(call LINK_O_FILES)  $(call CAPTURE_OUTPUT)

%.o : %.c $(INCLUDE_FILES)
	$(call COMPILE_C_FILE)  $(call CAPTURE_OUTPUT)

%.o : %.C $(INCLUDE_FILES)
	$(call COMPILE_C_FILE)  $(call CAPTURE_OUTPUT)

%.o : %.s
	$(call COMPILE_S_FILE)  $(call CAPTURE_OUTPUT)

################################################################################
# Type the list of available tests on specified directory
################################################################################
.PHONY: help
help:
		@$(ECHO);
		@$(ECHO) "Makefile for building the MCAL Sample Application"
		@$(ECHO) "        "
		@$(ECHO) "Available targets:"
		@$(ECHO) "    build - compiles and links the application"
		@$(ECHO) "    clean - cleans the folder structure of the files generated during build"
		@$(ECHO) "        "
		@$(ECHO) "Options:"
		@$(ECHO) "    TOOLCHAIN=toolchain_name  - selects the toolchain used for building the application"
		@$(ECHO) "           Possible values for toolchain_name:"
		@$(ECHO) "                 - ghs  - (default) - Builds with GreenHills Multi. Uses GHS_DIR environment variable."
		@$(ECHO) "                 - cw   - Builds with Freescale CodeWarrior for MPC. Uses CW_DIR environment variable."
		@$(ECHO) "                 - diab - Builds with Windriver DIAB. Uses DIAB_DIR environment variable."
		@$(ECHO) "        "
		@$(ECHO) "Example commands:"
		@$(ECHO) "        "
		@$(ECHO) "    make clean"
		@$(ECHO) "    make build"
		@$(ECHO) "    make TOOLCHAIN=diab clean build"
		@$(ECHO) "        "

#

################################################################################
# Clean targets
################################################################################
.PHONY: clean
# delete all files
clean:
	$(RM) $(call cmdpath, $(OUT_DIR)/*.elf)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.a)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.o)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.d)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dba)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dbo)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dla)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dnm)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.map)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.run)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.lst)
	$(RM) *.si
	$(RM) compiler_used.s

#
#
################################################################################
# Makefile debug targets
################################################################################
print-%: ; $(error DEBUG Info: $* is $($*) ($(value $*)) (from $(origin $*)))

