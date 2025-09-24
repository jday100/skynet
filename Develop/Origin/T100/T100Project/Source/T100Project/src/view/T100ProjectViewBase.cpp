#include "T100ProjectViewBase.h"

#include <wx/msgdlg.h>
#include "T100ProjectMain.h"
#include "T100SetupCompilerDialog.h"

#include "T100ProjectCreateWizard.h"
#include "T100WorkSpaceCreateWizard.h"
#include "T100ModuleCreateDialog.h"

#include "T100ProjectInvoking.h"

T100ProjectViewBase::T100ProjectViewBase()
{
    //ctor
    m_dirty     = T100FALSE;
}

T100ProjectViewBase::~T100ProjectViewBase()
{
    //dtor
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

T100VOID T100ProjectViewBase::UpdateTitle()
{
    T100WSTRING         path;
    T100WSTRING         title;

    if(m_mainPanel){
        path    = m_mainPanel->GetCurrentFilePath();

        if(path.empty()){
            path    = m_mainPanel->GetCurrentLabel();
        }

        m_mainPanel->UpdateCurrentLabel();
    }

    if(path.empty()){
        title   = m_projectTitle;
    }else{
        if(m_dirty){
            title   = m_projectTitle + L" - " + path + L"*";
        }else{
            title   = m_projectTitle + L" - " + path;
        }
    }
    m_frame->SetLabel(title);
}

T100VOID T100ProjectViewBase::ShowViewWorkSpaceTree(T100BOOL value)
{
    if(value){
        m_manager->GetPane(m_projectTree).Show();
    }else{
        m_manager->GetPane(m_projectTree).Hide();
    }
    m_mainMenu->ViewWorkSpaceTree(value);
    m_manager->Update();
}

T100VOID T100ProjectViewBase::ShowViewSearchResult(T100BOOL value)
{
    if(value){
        m_manager->GetPane(m_debugPanel).Show();
    }else{
        m_manager->GetPane(m_debugPanel).Hide();
    }
    m_mainMenu->ViewSearchResult(value);
    m_manager->Update();
}

T100VOID T100ProjectViewBase::ShowViewCompileOutput(T100BOOL value)
{
    if(value){
        m_manager->GetPane(m_compilePanel).Show();
    }else{
        m_manager->GetPane(m_compilePanel).Hide();
    }
    m_mainMenu->ViewCompileOutput(value);
    m_manager->Update();
}

T100VOID T100ProjectViewBase::ShowWorkSpaceCreateWizard()
{
    T100WorkSpaceCreateWizard       wizard(m_frame);

    wizard.RunWizard(wizard.GetFirstPage());
}

T100VOID T100ProjectViewBase::ShowWorkSpacePopupMenu(T100BOOL value)
{
    m_projectTree->ShowWorkSpacePopupMenu(value);
}

T100BOOL T100ProjectViewBase::ShowWorkSpaceNotExistsDialog()
{
    T100INT     result;

    result = wxMessageBox(L"Directory is not exists, Create it?", L"Error", wxICON_WARNING | wxYES | wxNO | wxCANCEL, m_frame);

    if(result == wxYES){
        return T100TRUE;
    }
    return T100FALSE;
}

T100INT T100ProjectViewBase::ShowWorkSpaceFileExistsDialog()
{
    T100INT     result;

    result = wxMessageBox(L"WorkSpace's config file with the same name already exists in the workspace's folder,\
                          \nAre you sure you want to overrite it?", L"Warning",
                          wxICON_WARNING | wxYES | wxNO | wxCANCEL, m_frame);

    return result;
}

T100VOID T100ProjectViewBase::ShowWorkSpaceFileNotExistsDailog()
{
    wxMessageBox(L"WorkSpace's config file not exists in the workspace's folder!", L"Error",
                          wxICON_ERROR | wxCLOSE, m_frame);
}

T100VOID T100ProjectViewBase::ShowWorkSpaceCreateFailureDialog()
{
    wxMessageBox(L"WorkSpace create failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}

T100VOID T100ProjectViewBase::ShowWorkSpaceOpenFailureDialog()
{
    wxMessageBox(L"WorkSpace open failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}

T100INT T100ProjectViewBase::ShowWorkSpaceNotSaveDialog()
{
    T100INT     result;

    result = wxMessageBox(L"Some file not save, Save it?", L"Info", wxICON_WARNING | wxYES | wxNO | wxCANCEL, m_frame);

    return result;
}


T100VOID T100ProjectViewBase::ShowProjectCreateWizard()
{
    T100ProjectCreateWizard         wizard(m_frame);

    wizard.RunWizard(wizard.GetFirstPage());
}

T100VOID T100ProjectViewBase::ShowProjectCreateFailureDialog()
{
    wxMessageBox(L"Project create failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}


T100VOID T100ProjectViewBase::ShowFileOpenFailureDialog()
{
    wxMessageBox(L"File open failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}


T100VOID T100ProjectViewBase::ShowSetupCompilerDialog()
{
    T100SetupCompilerDialog     dialog(m_frame, wxID_ANY, L"Setup Compiler...");

    dialog.ShowModal();
}

T100INT T100ProjectViewBase::ShowFolderDialog(T100WSTRING& path)
{
    T100INT         result;
    wxDirDialog     dialog(m_frame);

    result  = dialog.ShowModal();

    if(result == wxID_OK){
        path    = dialog.GetPath().ToStdWstring();
    }

    return result;
}

T100INT T100ProjectViewBase::ShowFileNameDialog(T100WxFileInfo& info)
{
    T100INT         result;
    wxFileDialog    dialog(m_frame);

    result  = dialog.ShowModal();

    if(result == wxID_OK){
        info.SetLabel(dialog.GetFilename().ToStdWstring());
        info.SetPath(dialog.GetPath().ToStdWstring());
    }

    return result;
}

T100INT T100ProjectViewBase::ShowModuleCreateDialog()
{
    T100INT                         result;
    T100ModuleCreateDialog          dialog(m_frame, wxID_ANY, L"Create Module...");

    if(dialog.ShowModal() == wxID_APPLY){
        T100ProjectInvoking::OnModuleCreateDone(dialog.GetModuleInfo());
    }

    return result;
}
