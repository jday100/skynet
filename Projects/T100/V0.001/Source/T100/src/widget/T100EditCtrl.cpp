#include "T100EditCtrl.h"

BEGIN_EVENT_TABLE(T100EditCtrl, wxStyledTextCtrl)

END_EVENT_TABLE()

T100EditCtrl::T100EditCtrl(wxWindow *parent, wxWindowID id, const wxPoint& pos,
                     const wxSize& size, long style, const wxString& name)
    :wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    //ctor
}

T100EditCtrl::~T100EditCtrl()
{
    //dtor
}
