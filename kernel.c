extern void print(char *str);

void kernel_entry() {
    __asm__ __volatile__(
        "mov $0x0003,%%ax\n\t"
        "int $0x10"
        :::"ax"
    );
}