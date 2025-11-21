#include "T100DynamicLibrary.h"

#include "string/T100Unicode.h"

namespace T100WINDOWS{

T100DynamicLibrary::T100DynamicLibrary(const T100WSTRING& filename) :
    T100Class(),
    m_filename(filename)
{
    //ctor
}

T100DynamicLibrary::~T100DynamicLibrary()
{
    //dtor
}

T100VOID T100DynamicLibrary::Load()
{
    m_module    = LoadLibrary(m_filename.c_str());
}

T100VOID T100DynamicLibrary::Unload()
{
    FreeLibrary(m_module);
}

T100VOID* T100DynamicLibrary::GetMethod(const T100WSTRING& method)
{
    FARPROC             result;
    T100STDSTRING       name;

    name        = T100Unicode::ToString8(method);

    result      = GetProcAddress(m_module, name.c_str());

    return (T100VOID*)result;
}

}
