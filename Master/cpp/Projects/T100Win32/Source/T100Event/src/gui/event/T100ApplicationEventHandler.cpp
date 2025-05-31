#include "gui/event/T100ApplicationEventHandler.h"

T100ApplicationEventHandler::T100ApplicationEventHandler() :
    T100EventHandler(L"T100Application", T100NULL),
    m_messageDispatcher(),
    m_idManager(),
    m_windowClass(),
    m_systemClass()
{
    //ctor
    init();
}

T100ApplicationEventHandler::~T100ApplicationEventHandler()
{
    //dtor
    uninit();
}

T100VOID T100ApplicationEventHandler::init()
{
    m_systemClass[TEXT("button")]               = T100TRUE;
    m_systemClass[TEXT("EDIT")]                 = T100TRUE;
    m_systemClass[TEXT("SysListView32")]        = T100TRUE;
}

T100VOID T100ApplicationEventHandler::uninit()
{

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

T100IDManager& T100ApplicationEventHandler::GetIDManager()
{
    return m_idManager;
}

T100WindowMessageDispatcher& T100ApplicationEventHandler::GetWindowMessageDispatcher()
{
    return m_messageDispatcher;
}

T100BOOL T100ApplicationEventHandler::IsRegistered(T100WSTRING type)
{
    T100BOOL    result  = T100FALSE;

    result  = m_systemClass[type];

    if(result){
        return result;
    }else{

    }

    result  = m_windowClass[type];

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
