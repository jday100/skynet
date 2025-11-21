import subprocess

def make():
    print("Making ... ")
    result = subprocess.call(
        "g++ \
        -c \
        -I./include/ \
        -I../../../T100Library/source/T100Library/include/ \
        src/vm/win64/T100VMWin64.cpp \
        -o T100VMWin64.o")
    result = subprocess.call(
        "ar \
        rcs \
        T100Win64.a \
        T100VMWin64.o")


if __name__ == "__main__":
    print("Main ... ")
    make()
