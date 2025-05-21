#include "T100DynamicLibrary.h"

#include "string/T100Unicode.h"

T100DynamicLibrary::T100DynamicLibrary(T100WSTRING label) :
    m_fileName(label)
{
    //ctor
}

T100DynamicLibrary::~T100DynamicLibrary()
{
    //dtor
}

T100BOOL T100DynamicLibrary::Exists()
{

}

T100VOID T100DynamicLibrary::Load()
{
    m_module    = LoadLibrary(m_fileName.c_str());
}

T100VOID T100DynamicLibrary::Unload()
{
    FreeLibrary(m_module);
}

T100VOID* T100DynamicLibrary::Get(T100WSTRING method)
{
    FARPROC             result;
    T100STDSTRING       name;

    name    = T100Unicode::to_string8(method);

    result  = GetProcAddress(m_module, name.c_str());

    return (T100VOID*)result;
}
