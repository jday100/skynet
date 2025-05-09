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

T100VOID T100Win32Application::init()
{
    m_framePtr  = T100NEW T100Frame();
    m_framePtr->Create(L"Win32Application", 800, 600);

    m_framePtr->Show();
}

T100VOID T100Win32Application::uninit()
{
    T100SAFE_DELETE m_framePtr;
}

T100INT T100Win32Application::Run()
{
    return m_framePtr->Run();
}
