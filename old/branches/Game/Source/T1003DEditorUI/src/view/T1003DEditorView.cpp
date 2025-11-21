#include "T1003DEditorView.h"

#include <wx/aui/aui.h>
#include <wx/filedlg.h>
#include "T1003DEditorUIMain.h"
#include "T1003DEditorMainMenu.h"
#include "T1003DEditorMainPanel.h"
#include "T1003DEditorManagerPanel.h"
#include "T1003DEditorPropertiesPanel.h"

#include "T1003DEditorConfigDialog.h"
#include "T1003DEditorSettingDialog.h"

T1003DEditorView::T1003DEditorView()
{
    //ctor
}

T1003DEditorView::~T1003DEditorView()
{
    //dtor
}

T100VOID T1003DEditorView::SetSkeletal(T1003DEditorSkeletal* skeletal)
{
    m_skeletal  = skeletal;
}

T1003DEditorSkeletal* T1003DEditorView::GetSkeletal()
{
    return m_skeletal;
}

T1003DEditorMainMenu* T1003DEditorView::GetMainMenu()
{
    return m_mainMenu;
}

T1003DEditorMainPanel* T1003DEditorView::GetMainPanel()
{
    return m_mainPanel;
}

T1003DEditorScenePanel* T1003DEditorView::GetScenePanel()
{
    return m_managerPanel->GetScenePanel();
}

T1003DEditorEntityPanel* T1003DEditorView::GetEntityPanel()
{
    return m_managerPanel->GetEntityPanel();
}

T1003DEditorPropertiesPanel* T1003DEditorView::GetPropertiesPanel()
{
    return m_propertiesPanel;
}

T100VOID T1003DEditorView::Create(T1003DEditorUIFrame* frame)
{
    m_projectName       = L"3DEditor (Qu) 2025";
    m_frame             = frame;
    m_auiManager        = T100NEW wxAuiManager((wxWindow*)frame);
    m_mainMenu          = T100NEW T1003DEditorMainMenu();
    m_mainPanel         = T100NEW T1003DEditorMainPanel((wxWindow*)m_frame);
    m_managerPanel      = T100NEW T1003DEditorManagerPanel((wxWindow*)m_frame);
    m_propertiesPanel   = T100NEW T1003DEditorPropertiesPanel((wxWindow*)m_frame);

    SetTitle();
    m_mainMenu->Create(m_frame);
    m_managerPanel->GetEntityPanel()->SetSkeletal(m_skeletal);

    m_auiManager->AddPane(m_mainPanel, wxAuiPaneInfo().Name(wxT("main")).Center().CloseButton(T100FALSE));
    m_auiManager->AddPane(m_managerPanel, wxAuiPaneInfo().Name(wxT("manager")).BestSize(420, -1).MinSize(420, -1));
    m_auiManager->AddPane(m_propertiesPanel, wxAuiPaneInfo().Name(wxT("properties")).BestSize(420, -1).MinSize(420, -1));

    m_auiManager->Update();

    m_mainPanel->SetFocus();
    m_mainMenu->SetManager();
    m_mainMenu->SetProperties();
}

T100VOID T1003DEditorView::Destroy()
{
    m_auiManager->UnInit();
}

T100VOID T1003DEditorView::SetTitle(T100WSTRING name)
{
    T100WSTRING     title;
    m_title = name;

    if(m_dirty){
        title   = L"*";
    }
    if(m_title.empty()){
        title   += L"Untitled - " + m_projectName;
    }else{
        title   += m_title + L" - " + m_projectName;
    }

    m_frame->SetTitle(title);
}

T100VOID T1003DEditorView::SetDirty(T100BOOL dirty)
{
    m_dirty = dirty;
    SetTitle(m_title);

    m_mainMenu->SetSave(dirty);
}

T100BOOL T1003DEditorView::IsDirty()
{
    return m_dirty;
}

T100VOID T1003DEditorView::Clear()
{
    m_dirty = T100FALSE;
    SetTitle();
}

T100VOID T1003DEditorView::Update()
{
    m_auiManager->Update();
}

T100BOOL T1003DEditorView::Open(T100WSTRING& filename)
{
    wxFileDialog        dialog((wxWindow*)m_frame, _("Please select a file"), "", "", "3D files (*.3df) | *.3df", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T1003DEditorView::Save(T100WSTRING& filename)
{
    wxFileDialog        dialog((wxWindow*)m_frame, _("Please input a file name"), "", "", "3D files (*.3df) | *.3df", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Input a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T1003DEditorView::Import(T100WSTRING& filename)
{
    wxFileDialog        dialog((wxWindow*)m_frame, _("Please select a file"), "", "", "3D files (*.gltf) | *.gltf |3D files (*.h3d) | *.h3d", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    filename = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100VOID T1003DEditorView::ShowManager(T100BOOL flag)
{
    if(flag){
        m_auiManager->GetPane(wxT("manager")).Show();
    }else{
        m_auiManager->GetPane(wxT("manager")).Hide();
    }

    m_auiManager->Update();
}

T100VOID T1003DEditorView::ShowProperties(T100BOOL flag)
{
    if(flag){
        m_auiManager->GetPane(wxT("properties")).Show();
    }else{
        m_auiManager->GetPane(wxT("properties")).Hide();
    }

    m_auiManager->Update();
}

T100VOID T1003DEditorView::ShowConfig()
{
    if(!m_configDialog){
        m_configDialog  = T100NEW T1003DEditorConfigDialog((wxWindow*)m_frame, wxID_ANY, wxT("Config"));
    }

    m_configDialog->ShowModal();
}

T100VOID T1003DEditorView::ShowSettings()
{
    if(!m_settingDialog){
        m_settingDialog = T100NEW T1003DEditorSettingDialog((wxWindow*)m_frame, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    }

    m_settingDialog->ShowModal();
}

T100VOID T1003DEditorView::SetStatus(T100UINT id, wxString msg)
{
    m_frame->SetStatus(id, msg);
}
