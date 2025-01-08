#include "T100ApplicationWindow.h"

T100ApplicationWindow::T100ApplicationWindow(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) :
        m_hthis_instance(hThisInstance),
        m_hprev_instance(hPrevInstance),
        m_lpsz_argument(lpszArgument),
        m_ncmd_show(nCmdShow)
{
    //ctor
}

T100ApplicationWindow::~T100ApplicationWindow()
{
    //dtor
}

T100VOID T100ApplicationWindow::Create(LPCWSTR name, LPCWSTR title, WNDPROC wndproc, LPVOID lpParam)
{
    WNDCLASSEXW          wincl;

    wincl.hInstance         = m_hthis_instance;
    wincl.lpszClassName     = name;
    wincl.lpfnWndProc       = wndproc;
    wincl.style             = CS_DBLCLKS;
    wincl.cbSize            = sizeof(WNDCLASSEX);

    wincl.hIcon             = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm           = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor           = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName      = NULL;
    wincl.cbClsExtra        = 0;
    wincl.cbWndExtra        = 0;

    wincl.hbrBackground     = (HBRUSH)COLOR_BACKGROUND;
    if(!RegisterClassExW(&wincl)){
        return;
    }

    m_hwnd      = CreateWindowExW(
                             0,
                             name,
                             title,
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT,
                             CW_USEDEFAULT,
                             544,
                             375,
                             HWND_DESKTOP,
                             NULL,
                             m_hthis_instance,
                             lpParam
                             );
}

T100VOID T100ApplicationWindow::Destroy()
{

}

HWND T100ApplicationWindow::GetHWND()
{
    return m_hwnd;
}

int T100ApplicationWindow::Run()
{
    MSG         message;

    while(GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return message.wParam;
}

WINBOOL T100ApplicationWindow::Show()
{
    return ShowWindow(m_hwnd, m_ncmd_show);
}

LRESULT CALLBACK DefaultWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
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
