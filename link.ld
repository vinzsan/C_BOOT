ENTRY(boot_init)
SECTIONS{
    . = 0x7C00;

    .text : AT(0x7C00)
    {
        *(.text)
        *(.rodata)
    }
    /DISCARD/ :
    {
        *(.eh_frame)
        *(.note*)
        *(.comment)
        *(.note-GNU-stack)
    }
    .sig : AT(0x7DFE)
    {
        SHORT(0xAA55)
    }
}