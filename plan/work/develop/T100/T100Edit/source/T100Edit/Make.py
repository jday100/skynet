import subprocess

if __name__ == "__main__":
    print ("Hello world!")

    result = subprocess.call(["g++", "-I./include/edit/", "-c", "src/edit/T100Edit.cpp", "-o", "src/edit/T100Edit.o"])
    result = subprocess.call(["g++", "-I./include/edit/", "-I/mingw64/include/", "-c", "src/edit/T100View.cpp", "-o", "src/edit/T100View.o"])
    #result = subprocess.call(["g++", "-I./include/edit/", "-c", "src/edit/T100Menu.cpp", "-o", "src/edit/T100Menu.o"])
    result = subprocess.call("g++ -I./include/edit -Wwrite-strings -c src/edit/T100Menu.cpp -o src/edit/T100Menu.o");
    result = subprocess.call(["g++", "-I./include/edit/", "-c", "src/main.c", "-o", "src/main.o"])

    result = subprocess.call(
        "g++ -I./include/edit/ -c src/edit/T100File.cpp \
        -o src/edit/T100File.o");

    #result = subprocess.call(["g++", "src/edit/T100Edit.o", "src/edit/T100View.o", "src/edit/T100Menu.o", "src/main.o", "-l/mingw64/bin/libncursesw6.dll", "-o", "T100Edit.exe"]);

    #result = subprocess.call("g++ src/edit/T100Edit.o src/edit/T100View.o src/edit/T100Menu.o src/main.o -L/mingw64/lib/ -lncurses /mingw64/lib/libncurses.a -o T100Edit.exe")
    result = subprocess.call(
        "g++ src/edit/T100Edit.o \
        src/edit/T100View.o \
        src/edit/T100Menu.o \
        src/edit/T100File.o \
        src/main.o \
        -L/mingw64/lib/ -lncursesw -lmenuw \
        -o T100Edit.exe")

