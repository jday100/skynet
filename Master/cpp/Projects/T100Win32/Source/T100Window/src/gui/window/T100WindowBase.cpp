#include "gui/window/T100WindowBase.h"

#include "gui/layout/T100Layout.h"

T100WindowBase::T100WindowBase() :
    T100WindowEventHandler()
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

T100VOID T100WindowBase::SetLabel(T100WSTRING label)
{
    m_style.WindowLabel     = label;

    SetWindowText(m_hwnd, m_style.WindowLabel.c_str());
}

T100WSTRING T100WindowBase::GetLabel()
{
    return m_style.WindowLabel;
}

T100VOID T100WindowBase::SetFont(T100Font& font)
{
    m_font      = font;
}

T100Font& T100WindowBase::GetFont()
{
    return m_font;
}

T100VOID T100WindowBase::SetWidth(T100INT width)
{
    m_style.Width   = width;
}

T100INT T100WindowBase::GetWidth()
{
    return m_style.Width;
}

T100VOID T100WindowBase::SetHeight(T100INT height)
{
    m_style.Height  = height;
}

T100INT T100WindowBase::GetHeight()
{
    return m_style.Height;
}

T100VOID T100WindowBase::SetSize(T100Size size)
{
    m_style.Width   = size.width;
    m_style.Height  = size.height;

    //SetWindowPos(m_hwnd, NULL, m_style.X, m_style.Y, m_style.Width, m_style.Height, SW_SHOW);
    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    T100WindowMessageData   data(0, WM_SIZE, 0, 0);
    SendWindowMessage(data);
}

T100VOID T100WindowBase::SetSize(T100INT width, T100INT height)
{
    SetSize(T100Size(width, height));
}

T100Size T100WindowBase::GetSize()
{
    RECT        rect;
    GetWindowRect(m_hwnd, &rect);

    m_style.Width   = rect.right - rect.left;
    m_style.Height  = rect.bottom - rect.top;

    return T100Size(m_style.Width, m_style.Height);
}

T100VOID T100WindowBase::SetClientSize(T100Size size)
{

}

T100VOID T100WindowBase::SetClientSize(T100INT width, T100INT height)
{

}

T100Size T100WindowBase::GetClientSize()
{
    RECT        rect;
    GetClientRect(m_hwnd, &rect);

    return T100Size(rect.right - rect.left, rect.bottom - rect.top);
}

T100VOID T100WindowBase::SetPosition(T100Point value)
{
    m_style.X   = value.x;
    m_style.Y   = value.y;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);
}

T100Point T100WindowBase::GetPosition()
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
}

T100VOID T100WindowBase::Hide()
{
    ShowWindow(m_hwnd, SW_HIDE);
}

T100BOOL T100WindowBase::IsShown()
{
    return IsWindowVisible(m_hwnd);
}
