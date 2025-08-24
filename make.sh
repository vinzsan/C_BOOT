gcc -m16 init.c -o init.o -c -Os -Wall -g -Werror -ffreestanding -fno-pic 
gcc -m16 boot.c -o boot.o -c -Os -Wall -g -ffreestanding -fno-pic
gcc -m16 module.c -o module.o -c -Os -Wall -g -Werror -ffreestanding -fno-pic
gcc -m32 protected.c -o protected.o -c -Os -march=i686 -Wall -g -Werror -ffreestanding -fno-pic
#as --32 protected.s -o protected.o
gcc -m32 kernel.c -o kernel.o -c -Os -march=i686 -Wall -g -Werror -ffreestanding -fno-pic

ld -m elf_i386 -T link.ld init.o boot.o module.o protected.o -o boot.elf --nmagic -static -nostdlib --no-warn-rwx-segments
ld -m elf_i386 -T link_kernel.ld kernel.o module.o -o kernel.elf --nmagic -static -nostdlib --no-warn-rwx-segments
#upx --lzma --best boot.elf
objcopy -O binary boot.elf boot.bin
objcopy -O binary kernel.elf kernel.bin

dd if=/dev/zero of=os.img bs=512 count=2880
dd if=boot.bin of=os.img bs=512 count=1 conv=notrunc
dd if=kernel.bin of=os.img bs=512 seek=1 conv=notrunc

qemu-system-x86_64 -fda os.img
