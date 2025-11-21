import subprocess

if __name__ == "__main__":
    print("Hello world!")

    result = subprocess.call(
        "gcc \
        -nostdlib \
        -fno-builtin \
        -ffreestanding \
        -e start_entry \
        -I./include/ \
        -I../../source/T100Hard/include/ \
        main.c \
        ../../source/T100Hard/libHard.a \
        -o main.exe")

    result = subprocess.call(
        "objcopy -O binary main.exe main.bin")
