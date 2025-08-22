__asm__(".code16gcc\n");

extern void print(char *str);
//extern char *itoa(int value);
extern void printv(char *str,char vcolor);

struct __attribute__((packed)) GDTDescriptor {
    unsigned short limit;
    unsigned int   base;
};

static unsigned long long gdt[] = {
    0x0000000000000000ULL,
    0x00CF9A000000FFFFULL,
    0x00CF92000000FFFFULL 
};

static struct GDTDescriptor gdt_desc = {
    .limit = sizeof(gdt) - 1,
    .base  = (unsigned int)gdt
};

void boot_start(void){
    __asm__ __volatile__(
        "mov $0x0003,%%ax\n\tint $0x10":::"ax"
    );
    //print("[INFO] : System switch protected mode 32");

    __asm__ __volatile__(
        "lgdt %0"::"m"(gdt_desc)
    );
    
    __asm__ __volatile__(
        "cli\n\t"
        "mov %cr0, %eax\n\t"
        "or $1, %eax\n\t"
        "mov %eax, %cr0\n\t"
    );

    __asm__ __volatile__("ljmp $0x08,$pmode_entry\n\t");
    __asm__ __volatile__("hlt");
}
