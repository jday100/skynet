import os
import sys
import subprocess

def args():
    print("Args ... ")
    count = len(sys.argv)

    match count:
        case 1:
            make()
        case 2:
            value = sys.argv[1];
            match value:
                case 'clean':
                    clean()
                case 'rebuild':
                    rebuild()

def make():
    print("Making ... ")

    os.chdir("Source/T100CRT")
    result = os.system("python3 ./Make.py")

    os.chdir(root)

    os.chdir("Sample/main")
    result = os.system("python3 ./Make.py")

def clean():
    print("Cleaning ... ")

    os.chdir("Source/T100CRT")
    result = os.system("python3 ./Make.py clean")

    os.chdir(root)

    os.chdir("Sample/main")
    result = os.system("python3 ./Make.py clean")

def rebuild():
    clean()
    make()

if __name__ == "__main__":
    root = os.getcwd()
    args()
