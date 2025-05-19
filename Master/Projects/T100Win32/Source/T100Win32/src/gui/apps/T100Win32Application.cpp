#include "T100Win32Application.h"

#include "T100Frame.h"

T100Win32Application::T100Win32Application() :
    T100Win32ApplicationBase(),
    m_idManager()
{
    //ctor
}

T100Win32Application::~T100Win32Application()
{
    //dtor
}

T100VOID T100Win32Application::Create()
{
    m_rootPtr   = this;

    if(!m_framePtr){
        m_framePtr  = T100NEW T100Frame(this, T100NULL);
        //m_framePtr->Create(this, L"T100Win32Application", 800, 600);
        m_framePtr->Create(L"T100Frame");
        m_framePtr->Show();
    }
}

T100VOID T100Win32Application::Destroy()
{
    T100SAFE_DELETE m_framePtr;
}

T100IDManager& T100Win32Application::GetIDManager()
{
    return m_idManager;
}

T100INT T100Win32ApplicationMessageLoop()
{
    MSG         messages;

    while (GetMessage (&messages, T100NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

T100INT T100Runner(T100Win32Application& app, HINSTANCE hThisInstance, HINSTANCE, LPSTR, T100INT)
{
    app.SetThisInstance(hThisInstance);
    app.Create();

    return T100Win32ApplicationMessageLoop();
}
