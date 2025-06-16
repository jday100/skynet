#include "T100TextCtrl.h"

#include <windowsx.h>

namespace T100WINDOWS{

T100TextCtrl::T100TextCtrl() :
    T100Control(),
    m_font()
{
    //ctor
    init();
}

T100TextCtrl::T100TextCtrl(T100Window* parent) :
    T100Control(parent),
    m_font()
{
    //ctor
    init();
}

T100TextCtrl::~T100TextCtrl()
{
    //dtor
}

T100VOID T100TextCtrl::init()
{
    m_modified      = T100FALSE;
}

T100VOID T100TextCtrl::uninit()
{

}

T100VOID T100TextCtrl::Create(T100Window* parent, T100TextCtrlStyle* style)
{

}

T100VOID T100TextCtrl::Destroy()
{

}

T100VOID T100TextCtrl::SetValue(const T100WSTRING& value)
{
    SetWindowText(m_hwnd, value.c_str());
}

const T100WSTRING& T100TextCtrl::GetValue()
{
    T100WSTRING         result;

    return result;
}

T100VOID T100TextCtrl::SetModified(T100BOOL flag)
{
    Edit_SetModify(m_hwnd, flag);
    m_modified  = flag;
}

T100BOOL T100TextCtrl::IsModified()
{
    m_modified  = Edit_GetModify(m_hwnd);
    return m_modified;
}

T100WSTRING T100TextCtrl::GetSelection()
{
    T100WSTRING         result;

    return result;
}

}
