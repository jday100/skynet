#include "T100PSVMFile.h"

T100PSVMFile::T100PSVMFile(T100STRING file) :
    T100File(file)
{
    //ctor
}

T100PSVMFile::~T100PSVMFile()
{
    //dtor
}

T100BOOL T100PSVMFile::Load(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    wxXmlDocument       document;

    if(!document.Load(m_path)){
        return T100FALSE;
    }

    wxXmlNode*      root    = document.GetRoot();

    if(!root){
        return T100FALSE;
    }

    if(root->GetName() != "PSVM"){
        return T100FALSE;
    }

    wxXmlNode*      node    = root->GetChildren();

    while(node){
        T100STRING      name    = node->GetName().ToStdString();
        if(name == "firmware"){
            info->m_firmware    = node->GetAttribute("File").ToStdString();
        }

        node    = node->GetNext();
    }

    return T100TRUE;
}

T100BOOL T100PSVMFile::Save(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    wxXmlDocument       document;

    wxXmlNode*          root    = T100NEW wxXmlNode(wxXML_ELEMENT_NODE, "PSVM");

    wxXmlNode*          firmware    = T100NEW wxXmlNode(root, wxXML_ELEMENT_NODE, "firmware");

    firmware->AddAttribute("File", info->m_firmware);

    document.SetRoot(root);

    if(!document.Save(m_path)){
        return T100FALSE;
    }

    return T100TRUE;
}
