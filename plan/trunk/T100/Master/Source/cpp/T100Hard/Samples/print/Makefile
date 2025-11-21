all: print

print.o: print.c
	cc -c -fno-builtin -ffreestanding -nostdlib -m32 -I../../Source/hard -e start_entry print.c -o print.o

print: print.o
	#ld -e start_entry -m elf_i386 -Ttext-seg=0x100000 print.o -o print.elf
	#ld -m i386pe  -e start_entry -Ttext-seg=0x100000 print.o -o print ../../Source/hard/libhard.a
	ld -m i386pe  -e _start_entry -Ttext-seg=0x100000 print.o -o print ../../Source/hard/libhard.a
	objcopy -O binary print print.bin

clean:
	-rm *.o
