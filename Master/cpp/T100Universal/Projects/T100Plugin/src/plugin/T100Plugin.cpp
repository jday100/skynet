#include "T100Plugin.h"

namespace T100UNIVERSAL{

T100Plugin::T100Plugin(const T100WSTRING& filename) :
    T100Class(),
    m_library(filename)
{
    //ctor
}

T100Plugin::~T100Plugin()
{
    //dtor
}

T100VOID T100Plugin::Load()
{
    m_library.Load();

    //void(*method)()     = (void(*)())m_library.GetMethod(L"PluginInit");

    //method();
}

T100VOID T100Plugin::Unload()
{
    m_library.Unload();
}

T100VOID* T100Plugin::GetMethod(const T100WSTRING& method)
{
    return m_library.GetMethod(method);
}

}
