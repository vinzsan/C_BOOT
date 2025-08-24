/*OUTPUT_FORMAT("elf32-i386")*/
ENTRY(kernel_entry)
SECTIONS
{
    . = 0x1000;   /* VMA start */

    .text : { 
        *(.text) 
        *(.rodata) 
    }

    .data : { *(.data) }
    .bss  : { *(.bss COMMON) }

    /DISCARD/ : { 
        *(.eh_frame) 
        *(.comment) 
        *(.note*) 
    }
}

