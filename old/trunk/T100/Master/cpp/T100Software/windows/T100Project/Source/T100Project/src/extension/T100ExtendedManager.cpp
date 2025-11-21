#include "T100ExtendedManager.h"

#include "T100AllExtensions.h"

T100ExtendedManager::T100ExtendedManager() :
    m_extensions()
{
    //ctor
}

T100ExtendedManager::~T100ExtendedManager()
{
    //dtor
}

T100VOID T100ExtendedManager::SignIn(const T100WSTRING& label, T100Extension* extension)
{
    m_extensions[label]     = extension;
}

T100VOID T100ExtendedManager::SignOut(const T100WSTRING& label)
{
    m_extensions.erase(label);
}

T100VOID T100ExtendedManager::Append(const T100WSTRING& parent, T100UINT type, const T100WSTRING& label)
{
    T100MenuExtension*          extension;

    extension   = dynamic_cast<T100MenuExtension*>(m_extensions[parent]);

    if(extension){
        extension->Append(type, label);
    }
}

T100VOID T100ExtendedManager::Bind(const T100WSTRING& label, T100UINT type, T100EventHandler* handler, T100EVENT_FUNCTION call, T100EventHandler* data)
{
    handler->Connect(type, call, data);
}

T100VOID T100ExtendedManager::ConnectMenu(const T100WSTRING& label, T100UINT id, T100EventHandler* handler, T100EVENT_FUNCTION call, T100EventHandler* data)
{
    T100MenuExtension*          extension;

    extension   = dynamic_cast<T100MenuExtension*>(m_extensions[label]);

    if(extension){
        extension->ConnectMenu(id, handler, call, data);
        handler->ConnectMenu(id, call, data);
    }else{
        extension   = T100NEW T100MenuExtension();

        SignIn(label, extension);

        handler->ConnectMenu(id, call, data);
        extension->ConnectMenu(id, handler, call, data);
    }
}

T100VOID T100ExtendedManager::SendMenu(const T100WSTRING& label, T100MenuEvent& event)
{
    T100MenuExtension*          extension;

    extension   = dynamic_cast<T100MenuExtension*>(m_extensions[label]);

    if(extension){
        extension->SendEvent(&event);
    }
}

T100VOID T100ExtendedManager::FindMenu(const T100WSTRING& label, T100MenuEvent& event)
{
    T100MenuExtension*          extension;

    extension   = dynamic_cast<T100MenuExtension*>(m_extensions[label]);

    if(extension){
        extension->FindEvent(event);
    }
}

T100VOID T100ExtendedManager::SendEvent(const T100WSTRING& label, T100Event& event)
{
    T100WindowExtension*        extension;

    extension   = dynamic_cast<T100WindowExtension*>(m_extensions[label]);

    if(extension){
        extension->SendEvent(&event);
    }
}

T100VOID T100ExtendedManager::Connect(const T100WSTRING& label, T100VOID* value)
{
    T100WindowExtension*          extension;

    extension   = dynamic_cast<T100WindowExtension*>(m_extensions[label]);

    if(extension){
        extension->Connect(value);
    }
}
