#include "T100EditorView.h"

#include <wx/filedlg.h>
#include "T100EditorCtrl.h"

T100EditorView::T100EditorView()
{
    //ctor
    create();
}

T100EditorView::~T100EditorView()
{
    //dtor
    destroy();
}

T100VOID T100EditorView::create()
{
    m_main_menu     = T100NEW T100EditorMainMenu();
    m_main_frame    = T100NEW T100EditorFrame(0);

}

T100VOID T100EditorView::destroy()
{
    T100SAFE_DELETE m_main_menu;
}

T100VOID* T100EditorView::getFrame()
{
    if(m_main_frame){
        return m_main_frame;
    }

    return T100NULL;
}

wxAuiManager* T100EditorView::getAuiManager()
{
    if(m_main_frame){
        return m_main_frame->getAuiManager();
    }

    return T100NULL;
}

T100VOID T100EditorView::getCurrent()
{

}

T100BOOL T100EditorView::load(T100WString& filename)
{
    T100EditorCtrl*     editor          = T100NULL;


    wxFrame*    frame  = m_main_frame->getAuiManager()->GetPane(wxT("center")).CenterPane().frame;
}

T100BOOL T100EditorView::save(T100WString& filename)
{

}

T100BOOL T100EditorView::show()
{
    if(m_main_frame){
        m_main_frame->Show();
    }
}

T100BOOL T100EditorView::hide()
{

}

T100BOOL T100EditorView::renew()
{
    //m_manager->AddPane(m_projects_panel, wxAuiPaneInfo().Name(wxT("Projects")).BestSize(400, -1).Left());

    T100EditorCtrl*     editor          = T100NEW T100EditorCtrl((wxWindow*)getFrame());

    getAuiManager()->AddPane(editor, wxAuiPaneInfo().Name(wxT("unnamed")).BestSize(400, -1).Center());
    getAuiManager()->Update();
}

T100BOOL T100EditorView::open(T100WString& filename)
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    wxString    result      = dialog.GetPath();

    //filename    = result.ToStdWstring();

    return T100TRUE;
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
