#include "T100ProjectFile.h"

T100ProjectFile::T100ProjectFile(const T100WSTRING& path) :
    T100XML(path)
{
    //ctor
}

T100ProjectFile::~T100ProjectFile()
{
    //dtor
}

T100BOOL T100ProjectFile::Check()
{
    wxXmlDocument       document;

    if(document.Load(m_path)){

    }else{
        return T100FALSE;
    }

    wxXmlNode*      root    = document.GetRoot();

    if(root && root->GetName() == L"Project"){

    }else{
        return T100FALSE;
    }
    return T100TRUE;
}
