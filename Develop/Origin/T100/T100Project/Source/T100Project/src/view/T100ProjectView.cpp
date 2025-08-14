#include "T100ProjectView.h"

#include "T100ProjectMain.h"
#include "T100ProjectViewAboutDialog.h"

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

    m_manager->AddPane(m_projectTree, wxAuiPaneInfo().MinSize(100, -1).BestSize(300, -1).Left());

    m_frame->Maximize();
    m_manager->Update();
}

T100VOID T100ProjectView::Destroy()
{
    m_manager->UnInit();
    m_mainMenu->Destroy();
    T100SAFE_DELETE(m_mainMenu);
}

T100VOID T100ProjectView::WorkSpaceOpen(T100WorkSpaceInfo* info)
{
    m_projectTree->WorkSpaceOpen(info);
}

T100BOOL T100ProjectView::WorkSpaceClose()
{

}

T100VOID T100ProjectView::WorkSpaceSave()
{

}

T100VOID T100ProjectView::WorkSpaceSelected()
{
    m_mainMenu->WorkSpaceSelected();
}

T100VOID T100ProjectView::ProjectOpen(T100ProjectInfo* info)
{
    m_projectTree->ProjectOpen(info);
}

T100VOID T100ProjectView::ProjectSelected()
{
    m_mainMenu->ProjectSelected();
}

T100VOID T100ProjectView::FileModified()
{
    m_mainMenu->FileModified();
}

T100VOID T100ProjectView::FileOpen(wxTreeItemId id, T100FileInfo* info)
{
    if(m_mainPanel){

    }else{
        m_mainPanel     = T100NEW T100MainPanel(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FLAT);
        m_manager->AddPane(m_mainPanel, wxAuiPaneInfo().Center().CloseButton(T100FALSE).CaptionVisible(T100FALSE));
    }

    m_mainPanel->Create(info);

    m_projectTree->FileOpen(id, info);

    m_mainMenu->FileOpen();

    SetTitle();

    m_manager->Update();

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

T100VOID T100ProjectView::ShowSetupEditorDialog()
{

}

T100VOID T100ProjectView::ShowSetupCompilerDialog()
{

}

T100VOID T100ProjectView::Load(const T100PROJECT_INFO_VECTOR& projects)
{
    m_projectTree->Load(projects);
}

T100VOID T100ProjectView::New()
{
    m_mainPanel     = T100NEW T100MainPanel(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FLAT);
    m_manager->AddPane(m_mainPanel, wxAuiPaneInfo().Center().CloseButton(T100FALSE).CaptionVisible(T100FALSE));

    T100Editor*     editor      = T100NEW T100Editor(m_mainPanel);

    m_mainPanel->AddPage(editor, L"Editor");
    //m_mainPanel->AddPage(editor, L"Editor");

    m_manager->Update();
}

T100VOID T100ProjectView::Clear()
{
    m_projectTree->Clear();
    m_mainPanel->Clear();
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

T100VOID T100ProjectView::New(T100FileInfo* info)
{
    if(!m_mainPanel){
        m_mainPanel     = T100NEW T100MainPanel(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FLAT);
        m_manager->AddPane(m_mainPanel, wxAuiPaneInfo().Center().CloseButton(T100FALSE).CaptionVisible(T100FALSE));

        m_manager->Update();
    }

    m_mainPanel->Create(info);
}

T100VOID T100ProjectView::Open(T100FileInfo* info)
{
    if(!m_mainPanel){
        m_mainPanel     = T100NEW T100MainPanel(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FLAT);
        m_manager->AddPane(m_mainPanel, wxAuiPaneInfo().Center().CloseButton(T100FALSE).CaptionVisible(T100FALSE));

        m_manager->Update();
    }

    m_mainPanel->Create(info);
}

T100VOID T100ProjectView::FileSave()
{
    if(m_mainPanel){
        m_mainPanel->Save();
    }
}
