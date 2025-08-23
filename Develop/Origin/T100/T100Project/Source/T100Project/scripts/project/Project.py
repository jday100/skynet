import os
import sys

from xml.dom import minidom

def args():
    print("Args...")
    count = len(sys.argv)

    match count:
        case 2:
            value = sys.argv[1]
            create_project(value)


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

    try:
        with open("xml.xml", 'w', encoding='UTF-8') as xmlfile:
            xml.writexml(xmlfile, indent='', addindent='\t', newl='\n', encoding='UTF-8')
        print("OK")
    except Exception as err:
        print("Error:{err}".format(err=err))

def create_project_make():
    print("Create project make...")


if __name__ == "__main__":
    print("Main...")
    args()
