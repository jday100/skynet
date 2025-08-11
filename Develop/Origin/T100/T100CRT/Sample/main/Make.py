import sys
import subprocess

def args():
    print("Args ... ")
    count = len(sys.argv)

    match count:
        case 1:
            make()
        case 2:
            value = sys.argv[1]
            match value:
                case 'clean':
                    clean()
                case 'rebuild':
                    rebuild()

def make():
    print("Making ... ")
    cmd =   "gcc \
            -c \
            -I ../../Source/T100CRT/include/ \
            -I ../../mingw/include/ "

    result = subprocess.call(cmd +
                            "main.c \
                            -o main.o")

    result = subprocess.call(
                            "C:/zoo/bin/CodeBlocks/MinGW/libexec/gcc/x86_64-w64-mingw32/8.1.0/collect2 \
                            -lkernel32 \
                            -luser32 \
                            -lshell32 \
                            -lmsvcrt \
                            C:/zmsys2/msys2/mingw64/lib/libkernel32.a \
                            C:/zmsys2/msys2/mingw64/lib/libc++.a \
                            C:/zmsys2/msys2/mingw64/lib/libstdc++.a \
                            main.o \
                            ../../Source/T100CRT/T100CRT.a \
                            -o main.exe")

def clean():
    print("Cleaning ... ")
    result = subprocess.call("rm *.exe")
    result = subprocess.call("rm *.o")

def rebuild():
    clean()
    make()

if __name__ == "__main__":
    args()
