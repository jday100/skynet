import os
import sys

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
    global g_project_makefile

    try:
        cmd = "%s\\%s" % (g_project_path, g_project_makefile)
        with open(cmd, 'w', encoding='UTF-8') as makefile:
            makefile.write("""
import os
import sys
import subprocess

g_gcc_path  		= "C:\\\\zoo\\\\bin\\\\CodeBlocks\\\\MinGW\\\\bin"
g_project_path 		= "C:\\\\vm\\\\Hello"

def args():
	print("Args...")
	count = len(sys.argv)

	match count:
		case 2:
			value = sys.argv[1]
			match value:
				case 'build':
					build()
				case 'clean':
					clean()
				case 'rebuild':
					rebuild()

def build():
	print("Build...")

	global g_gcc_path
	global g_project_path

	cmd = "g++ -I%s\\\\source\\\\include" % (g_project_path)

	print(cmd)

	line = "%s\\\\%s %s\\\\source\\\\src\\\\Hello.cpp -o %s\\\\build\\\\main.exe" % (g_gcc_path, cmd, g_project_path, g_project_path)

	print(line)

	subprocess.call(line)

	print("Success")

def clean():
	print("Clean...")

def rebuild():
	print("Rebuild...")
	clean()
	build()

if __name__ == "__main__":
    print("Main...")
    args()
            """)
        print("Write OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

if __name__ == "__main__":
    print("Run Project Create...")
    args()
