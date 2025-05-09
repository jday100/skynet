#include "T100Window.h"

#include "T100Win32Application.h"

T100Window::T100Window() :
    T100EventHandler()
{
    //ctor
}

T100Window::~T100Window()
{
    //dtor
}

T100VOID T100Window::Create(T100Window* parent, T100WSTRING title, T100UINT width, T100UINT height)
{
    HWND        hwnd;
    m_width     = width;
    m_height    = height;

    if(parent){
        hwnd    = parent->GetHWND();
    }else{
        hwnd    = HWND_DESKTOP;
    }

    WNDCLASSEX      wincl;

    wincl.hInstance         = T100Win32Application::m_thisInstance;
    wincl.lpszClassName     = L"T100Window";
    wincl.lpfnWndProc       = T100DefaultWindowProcedure;
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

    m_hwnd = CreateWindowEx(
                    0,
                    L"T100Window",
                    title.c_str(),
                    WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    width,
                    height,
                    hwnd,
                    NULL,
                    T100Win32Application::m_thisInstance,
                    this
                    );

}

T100VOID T100Window::Destroy()
{

}

HWND T100Window::GetHWND()
{
    return m_hwnd;
}

T100VOID T100Window::Show()
{
    ShowWindow(m_hwnd, 1);
}

T100VOID T100Window::Hide()
{

}

T100INT T100Window::Run()
{
    MSG             messages;

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK T100DefaultWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100EventHandler* handlerPtr = reinterpret_cast<T100EventHandler*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch (message)
    {
        case WM_COMMAND:
            {
                if(handlerPtr){
                    T100EventBase           event;
                    event.MessageID     = message;
                    event.ID            = (UINT)wParam;
                    event.FLAGS         = (UINT)lParam;
                    handlerPtr->DispatchEvent(event);
                }
            }
            break;
        case WM_CREATE:
            {
                LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
                SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
            }
            break;
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                // TODO: 在此处添加使用 hdc 的任何绘图代码...
                EndPaint(hwnd, &ps);
            }
            break;
        case WM_DRAWITEM:
            {
                LPDRAWITEMSTRUCT pdis = (LPDRAWITEMSTRUCT)lParam;
                return TRUE;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
