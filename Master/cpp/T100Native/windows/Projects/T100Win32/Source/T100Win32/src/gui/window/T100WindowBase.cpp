#include "T100WindowBase.h"

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

T100VOID T100WindowBase::SetWidth(T100INT width)
{

}

T100INT T100WindowBase::GetWidth()
{

}

T100VOID T100WindowBase::SetHeight(T100INT height)
{

}

T100INT T100WindowBase::GetHeight()
{

}

T100VOID T100WindowBase::SetSize(const T100Size& size)
{
    m_style.Width   = size.Width;
    m_style.Height  = size.Height;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    T100WindowMessageData       data(0, WM_SIZE, 0, 0);
    SendWindowMessage(data);
}

T100VOID T100WindowBase::SetSize(T100INT width, T100INT height)
{

}

const T100Size& T100WindowBase::GetSize()
{

}

T100VOID T100WindowBase::SetClientSize(const T100Size& size)
{

}

T100VOID T100WindowBase::SetClientSize(T100INT width, T100INT height)
{

}

const T100Size T100WindowBase::GetClientSize()
{
    RECT        rect;

    GetClientRect(m_hwnd, &rect);

    return T100Size(rect.right - rect.left, rect.bottom - rect.top);
}

T100VOID T100WindowBase::SetPosition(const T100Point& value)
{
    m_style.X       = value.X;
    m_style.Y       = value.Y;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);
}

const T100Point& T100WindowBase::GetPosition()
{

}

T100VOID T100WindowBase::Enable()
{

}

T100VOID T100WindowBase::Disable()
{

}

T100BOOL T100WindowBase::IsEnabled()
{

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

}

T100VOID T100WindowBase::SetStyle(const T100WindowStyle& style)
{

}

const T100WindowStyle& T100WindowBase::GetStyle()
{

}

}
