import subprocess

def make():
    print("Making ... ")
    result = subprocess.call(
        "g++ \
        -c \
        -I./include/ \
        -I../../../T100Library/source/T100Library/include/ \
        src/host/base/T100HostBase.cpp \
        -o T100HostBase.o")
    result = subprocess.call(
        "ar \
        rcs \
        T100Host.a \
        T100HostBase.o")


if __name__ == "__main__":
    print("Main ... ")
    make()

