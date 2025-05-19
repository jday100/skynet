#include "gui/event/T100ApplicationEventHandler.h"

T100ApplicationEventHandler::T100ApplicationEventHandler() :
    T100EventHandler(L"T100Application", T100NULL),
    m_messageDispatcher()
{
    //ctor
}

T100ApplicationEventHandler::~T100ApplicationEventHandler()
{
    //dtor
}

T100VOID T100ApplicationEventHandler::SetThisInstance(HINSTANCE instance)
{
    m_thisInstance  = instance;
}

HINSTANCE T100ApplicationEventHandler::GetThisInstance()
{
    return m_thisInstance;
}

T100VOID T100ApplicationEventHandler::SetFrame(T100Frame* frame)
{
    m_framePtr  = frame;
}

T100Frame* T100ApplicationEventHandler::GetFramePtr()
{
    return m_framePtr;
}

T100WindowMessageDispatcher& T100ApplicationEventHandler::GetWindowMessageDispatcher()
{
    return m_messageDispatcher;
}

T100BOOL T100ApplicationEventHandler::IsRegistered(T100WSTRING type)
{
    T100BOOL    result  = m_windowClass[type];

    return result;
}

T100BOOL T100ApplicationEventHandler::RegisterWindowClass(T100WSTRING type)
{
    T100BOOL    result  = m_windowClass[type];

    if(!result){
        m_windowClass[type]     = T100TRUE;
    }

    return !result;
}
