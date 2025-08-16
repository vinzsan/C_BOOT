extern void print(char *str);

void kernel_entry(void) {
    print("Hello world");
    while(1) __asm__ __volatile__("hlt");
}