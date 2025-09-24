#include "T100Pack.h"

T100Pack::T100Pack(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name) :
    wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
}

T100Pack::~T100Pack()
{
    //dtor
}

T100VOID T100Pack::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100Pack::GetLabel()
{
    return m_label;
}

T100VOID T100Pack::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100Pack::GetPath()
{
    return m_path;
}
