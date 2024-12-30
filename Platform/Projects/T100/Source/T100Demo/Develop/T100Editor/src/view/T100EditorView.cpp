#include "T100EditorView.h"

#include <wx/filedlg.h>
#include "T100EditorCommon.h"
#include "T100EditorCtrl.h"

#include "T100MainPanel.h"

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

    T100MainPanel*  panel = T100NEW T100MainPanel(m_main_frame);
    m_manager       = T100NEW T100EditorWindowsManager(panel);

    getAuiManager()->AddPane(panel, wxAuiPaneInfo().Name(wxT("center")).BestSize(400, -1).CloseButton(T100FALSE).Center());
    getAuiManager()->Update();
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

T100EditorCtrl* T100EditorView::getCurrent()
{
    return m_manager->getCurrent();
}

T100BOOL T100EditorView::load(T100WString& filename)
{
    T100EditorCtrl*     editor          = T100NULL;


    editor  = m_manager->getCurrent();

    if(editor){
        wxString        result;

        result  = filename.to_wstring();
        editor->LoadFile(result);
    }

}

T100BOOL T100EditorView::save(T100WString& filename)
{
    T100EditorCtrl*     editor          = T100NULL;

    editor  = m_manager->getCurrent();

    if(editor){
        wxString        result;

        result  = filename.to_wstring();
        editor->SaveFile();
    }
}

T100BOOL T100EditorView::show()
{
    if(m_main_frame){
        m_main_frame->Show();
    }
}

T100BOOL T100EditorView::hide()
{
    if(m_main_frame){
        m_main_frame->Hide();
    }
}

T100BOOL T100EditorView::renew()
{
    m_manager->renew();
    getAuiManager()->Update();

    return T100TRUE;
}

T100BOOL T100EditorView::open(T100WString& filename)
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    wxString    result      = dialog.GetPath();

    filename    = result.ToStdWstring();

    return T100TRUE;
}

T100BOOL T100EditorView::close()
{
    T100EditorCtrl*     editor          = T100NULL;

    editor  = m_manager->getCurrent();

    if(editor){
        editor->Destroy();
    }
}

T100BOOL T100EditorView::save()
{
    T100EditorCtrl*     editor          = T100NULL;

    editor  = m_manager->getCurrent();

    if(editor){
        editor->SaveFile();
    }
}

T100BOOL T100EditorView::save_as()
{
    wxFileDialog        dialog(T100NULL, _("Please input a file name"), "", "", "All files(*.*)|*.*", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Input a file name:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    T100WString         filename;
    T100EditorCtrl*     editor          = T100NULL;

    filename    = dialog.GetPath().ToStdWstring();
    editor      = m_manager->getCurrent();

    if(editor){
        editor->SaveFile(dialog.GetPath());
    }
}

T100BOOL T100EditorView::quit()
{
    m_manager->quit();
}

T100BOOL T100EditorView::undo()
{
    m_manager->getCurrent()->Undo();
}

T100BOOL T100EditorView::redo()
{
    m_manager->getCurrent()->Redo();
}

T100BOOL T100EditorView::cut()
{
    m_manager->getCurrent()->Cut();
}

T100BOOL T100EditorView::copy()
{
    m_manager->getCurrent()->Copy();
}

T100BOOL T100EditorView::paste()
{
    m_manager->getCurrent()->Paste();
}

T100BOOL T100EditorView::find()
{

}

T100BOOL T100EditorView::replace()
{

}
