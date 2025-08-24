//__asm__(".code32\n");
__asm__(".global pmode_entry\n");

// IDK This is bug or my code is bad :<
//__attribute__((naked))
void pmode_entry(void) {
    __asm__ __volatile__ (
        "mov $0x10, %%ax\n\t"
        "mov %%ax, %%gs\n\t"
        "mov %%ax, %%ss\n\t"
        "mov $0x90000, %%esp\n\t"
//      	"ljmp *kernel_entry\n\t"
        "ljmp $0x0000,$0x1000\n\t"
        "hlt\n"
        ::: "ax"
    );
}
