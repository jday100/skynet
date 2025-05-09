#include "T100Button.h"

#include "T100Win32Application.h"

T100Button::T100Button() :
    T100Window()
{
    //ctor
}

T100Button::~T100Button()
{
    //dtor
}

T100VOID T100Button::Create(HWND hwnd)
{
    m_width     = 100;
    m_height    = 30;

    m_hwnd = CreateWindow(
        TEXT("button"), TEXT("ok"),
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,
        CW_USEDEFAULT, CW_USEDEFAULT, 100, 30, hwnd, (HMENU)1000,
        T100Win32Application::m_thisInstance, this
    );

    Register(1000, this);
}
