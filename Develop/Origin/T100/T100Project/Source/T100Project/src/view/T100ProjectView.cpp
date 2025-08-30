#include "T100ProjectView.h"

#include <wx/textdlg.h>
#include "T100EditorPack.h"
#include "T100ProjectMain.h"
#include "T100ProjectViewAboutDialog.h"
#include "T100ProjectViewSetupEditorDialog.h"
#include "T100ProjectViewSetupCompilerDialog.h"

T100ProjectView::T100ProjectView() :
    T100ProjectViewBase()
{
    //ctor
}

T100ProjectView::~T100ProjectView()
{
    //dtor
}

T100VOID T100ProjectView::Create(T100ProjectFrame* frame)
{
    m_frame     = frame;
    m_manager   = T100NEW wxAuiManager(m_frame);
    m_mainMenu  = T100NEW T100ProjectViewMainMenu();

    m_mainMenu->Create(frame);

    m_projectTree   = T100NEW T100ProjectTree(m_frame);
    m_buildPanel    = T100NEW T100BuildPanel(m_frame, wxID_ANY);

    m_manager->AddPane(m_projectTree, wxAuiPaneInfo().MinSize(100, -1).BestSize(300, -1).Left());
    m_manager->AddPane(m_buildPanel, wxAuiPaneInfo().MinSize(-1, 100).BestSize(-1, 300).Bottom());

    SetTitle();

    m_frame->Maximize();
    m_manager->Update();
}

T100VOID T100ProjectView::Destroy()
{
    m_manager->UnInit();
    m_mainMenu->Destroy();
    T100SAFE_DELETE(m_mainMenu);
}

T100BOOL T100ProjectView::WorkSpaceOpen(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    if(m_projectTree->WorkSpaceOpen(info)){

    }else{
        return T100FALSE;
    }

    m_mainMenu->WorkSpaceSelect();

    return T100TRUE;
}

T100BOOL T100ProjectView::WorkSpaceClose()
{

}

T100BOOL T100ProjectView::WorkSpaceSave()
{

}

T100BOOL T100ProjectView::WorkSpaceSelect()
{
    m_mainMenu->WorkSpaceSelect();
    return T100TRUE;
}

T100VOID T100ProjectView::ShowSetupEditorDialog()
{
    T100ProjectViewSetupEditorDialog        dialog(m_frame, wxID_ANY, L"Setup Editor...");

    if(dialog.ShowModal() == wxID_APPLY){

    }
}

T100VOID T100ProjectView::ShowSetupCompilerDialog()
{
    T100ProjectViewSetupCompilerDialog     dialog(m_frame, wxID_ANY, L"Setup Compiler...");

    dialog.ShowModal();
}

T100VOID T100ProjectView::FileClose(T100Pack* pack)
{
    T100WSTRING         filename;
    T100EditorPack*     editor      = T100NULL;

    editor  = dynamic_cast<T100EditorPack*>(pack);

    if(editor){
        if(editor->GetEditor()){
            if(editor->GetEditor()->GetPath().empty()){
                ShowFileName(filename);
                if(filename.empty()){
                    return;
                }
            }else{

            }

            editor->GetEditor()->SetPath(filename);
            editor->GetEditor()->SaveFile(filename);
        }
    }
}

T100VOID T100ProjectView::PageClose(T100Pack* pack)
{
    SetTitle();
}

T100VOID T100ProjectView::ProjectOpen(T100ProjectInfo* info)
{
    m_projectTree->ProjectOpen(info);
}

T100BOOL T100ProjectView::ProjectSelect()
{
    m_mainMenu->ProjectSelect();
    return T100TRUE;
}

T100VOID T100ProjectView::FileModified()
{
    m_mainMenu->FileModified();
}

T100BOOL T100ProjectView::FileOpen(wxTreeItemId id, T100FileInfo* info)
{
    if(!CheckMainPanel()){
        return T100FALSE;
    }

    if(!m_mainPanel->Open(info)){
        return T100FALSE;
    }

    if(!m_projectTree->FileOpen(id, info)){
        return T100FALSE;
    }

    m_mainMenu->FileOpen();

    SetTitle();

    m_manager->Update();

    return T100TRUE;
}

T100VOID T100ProjectView::FolderOpen(wxTreeItemId id, T100FolderInfo* info)
{
    m_projectTree->FolderOpen(id, info);
}

T100VOID T100ProjectView::FolderSelected()
{
    m_mainMenu->FolderSelected();
}

T100VOID T100ProjectView::ProjectOpen(wxTreeItemId id, T100ProjectInfo* info)
{
    m_projectTree->ProjectOpen(id, info);
}

T100VOID T100ProjectView::ShowFileName(T100WSTRING& filename)
{
    wxTextEntryDialog           dialog(m_frame, L"filename");

    if(dialog.ShowModal() == wxID_OK){
        filename    = dialog.GetValue().ToStdWstring();
    }
}

T100VOID T100ProjectView::Load(const T100PROJECT_INFO_VECTOR& projects)
{
    m_projectTree->Load(projects);
}

T100VOID T100ProjectView::Clear()
{
    m_projectTree->Clear();
    if(m_mainPanel){
        m_mainPanel->Clear();
    }

    m_mainMenu->Clear();
}

T100VOID T100ProjectView::About()
{
    T100ProjectViewAboutDialog          dialog(m_frame, wxID_ANY, L"About...");

    dialog.ShowModal();
}

T100VOID T100ProjectView::OnResize()
{
    m_manager->Update();
}

T100VOID T100ProjectView::FileSave()
{
    if(!m_mainPanel){
        return;
    }

    T100Editor*     current     = T100NULL;

    current     = m_mainPanel->GetCurrentEditor();

    if(!current){
        return;
    }

    T100WSTRING         path;
    T100WSTRING         filename;

    path    = current->GetPath();

    if(path.empty()){
        ShowFileName(filename);
        path    = filename;
        if(path.empty()){
            return;
        }
    }

    current->SetPath(path);

    m_mainPanel->Save();

    ClearDirty();
    SetTitle();
}

T100VOID T100ProjectView::PageChanged()
{
    SetTitle();
}


