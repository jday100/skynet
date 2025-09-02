import os
import sys
import subprocess

g_project_path      = ""
g_compiler_path     = ""

g_project_code      = ""
g_project_include   = ""
g_project_source    = ""

def args():
    print("Run args...")
    count = len(sys.argv)

    if(count != 7):
        return

    global g_project_path
    global g_compiler_path

    global g_project_code
    global g_project_include
    global g_project_source

    value               = sys.argv[1]
    g_project_path      = sys.argv[2]
    g_compiler_path     = sys.argv[3]

    g_project_code      = sys.argv[4]
    g_project_include   = sys.argv[5]
    g_project_source    = sys.argv[6]

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

    global g_project_code
    global g_project_include
    global g_project_source

    bin     = "g++ -I%s\\%s\\%s" % (g_project_path, g_project_code, g_project_include)

    line    = "%s\\%s\\%s\\" % (g_project_path, g_project_code, g_project_source)

    cmd     = "%s %s" % (bin, line)

    print(cmd)

    subprocess.call(cmd)

    print("Success")

def clean():
    print("Run project clean...")

def rebuild():
    print("Run project rebuild...")
    clean()
    build()

if __name__ == "__main__":
    print("Run project build...")
    args()
