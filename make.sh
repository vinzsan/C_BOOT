gcc -m16 init.c -o init.o -c -Os -Wall -g -Werror -ffreestanding -fno-pic 
gcc -m16 boot.c -o boot.o -c -Os -Wall -g -ffreestanding -fno-pic
gcc -m16 module2.c -o module2.o -c -Os -Wall -g -Werror -ffreestanding -fno-pic
gcc -m32 protected.c -o protected.o -c -Os -march=i686 -Wall -g -Werror -ffreestanding -fno-pic
#as --32 protected.s -o protected.o
gcc -m32 kernel.c -o kernel.o -c -Os -march=i686 -Wall -g -Werror -ffreestanding -fno-pic

ld -m elf_i386 -T link.ld init.o boot.o module2.o protected.o kernel.o -o boot.elf --nmagic -static -nostdlib --no-warn-rwx-segments
#upx --lzma --best boot.elf
objcopy -O binary boot.elf boot.bin
