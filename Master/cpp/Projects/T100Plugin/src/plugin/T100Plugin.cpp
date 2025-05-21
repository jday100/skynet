#include "T100Plugin.h"

#include "dynamiclibrary/T100DynamicLibrary.h"

T100Plugin::T100Plugin(T100WSTRING label) :
    T100Class(),
    m_label(label)
{
    //ctor
}

T100Plugin::~T100Plugin()
{
    //dtor
}

T100VOID T100Plugin::Load()
{
    m_library       = T100NEW T100DynamicLibrary(m_label);

    m_library->Load();

    void(*method)()     = (void(*)())m_library->Get(L"PluginInit");

    method();

}

T100VOID T100Plugin::Unload()
{
    m_library->Unload();
    T100SAFE_DELETE m_library;
}
