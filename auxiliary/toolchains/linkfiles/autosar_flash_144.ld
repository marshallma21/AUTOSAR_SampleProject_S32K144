/*==================================================================================================

   @file        autosar_flash_144.ld
   @version     1.0.1

   @brief       GHS Linker Command File
   @details     GHS Linker Command File.
                This file contains sample code only. It is not part of the production code deliverables
====================================================================================================    
   Project      : AUTOSAR 4.2 MCAL
   Platform     : ARM
   Peripheral   : LPit
   Dependencies : none
   
   Autosar Version       : 4.2.2
   Autosar Revision      : ASR_REL_4_2_REV_0002
   Autosar Conf. Variant : 
   Software Version      : 1.0.1
   Build Version         : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831

   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
   All Rights Reserved.

====================================================================================================

Note: This linker command file to be used with S32K144 device only.
==================================================================================================*/

MEMORY
{
    /* S32K144 - 512 KB Flash in range 0x00000000:0x0007FFFF */
    flash_rsvd1          : org = 0x00, len = 0x8
    flash_rsvd2          : org = 0x400, len = 0x10
    flash_memory         : org = 0x00000410, len = 0x7FBF0
    
    /* S32K144- 60 KB RAM in range 0x1FFF8000:0x20006FFF */
    int_sram             : org = 0x1FFF8000, len = 0xEE10     /* 60K - 0x60 - 0x90 - 0x100 */
    res_ram_fls          : org = 0x20006E10, len = 0x60       /* a reserved ram section needed by FLS driver */
    res_ram_eep          : org = 0x20006E70, len = 0x90       /* a reserved ram section needed by EEP driver */
    int_results          : org = 0x20006F00, len = 0x100
    ram_rsvd2            : org = .,          len = 0
}

//
// Program layout for starting in ROM, copying data to RAM,
// and continuing to execute out of ROM.
//

SECTIONS
{
//
// RAM SECTIONS
    .intc_vector                       ABS ALIGN(4) : > int_sram
    .ramcode                               ALIGN(4) : > .
    .sdabase                               ALIGN(8) : > .   
    .sdata                                 ALIGN(4) : > .
    .data                                  ALIGN(4) : > .
    .mcal_data                             ALIGN(4) : > .
    .sbss                                  ALIGN(4) : > .
    .bss                                  ALIGN(16) : > .
    .mcal_bss                             ALIGN(4)  : > .
    // reserve space for .acfls_code_ram and .aceep_code_ram
    .acfls_code_ram                        ALIGN(4) : {. += SIZEOF(.acfls_code_rom);} > .
    .aceep_code_ram                        ALIGN(4) : {. += SIZEOF(.aceep_code_rom);} > .
    // make sure the size of the reserved space is 4-bytes aligned     
    .acfls_code_ram_end                    ALIGN(4) : > .
    .aceep_code_ram_end                    ALIGN(4) : > .
    
    .stack_main  ALIGN(16)                          : > .
   
    .mcal_bss_no_cacheable                ALIGN(4)  : > .
    .mcal_data_no_cacheable               ALIGN(4)  : > . 
   

    

//
// ROM SECTIONS
//
    .rcw                                            : > flash_rsvd1
    .flash_config                                   : > flash_rsvd2
    .ROM.intc_vector  ROM(.intc_vector) ALIGN(0x10) : > flash_memory 
    .startup                                        : > .
    .systeminit                                     : > . /* SystemInit */
    .text.startup                                   : > .
    .text                                           : > .
    .mcal_text                                      : > .
    .rodata                                         : > .

    .ROM.ramcode              ROM(.ramcode) ALIGN(4): > .
    .ROM.sdata                 ROM(.sdata) ALIGN(4) : > .
    .ROM.data                    ROM(.data) ALIGN(4): > .
    .ROM.mcal_data         ROM(.mcal_data) ALIGN(4) : > .
    .ROM.mcal_data_no_cacheable  ROM(.mcal_data_no_cacheable) ALIGN(4) : > .

    
    .mcal_const_cfg                                 : > flash_memory
    .mcal_const                                     : > flash_memory    
    .acfls_code_rom                        ALIGN(4) : > flash_memory
    .aceep_code_rom                        ALIGN(4) : > flash_memory
    
    //INT_SRAM_START      = ADDR(int_sram);
    //INT_SRAM_SIZE       = 0x60000/64;                     // Init 64 bytes at a time
//    _bss_start      = ADDR(.bss);
//    _bss_end       =  ADDR(.bss) + 4*((SIZEOF(.bss) + SIZEOF(.mcal_bss )+ SIZEOF(.mcal_bss_no_cacheable) + 3) /4);   // Init 4 bytes at a time
    
    
    
    INT_SRAM_START      = ADDR(int_sram);
    INT_SRAM_SIZE       = (ADDR(ram_rsvd2) - ADDR(int_sram))/64;                     // Init 64 bytes at a time
    INT_SRAM_END        = ADDR(ram_rsvd2);
    SBSS_SRAM_START     = ADDR(.sbss);
    SBSS_SRAM_SIZE      = (SIZEOF(.sbss)+3)/4;            // Init 4 bytes at a time
    BSS_SRAM_START      = ADDR(.bss);
    BSS_SRAM_SIZE       = (SIZEOF(.bss)+SIZEOF(.mcal_bss)+3)/4;   // Init 4 bytes at a time

    BSS_NO_CACHEABLE_SRAM_START      = ADDR(.mcal_bss_no_cacheable);
    BSS_NO_CACHEABLE_SRAM_SIZE       = (SIZEOF(.mcal_bss_no_cacheable)+3)/4;

    RC_RAMCODE_SRC =  ADDR(.ROM.ramcode);
    RC_RAMCODE_DEST = ADDR(.ramcode);
    RC_RAMCODE_SIZE = (SIZEOF(.ROM.ramcode)+3) / 4;         // Copy 4 bytes at a time
    
    /* generate symbols used in start-up code to init .intc_vector section */
    RC_INTC_VECTOR_SRC  =  ADDR(.ROM.intc_vector);
    RC_INTC_VECTOR_DEST = ADDR(.intc_vector);
    RC_INTC_VECTOR_SIZE = (SIZEOF(.ROM.intc_vector)+3) /4;  // Copy 4 bytes at a time
    
    
    RC_SDATA_SRC        = ADDR(.ROM.sdata);
    RC_SDATA_DEST       = ADDR(.sdata);
    RC_SDATA_SIZE       = (SIZEOF(.ROM.sdata)+3)/4;          // Copy 4 bytes at a time
    RC_DATA_SRC         = ADDR(.ROM.data);
    RC_DATA_DEST        = ADDR(.data);
    RC_DATA_SIZE        = (SIZEOF(.ROM.data)+3)/4 + (SIZEOF(.ROM.mcal_data)+3)/4; // Copy 4 bytes at a time

    /* generate symbols used in start-up code to init .mcal_data_no_cacheable section */
    RC_DATA_NO_CACHEABLE_SRC    = ADDR(.ROM.mcal_data_no_cacheable) ;
    RC_DATA_NO_CACHEABLE_DEST   = ADDR(.mcal_data_no_cacheable);
    RC_DATA_NO_CACHEABLE_SIZE   = (SIZEOF(.ROM.mcal_data_no_cacheable)+3) / 4;
    
    __SP_END            = ADDR(.stack_main);
    __STACK_START       = ADDR(.stack_main)+SIZEOF(.stack_main); 
    _Stack_end    = addr(.stack_main);
    _Stack_start  = addr(.stack_main)+sizeof(.stack_main); 
    
    __RAM_NO_CACHEABLE_START      = ADDR(.mcal_bss_no_cacheable);
    __RAM_NO_CACHEABLE_END        = ADDR(ram_rsvd2)-1;
    __RAM_CACHEABLE_START         = ADDR(int_sram);
    __RAM_CACHEABLE_END           = ADDR(.mcal_bss_no_cacheable)-1;

    /* Fls module access code support */    
    Fls_ACEraseRomStart         = ADDR(.acfls_code_rom);
    Fls_ACEraseRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACEraseSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    Fls_ACWriteRomStart         = ADDR(.acfls_code_rom);
    Fls_ACWriteRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACWriteSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/
    
    _ERASE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
  
    /* Eep module access code support */    
    Eep_ACWriteRomStart         = ADDR(.aceep_code_rom);
    Eep_ACWriteRomEnd           = ADDR(.aceep_code_rom) + SIZEOF(.aceep_code_rom);
    Eep_ACWriteSize             = (SIZEOF(.aceep_code_rom)+3) / 4; /* Copy 4 bytes at a time*/
    
    _WRITE_FUNC_ADDRESS_EEP_    = ADDR(.aceep_code_ram);

    BSS_NO_CACHEABLE_SRAM_START      = ADDR(.mcal_bss_no_cacheable);
    BSS_NO_CACHEABLE_SRAM_SIZE       = (SIZEOF(.mcal_bss_no_cacheable)+3)/4;

}

OPTION ("-keep=Fls_Flash_AccessCode")
OPTION ("-keep=Eep_Eeprom_AccessCode")
OPTION ("-keep=ccov_main")
