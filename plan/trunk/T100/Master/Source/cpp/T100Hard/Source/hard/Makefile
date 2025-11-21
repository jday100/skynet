all: libhard.a

libhard.a: display.o
	ar --target=elf32-i386 -r -s libhard.a display.o

display.o: display.h display.c
	cc -c -fno-builtin -ffreestanding -nostdlib -m32 display.c -o display.o

test:
	ld -e start_entry -m elf_i386 -Ttext-seg=0x100000 test.o -o test.elf

clean:
	##if exist libhard.a -del libhard.a
	-rm libhard.a
	-rm *.o

