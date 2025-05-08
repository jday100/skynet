#include "gui/T100OwnedWindow.h"

#include "T100Win32Application.h"

T100OwnedWindow::T100OwnedWindow() :
    T100Window()
{
    //ctor
}

T100OwnedWindow::~T100OwnedWindow()
{
    //dtor
}

T100VOID T100OwnedWindow::RegisterWindow(T100WSTRING label)
{
    WNDCLASSEX      wincl;

    wincl.hInstance         = T100Win32Application::m_thisInstance;
    wincl.lpszClassName     = L"T100OwnedWindow";
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

T100VOID T100OwnedWindow::Create(T100Window* parent, T100WSTRING label, T100UINT width, T100UINT height)
{
    HWND        hwnd;
    T100LONG    style;
    m_width     = width;
    m_height    = height;

    if(parent){
        hwnd    = parent->GetHWND();
        style   = WS_CHILDWINDOW;
        parent->AddChildPtr(this);
    }else{
        hwnd    = HWND_DESKTOP;

    }

    RegisterWindow(label);

    m_hwnd  = T100WindowBase::Create(hwnd, L"T100OwnedWindow", style, 0);
}
