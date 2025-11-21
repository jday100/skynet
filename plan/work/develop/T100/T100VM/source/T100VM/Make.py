import subprocess

def make():
    print("Making ... ")
    cmd =   "g++ \
            --verbose \
            -c \
            -I ../../../T100Library/source/T100Library/include/  \
            -I C:/zoo/lib/wxWidgets-3.0.5/include/ \
            -I C:/zoo/lib/wxWidgets-3.0.5/lib/gcc_dll/mswu/ \
            -I ./include/ "

    result = subprocess.call(cmd +
                            "src/vm/T100VM.cpp \
                            -o T100VM.o")

    result = subprocess.call(cmd +
                            "T100VMApp.cpp \
                            -o T100VMApp.o")

    result = subprocess.call(cmd +
                            "T100VMMain.cpp \
                            -o T100VMMain.o")

    result = subprocess.call(
                            "g++ \
                            T100VM.o \
                            T100VMApp.o \
                            T100VMMain.o \
                            -L C:/zoo/lib/wxWidgets-3.0.5/lib/gcc_dll/ \
                            C:/zoo/lib/wxWidgets-3.0.5/lib/gcc_dll/wxmsw30ud_gcc_custom.dll \
                            -o T100VM.exe")


    """
    result = subprocess.call(
        "g++ \
        -c \
        -I./include/ \
        -I../../../T100Library/source/T100Library/include/ \
        src/vm/T100VM.cpp \
        -o T100VM.o")

    result = subprocess.call(
        "g++ \
        T100VM.o \
        -lwin64 \
        -o T100VM.exe")


    result = subprocess.call(
        "g++ \
        -I./include/ \
        -I../../../T100Library/source/T100Library/include/ \
        -L/mingw64/lib/ \
        -lgdi32 -luser32 -lkernel32 -lcomctl32 \
        src/vm/T100VM.cpp \
        -o T100VM.exe")
    """

if __name__ == "__main__":
    print("Main ... ")
    make()
