//extern void print(char *str);
extern void clear_screen(char flags);
//extern void printv(char *str,char color);
//extern void puts_at(const char *str,int row,int col,char attr);
extern void puts(const char *str,char attr);

//__attribute__((section(".rodata"))) char *str = "Hello from rodata\r\n";

void kernel_entry() {
    //print("Hello world");
    clear_screen(0x07);
    //printv("Test",0x0f); // Coba expand memory -> upper
    //print("Test kernel mode");
    puts("Hello world",0x0f);
    __asm__ __volatile__(
    "movl $1,%%eax\n\t"
    :::"eax"
  ); // Test 32 addr
  //   __asm__ __volatile__(
  //   "movw $0x2000,%%ax\n\t"
  //   "movw $0x604,%%dx\n\t"
  //   "out %%ax,%%dx"
  //   :::"ax","dx"
  // );
  //puts_at("Hello world",10,20,0x0f);
    //printv("Hello world",0x0f);
    while(1)__asm__ __volatile__("hlt");
}
