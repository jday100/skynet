#include "T100Window.h"

T100Window::T100Window(HINSTANCE hThisInstance,
                       LPCWSTR name,
                       int nCmdShow,
                       WNDPROC winproc) :
    m_this_instance(hThisInstance),
    m_name(name),
    m_cmd_show(nCmdShow),
    m_winproc(winproc)
{
    //ctor
    init();
}

T100Window::~T100Window()
{
    //dtor
    uninit();
}

T100VOID T100Window::init()
{
    m_wincl.hInstance       = m_this_instance;
    m_wincl.lpszClassName   = m_name;
    m_wincl.lpfnWndProc     = m_winproc;
    m_wincl.style           = CS_DBLCLKS;
    m_wincl.cbSize          = sizeof(m_wincl);

    m_wincl.hIcon           = LoadIcon(NULL, IDI_APPLICATION);
    m_wincl.hIconSm         = LoadIcon(NULL, IDI_APPLICATION);
    m_wincl.hCursor         = LoadCursor(NULL, IDC_ARROW);
    m_wincl.lpszMenuName    = NULL;
    m_wincl.cbClsExtra      = 0;
    m_wincl.cbWndExtra      = 0;
    m_wincl.hbrBackground   = (HBRUSH)COLOR_BACKGROUND;

    if(!RegisterClassExW(&m_wincl)){
        return;
    }
}

T100VOID T100Window::uninit()
{

}

T100VOID T100Window::Create(LPCWSTR title)
{
    m_title = title;
    m_hwnd  = CreateWindowExW(
                              0,
                              m_name,
                              m_title,
                              WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              544,
                              375,
                              HWND_DESKTOP,
                              NULL,
                              m_this_instance,
                              NULL
                              );
}

T100VOID T100Window::Destroy()
{
    UnregisterClassW(m_name, m_this_instance);
}

T100BOOL T100Window::Show()
{
    return ShowWindow(m_hwnd, m_cmd_show);
}

T100INT T100Window::Run()
{
    while(GetMessage(&m_message, NULL, 0, 0))
    {
        TranslateMessage(&m_message);
        DispatchMessage(&m_message);
    }
    return m_message.wParam;
}

LRESULT CALLBACK T100Window::DefaultWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
