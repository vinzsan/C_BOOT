__asm__(".code16gcc\n");


void putch(char c){
    __asm__ __volatile__("int $0x10\n\t"::"a"(0x0E00 | c):);
}

void print(char *str){
    while(*str){
        putch(*str++);
    }
}

void printv(char* text, char color)
{
    char* video_mem = (char*)0xB8000;
    for(int i = 0; text[i] != '\0'; ++i)
    {
        video_mem[i * 2] = text[i];
        video_mem[i * 2 + 1] = color;
    }
}

char *itoa(int value) {
    static char buf[20];
    char *p = buf + sizeof(buf) - 1;
    int sign = value < 0;
    *p = '\0';
    if (value == 0) {
        *--p = '0';
        return p;
    }
    if (sign) value = -value;
    while (value > 0) {
        *--p = (value % 10) + '0';
        value /= 10;
    }
    if (sign) *--p = '-';
    return p;
}

void clear_screen(char color) {
    char *video = (char*)0xB8000;
    for (int i = 0; i < 80*25; i++) {
        video[i*2] = ' ';      // spasi
        video[i*2+1] = color;  // warna (misal 0x07: abu-abu di hitam)
    }
}

