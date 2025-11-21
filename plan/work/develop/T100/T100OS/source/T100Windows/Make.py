import subprocess

if __name__ == "__main__":
    print("Making ... ")
    result = subprocess.call(
        "g++ \
        -I./include/ \
        src/windows/display.c \
        -c \
        -g \
        -o src/windows/display.o")

    result = subprocess.call(
        "ld src/windows/display.o \
        -lkernel32 \
        -g \
        -o libWindows.a")
