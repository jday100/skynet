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
            -I ./include/ "

    result = subprocess.call(cmd +
                            "main.c \
                            -o main.o")

    result = subprocess.call(
                            "ld \
                            main.o \
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
