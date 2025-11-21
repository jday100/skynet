#include "gui/window/T100WindowBase.h"

namespace T100WINDOWS{

T100WindowBase::T100WindowBase() :
    T100EventHandler()
{
    //ctor
}

T100WindowBase::~T100WindowBase()
{
    //dtor
}

HWND T100WindowBase::GetHWND()
{
    return m_hwnd;
}

T100VOID T100WindowBase::SetLabel(const T100WSTRING& label)
{
    SetWindowText(m_hwnd, label.c_str());
    T100Object::SetLabel(label);
}

T100VOID T100WindowBase::SetWidth(T100INT width)
{
    m_style.Width   = width;
    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    //T100WindowMessageData       data(0, WM_SIZE, 0, 0);
    //SendWindowMessage(data);
}

T100INT T100WindowBase::GetWidth()
{
    return m_style.Width;
}

T100VOID T100WindowBase::SetHeight(T100INT height)
{
    m_style.Height  = height;
    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    //T100WindowMessageData       data(0, WM_SIZE, 0, 0);
    //SendWindowMessage(data);
}

T100INT T100WindowBase::GetHeight()
{
    return m_style.Height;
}

T100VOID T100WindowBase::SetSize(const T100Size& size)
{
    m_style.Width   = size.Width;
    m_style.Height  = size.Height;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    //T100WindowMessageData       data(0, WM_SIZE, 0, 0);
    //SendWindowMessage(data);
}

T100VOID T100WindowBase::SetSize(T100INT width, T100INT height)
{
    SetSize(T100Size(width, height));
}

const T100Size T100WindowBase::GetSize()
{
    return T100Size(m_style.Width, m_style.Height);
}

T100VOID T100WindowBase::SetClientSize(const T100Size& size)
{
    m_style.Width   = size.Width;
    m_style.Height  = size.Height;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    //T100WindowMessageData       data(0, WM_SIZE, 0, 0);
    //SendWindowMessage(data);
}

T100VOID T100WindowBase::SetClientSize(T100INT width, T100INT height)
{
    SetClientSize(T100Size(width, height));
}

const T100Size T100WindowBase::GetClientSize()
{
    RECT        rect;

    GetClientRect(m_hwnd, &rect);

    m_style.Width   = rect.right - rect.left;
    m_style.Height  = rect.bottom - rect.top;

    return T100Size(m_style.Width, m_style.Height);
}

T100VOID T100WindowBase::SetPosition(const T100Point& value)
{
    m_style.X       = value.X;
    m_style.Y       = value.Y;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);
}

const T100Point T100WindowBase::GetPosition()
{
    return T100Point(m_style.X, m_style.Y);
}

T100VOID T100WindowBase::Enable()
{
    EnableWindow(m_hwnd, T100TRUE);
}

T100VOID T100WindowBase::Disable()
{
    EnableWindow(m_hwnd, T100FALSE);
}

T100BOOL T100WindowBase::IsEnabled()
{
    return IsWindowEnabled(m_hwnd);
}

T100VOID T100WindowBase::Show()
{
    ShowWindow(m_hwnd, SW_SHOW);

    RECT        rect;
    if(GetWindowRect(m_hwnd, &rect)){
        m_style.X       = rect.left;
        m_style.Y       = rect.top;
        m_style.Width   = rect.right - rect.left;
        m_style.Height  = rect.bottom - rect.top;
    }
}

T100VOID T100WindowBase::Hide()
{
    ShowWindow(m_hwnd, SW_HIDE);
}

T100BOOL T100WindowBase::IsShown()
{
    return IsWindowVisible(m_hwnd);
}

T100VOID T100WindowBase::SetStyle(const T100WindowStyle& style)
{
    m_style     = style;
}

const T100WindowStyle& T100WindowBase::GetStyle()
{
    return m_style;
}

}
