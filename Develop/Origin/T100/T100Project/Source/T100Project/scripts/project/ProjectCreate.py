import os
import sys
import shutil

from xml.dom import minidom

g_project_path      = ""
g_project_exec      = ""
g_project_python    = ""

g_project_build     = ""
g_project_code      = ""
g_project_include   = ""
g_project_source    = ""

g_project_filename  = "project.xml"
g_project_makefile  = "make.py"

def args():
    print("Run args...")
    count = len(sys.argv)

    if(count != 10):
        return

    global g_project_path
    global g_project_exec
    global g_project_python

    g_project_path      = sys.argv[1]
    g_project_exec      = sys.argv[2]
    g_project_python    = sys.argv[3]

    global g_project_build
    global g_project_code
    global g_project_include
    global g_project_source

    g_project_build     = sys.argv[4]
    g_project_code      = sys.argv[5]
    g_project_include   = sys.argv[6]
    g_project_source    = sys.argv[7]

    global g_project_filename
    global g_project_makefile

    g_project_filename  = sys.argv[8]
    g_project_makefile  = sys.argv[9]

    create_project()

def create_project():
    print("Run create project...")
    global g_project_path

    global g_project_build
    global g_project_code
    global g_project_include
    global g_project_source

    global g_project_filename
    global g_project_makefile

    if os.path.exists(g_project_path):
        print("Project exists");
        print("Return1")
        return
    else:
        print("Project not exists")
        os.mkdir(g_project_path)

        cmdb = "%s\\%s" % (g_project_path, g_project_build)
        os.mkdir(cmdb)

        cmdc = "%s\\%s" % (g_project_path, g_project_code)
        os.mkdir(cmdc)

        cmdi = "%s\\%s" % (cmdc, g_project_include)
        os.mkdir(cmdi)

        cmds = "%s\\%s" % (cmdc, g_project_source)
        os.mkdir(cmds)

        create_project_file()
        create_project_make()
        create_project_main()

        print("Success")

def create_project_file():
    print("Run create project file...")

    xml     = minidom.Document()

    project = xml.createElement("Project")

    xml.appendChild(project)

    global g_project_path
    global g_project_filename

    try:
        cmd = "%s\\%s" % (g_project_path, g_project_filename)
        with open(cmd, 'w', encoding='UTF-8') as xmlfile:
            xml.writexml(xmlfile, indent='', addindent='\t', newl='\n', encoding='UTF-8')
        print("Write OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_project_make():
    print("Run create project make...")

    global g_project_path
    global g_project_exec
    global g_project_makefile

    try:
        source  = "%s\\scripts\\project\\ProjectBuild.py" % (g_project_exec)
        target  = "%s\\%s" % (g_project_path, g_project_makefile)

        cmd = "copy %s %s" % (source, target)

        shutil.copy(source, target)

        print("Write OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_project_main():
    print("Run create project main...")

    global g_project_path
    global g_project_code
    global g_project_source

    try:
        cmd = "%s\\%s\\%s\\%s" % (g_project_path, g_project_code, g_project_source, "main.cpp")
        with open(cmd, 'w', encoding='UTF-8') as source:
            source.write("""
#include <iostream>

using namespace std;

int WinMain()
{
    cout << "Hello world!" << endl;
    return 0;
}
            """)
        print("Write OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

if __name__ == "__main__":
    print("Run Project Create...")
    args()

