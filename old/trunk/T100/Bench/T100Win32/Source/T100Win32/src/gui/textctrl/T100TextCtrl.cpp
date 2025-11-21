#include "gui/T100TextCtrl.h"

#include <windowsx.h>

namespace T100WINDOWS{

T100TextCtrl::T100TextCtrl() :
    T100Control(),
    m_font()
{
    //ctor
    m_modified      = T100FALSE;
}

T100TextCtrl::T100TextCtrl(T100Window* parent) :
    T100Control(parent),
    m_font()
{
    //ctor
    init(parent);
}

T100TextCtrl::~T100TextCtrl()
{
    //dtor
}

T100VOID T100TextCtrl::init(T100Window* parent)
{
    m_modified      = T100FALSE;
    T100Control::Create(parent, &m_style);
}

T100VOID T100TextCtrl::uninit()
{

}

T100VOID T100TextCtrl::Create(T100Window* parent, T100TextCtrlStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100TextCtrlStyle();
    }
    init(parent);
}

T100VOID T100TextCtrl::Destroy()
{

}

T100VOID T100TextCtrl::SetValue(const T100WSTRING& value)
{
    m_value     = value;
    SetWindowText(m_hwnd, value.c_str());
}

const T100WSTRING T100TextCtrl::GetValue()
{
    T100WSTRING     result;
    T100WCHAR*      buffer      = T100NULL;
    T100UINT        length;

    length  = GetLength() + 1;

    if(length != 0){
        buffer  = T100NEW T100WCHAR[length];
        Edit_GetText(m_hwnd, buffer, length);
        result  = buffer;
        T100SAFE_DELETES(buffer);
    }

    m_value = result;

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

T100VOID T100TextCtrl::SetFont(const T100Font& font)
{
    m_font      = font;
    SetWindowFont(m_hwnd, m_font.GetHFONT(), T100TRUE);
}

const T100Font& T100TextCtrl::GetFont()
{
    return m_font;
}

T100WSTRING T100TextCtrl::GetSelection()
{
    T100UINT64      value;
    T100UINT        head;
    T100UINT        tail;

    value   = Edit_GetSel(m_hwnd);

    head    = LOWORD(value);
    tail    = HIWORD(value);

    T100WSTRING         result;

    m_value.substr(head, tail);

    return result;
}

T100UINT T100TextCtrl::GetLength()
{
    T100UINT    result;

    result  = Edit_GetTextLength(m_hwnd);

    return result;
}

T100VOID T100TextCtrl::Append(const T100WSTRING& value)
{

}

T100VOID T100TextCtrl::Insert(T100UINT, const T100WSTRING& value)
{

}

T100VOID T100TextCtrl::Remove(T100UINT head, T100UINT tail)
{
    SNDMSG(m_hwnd, WM_CUT, 0, 0);
}

T100VOID T100TextCtrl::Cut()
{
    SNDMSG(m_hwnd, WM_CUT, 0, 0);
}

T100VOID T100TextCtrl::Copy()
{
    SNDMSG(m_hwnd, WM_COPY, 0, 0);
}

T100VOID T100TextCtrl::Paste()
{
    SNDMSG(m_hwnd, WM_PASTE, 0, 0);
}

T100VOID T100TextCtrl::ProcessNotifyMessage(const T100WindowMessageData& message)
{
    switch(message.MESSAGE_ID){
    case T100EVENT_TEXTCTRL_CHANGE:
        {
            CallNotify(T100EVENT_TEXTCTRL_CHANGE, message);
        }
        break;
    }
}

}
