#include "T100ProjectView.h"

#include "T100ProjectMain.h"

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
    m_frame         = frame;
    m_manager       = T100NEW wxAuiManager(m_frame);

    m_mainMenu      = T100NEW T100MainMenu();

    m_mainMenu->Create(m_frame);

    m_projectTree   = T100NEW T100ProjectTree(m_frame);
    m_compilePanel  = T100NEW T100CompilePanel(m_frame, wxID_ANY);
    m_debugPanel    = T100NEW T100DebugPanel(m_frame, wxID_ANY);

    m_manager->AddPane(m_projectTree, wxAuiPaneInfo().Name(wxT("WorkSpace")).MinSize(100, -1).BestSize(300, -1).Left());
    m_manager->AddPane(m_compilePanel, wxAuiPaneInfo().Name(wxT("CompileOutput")).MinSize(-1, 100).BestSize(-1, 300).Bottom());
    m_manager->AddPane(m_debugPanel, wxAuiPaneInfo().Name(wxT("DebugOutput")).MinSize(-1, 100).BestSize(-1, 300).Bottom());

    m_mainMenu->ViewWorkSpaceTree();
    m_mainMenu->ViewSearchResult();
    m_mainMenu->ViewCompileOutput();

    m_frame->Maximize();
    m_manager->Update();
}

T100VOID T100ProjectView::Destroy()
{
    m_manager->UnInit();
    m_mainMenu->Destroy();
    T100SAFE_DELETE(m_mainMenu);
    T100SAFE_DELETE(m_projectTree);
    T100SAFE_DELETE(m_compilePanel);
    T100SAFE_DELETE(m_mainPanel);
}

T100BOOL T100ProjectView::WorkSpaceOpen(T100WorkSpaceInfo* info)
{
    if(m_projectTree->WorkSpaceOpen(info)){
        m_mainMenu->WorkSpaceOpen();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectView::WorkSpaceClose()
{
    Clear();
    return T100TRUE;
}

T100BOOL T100ProjectView::ProjectAppend(T100ProjectInfo* info)
{
    return m_projectTree->ProjectAppend(info);
}

T100BOOL T100ProjectView::ProjectOpen(wxTreeItemId id, T100ProjectInfo* info)
{
    if(m_projectTree->ProjectOpen(id, info)){
        m_mainMenu->ProjectOpen();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectView::ProjectSelect()
{
    m_mainMenu->ProjectSelect();
}

T100BOOL T100ProjectView::ProjectBuild()
{
    m_mainMenu->ProjectBuild();
}

T100BOOL T100ProjectView::FolderList(wxTreeItemId id, T100FolderInfo* info)
{
    return m_projectTree->FolderList(id, info);
}

T100BOOL T100ProjectView::FileSelect()
{
    m_mainMenu->FileSelect();
    return T100TRUE;
}

T100BOOL T100ProjectView::FileSelect(wxTreeItemId id, T100FileInfo* info)
{
    return m_mainPanel->Select(info);
}

T100BOOL T100ProjectView::FileSelect(T100FileInfo* info)
{
    return m_mainPanel->Select(info);
}

T100BOOL T100ProjectView::FileOpen(wxTreeItemId id, T100FileInfo* info)
{
    if(!CheckMainPanel()){
        return T100FALSE;
    }

    if(!m_mainPanel->Open(info)){
        return T100FALSE;
    }

    m_mainMenu->FileOpen();
    UpdateTitle();

    m_manager->Update();
}

T100BOOL T100ProjectView::FileOpen(T100FileInfo* info)
{
    if(!CheckMainPanel()){
        return T100FALSE;
    }

    if(!m_mainPanel->Open(info)){
        return T100FALSE;
    }

    m_mainMenu->FileOpen();
    UpdateTitle();

    m_manager->Update();
}


T100VOID T100ProjectView::FileModified()
{
    m_mainMenu->FileModified();
    SetDirty();
    UpdateTitle();
}

T100BOOL T100ProjectView::FileSave()
{
    if(!m_mainPanel)
    {
        return T100FALSE;
    }

    T100WxFileInfo      info;
    T100WSTRING         path;

    path    = m_mainPanel->GetCurrentFilePath();

    if(path.empty()){
        if(ShowFileNameDialog(info) == wxID_OK){
            m_mainPanel->GetCurrentEditor()->SetPath(path);
        }else{
            return T100FALSE;
        }
    }

    if(path.empty()){
        return T100FALSE;
    }

    if(m_mainPanel->Save()){
        m_mainMenu->FileSave();
        ClearDirty();
        UpdateTitle();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectView::FileSaveAs(T100WxFileInfo* info)
{
    return m_mainPanel->SaveAs(info);
}

T100BOOL T100ProjectView::FileRemove(T100FileInfo* info)
{
    return m_mainPanel->Close(info);
}

T100BOOL T100ProjectView::FileRemove(wxTreeItemId id, T100FileInfo* info)
{
    if(id.IsOk() && info){

    }else{
        return T100FALSE;
    }

    if(m_mainPanel->Close(info)){

    }else{
        return T100FALSE;
    }

    if(m_projectTree->Remove(id)){

    }else{
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100ProjectView::DebugPrint(const T100WSTRING& value)
{
    return m_debugPanel->Append(value);
}

T100BOOL T100ProjectView::CheckMainPanel()
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
    m_manager->Update();
    return T100TRUE;
}

T100BOOL T100ProjectView::Clear()
{
    if(m_projectTree->Clear()){
        if(m_mainPanel){
            if(!m_mainPanel->Clear()){
                return T100FALSE;
            }
        }
        m_mainMenu->Clear();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectView::Quit()
{
    m_frame->Close();
}

T100BOOL T100ProjectView::ModuleAppend(T100WorkSpaceInfo* workspace, T100ProjectInfo* project, T100ModuleInfo* module)
{
    return m_projectTree->ModuleAppend(workspace, project, module);
}

wxTreeItemId T100ProjectView::GetSelection()
{
    return m_projectTree->GetSelection();
}

const T100WSTRING T100ProjectView::GetCurrentFilePath()
{
    return m_mainPanel->GetCurrentFilePath();
}
