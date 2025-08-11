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
            -nostdlib \
            -fno-builtin \
            -I ./include/ "

    result = subprocess.call(cmd +
                            "src/T100CRT.c \
                            -o src/T100CRT.o")

    result = subprocess.call(cmd +
                            "src/string.c \
                            -o src/string.o")

    result = subprocess.call(cmd +
                            "src/stdio.c \
                            -o src/stdio.o")

    result = subprocess.call(
                            "ar \
                            rcs \
                            T100CRT.a \
                            src/string.o \
                            src/stdio.o \
                            src/T100CRT.o")

def clean():
    print("Cleaning ... ")
    result = subprocess.call("rm *.a")
    result = subprocess.call("rm src/*.o")

def rebuild():
    clean()
    make()

if __name__ == "__main__":
    args()
