#include "T100PluginServer.h"

namespace T100UNIVERSAL{

T100PluginServer::T100PluginServer() :
    T100Class(),
    m_plugins()
{
    //ctor
}

T100PluginServer::~T100PluginServer()
{
    //dtor
}

T100VOID T100PluginServer::Start()
{

}

T100VOID T100PluginServer::Stop()
{

}

T100VOID T100PluginServer::Load(const T100WSTRING& label)
{
    T100Plugin*     plugin  = T100NEW T100Plugin(GetFileName(label));

    plugin->Load();

    m_plugins[label]    = plugin;
}

T100VOID* T100PluginServer::GetMethod(const T100WSTRING& label, const T100WSTRING& method)
{
    T100Plugin*     plugin      = T100NULL;

    plugin  = m_plugins[label];

    if(!plugin){
        return T100NULL;
    }

    return plugin->GetMethod(method);
}

T100WSTRING T100PluginServer::GetFileName(const T100WSTRING& label)
{
    T100WSTRING         result;

    result  = L"../plugins/T100ProjectPlugin" + label + L".dll";

    return result;
}

}
