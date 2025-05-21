#include "T100Win32ApplicationBase.h"

T100Win32ApplicationBase::T100Win32ApplicationBase() :
    T100ApplicationEventHandler(),
    m_messageDispatcher()
{
    //ctor
}

T100Win32ApplicationBase::~T100Win32ApplicationBase()
{
    //dtor
}

T100VOID T100Win32ApplicationBase::SetThisInstance(HINSTANCE instance)
{
    m_thisInstance  = instance;
}

HINSTANCE T100Win32ApplicationBase::GetThisInstance()
{
    return m_thisInstance;
}

T100VOID T100Win32ApplicationBase::SetFrame(T100Frame* frame)
{
    m_framePtr  = frame;
}

T100Frame* T100Win32ApplicationBase::GetFramePtr()
{
    return m_framePtr;
}

T100WindowMessageDispatcher& T100Win32ApplicationBase::GetWindowMessageDispatcher()
{
    return m_messageDispatcher;
}

T100BOOL T100Win32ApplicationBase::RegisterWindowClass(T100WSTRING type)
{
    T100BOOL    result  = m_windowClass[type];

    if(!result){
        m_windowClass[type]     = T100TRUE;
    }

    return !result;
}
