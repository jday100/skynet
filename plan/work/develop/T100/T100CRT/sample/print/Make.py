import sys
import subprocess

def args():
    print("Args ... ")
    count = len(sys.argv)

    if(count == 1):
        make()
        return
    elif(count == 2):
        if(sys.argv[1] == "clean"):
            clean()
        return

def make():
    print("Making ... ")
    result = subprocess.call(
        "gcc \
        -c \
        -fno-builtin \
        -I./include/ \
        -I../../source/T100CRT/include/ \
        main.c \
        -o main.o")

    result = subprocess.call(
        "gcc \
        -nostdlib \
        -fno-builtin \
        -L /mingw64/lib/ \
        -luser32 \
        -lkernel32 \
        -lshell32 \
        -lmsvcrt \
        main.o \
        ../../source/T100CRT/T100CRT.a \
        C:/zmsys2/msys2/mingw64/lib/libkernel32.a \
        C:/zmsys2/msys2/mingw64/lib/libc++.a \
        C:/zmsys2/msys2/mingw64/lib/libstdc++.a \
        -o main.exe")

def clean():
    print("Cleaning ... ")
    result = subprocess.call("rm *.exe")
    result = subprocess.call("rm *.o")

if __name__ == "__main__":
    args()

