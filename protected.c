//__asm__(".code32\n");
__asm__(".globl pmode_entry\n");

__attribute__((naked))
void pmode_entry(void) {
    __asm__ __volatile__ (
        "mov $0x10, %%ax\n\t"
        "mov %%ax, %%ds\n\t"
        "mov %%ax, %%es\n\t"
        "mov %%ax, %%fs\n\t"
        "mov %%ax, %%gs\n\t"
        "mov %%ax, %%ss\n\t"
        "mov $0x90000, %%esp\n\t"
        "ljmp *kernel_entry\n\t"
        "hlt\n"
        ::: "ax"
    );
}
