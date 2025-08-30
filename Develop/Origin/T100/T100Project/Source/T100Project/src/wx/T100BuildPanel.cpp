#include "T100BuildPanel.h"

T100BuildPanel::T100BuildPanel(wxWindow *parent,
               wxWindowID id,
               const wxString& value,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name) :
    wxTextCtrl(parent, id, value, pos, size, style, validator, name)
{
    //ctor
}

T100BuildPanel::~T100BuildPanel()
{
    //dtor
}

T100BOOL T100BuildPanel::Append(const T100WSTRING& value)
{
    AppendText(value);
}

