extern void print(char *str);
extern void clear_screen(char flags);
extern void printv(char *str,char color);

//__attribute__((section(".rodata"))) char *str = "Hello from rodata\r\n";

void kernel_entry() {
    //print("Hello world");
    clear_screen(0x07);
    printv("Test",0x0f); // Coba expand memory -> upper
    //print("Test kernel mode");
    //printv("Hello world",0x0f);
    while(1)__asm__ __volatile__("hlt");
}
