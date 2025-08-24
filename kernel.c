//extern void print(char *str);
extern void clear_screen(char flags);
extern void printv(char *str,char color);
extern char *itoa(int value);

void kernel_entry() {
    clear_screen(0x07);
    void *ptr;
    __asm__ __volatile__(
    "lea (kernel_entry),%0"
    ::"r"(&ptr):
  );
    printv(itoa((int)(void *)&ptr),0x0f); // Coba expand memory -> upper
    //print("Test kernel mode");
    //puts("Hello world",0x0f);
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
    //printv("Hello world",0x0f);
    while(1)__asm__ __volatile__("hlt");
}
