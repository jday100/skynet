#include "T100ExtensionServer.h"

namespace T100UNIVERSAL{

T100ExtensionServer::T100ExtensionServer() :
    T100Class(),
    m_extensions()
{
    //ctor
}

T100ExtensionServer::~T100ExtensionServer()
{
    //dtor
}

T100VOID T100ExtensionServer::Start()
{

}

T100VOID T100ExtensionServer::Stop()
{

}

T100VOID T100ExtensionServer::CreateExtension(const T100WSTRING& label, T100Extension* extension)
{
    m_extensions.Append(label, extension);
}

T100VOID T100ExtensionServer::DestroyExtension(const T100WSTRING& label)
{
    m_extensions.Remove(label);
}

T100Extension* T100ExtensionServer::Find(const T100WSTRING& label)
{
    return m_extensions[label];
}

}
