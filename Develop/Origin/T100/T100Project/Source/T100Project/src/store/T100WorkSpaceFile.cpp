#include "T100WorkSpaceFile.h"

#include <io.h>

T100WorkSpaceFile::T100WorkSpaceFile(const T100WSTRING& filename) :
    T100XML(filename),
    m_filename(filename)
{
    //ctor
}

T100WorkSpaceFile::~T100WorkSpaceFile()
{
    //dtor
}

T100BOOL T100WorkSpaceFile::IsExists()
{
    T100INT     result;

    result = ::_waccess(m_filename.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100WorkSpaceFile::Load(T100WorkSpaceInfo* info)
{
    wxXmlDocument       document;

    if(!document.Load(m_filename)){
        return T100FALSE;
    }

    wxXmlNode*      root    = document.GetRoot();

    if(!root){
        return T100FALSE;
    }

    if(root->GetName() == L"WorkSpace"){

    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100VOID T100WorkSpaceFile::Save(T100WorkSpaceInfo* info)
{
    wxXmlDocument       document;
    wxXmlNode*          type    = T100NEW wxXmlNode(wxXML_DOCUMENT_TYPE_NODE, L"WorkSpace");
    wxXmlNode*          root    = T100NEW wxXmlNode(wxXML_ELEMENT_NODE, L"WorkSpace");

    document.SetDocumentNode(type);
    document.SetRoot(root);
    document.Save(m_filename);
}
