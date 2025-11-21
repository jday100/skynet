#include "T100ProjectFile.h"

#include <io.h>

T100ProjectFile::T100ProjectFile(const T100WSTRING& filename) :
    T100XML(filename)
{
    //ctor
}

T100ProjectFile::~T100ProjectFile()
{
    //dtor
}

T100BOOL T100ProjectFile::IsExists()
{
    T100INT     result;

    result = ::_waccess(m_filename.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100ProjectFile::Check(const T100WSTRING& filename)
{

}

T100BOOL T100ProjectFile::Create()
{
    wxXmlDocument       document;
    wxXmlNode*          type    = T100NEW wxXmlNode(wxXML_DOCUMENT_TYPE_NODE, L"Project");
    wxXmlNode*          root    = T100NEW wxXmlNode(wxXML_ELEMENT_NODE, L"Project");

    document.SetDocumentNode(type);
    document.SetRoot(root);
    document.Save(m_filename);

    return T100TRUE;
}
