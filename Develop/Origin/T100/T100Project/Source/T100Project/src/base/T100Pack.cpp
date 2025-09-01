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
    m_index     = 0;
}

T100Pack::~T100Pack()
{
    //dtor
}

T100VOID T100Pack::SetIndex(T100INT index)
{
    m_index     = index;
}

T100INT T100Pack::GetIndex()
{
    return m_index;
}
