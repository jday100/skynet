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
            -D_CRTBLD \
            -I ../include/ "

    result = subprocess.call(cmd +
                            "crtbegin.c \
                            -o crtbegin.o")

    result = subprocess.call(cmd +
                            "crtend.c \
                            -o crtend.o")

    result = subprocess.call(cmd +
                            "crtexe.c \
                            -o crtexe.o")

    result = subprocess.call(
                            "ar \
                            rcs \
                            crt.a \
                            crtbegin.o \
                            crtend.o \
                            crtexe.o")

def clean():
    print("Cleaning ... ")
    result = subprocess.call("rm *.a")
    result = subprocess.call("rm *.o")

def rebuild():
    clean()
    make()

if __name__ == "__main__":
    args()
