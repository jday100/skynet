#include "T100EditorCtrl.h"

const long T100EditorCtrl::ID_STC_MODIFIED = wxNewId();

BEGIN_EVENT_TABLE(T100EditorCtrl,wxStyledTextCtrl)
    EVT_STC_CHANGE(ID_STC_MODIFIED, T100EditorCtrl::OnModified)
END_EVENT_TABLE()

T100EditorCtrl::T100EditorCtrl(wxWindow *parent, wxWindowID id,
                     const wxPoint& pos,
                     const wxSize& size, long style,
                     const wxString& name)
    :wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    //ctor
}

T100EditorCtrl::~T100EditorCtrl()
{
    //dtor
}

void T100EditorCtrl::OnModified(wxStyledTextEvent& event)
{

}
