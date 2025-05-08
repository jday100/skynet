#include "gui/T100Panel.h"

#include "T100Win32Application.h"

T100Panel::T100Panel() :
    T100Window()
{
    //ctor
}

T100Panel::~T100Panel()
{
    //dtor
}

T100VOID T100Panel::Create(T100Window* parent, T100WSTRING label, T100UINT width, T100UINT height)
{
    HWND        hwnd;
    m_width     = width;
    m_height    = height;

    m_label     = label;

    if(parent){
        hwnd    = parent->GetHWND();
        parent->AddChildPtr(this);
    }else{
        return;
    }

    if(RegisterWindowClass(L"T100Panel")){
        WNDCLASSEX      wincl;

        wincl.hInstance         = T100Win32Application::m_thisInstance;
        wincl.lpszClassName     = L"T100Panel";
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

    m_hwnd = T100WindowBase::Create(hwnd, label, WS_VISIBLE | WS_CHILD | WS_CAPTION, 0);

    Register(m_hwnd, this);
}

