import subprocess

if __name__ == "__main__":
    print("Making ... ")
    result = subprocess.call(
        "g++ \
        -I./include/windows/ \
        -I../../../source/T100Windows/include/ \
        main.c \
        -c \
        -g \
        -o main.o")

    result = subprocess.call(
        "ld main.o \
        -g \
        -e start_entry \
        -L ../../../source/T100Windows/ \
        -lWindows \
        -o main.exe")
