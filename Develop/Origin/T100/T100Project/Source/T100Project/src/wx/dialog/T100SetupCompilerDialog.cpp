#include "T100SetupCompilerDialog.h"

T100SetupCompilerDialog::T100SetupCompilerDialog(wxWindow *parent,
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

T100SetupCompilerDialog::~T100SetupCompilerDialog()
{
    //dtor
}
