#include "T100PluginManager.h"

T100PluginManager::T100PluginManager()
{
    //ctor
}

T100PluginManager::~T100PluginManager()
{
    //dtor
}

T100VOID T100PluginManager::SetExtensionManager(T100ExtensionManager* manager)
{
    m_extensionManager      = manager;
}

T100ExtensionManager* T100PluginManager::GetExtensionManager()
{
    return m_extensionManager;
}

T100VOID T100PluginManager::Load(T100Plugin* plugin)
{
    plugin->Init(m_extensionManager);
}
