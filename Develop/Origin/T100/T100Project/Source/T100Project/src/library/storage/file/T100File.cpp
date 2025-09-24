#include "T100File.h"

#include <io.h>

T100File::T100File(const T100WSTRING& path) :
    m_path(path)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100VOID T100File::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100File::GetPath()
{
    return m_path;
}

T100BOOL T100File::IsExists()
{
    T100INT         result;

    result  = ::_waccess(m_path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }
    return T100FALSE;
}
