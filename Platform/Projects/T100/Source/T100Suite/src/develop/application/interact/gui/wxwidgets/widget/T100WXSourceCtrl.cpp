#include "T100WXSourceCtrl.h"

BEGIN_EVENT_TABLE(T100WXSourceCtrl,wxStyledTextCtrl)

END_EVENT_TABLE()

T100WXSourceCtrl::T100WXSourceCtrl(wxWindow *parent, wxWindowID id,
                     const wxPoint& pos,
                     const wxSize& size, long style,
                     const wxString& name)
    :wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    //ctor
}

T100WXSourceCtrl::~T100WXSourceCtrl()
{
    //dtor
}
