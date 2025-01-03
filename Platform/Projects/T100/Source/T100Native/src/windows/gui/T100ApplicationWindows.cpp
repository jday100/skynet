#include "T100ApplicationWindows.h"

T100ApplicationWindows::T100ApplicationWindows(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
    :m_hthis_instance(hThisInstance),
    m_hprev_instance(hPrevInstance),
    m_lpsz_argument(lpszArgument),
    m_ncmd_show(nCmdShow)
{
    //ctor
    init();
}

T100ApplicationWindows::~T100ApplicationWindows()
{
    //dtor
    uninit();
}

T100VOID T100ApplicationWindows::init()
{
    TCHAR               name[]      = _T("CodeBlocksWindowsApp");
    WNDCLASSEX          wincl;

    wincl.hInstance         = m_hthis_instance;
    wincl.lpszClassName     = name;
    wincl.lpfnWndProc       = WindowProcedure;
    wincl.style             = CS_DBLCLKS;
    wincl.cbSize            = sizeof(WNDCLASSEX);

    wincl.hIcon             = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm           = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor           = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName      = NULL;
    wincl.cbClsExtra        = 0;
    wincl.cbWndExtra        = 0;

    wincl.hbrBackground     = (HBRUSH)COLOR_BACKGROUND;
    if(!RegisterClassEx(&wincl)){
        return;
    }
}

T100VOID T100ApplicationWindows::uninit()
{

}

T100VOID T100ApplicationWindows::Create()
{
    TCHAR               szClassName[]      = _T("CodeBlocksWindowsApp");

    m_hwnd      = CreateWindowEx(
                             0,
                             szClassName,
                             _T("Code::Blocks Template Windows App"),
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
}

HWND T100ApplicationWindows::getHWND()
{
    return m_hwnd;
}

T100VOID T100ApplicationWindows::Show()
{
    ShowWindow(m_hwnd, m_ncmd_show);


}

int T100ApplicationWindows::run()
{
    MSG     messages;

    while(GetMessage(&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK T100ApplicationWindows::WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
