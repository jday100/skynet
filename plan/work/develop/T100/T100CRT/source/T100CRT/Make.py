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
    cmd =   "g++ \
            -c \
            -nostdlib \
            -fno-builtin \
            -I ./include/ "

    result = subprocess.call(cmd +
                            "src/T100String.cpp \
                            -o T100String.o")

    result = subprocess.call(cmd +
                            "src/T100Console.cpp \
                            -o T100Console.o")

    result = subprocess.call(cmd +
                            "src/T100CRT.cpp \
                            -o T100CRT.o")

    result = subprocess.call(
                            "ar \
                            rcs \
                            T100CRT.a \
                            T100String.o \
                            T100Console.o \
                            T100CRT.o")

def clean():
    print("Cleaning ... ")
    result = subprocess.call("rm *.a")
    result = subprocess.call("rm *.o")

if __name__ == "__main__":
    args()
