#include "gui/T100Win32Application.h"

T100Win32Application::T100Win32Application() :
    T100Win32ApplicationBase()
{
    //ctor
}

T100Win32Application::~T100Win32Application()
{
    //dtor
}

T100VOID T100Win32Application::Create()
{
    if(!m_framePtr){
        T100FrameStyle          style;
        m_framePtr      = T100NEW T100Frame(this, &style);
    }

    m_framePtr->Show();
}

T100VOID T100Win32Application::Destroy()
{
    T100SAFE_DELETE m_framePtr;
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
