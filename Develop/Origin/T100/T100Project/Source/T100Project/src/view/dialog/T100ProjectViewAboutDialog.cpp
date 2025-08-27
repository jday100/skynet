#include "T100ProjectViewAboutDialog.h"

T100ProjectViewAboutDialog::T100ProjectViewAboutDialog(wxWindow *parent,
             wxWindowID id,
             const wxString& title,
             const wxPoint& pos,
             const wxSize& size,
             long style,
             const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    Center();
}

T100ProjectViewAboutDialog::~T100ProjectViewAboutDialog()
{
    //dtor
}
