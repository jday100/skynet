#include "T100Library.h"

#include <dlfcn.h>
#include "T100Unicode.h"


T100Library::T100Library(T100WSTRING name)
    :T100File(name)
{
    //ctor
}

T100Library::~T100Library()
{
    //dtor
}

T100BOOL T100Library::load()
{
    T100WSTRING         source;
    T100STDSTRING       target;
    int                 result;
    int                 mode;

    source  = getName();
    target  = T100Unicode::to_string8(source);

    mode    = RTLD_LAZY;

    m_handle = dlopen(target.c_str(), mode);

    if(!m_handle){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100Library::unload()
{
    T100BOOL        result;

    result  = dlclose(m_handle);

    if(-1 == result){
        return T100FALSE;
    }

    return T100FALSE;
}

T100VOID* T100Library::getMethod(T100WSTRING name)
{
    T100VOID*           result      = T100NULL;
    T100STDSTRING       target;

    target = T100Unicode::to_string8(name);

    result = dlsym(m_handle, target.c_str());

    return result;
}
