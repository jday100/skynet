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
        os.mkdir(path + "\\build")
        os.mkdir(path + "\\source")
        os.mkdir(path + "\\source\\include")
        os.mkdir(path + "\\source\\src")

        create_project_file()
        create_project_make()

        print("Success")

def create_project_file():
    print("Create project file...")
    xml = minidom.Document()
    root = xml.documentElement
    project = xml.createElement("project")
    xml.appendChild(project)

    global g_project_path

    try:
        with open(g_project_path + "/" + "project.xml", 'w', encoding='UTF-8') as xmlfile:
            xml.writexml(xmlfile, indent='', addindent='\t', newl='\n', encoding='UTF-8')
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_project_make():
    print("Create project make...")

    global g_project_path

    try:
        with open(g_project_path + "/" + "Make.py", 'w', encoding='UTF-8') as makefile:
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

	cmd = "g++             -c             -I%s\\\\source\\\\include" % (g_project_path)

	print(cmd)

	line = "%s\\\\%s %s\\\\source\\\\src\\\\Hello.cpp -o %s\\\\build\\\\main.o" % (g_gcc_path, cmd, g_project_path, g_project_path)

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
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

if __name__ == "__main__":
    print("Main...")
    args()
