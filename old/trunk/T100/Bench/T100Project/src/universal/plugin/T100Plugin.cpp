#include "T100Plugin.h"

T100Plugin::T100Plugin()
{
    //ctor
}

T100Plugin::~T100Plugin()
{
    //dtor
}

T100ExtensionManager* T100Plugin::GetExtensionManager()
{
    return m_extensionManager;
}

T100VOID T100Plugin::Init(T100ExtensionManager* manager)
{
    m_extensionManager      = manager;
}
