#include "T100XML.h"

T100XML::T100XML(const T100WSTRING& path) :
    m_path(path)
{
    //ctor
}

T100XML::~T100XML()
{
    //dtor
}

T100VOID T100XML::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100XML::GetPath()
{
    return m_path;
}

T100BOOL T100XML::IsExists()
{
    T100INT         result;

    result  = ::_waccess(m_path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }
    return T100FALSE;
}
