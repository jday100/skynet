import subprocess

if __name__ == "__main__":
    print("Hello world!")

    result = subprocess.call(
        "gcc -c -I./include/ src/display.c \
        -o src/display.o")

    result = subprocess.call(
        "ld src/display.o \
        -o libHard.a")
