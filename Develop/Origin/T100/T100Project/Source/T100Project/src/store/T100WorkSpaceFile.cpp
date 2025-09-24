#include "T100WorkSpaceFile.h"

T100WorkSpaceFile::T100WorkSpaceFile(const T100WSTRING& path) :
    T100XML(path)
{
    //ctor
}

T100WorkSpaceFile::~T100WorkSpaceFile()
{
    //dtor
}

T100BOOL T100WorkSpaceFile::Load(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    wxXmlDocument       document;
    if(!document.Load(m_path)){
        return T100FALSE;
    }

    wxXmlNode*      root        = document.GetRoot();

    if(!root){
        return T100FALSE;
    }

    if(root->GetName() == L"WorkSpace"){

    }else{
        return T100FALSE;
    }

    wxXmlNode*      node        = root->GetChildren();

    while(node){
        if(node->GetName() == L"Compiler"){
            info->SetCompilerPath(node->GetAttribute(L"Path").ToStdWstring());
        }else if(node->GetName() == L"Python"){
            info->SetPythonFile(node->GetAttribute(L"File").ToStdWstring());
        }

        node = node->GetNext();
    }

    return T100TRUE;
}

T100BOOL T100WorkSpaceFile::Save(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    wxXmlDocument       document;
    wxXmlNode*          root        = T100NEW wxXmlNode(wxXML_ELEMENT_NODE, L"WorkSpace");

    wxXmlNode*          compiler    = T100NEW wxXmlNode(root, wxXML_ELEMENT_NODE, L"Compiler");

    compiler->AddAttribute(L"Path", info->GetCompilerPath());

    wxXmlNode*          python      = T100NEW wxXmlNode(root, wxXML_ELEMENT_NODE, L"Python");

    python->AddAttribute(L"File", info->GetPythonFile());

    document.SetRoot(root);
    return document.Save(m_path);
}
