all:display.o

display.o:display.asm
	nasm -f elf display.asm

bios:bios.o

bios.o:bios.asm
	nasm -f bin bios.asm -o bios.bin

clean:
	rm -rf *.o
