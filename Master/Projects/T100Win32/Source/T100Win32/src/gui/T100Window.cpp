#include "T100Window.h"

#include "T100Layout.h"
#include "T100Win32Application.h"

T100Window::T100Window() :
    T100WindowBase()
{
    //ctor
}

T100Window::T100Window(T100Window* parent, T100WSTRING label) :
    T100WindowBase()
{
    //ctor
    m_parentPtr = parent;
    m_label     = label;
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
        parent->AddChildPtr(this);
    }else{
        hwnd    = HWND_DESKTOP;
    }

    if(RegisterWindowClass(L"T100Window")){
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

    Register(m_hwnd, this);
    init();
}

T100VOID T100Window::Destroy()
{
    uninit();
}

T100VOID T100Window::init()
{
    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_CALL)&OnResize);
}

T100VOID T100Window::uninit()
{

}

HWND T100Window::GetHWND()
{
    return m_hwnd;
}

T100VOID T100Window::SetLayoutPtr(T100Layout* layout)
{
    m_layoutPtr = layout;

    m_layoutPtr->SetParentPtr(this);
    m_layoutPtr->SetChildren(m_children);
}

T100Layout* T100Window::GetLayoutPtr()
{
    return m_layoutPtr;
}

T100VOID T100Window::AddChildPtr(T100Window* winPtr)
{
    m_children.push_back(winPtr);
}

T100VOID T100Window::Show()
{
    ShowWindow(m_hwnd, SW_SHOW);
}

T100VOID T100Window::Hide()
{

}

T100Size T100Window::GetSize()
{
    RECT        rect;
    GetWindowRect(m_hwnd, &rect);

    return T100Size(rect.right - rect.left, rect.bottom - rect.top);
}

T100VOID T100Window::SetSize(T100Size size)
{
    m_width     = size.m_x;
    m_height    = size.m_y;
    //SetWindowPos(m_hwnd, HWND_TOPMOST, m_position.m_x, m_position.m_y, size.m_x, size.m_y, SWP_SHOWWINDOW);
    MoveWindow(m_hwnd, m_position.m_x, m_position.m_y, m_width, m_height, T100TRUE);
}

T100Size T100Window::GetClientSize()
{
    RECT        rect;
    GetClientRect(m_hwnd, &rect);

    return T100Size(rect.right - rect.left, rect.bottom - rect.top);
}

T100VOID T100Window::SetClientSize(T100Size size)
{

}

T100VOID T100Window::SetPosition(T100Point value)
{
    m_position  = value;
    //SetWindowPos(m_hwnd, HWND_TOPMOST, m_position.m_x, m_position.m_y, m_width, m_height, SWP_SHOWWINDOW);

    MoveWindow(m_hwnd, m_position.m_x, m_position.m_y, m_width, m_height, T100TRUE);
}

T100Point T100Window::GetPosition()
{
    return m_position;
}

T100VOID T100Window::OnResize(T100Event&)
{
    if(m_layoutPtr){
        m_layoutPtr->Update();
    }
}

T100INT T100Window::Run()
{
    MSG             messages;

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        ::DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK T100DefaultWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100MESSAGE_DATA        data        = {hwnd, message, wParam, lParam};
    T100EventHandler*       handlerPtr  = reinterpret_cast<T100EventHandler*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch (message)
    {
        case WM_COMMAND:
        case WM_PAINT:
        case WM_SIZE:
            {
                if(handlerPtr){
                    handlerPtr->DispatchMessage(data);
                }else{
                    return DefWindowProc (hwnd, message, wParam, lParam);
                }
            }
            break;
        case WM_CREATE:
            {
                LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
                SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
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
