#include "T100EditorView.h"

#include <wx/filedlg.h>

T100EditorView::T100EditorView()
{
    //ctor
}

T100EditorView::~T100EditorView()
{
    //dtor
}

T100VOID T100EditorView::create()
{
    m_main_menu = T100NEW T100EditorMainMenu();
}

T100VOID T100EditorView::destroy()
{
    T100SAFE_DELETE m_main_menu;
}

T100BOOL T100EditorView::show()
{

}

T100BOOL T100EditorView::hide()
{

}

T100BOOL T100EditorView::renew()
{

}

T100BOOL T100EditorView::open()
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    //FileComboBox->Append(FileComboBox->GetValue());
    //FileComboBox->SetValue(dialog.GetPath());
}

T100BOOL T100EditorView::close()
{

}

T100BOOL T100EditorView::save()
{

}

T100BOOL T100EditorView::save_as()
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;
}

T100BOOL T100EditorView::quit()
{

}
