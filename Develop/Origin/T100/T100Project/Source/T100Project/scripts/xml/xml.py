import xml.dom.minidom

def create_xml():
    print("Create xml...")

    xml = minidom.Document()
    root = xml.createElement("aaa")
    xml.writexml()
