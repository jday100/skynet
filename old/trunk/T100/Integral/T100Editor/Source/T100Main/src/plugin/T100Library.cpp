#include "T100Library.h"

#include <libloaderapi.h>

T100Library::T100Library(T100WSTRING path) :
    T100File(path)
{
    //ctor
}

T100Library::~T100Library()
{
    //dtor
}

T100BOOL T100Library::Load()
{
    m_module    = LoadLibraryW(m_path.c_str());

    if(!m_module){
        return T100FALSE;
    }
    return T100TRUE;
}

FARPROC T100Library::GetProcedure(T100STRING value)
{
    return GetProcAddress(m_module, value.c_str());
}
