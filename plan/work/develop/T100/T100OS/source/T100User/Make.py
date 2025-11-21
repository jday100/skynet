import subprocess

if __name__ == "__main__":
    result = subprocess.call(
        "g++ \
        -I./include/ \
        src/os/user/display.c \
        -c \
        -o src/os/user/display.o")

    result = subprocess.call(
        "ld src/os/user/display.o \
        -o libUser.a")
