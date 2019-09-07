#===================================================================================================
#   @file        build_cfg.mak
#   @version     1.0.1
#
#   @brief       configuration file for LINARO toolchain
#   @details     This file contains the compiler, assembler, linker options for LINARO toolchain
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
#===================================================================================================
#

# Setup buid tools
# MISRA-C 2004 Rule checking.
PRJFLAG :=-D$(DERIVATIVE)
#MODEFLAG=$(DEFINE_FLAG_SPECIFIC)
MISRA_ALL = --misra_2004=all
# Allowed exceptions are to be documented in the source code. Exceptions are documented in Global_MSG_C-Coding_Guidelines.doc Appendix A
MISRA_ALLOWED = --misra_2004=all,-5.7,-11.3,-11.4,-14.7,-17.1,-17.2,-17.4,-20.3,-20.4
#MISRA = $(MISRA_ALLOWED)
ifeq ($(DERIVATIVE),S32K118)
clib           := $(call winpath, $(TOOLCHAIN_DIR)/arm-none-eabi/newlib/lib/thumb/v6-m)
clib_std       := $(call winpath,$(TOOLCHAIN_DIR)/lib/gcc/arm-none-eabi/6.3.1/thumb/v6-m)
else
clib   :=$(call winpath, $(TOOLCHAIN_DIR)/arm-none-eabi/newlib/lib/thumb)
clib   +=$(call winpath, $(TOOLCHAIN_DIR)/arm-none-eabi/newlib/lib)
endif

SUBDERIVATIVE_NAME=-DDERIVATIVE_$(DERIVATIVE)

CC             := $(call winpath, $(TOOLCHAIN_DIR)/bin/arm-none-eabi-gcc.exe)
LD             := $(call winpath, $(TOOLCHAIN_DIR)/bin/arm-none-eabi-g++.exe)
AS             := $(call winpath, $(TOOLCHAIN_DIR)/bin/arm-none-eabi-gcc.exe)
CCOPT 			:=  $(CCOPT) \
                    $(MISRA) \
                    $(PRJFLAG) \
                    -DLINARO \
                    -DAUTOSAR_OS_NOT_USED \
                    $(SUBDERIVATIVE_NAME) \
                    -DEU_DISABLE_ANSILIB_CALLS \
                    -c \
                    -Os \
                    -ggdb3 \
                    -mthumb \
                    -ansi \
                    -mlittle-endian \
                    -fomit-frame-pointer \
                    -msoft-float \
                    -fno-common \
                    -Wall \
                    -Wextra \
                    -Wstrict-prototypes \
                    -Wno-sign-compare \
                    -fstack-usage \
                    -fdump-ipa-all \
                    -lc \
                    -e _start \
                    -std=c99 \
                    -Werror=implicit-function-declaration

					
MAPFILE = $(call winpath, $(OUT_DIR)/$(TEST_NAME).map)


LDOPT           :=  -e _start \
                    $(addprefix -L , $(clib)) \
                    $(addprefix -B , $(clib)) \
                    --disable-newlib-supplied-syscalls \
                    -specs=nosys.specs -u _printf_float -u _scanf_float \
                    -nostartfiles -static -lc -lnosys
#                    -nostartfiles  -static -lc -lm -lgcc -lnosys
                
ASOPT           :=  $(MODEFLAG) \
                    -c \
                    -mthumb \
                    -x assembler-with-cpp 

                   
ifeq ($(DERIVATIVE),S32K118)
    CCOPT:=         $(CCOPT) -mcpu=cortex-m0plus
    ASOPT:=         $(ASOPT) -mcpu=cortex-m0plus
    LDOPT:=         $(LDOPT) $(addprefix -L , $(clib_std)) \
                             $(addprefix -B , $(clib_std))
else
    CCOPT:=         $(CCOPT) -mcpu=cortex-m4
    ASOPT:=         $(ASOPT) -mcpu=cortex-m4
endif

ifeq ($(findstring @LoadTo=ram, $(TEST_PARAMS)),)
    # if compiling/linking into flash
else
    #if compiling/linking into ram
    ASOPT       := $(ASOPT) -DSINTRAM
	CCOPT       := $(CCOPT) -DSINTRAM 
endif

ifeq ($(ENABLE_RCHECK),ON)
    #if code runtime checks are needed
    CCOPT:= $(CCOPT) -check=all -DENABLE_RCHECK -DAUX_BUFFER_ADDR=$(AUX_BUFFER_ADDR)
else
    ifeq ($(AUX_BUFFER_APP),ON)
        CCOPT       := $(CCOPT) -DENABLE_TIMERS 
    endif
endif

ifeq ($(T32_TRACE_APP),ON)
    CCOPT       := $(CCOPT) -DT32_TRACE_APP
    LDOPT       := $(LDOPT) -Xlinker --gc-sections
endif

ifeq ($(D_CACHE_ENABLE),ON)
    #if D_CACHE is needed
    CCOPT:= $(CCOPT) -DD_CACHE_ENABLE
endif
ifeq ($(I_CACHE_ENABLE),ON)
    #if I_CACHE is needed
    CCOPT:= $(CCOPT) -DI_CACHE_ENABLE
endif
ifeq ($(BTB_ENABLE),ON)
   #if BTB is needed
    CCOPT:= $(CCOPT) -DBTB_ENABLE
endif


# Setup system libs, inlude dirs, and sourceinclude files
LIBS            := 
#INCLUDE_DIRS    = 
#SRC_FILES        = 
# Extention of the linked executable file
EXE_EXT := elf


# Compiling and Linking macros
COMPILE_C_FILE = $(CC) $(CCOPT) -DFILE_BASENAME=$(basename $(notdir $<)) -c $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) -o $(call winpath, $(OUT_DIR)/$@)
PREPROCESS_C_FILE = $(CC) $(CCOPT)  -DENABLE_DUMMY_SUITES -DPREPROCESS_ONLY_TEST -E $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) -o $(call winpath, $(OUT_DIR)/$(notdir $@))
COMPILE_S_FILE = $(AS) $(ASOPT) $(call winpath, $<) -o $(call winpath, $(OUT_DIR)/$@)
LINK_O_FILES = $(LD) $(LDOPT) -Xlinker -Map=$(MAPFILE) -T $(foreach LINKER_DEF, $(LINKER_DEFS), $(call winpath, $(LINKER_DEF))) $(addprefix $(call winpath, $(OUT_DIR)/), $(OUT_FILES)) $(call winpath, $(LIBS)) -o $(call winpath, $@)
#LINK_O_FILES = $(LD) -Xlinker -Map=$(MAPFILE)  -T $(foreach LINKER_DEF, $(LINKER_DEFS), $(call winpath, $(LINKER_DEF))) $(addprefix $(call winpath, $(OUT_DIR)/), $(OUT_FILES)) $(call winpath, $(LIBS)) $(LDOPT) -o $(call winpath, $@)

COMPILER_VERSION_CMD = $(CC) --version a.c 2>&1 | grep $(COMPILER_REFERENCE_VERSION)
COMPILER_REFERENCE_VERSION := "(Linaro GCC 6.3-2017.06~dev) 6.3.1 20170509"

#check toolchain version
ifeq ($(TOOLCHAIN_VERSION),)
    #export to environment - so that is checked only once during current make run
    export TOOLCHAIN_VERSION:= $(strip $(shell $(COMPILER_VERSION_CMD)))
endif
ifeq ($(strip $(TOOLCHAIN_VERSION)),)
    $(shell echo "**************************************************************************************" 1>&2) 
    $(shell echo Bad Compiler version 1>&2) 
    $(shell echo For $(PLATFORM)-$(DERIVATIVE) you must use: $(COMPILER_REFERENCE_VERSION) 1>&2) 
    $(shell echo "**************************************************************************************" 1>&2) 
    $(error Bad Compiler version)
endif
