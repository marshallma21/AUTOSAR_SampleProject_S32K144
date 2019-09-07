::====================================================================================================
::
::    @file                launch.bat
::    @version             1.0.1
::
::    @brief               Integration Framework - internal build launcher.
::    @details             Launches the build of the sample application
::
::    Platform      :      ARM
::    Build Version :      S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
::
::   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
::       Copyright 2017 - 2018 NXP
::       All Rights Reserved.
::
::    This file contains sample code only. It is not part of the production code deliverables.
::
::====================================================================================================
::

@echo off

::You have to uncomment and set the following variables if they are not already set
:: uncomment line below if you do not set TRESOS_DIR over environment
::TRESOS
SET TRESOS_DIR=D:/EB/tresos
::MAKE
SET MAKE_DIR=D:/NXP/S32DS_ARM_v2018.R1/utils/msys32/usr
::GHS
SET GHS_DIR=C:/tools/ghs/ARM_MULTI_7.1.4COMPILER_2017.1.4
::GCC
SET LINARO_DIR=H:/toolchain/gcc-arm-none-eabi
::IAR
SET IAR_DIR=C:/tools/IARSystem/EmbeddedWorkbench8.0/arm
::Path to the plugins folder
SET PLUGINS_DIR=C:/NXP/AUTOSAR/S32K14X_MCAL4_2_RTM_HF1_1_0_1/eclipse/plugins
::SSC             
::SET SSC_ROOT=C:/NXP/AUTOSAR/S32K_AUTOSAR_OS_4_0_93_BETA_0_9_0

::SSC             
SET TRESOS_WORKSPACE_DIR=D:/AUTOSAR/Project/S32DS/IntegrationFramework_TS_T40D2M10I1R0/mcal_cfg

::SET TRESOS_WORKSPACE_DIR=C:/Users/nxf35061/Desktop/118/lighting_S32K118_4.2_RTM1.0.1/output


if not defined TRESOS_DIR GOTO missing_path_names_TRESOS_DIR
if not exist %TRESOS_DIR% GOTO missing_path_names_TRESOS_DIR

cmd /c "make.bat %1 %2 %3 %4 %5 %6"

GOTO end

:: The variable TRESOS_DIR was not specified
:missing_path_names_TRESOS_DIR
ECHO.
ECHO    The variable TRESOS_DIR was not set correctly.
ECHO    Please specify this variable manually, by editing
ECHO    the batch file 'launch.bat'.
ECHO.
pause
GOTO end

:end
