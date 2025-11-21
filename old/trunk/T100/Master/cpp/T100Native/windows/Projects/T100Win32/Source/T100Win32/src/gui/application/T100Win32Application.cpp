#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100Win32Application::T100Win32Application() :
    T100EventHandler(),
    m_idManager(),
    m_dispatcher(),
    m_windowClass(),
    m_systemClass()
{
    //ctor
    init();
}

T100Win32Application::~T100Win32Application()
{
    //dtor
    uninit();
}

T100VOID T100Win32Application::init()
{
    m_systemClass[TEXT("button")]               = T100TRUE;
    m_systemClass[TEXT("edit")]                 = T100TRUE;
    m_systemClass[TEXT("SysListView32")]        = T100TRUE;
    m_systemClass[TEXT("SysTreeView32")]        = T100TRUE;
}

T100VOID T100Win32Application::uninit()
{

}

T100VOID T100Win32Application::Create()
{
    if(!m_frame){
        m_frame     = T100NEW T100Frame(this);
    }
    m_frame->Show();
}

T100VOID T100Win32Application::Destroy()
{
    T100SAFE_DELETE(m_frame);
}

T100VOID T100Win32Application::SetInstance(HINSTANCE instance)
{
    m_instance  = instance;
}

HINSTANCE T100Win32Application::GetInstance()
{
    return m_instance;
}

T100VOID T100Win32Application::SetFrame(T100Frame* frame)
{
    m_frame     = frame;
}

T100Frame* T100Win32Application::GetFrame()
{
    return m_frame;
}

T100IDManager& T100Win32Application::GetIDManager()
{
    return m_idManager;
}

T100WindowMessageDispatcher& T100Win32Application::GetWindowMessageDispatcher()
{
    return m_dispatcher;
}

T100BOOL T100Win32Application::IsRegistered(const T100WSTRING& type)
{
    T100BOOL        result      = T100FALSE;

    result  = m_systemClass[type];

    if(result){
        return T100TRUE;
    }

    result  = m_windowClass[type];

    return result;
}

T100BOOL T100Win32Application::RegisterWindowClass(const T100WSTRING& type)
{
    T100BOOL        result      = T100FALSE;

    result  = m_windowClass[type];

    if(result){

    }else{
        m_windowClass[type]     = T100TRUE;
    }

    return !result;
}

T100INT T100Win32MessageLoop()
{
    MSG         message;

    while(GetMessage(&message, T100NULL, 0, 0)){
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}

T100INT T100Runner(T100Win32Application& application, HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, T100INT nCmdShow)
{
    application.SetInstance(hThisInstance);
    application.Create();

    return T100Win32MessageLoop();
}

}
