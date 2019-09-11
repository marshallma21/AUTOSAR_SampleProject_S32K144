# AUTOSAR_SampleProject_S32K144
This is a sample project from NXP's MCAL sample for AUTOSAR 4.2.2. Please refer to [NXP's webpage.](https://www.nxp.com/design/automotive-software-and-tools/autosar-/autosar-4.2.x-classic-platform-software:AUTOSAR-4-2)

The orginal sample code requires additional wiring on [S32K144EVB](https://www.nxp.com/design/development-boards/automotive-development-platforms/s32k-mcu-platforms/s32k144-evaluation-board:S32K144EVB), which is my device. So some changes are made to adapt to the device, including:
1. Change the LED2 and LED3 to RGB-Blue and RGB-Green
2. Change the LED toggle button to SW3(PC13)
3. Change the Dimming button to SW2
4. Change the PWN channel to RGB-Red

Above changes are made in EB tresos. And the generated code are placed in `mcal_cfg`. MCAL plugins are included in `plugins` folder. Try to make it easy for compile. 

I have also disabled some features in SysDal and IoDal, in order to make the sample less complicated. 
But the plan is to add them back after I figure out how the whole AUTOSAR works.

To compile the project under windows, you need to config the `auxiliary/build/launch.bat`. 
- `MAKE_DIR` is the msys32 bin folder, which contains `make` command.
- `LINARO_DIR` is where your toolchain locates. The recommend toolchain for S32K144 is *gcc-arm-none-eabi*
- `PLUGINS_DIR` is the MCAL plugins DIR. If you have installed the NXP AUTOSAR 4.2 MCAL for S32K144, set to that DIR. Otherwise, you can set to project folder `./plugins`.
- `TRESOS_WORKSPACE_DIR` is the DIR for MCAL generation code. Set it to your actual EB project generated folder, or set it to `./mcal_cfg`.

If you have installed [S32DS for ARM](https://www.nxp.com/design/software/embedded-software/s32-design-studio-ide/s32-design-studio-ide-for-arm-based-mcus:S32DS-ARM), you should be able to use tools from it
- `MAKE_DIR` to `{S32DS}/utils/msys32/usr`
- `LINARO_DIR`to `{S32DS}/Cross_Tools/gcc-6.3-arm32-eabi`

After setting all these, run `build.bat` in cmd. If everything goes right, you should be able to find the compiled app `IntegrationFramework.elf` in `auxiliary/build/bin`.

Once you have the compiled file, you can use S32DS to download and debug.

Leave a message if you have any question.

Marshall Ma
