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

T100VOID T100PluginServer::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100PluginServer::GetPath()
{
    return m_path;
}

T100VOID T100PluginServer::SetPrefix(const T100WSTRING& prefix)
{
    m_prefix    = prefix;
}

const T100WSTRING& T100PluginServer::GetPrefix()
{
    return m_prefix;
}

T100VOID T100PluginServer::SetSuffix(const T100WSTRING& suffix)
{
    m_suffix    = suffix;
}

const T100WSTRING& T100PluginServer::GetSuffix()
{
    return m_suffix;
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

    //result  = L"../plugins/T100ProjectPlugin" + label + L".dll";

    result  = m_path + m_prefix + label + m_suffix;

    return result;
}

}
