#===================================================================================================
#   @file        build_cfg.mak
#   @version     1.0.1
#
#   @brief       configuration file for IAR toolchain
#   @details     This file contains the compiler, assembler, linker options for IAR toolchain
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

clib        := $(call winpath, $(TOOLCHAIN_DIR)/lib/thumb2)

SUBDERIVATIVE_NAME=-DDERIVATIVE_$(DERIVATIVE)

CC 			:= $(call winpath, $(TOOLCHAIN_DIR)/bin/iccarm.exe)
LD 			:= $(call winpath, $(TOOLCHAIN_DIR)/bin/ilinkarm.exe)
AS 			:= $(call winpath, $(TOOLCHAIN_DIR)/bin/iasmarm.exe)

PROD_PAT = $(realpath $(TRESOS_DIR)) $(realpath $(GENERATE_DIR))

CCOPT 			:=  $(CCOPT) \
                    --cpu_mode=thumb \
                    --endian=little \
                    $(MISRA) \
                    $(PRJFLAG) \
                    -DIAR \
                   -DAUTOSAR_OS_NOT_USED \
                   $(SUBDERIVATIVE_NAME) \
                   -DEU_DISABLE_ANSILIB_CALLS \
                   --debug \
                   --no_clustering \
                   --no_mem_idioms \
                   --diag_suppress=Pa050 \
                   --no_explicit_zero_opt \
                   -e \
                   --require_prototypes \
                   --no_wrap_diagnostics
                   
                   
# Production Compiler Options
CCOPT_PROD  := 
# TEST Compiler Options
CCOPT_TEST  := 

MAPFILE = $(call winpath, $(OUT_DIR)/$(TEST_NAME).map)                    
LDOPT 			:=  --entry _start \
                    --enable_stack_usage \
                    --skip_dynamic_initialization \
                    --no_wrap_diagnostics

                    
                    
ASOPT 			:=  $(ASOPT) \
                    --cpu_mode thumb \
                    -g

# Production Compiler Options
ASOPT_PROD  :=
# TEST Compiler Options
ASOPT_TEST  := 

ifeq ($(DERIVATIVE),S32K118)
    CCOPT:=         $(CCOPT) --cpu=Cortex-M0+
    LDOPT:=         $(LDOPT) --cpu=Cortex-M0+
    ASOPT:=         $(ASOPT) --cpu Cortex-M0+
else
    CCOPT:=         $(CCOPT) --cpu=Cortex-M4
    LDOPT:=         $(LDOPT) --cpu=Cortex-M4
    ASOPT:=         $(ASOPT) --cpu Cortex-M4
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
    CCOPT:= $(CCOPT) -DCCOV_ENABLE
    ASOPT:= $(ASOPT) -DCCOV_ENABLE
endif

ifeq ($(T32_TRACE_APP),ON)
    #if trace coverage is needed
    CCOPT:=         $(CCOPT) -On
else
    CCOPT:=         $(CCOPT) --no_system_include \
                             -Ohz
    ifneq ($(DERIVATIVE),S32K118)
        LDOPT:=         $(LDOPT) --no_library_search
    endif  
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
PREPROCESS_C_FILE = $(CC) $(CCOPT) $(if $(strip $(foreach PATTERN,$(PROD_PAT),$(findstring $(PATTERN),$(realpath $<)))), $(CCOPT_PROD) , $(CCOPT_TEST) )  -DENABLE_DUMMY_SUITES -DPREPROCESS_ONLY_TEST $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) --preprocess=n  $(call winpath, $(OUT_DIR)/$(notdir $@))
COMPILE_S_FILE = $(AS) $(ASOPT) $(if $(strip $(foreach PATTERN,$(PROD_PAT),$(findstring $(PATTERN),$(realpath $<)))), $(ASOPT_PROD) , $(ASOPT_TEST) ) $(call winpath, $<) -o $(call winpath, $(OUT_DIR)/$@)
LINK_O_FILES = $(LD) $(LDOPT) --map $(MAPFILE) --config $(foreach LINKER_DEF, $(LINKER_DEFS), $(call winpath, $(LINKER_DEF))) $(addprefix $(call winpath, $(OUT_DIR)/), $(OUT_FILES)) $(call winpath, $(LIBS)) -o $(call winpath, $@)

COMPILER_VERSION_CMD = $(CC) -v 2>&1 | grep $(COMPILER_REFERENCE_VERSION)
COMPILER_REFERENCE_VERSION := "IAR ANSI C/C++ Compiler V8.11.2.13589/W32 for ARM"

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

