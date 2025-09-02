import os
import sys

g_project_path      = ""
g_project_code      = ""
g_project_include   = ""
g_project_source    = ""

g_module_label      = ""
g_module_include    = ""
g_module_source     = ""

def args():
    print("Run args...")
    count = len(sys.argv)

    if(count != 8):
        return

    global g_project_path
    global g_project_code
    global g_project_include
    global g_project_source

    global g_module_label
    global g_module_include
    global g_module_source

    g_project_path      = sys.argv[1]
    g_project_code      = sys.argv[2]
    g_project_include   = sys.argv[3]
    g_project_source    = sys.argv[4]

    g_module_label      = sys.argv[5]
    g_module_include    = sys.argv[6]
    g_module_source     = sys.argv[7]

    create_module()

    print("Success")


def create_module():
    print("Run create module...")
    create_module_include()
    create_module_source()

def create_module_include():
    print("Run create module include...")

    global g_project_path
    global g_project_code
    global g_project_include
    global g_project_source

    global g_module_label
    global g_module_include
    global g_module_source

    try:
        cmd = "%s\\%s\\%s\\%s" % (g_project_path, g_project_code, g_project_include, g_module_include)
        with open(cmd, 'w', encoding='UTF-8') as source:
            value = """
#ifndef %s_H
#define %s_H

#endif // %s_H
            """ % (g_module_label, g_module_label, g_module_label)

            source.write(value)

        print("Write OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_module_source():
    print("Run create module source...")

    global g_project_path
    global g_project_code
    global g_project_include
    global g_project_source

    global g_module_label
    global g_module_include
    global g_module_source

    try:
        cmd = "%s\\%s\\%s\\%s" % (g_project_path, g_project_code, g_project_source, g_module_source)
        with open(cmd, 'w', encoding='UTF-8') as source:
            value = """
#include "%s"
            """ % (g_module_include)

            source.write(value)
        print("Write OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

if __name__ == "__main__":
    print("Run Module Create...")
    args()
