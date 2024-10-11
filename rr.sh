rm *.o
rm *.bin
rm *.flp
rm *.img
nasm -f bin bootloader.asm -o main.bin
nasm -f elf 32/kernel_entry.asm -o kernel_entry.o 
/usr/local/i386elfgcc/bin/i386-elf-gcc -ffreestanding -m32 -mtune=intel -g -c 32/kernel.cpp -o kernel.o 
/usr/local/i386elfgcc/bin/i386-elf-ld -o full_kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o  --oformat binary
cat main.bin full_kernel.bin > main.flp