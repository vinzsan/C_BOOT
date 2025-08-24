#define VIDEO_MEMORY 0xB8000
#define ROWS 25
#define COLS 80

static int cursor_row = 0;
static int cursor_col = 0;

void putc(char c, char attr) {
    unsigned short *vmem = (unsigned short*) VIDEO_MEMORY;

    if (c == '\n') {
        cursor_row++;
        cursor_col = 0;
    } else {
        int index = cursor_row * COLS + cursor_col;
        vmem[index] = (attr << 8) | c;
        cursor_col++;
        if (cursor_col >= COLS) {
            cursor_col = 0;
            cursor_row++;
        }
    }

    // scroll jika lewat ROWS
    if (cursor_row >= ROWS) {
        // geser layar ke atas
        for (int i = 0; i < (ROWS-1)*COLS; i++) {
            vmem[i] = vmem[i+COLS];
        }
        // kosongkan baris terakhir
        for (int i = (ROWS-1)*COLS; i < ROWS*COLS; i++) {
            vmem[i] = (0x07 << 8) | ' ';
        }
        cursor_row = ROWS-1;
    }
}

void puts(const char *s, char attr) {
    while (*s) {
        putc(*s++, attr);
    }
}

void clear_screen(char color) {
    char *video = (char*)0xB8000;
    for (int i = 0; i < 80*25; i++) {
        video[i*2] = ' ';
        video[i*2+1] = color;
    }
}

