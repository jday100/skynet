#include "T100Editor.h"

#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100Editor, wxStyledTextCtrl)
    EVT_STC_MODIFIED(wxID_ANY, OnModified)
END_EVENT_TABLE()

T100Editor::T100Editor(wxWindow *parent,
                        wxWindowID id,
                        const wxPoint& pos,
                        const wxSize& size,
                        long style,
                        const wxString& name) :
    wxStyledTextCtrl(parent, id, pos, size, style, name)
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

T100VOID T100Editor::OnModified(wxStyledTextEvent& event)
{
    T100ProjectInvoking::OnModified();
}
