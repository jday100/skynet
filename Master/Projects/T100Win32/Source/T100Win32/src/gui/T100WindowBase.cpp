#include "T100WindowBase.h"

#include "T100Win32Application.h"

T100WindowBase::T100WindowBase() :
    T100EventHandler()
{
    //ctor
}

T100WindowBase::~T100WindowBase()
{
    //dtor
}

T100VOID T100WindowBase::SetLabel(T100WSTRING label)
{
    m_label     = label;
}

T100WSTRING T100WindowBase::GetLabel()
{
    return m_label;
}

HWND T100WindowBase::GetHWND()
{
    return m_hwnd;
}

T100UINT T100WindowBase::GetWidth()
{
    return m_width;
}

T100UINT T100WindowBase::GetHeight()
{
    return m_height;
}

HWND T100WindowBase::Create(HWND parent, T100WSTRING type, T100LONG style, T100LONG value)
{
    HWND        hwnd;

    hwnd    = CreateWindowEx(
                    0,
                    type.c_str(),
                    m_label.c_str(),
                    style,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    m_width,
                    m_height,
                    parent,
                    (HMENU)value,
                    T100Win32Application::m_thisInstance,
                    this
                    );

    return hwnd;
}
