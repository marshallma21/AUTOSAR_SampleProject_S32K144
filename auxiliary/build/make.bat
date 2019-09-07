::====================================================================================================
::
::    @file        make.bat
::    @version     1.0.1
::
::    @brief       Integration Framework - make command launcher.
::    @details     launches the make command. A user makefile and optional parameter can be specified
::                 USAGE:
::                      make.bat [-f makefilename] [make_options] [target]
::                              -f          this parameter is optional. If -f is
::                                          missing, a default makefile.mak is used
::                              make_options options of make.exe
::                              target      one of the make targets
::                                          (listed when calling launch.bat)
::                      make.bat help      print information on usage
::                      make.bat -h
::                      make.bat --h
::
::    Platform          :    ARM
::    Build Version     :    S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
::
::   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
::       Copyright 2017 - 2018 NXP
::       All Rights Reserved.
::
::    This file contains sample code only. It is not part of the production code deliverables.
::
::====================================================================================================
::


@ECHO OFF


:: a help message is wanted
IF "%1"=="-h" GOTO need_help
IF "%1"=="--help" GOTO need_help
IF "%1"=="help" GOTO need_help
:: a user makefile is specified
IF "%1"=="-f" GOTO user_makefile
:: no user makefile is specified, use default file
IF "%1"=="clean" GOTO default_make_clean
IF "%1"=="TOOLCHAIN" GOTO default_make_toolchain
IF "%1"=="MODE" GOTO default_make_runmode
IF "%1"=="OS" GOTO default_make_os
GOTO default_make

:: output a help message on usage of make.bat
:need_help
ECHO.
ECHO.
ECHO    launch.bat [-f makefilename] [make_options] [TOOLCHAIN=(ghs|linaro|iar)]
ECHO          -f            this parameter is optional. If -f is
ECHO                        missing, a default makefile.mak is used
ECHO          make_options  options of make.exe
ECHO          TOOLCHAIN=ghs Select the ghs toolchain.
ECHO                        Default toolchai is ghs
ECHO.
ECHO    launch.bat help      print this message
ECHO    launch.bat -h
ECHO    launch.bat --help
ECHO.
ECHO.
GOTO end

:: a user makefile is specified
:default_make_runmode
set USER_MAKE_FILE=makefile
set TOOL=%3 %4
set CORE=%5 %6
IF "%3"=="TOOLCHAIN" set TOOL=%3=%4
IF "%5"=="COREID" set CORE=%5=%6
ECHO %MAKE_DIR%/bin/make.exe -f %USER_MAKE_FILE% %1=%2 %TOOL% %CORE% %7 %8 %9
CALL %MAKE_DIR%/bin/make.exe -f %USER_MAKE_FILE% %1=%2 %TOOL% %CORE% %7 %8 %9
GOTO end

:user_makefile
set USER_MAKE_FILE=%2
CALL %MAKE_DIR%/bin/make.exe -f %2 %3 %4 %5 %6 %7 %8 %9
GOTO end

:: clean target received in command line
:default_make_clean
set USER_MAKE_FILE=makefile
CALL %MAKE_DIR%/bin/make.exe -f makefile %1
GOTO end

:: toolchain parameter received in command line
:default_make_toolchain
set USER_MAKE_FILE=makefile
IF "%3"=="MODE" set MODE=%3=%4
IF "%5"=="DERIV" set DERIV=%5=%6
ECHO %MAKE_DIR%/bin/make.exe -f %USER_MAKE_FILE% %1=%2 %MODE% %DERIV% %7 %8 %9
CALL %MAKE_DIR%/bin/make.exe -f %USER_MAKE_FILE% %1=%2 %MODE% %DERIV% %7 %8 %9
GOTO end

:default_make_os
set TOOL=%2 %3
IF "%2"=="TOOLCHAIN" set TOOL=%2=%3
ECHO %MAKE_DIR%/bin/make.exe -f makefile_os %TOOL% %4 %5 %6 %7 %8 %9
CALL %MAKE_DIR%/bin/make.exe -f makefile_os %TOOL% %4 %5 %6 %7 %8 %9
GOTO end

:: no user makefile is specified, take default
:default_make
set USER_MAKE_FILE=makefile
CALL %MAKE_DIR%/bin/make.exe -f makefile %1 %2 %3 %4 %5 %6 %7 %8 %9
GOTO end

:end
:: End of make.bat
exit