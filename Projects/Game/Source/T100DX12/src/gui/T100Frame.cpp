#include "T100Frame.h"

T100Frame::T100Frame(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) :
    m_hthis_instance(hThisInstance),
    m_hprev_instance(hPrevInstance),
    m_lpsz_argument(lpszArgument),
    m_ncmd_show(nCmdShow)
{
    //ctor
}

T100Frame::~T100Frame()
{
    //dtor
    Destroy();
}

T100VOID T100Frame::Create(LPCWSTR name, LPCWSTR title, WNDPROC wndproc)
{
    m_name                      = name;

    m_wincl.hInstance           = m_hthis_instance;
    m_wincl.lpszClassName       = name;
    m_wincl.lpfnWndProc         = wndproc;
    m_wincl.style               = CS_DBLCLKS;
    m_wincl.cbSize              = sizeof(m_wincl);

    m_wincl.hIcon               = LoadIcon(NULL, IDI_APPLICATION);
    m_wincl.hIconSm             = LoadIcon(NULL, IDI_APPLICATION);
    m_wincl.hCursor             = LoadCursor(NULL, IDC_ARROW);
    m_wincl.lpszMenuName        = NULL;
    m_wincl.cbClsExtra          = 0;
    m_wincl.cbWndExtra          = 0;
    m_wincl.hbrBackground       = (HBRUSH)COLOR_BACKGROUND;

    if(!RegisterClassEx(&m_wincl)){
        return;
    }

    m_hwnd      = CreateWindowEx(
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
                                 NULL
                                 );

    m_width     = 544;
    m_height    = 375;
}

T100VOID T100Frame::Destroy()
{
    UnregisterClass(m_name, m_hthis_instance);
}

HWND T100Frame::GetHWND()
{
    return m_hwnd;
}

UINT32 T100Frame::GetWidth()
{
    return m_width;
}

UINT32 T100Frame::GetHeight()
{
    return m_height;
}

int T100Frame::Run()
{
    MSG         message;

    while(GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return message.wParam;
}

T100BOOL T100Frame::Show()
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
