#include "T100App.h"

T100App::T100App(HINSTANCE hThisInstance,
                 HINSTANCE hPrevInstance,
                 LPSTR lpArgument,
                 int nCmdShow) :
    m_this_instance(hThisInstance),
    m_prev_instance(hPrevInstance),
    m_argument(lpArgument),
    m_cmd_show(nCmdShow)
{
    //ctor
    create();
}

T100App::~T100App()
{
    //dtor
    destroy();
}

T100VOID T100App::create()
{
    m_window    = T100NEW T100Window(m_this_instance,
                                     _T("CodeBlocksWindowsApp"),
                                     m_cmd_show);

    m_window->Create(_T("Code::Blocks Template Windows App"));
    m_window->Show();
}

T100VOID T100App::destroy()
{
    T100SAFE_DELETE m_window;
}

T100INT T100App::Run()
{
    return m_window->Run();
}
