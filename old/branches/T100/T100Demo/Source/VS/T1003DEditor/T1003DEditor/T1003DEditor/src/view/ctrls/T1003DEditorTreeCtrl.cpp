#include "view/ctrls/T1003DEditorTreeCtrl.h"

BEGIN_EVENT_TABLE(T1003DEditorTreeCtrl,wxTreeCtrl)

END_EVENT_TABLE()

T1003DEditorTreeCtrl::T1003DEditorTreeCtrl(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name) :
    wxTreeCtrl(parent, id, pos, size, style, validator, name)
{
    //ctor
}

T1003DEditorTreeCtrl::~T1003DEditorTreeCtrl()
{
    //dtor
}
