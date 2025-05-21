#include "T100PluginServer.h"

#include "plugin/T100Plugin.h"

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

T100VOID T100PluginServer::Execute(T100WSTRING label)
{
    T100Plugin*     plugin      = T100NULL;

    plugin  = m_plugins[label];

    if(!plugin){
        T100Plugin*     item    = T100NEW T100Plugin(GetFileName(label));

        item->Load();

        m_plugins[label]    = item;
        plugin              = m_plugins[label];
    }

    if(!plugin){
        return;
    }


}

T100WSTRING T100PluginServer::GetFileName(T100WSTRING label)
{
    T100WSTRING     result;

    result  = L"plugins/T100ProjectPlugin" + label + L".dll";

    return result;
}
