#include "T100ExtensionManager.h"

T100ExtensionManager::T100ExtensionManager() :
    m_extensions()
{
    //ctor
}

T100ExtensionManager::~T100ExtensionManager()
{
    //dtor
}

T100VOID T100ExtensionManager::Create(const T100WSTRING& label, T100Extension* extension)
{
    m_extensions.Append(label, extension);
}

T100VOID T100ExtensionManager::Destroy(const T100WSTRING& label)
{
    m_extensions.Remove(label);
}

T100Extension* T100ExtensionManager::Find(const T100WSTRING& label)
{
    return m_extensions[label];
}
