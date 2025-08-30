#include "T100ProjectViewBase.h"

#include <wx/msgdlg.h>
#include <wx/dirdlg.h>
#include "T100ProjectMain.h"
#include "T100ProjectCreateWizard.h"
#include "T100ProjectViewAboutDialog.h"
#include "T100WorkSpaceCreateDialog.h"
#include "T100WorkSpacePropertiesDialog.h"


T100ProjectViewBase::T100ProjectViewBase()
{
    //ctor
    init();
}

T100ProjectViewBase::~T100ProjectViewBase()
{
    //dtor
    uninit();
}

T100VOID T100ProjectViewBase::init()
{
    m_dirty     = T100FALSE;
}

T100VOID T100ProjectViewBase::uninit()
{

}

T100VOID T100ProjectViewBase::SetDirty()
{
    m_dirty     = T100TRUE;
}

T100VOID T100ProjectViewBase::ClearDirty()
{
    m_dirty     = T100FALSE;
}

T100BOOL T100ProjectViewBase::IsDirty()
{
    return m_dirty;
}

wxAuiManager* T100ProjectViewBase::GetAuiManager()
{
    return m_manager;
}

T100ProjectFrame* T100ProjectViewBase::GetFrame()
{
    return m_frame;
}

T100ProjectViewMainMenu* T100ProjectViewBase::GetMainMenu()
{
    return m_mainMenu;
}

T100ProjectTree* T100ProjectViewBase::GetProjectTree()
{
    return m_projectTree;
}

T100MainPanel* T100ProjectViewBase::GetMainPanel()
{
    return m_mainPanel;
}

T100BuildPanel* T100ProjectViewBase::GetBuildPanel()
{
    return m_buildPanel;
}

T100VOID T100ProjectViewBase::SetTitle()
{
    T100WSTRING         title;
    T100Editor*         current     = T100NULL;

    if(m_mainPanel){
        current     = m_mainPanel->GetCurrentEditor();

        if(current){
            if(m_dirty){
                title   = m_projectName + L" - " + current->GetPath() + L"*";
            }else{
                title   = m_projectName + L" - " + current->GetPath();
            }
        }else{
            title   = m_projectName;
        }
    }else{
        title   = m_projectName;
    }

    m_frame->SetLabel(title);
}

T100BOOL T100ProjectViewBase::CheckMainPanel()
{
    if(m_mainPanel){
        return T100TRUE;
    }

    m_mainPanel     = T100NEW T100MainPanel(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FLAT);
    if(m_manager->AddPane(m_mainPanel, wxAuiPaneInfo().Center().CloseButton(T100FALSE).CaptionVisible(T100FALSE))){

    }else{
        T100SAFE_DELETE(m_mainPanel);
        return T100FALSE;
    }
    return T100TRUE;
}

T100INT T100ProjectViewBase::ShowDirDialog(T100WSTRING& path)
{
    T100INT             result;
    wxDirDialog         dialog(m_frame);

    result  = dialog.ShowModal();

    if(result == wxID_OK){
        path    = dialog.GetPath().ToStdWstring();
    }

    return result;
}

T100BOOL T100ProjectViewBase::ShowWorkSpaceCreateDialog(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WorkSpaceCreateDialog       dialog(m_frame, wxID_ANY, L"Create WorkSpace...");

    if(dialog.ShowModal() == wxID_APPLY){
        info->SetPath(dialog.GetWorkSpacePath());
        info->SetPythonFile(dialog.GetPythonFile());
        info->SetCompilerPath(dialog.GetCompilerPath());
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectViewBase::ShowWorkSpaceNotExistsDialog()
{
    T100INT     result;

    result = wxMessageBox(L"", L"", wxYES_NO | wxCANCEL, m_frame);

    if(result == wxYES){
        return T100TRUE;
    }else{

    }

    return T100FALSE;
}

T100INT T100ProjectViewBase::ShowWorkSpaceFileExistsDialog()
{
    T100INT     result;

    result = wxMessageBox(L"WorkSpace's config file with the same name already exists in the workspace's folder, Are you sure you want to overwrite it?", L"Message", wxYES_NO | wxCANCEL, m_frame);

    return result;
}

T100BOOL T100ProjectViewBase::ShowWorkSpaceFileNotExistsDialog()
{
    T100INT     result;

    result = wxMessageBox(L"WorkSpace's config file not exists in the workspace's folder, Are you sure you want to create it?", L"Message", wxYES | wxCANCEL, m_frame);

    if(result == wxYES){
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100ProjectViewBase::ShowWorkSpacePropertiesDialog()
{
    T100WorkSpacePropertiesDialog       dialog(m_frame, wxID_ANY, L"WorkSpace Properties...");

    dialog.ShowModal();
}

T100VOID T100ProjectViewBase::ShowWorkSpaceOpenFailureDialog()
{
    wxMessageBox(L"WorkSpace open failure!", L"Message", wxCLOSE, m_frame);
}

T100VOID T100ProjectViewBase::ShowProjectCreateWizard()
{
    T100ProjectCreateWizard     wizard(m_frame);

    wizard.CentreOnScreen();

    wizard.RunWizard(wizard.GetFirstPage());
}

T100VOID T100ProjectViewBase::ShowModuleCreateDialog()
{

}

T100VOID T100ProjectViewBase::ShowBuildPanel()
{
    if(m_buildPanel){

    }else{
        m_buildPanel    = T100NEW T100BuildPanel(m_frame, wxID_ANY);
        if(m_manager->AddPane(m_buildPanel, wxAuiPaneInfo().Bottom())){

        }else{
            T100SAFE_DELETE(m_buildPanel);
            return;
        }
    }

    m_buildPanel->Show();
    m_manager->Update();
}

T100VOID T100ProjectViewBase::ShowAboutDialog()
{
    T100ProjectViewAboutDialog      dialog(m_frame, wxID_ANY, L"About...");

    dialog.CentreOnScreen();
    dialog.ShowModal();
}
