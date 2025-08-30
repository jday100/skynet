import os
import sys

g_project_path      = ""
g_module_label      = ""

def args():
    print("Args...")
    count = len(sys.argv)

    match count:
        case 3:
            global g_project_path
            global g_module_label

            g_project_path  = sys.argv[1]
            g_module_label  = sys.argv[2]
            create_module()


def create_module():
    print("CreateModule...")
    create_module_include()
    create_module_source()

def create_module_include():
    print("Create module include...")

    global g_project_path
    global g_module_label

    try:
        with open(g_project_path + "/include/" + g_module_label + ".h", 'w', encoding='UTF-8') as source:
            source.write("""
            """)
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_module_source():
    print("Create module source...")

    global g_project_path
    global g_module_label

    try:
        with open(g_project_path + "/src/" + g_module_label + ".cpp", 'w', encoding='UTF-8') as source:
            source.write("""
            """)
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

if __name__ == "__main__":
    print("Main...")
    args()
