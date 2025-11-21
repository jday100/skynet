#include "view/dialog/T1003DEditorConfigDialog.h"

BEGIN_EVENT_TABLE(T1003DEditorConfigDialog,wxDialog)

END_EVENT_TABLE()

T1003DEditorConfigDialog::T1003DEditorConfigDialog(wxWindow *parent,
             wxWindowID id,
             const wxString& title,
             const wxPoint& pos,
             const wxSize& size,
             long style,
             const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    init();
}

T1003DEditorConfigDialog::~T1003DEditorConfigDialog()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorConfigDialog::init()
{
    SetSize(800, 600);
    Center();
}

T100VOID T1003DEditorConfigDialog::uninit()
{

}
