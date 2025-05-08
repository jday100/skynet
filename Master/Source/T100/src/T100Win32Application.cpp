#include "T100Win32Application.h"


HINSTANCE       T100Win32Application::m_thisInstance            = T100NULL;
T100INT         T100Win32Application::m_cmdShow                 = 0;


T100Win32Application::T100Win32Application(HINSTANCE hThisInstance,
                                            HINSTANCE hPrevInstance,
                                            LPSTR lpCmdLine,
                                            T100INT nCmdShow) :
    T100Application()
{
    //ctor
    m_thisInstance  = hThisInstance;
    m_cmdShow       = nCmdShow;

    init();
}

T100Win32Application::~T100Win32Application()
{
    //dtor
    uninit();
}

T100VOID T100Win32Application::Create(T100WSTRING title)
{
    if(!m_framePtr){
        m_framePtr  = T100NEW T100Frame();
        m_framePtr->Create(title, 800, 600);
    }

    m_framePtr->Show();
}

T100VOID T100Win32Application::Destroy()
{
    T100SAFE_DELETE m_framePtr;
}

T100VOID T100Win32Application::init()
{

}

T100VOID T100Win32Application::uninit()
{

}

T100VOID T100Win32Application::SetFramePtr(T100Frame* framePtr)
{
    m_framePtr  = framePtr;
}

T100Frame* T100Win32Application::GetFramePtr()
{
    return m_framePtr;
}

T100INT T100Win32Application::Run()
{
    return m_framePtr->Run();
}
