__asm__(".code16gcc\n");
__asm__(".global $boot_init\n");
__asm__("jmpl $0x0000,$boot_init\n");

void boot_init(){
    __asm__ __volatile__(
        "cli\n\t"
        "xor %%ax,%%ax\n\t"
        "mov %%ax,%%ds\n\t"
        "mov %%ax,%%es\n\t"
        "mov %%ax,%%fs\n\t"
        "mov %%ax,%%gs\n\t"
        "mov %%ax,%%ss\n\t"
        "mov $0x7C00,%%sp\n\t"
        "sti"
        :::
    );
    __asm__ __volatile__("jmpl $0x0000,$boot_start");
    while(1) __asm__ __volatile__("hlt");
}
