import os
import sys

from xml.dom import minidom


g_project_path      = ""
g_project_exec      = ""
g_project_python    = ""

def args():
    print("Args...")
    count = len(sys.argv)

    match count:
        case 2:
            global g_project_path
            g_project_path = sys.argv[1]
            create_project(g_project_path)


def create_project(path):
    print("CreateProject...")

    if os.path.exists(path):
        print("Dir exists")
    else:
        print("Dir not exists")
        os.mkdir(path)
        os.mkdir(path + "/include")
        os.mkdir(path + "/src")

        create_project_file()
        create_project_make()

def create_project_file():
    print("Create project file...")
    xml = minidom.Document()
    root = xml.createElement("aaa")

    global g_project_path

    try:
        with open(g_project_path + "/" + "xml.xml", 'w', encoding='UTF-8') as xmlfile:
            xml.writexml(xmlfile, indent='', addindent='\t', newl='\n', encoding='UTF-8')
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_project_make():
    print("Create project make...")

    global g_project_path

    try:
        with open(g_project_path + "/" + "Make.py", 'w', encoding='UTF-8') as makefile:
            makefile.write("")
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

if __name__ == "__main__":
    print("Main...")
    args()
