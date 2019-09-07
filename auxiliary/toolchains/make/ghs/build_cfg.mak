#===================================================================================================
#   @file    build_cfg.mak
#   @version 1.0.1
#
#   @brief       configuration file for GHS toolchain
#   @details     This file contains the compiler, assembler, linker options for GHS toolchain
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
MISRA_ALL = --misra_2004=all
# Allowed exceptions are to be documented in the source code. Exceptions are documented in Global_MSG_C-Coding_Guidelines.doc Appendix A
MISRA_ALLOWED = --misra_2004=all,-5.7,-11.3,-11.4,-14.7,-17.1,-17.2,-17.4,-20.3,-20.4
#MISRA = $(MISRA_ALLOWED)


ifeq ($(DERIVATIVE),S32K118)
    clib        := $(call winpath, $(TOOLCHAIN_DIR)/lib/thumb)
else
    clib        := $(call winpath, $(TOOLCHAIN_DIR)/lib/thumb2)
endif 

SUBDERIVATIVE_NAME=-DDERIVATIVE_$(DERIVATIVE)

CC 			:= $(call winpath, $(TOOLCHAIN_DIR)/ccthumb.exe)
LD 			:= $(call winpath, $(TOOLCHAIN_DIR)/elxr.exe)
AS 			:= $(call winpath, $(TOOLCHAIN_DIR)/ccthumb.exe)

PROD_PAT = $(realpath $(TRESOS_DIR)) $(realpath $(GENERATE_DIR))

CCOPT 			:=  $(CCOPT) \
                    $(MISRA) \
                    $(PRJFLAG) \
                    -DGHS \
                   -DAUTOSAR_OS_NOT_USED \
                   $(SUBDERIVATIVE_NAME) \
                   -DEU_DISABLE_ANSILIB_CALLS \
                   -c \
                   -Osize \
                   -Wall\
                   -ansi \
                   -G \
                   -preprocess_assembly_files \
                   --no_exceptions \
                   -dual_debug \
                   --prototype_errors \
                   -Wundef \
                   -noslashcomment \
                   -Wimplicit-int \
                   -Wshadow \
                   -Wtrigraphs \
                   -nostartfile \
                   --no_commons \
                   --incorrect_pragma_warnings \
                   -keeptempfiles \
                   -list \
                   --short_enum 
                   
# Production Compiler Options
CCOPT_PROD  := 
# TEST Compiler Options
CCOPT_TEST  := 
LDOPT 			:=  -Mn -delete \
                    -v \
                    -ignore_debug_references \
                    -map \
                    -keepmap \
                    -L$(clib) \
                    -lstartup \
                    -lsys \
                    -larch \
                    -lansi \
                    -lutf8_s32
                    
                    
ASOPT 			:=  $(ASOPT) \
                    -c \
                    -preprocess_assembly_files \
                    -asm=-list

# Production Compiler Options
ASOPT_PROD  :=
# TEST Compiler Options
ASOPT_TEST  := 

ifeq ($(DERIVATIVE),S32K118)
    CCOPT:=         $(CCOPT) -cpu=cortexm0plus
    ASOPT:=         $(ASOPT) -cpu=cortexm0plus
else
    CCOPT:=         $(CCOPT) -cpu=cortexm4
    ASOPT:=         $(ASOPT) -cpu=cortexm4
endif    

ifeq ($(findstring @LoadTo=ram, $(TEST_PARAMS)),)
    # if compiling/linking into flash
else
    #if compiling/linking into ram
    ASOPT       := $(ASOPT) -DSINTRAM
	CCOPT       := $(CCOPT) -DSINTRAM 
endif

ifeq ($(CCOV_ENABLE),ON)
    #if code coverage is needed
    CCOPT:= $(CCOPT) -DCCOV_ENABLE --keep_static_symbols
    ASOPT:= $(ASOPT) -DCCOV_ENABLE
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
LIBS			:= 
#INCLUDE_DIRS	= 
#SRC_FILES		= 
# Extention of the linked executable file
EXE_EXT := elf

# Compiling and Linking macros
COMPILE_C_FILE = $(CC) $(CCOPT) $(if $(strip $(foreach PATTERN,$(PROD_PAT),$(findstring $(PATTERN),$(realpath $<)))), $(CCOPT_PROD) , $(CCOPT_TEST) ) -DFILE_BASENAME=$(basename $(notdir $<)) -c $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) -o $(call winpath, $(OUT_DIR)/$@)
PREPROCESS_C_FILE = $(CC) $(CCOPT) $(if $(strip $(foreach PATTERN,$(PROD_PAT),$(findstring $(PATTERN),$(realpath $<)))), $(CCOPT_PROD) , $(CCOPT_TEST) ) -DENABLE_DUMMY_SUITES -DPREPROCESS_ONLY_TEST -E $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) -o $(call winpath, $(OUT_DIR)/$(notdir $@))
COMPILE_S_FILE = $(AS) $(ASOPT) $(if $(strip $(foreach PATTERN,$(PROD_PAT),$(findstring $(PATTERN),$(realpath $<)))), $(ASOPT_PROD) , $(ASOPT_TEST) ) $(call winpath, $<) -o $(call winpath, $(OUT_DIR)/$@)
LINK_O_FILES = $(LD) $(LDOPT) $(foreach LINKER_DEF, $(LINKER_DEFS), $(call winpath, $(LINKER_DEF))) $(addprefix $(call winpath, $(OUT_DIR)/), $(OUT_FILES)) $(call winpath, $(LIBS)) -o $(call winpath, $@)

COMPILER_VERSION_CMD = $(CC) -V a.c 2>&1 | grep $(COMPILER_REFERENCE_VERSION)
COMPILER_REFERENCE_VERSION := "C-ARM 2017.1.4 RELEASE VERSION: Copyright (C) 1983-2016 Green Hills Software."

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
