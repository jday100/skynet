#include "T100PluginApplication.h"

T100PluginApplication::T100PluginApplication() :
    T100Win32Application(),
    m_server()
{
    //ctor
}

T100PluginApplication::~T100PluginApplication()
{
    //dtor
}

T100VOID T100PluginApplication::Create()
{
    m_server.Start();

    m_server.Execute(L"Start");
}

T100VOID T100PluginApplication::Destroy()
{
    m_server.Stop();
}

