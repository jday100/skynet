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

T100VOID T100WindowBase::Show()
{
    ShowWindow(m_hwnd, SW_SHOW);
}

T100VOID T100WindowBase::Hide()
{

}

}
