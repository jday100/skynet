import os
import sys
import subprocess

g_project_path      = ""
g_compiler_path     = ""

g_project_build             = ""
g_project_code              = ""
g_project_include           = ""
g_project_source            = ""
g_project_build_filename    = ""

def args():
    print("Run args...")
    count = len(sys.argv)

    if(count != 9):
        return

    global g_project_path
    global g_compiler_path

    global g_project_build
    global g_project_code
    global g_project_include
    global g_project_source
    global g_project_build_filename

    value               = sys.argv[1]
    g_project_path      = sys.argv[2]
    g_compiler_path     = sys.argv[3]

    g_project_build             = sys.argv[4]
    g_project_code              = sys.argv[5]
    g_project_include           = sys.argv[6]
    g_project_source            = sys.argv[7]
    g_project_build_filename    = sys.argv[8]

    match value:
        case 'build':
            build()
        case 'clean':
            clean()
        case 'rebuild':
            rebuild()


def build():
    print("Run project build...")

    global g_project_path
    global g_compiler_path

    global g_project_build
    global g_project_code
    global g_project_include
    global g_project_source
    global g_project_build_filename

    bin     = "%s\\g++ -c -I%s\\%s\\%s" % (g_compiler_path, g_project_path, g_project_code, g_project_include)
    source  = "%s\\%s\\%s\\" % (g_project_path, g_project_code, g_project_source)
    target  = "%s\\%s\\" % (g_project_path, g_project_build)
    link    = ""

    cmd     = "%s %s%s.cpp -o %s%s.o" % (bin, source, "T100HardDisplay", target, "T100HardDisplay")

    print(cmd)

    subprocess.call(cmd)

    cmd     = "%s %s%s.cpp -o %s%s.o" % (bin, source, "T100HardSystem", target, "T100HardSystem")

    print(cmd)

    subprocess.call(cmd)

    print("Success")

def clean():
    print("Run project clean...")
    global g_project_path
    global g_project_build
    global g_project_build_filename

    cmd 	= "cmd.exe /c del /q %s\\%s\\%s" % (g_project_path, g_project_build, g_project_build_filename)

    print(cmd)

    subprocess.call(cmd)

    print("Success")

def rebuild():
    print("Run project rebuild...")
    clean()
    build()

if __name__ == "__main__":
    print("Run project build...")
    args()
