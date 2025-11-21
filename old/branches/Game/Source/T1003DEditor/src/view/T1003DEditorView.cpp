#include "T1003DEditorView.h"

#include <wx/aui/aui.h>
#include <wx/filedlg.h>
#include "T1003DEditorCallback.h"
#include "T1003DEditorEntityManager.h"
#include "T1003DEditorMainPanel.h"
#include "T1003DEditorEntityPanel.h"
#include "T1003DEditorPropertiesPanel.h"
#include "T1003DEditorConfigDialog.h"
#include "T1003DEditorMain.h"

T1003DEditorView::T1003DEditorView()
    :m_frame(T100NULL)
{
    //ctor
}

T1003DEditorView::~T1003DEditorView()
{
    //dtor
    Destroy();
}

T100VOID T1003DEditorView::Create(T1003DEditorFrame* frame)
{
    m_frame             = frame;
    m_aui_manager       = T100NEW wxAuiManager((wxWindow*)m_frame);
    m_entity_manager    = T100NEW T1003DEditorEntityManager();
    m_entity_panel      = T100NEW T1003DEditorEntityPanel((wxWindow*)m_frame);
    m_properties_panel  = T100NEW T1003DEditorPropertiesPanel((wxWindow*)m_frame);
    m_main              = T100NEW T1003DEditorMainPanel((wxWindow*)m_frame);

    m_entity_panel->setSkeletal(m_skeletal);
    m_main->setView(this);

    m_aui_manager->AddPane(m_entity_panel, wxAuiPaneInfo().BestSize(400, -1));
    m_aui_manager->AddPane(m_properties_panel, wxAuiPaneInfo().BestSize(400, -1));
    m_aui_manager->AddPane(m_main, wxAuiPaneInfo().CloseButton(T100FALSE).Center());


    m_aui_manager->Update();

    T1003DEditorCallback::Create(m_main->GetHWND(), m_main->GetClientSize().GetWidth(), m_main->GetClientSize().GetHeight());

    SetTitle();
}

T100VOID T1003DEditorView::Destroy()
{
    T100SAFE_DELETE m_entity_panel;

    m_aui_manager->UnInit();
    T100SAFE_DELETE m_aui_manager;
}

T100VOID T1003DEditorView::SetSkeletal(T1003DEditorSkeletal* skeletal)
{
    m_skeletal  = skeletal;
}

T1003DEditorSkeletal* T1003DEditorView::GetSkeletal()
{
    return m_skeletal;
}

T1003DEditorMainPanel* T1003DEditorView::getMainPanel()
{
    return m_main;
}

T1003DEditorEntityPanel* T1003DEditorView::getEntityPanel()
{
    return m_entity_panel;
}

T1003DEditorPropertiesPanel* T1003DEditorView::getPropertiesPanel()
{
    return m_properties_panel;
}

T100Entity* T1003DEditorView::getEntity()
{
    return m_entity_manager->getCurrent();
}

T1003DEditorEntityManager* T1003DEditorView::getEntityManager()
{
    return m_entity_manager;
}

T100VOID T1003DEditorView::ShowConfigDialog()
{
    T1003DEditorConfigDialog            dialog((wxWindow*)m_frame);

    dialog.ShowModal();
}

T100BOOL T1003DEditorView::Open(T100WSTRING& filename)
{
    wxFileDialog        dialog((wxWindow*)m_frame, _("Please select a file"), "", "", "3D files (*.3df) | *.3df; All files (*.*) | *.*;", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T1003DEditorView::Save(T100WSTRING& filename)
{

}

T100VOID T1003DEditorView::SetCursor()
{
    m_frame->SetCursor(*wxCROSS_CURSOR);
}

T100VOID T1003DEditorView::SetTitle()
{
    m_frame->SetTitle(L"3DEditor");
}
