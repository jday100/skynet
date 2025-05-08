#include "gui/ctrls/T100Button.h"

#include "T100Win32Application.h"

T100Button::T100Button() :
    T100Control()
{
    //ctor
}

T100Button::T100Button(T100Window* parent, T100WSTRING label) :
    T100Control(parent, label)
{
    //ctor
    Create(parent);
}

T100Button::~T100Button()
{
    //dtor
}

T100VOID T100Button::Create(T100Window* parent)
{
    if(!parent){
        return;
    }

    HWND hwnd    = parent->GetHWND();
    parent->AddChildPtr(this);

    m_width     = 100;
    m_height    = 30;

    T100INT     id      = m_idManager.Next();

    m_hwnd = ::CreateWindow(
        TEXT("button"), m_label.c_str(),
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_DEFPUSHBUTTON,
        CW_USEDEFAULT, CW_USEDEFAULT, 100, 30, hwnd, (HMENU)id,
        T100Win32Application::m_thisInstance, this
    );

    Register(id, this);
}
