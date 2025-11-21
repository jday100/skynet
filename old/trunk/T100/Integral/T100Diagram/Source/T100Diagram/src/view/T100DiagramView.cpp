#include "T100DiagramView.h"

#include <wx/filedlg.h>
#include "T100DiagramMain.h"
#include "T100Canvas.h"
#include "T100SourceImportDialog.h"

T100DiagramView::T100DiagramView()
{
    //ctor
}

T100DiagramView::~T100DiagramView()
{
    //dtor
}

T100VOID T100DiagramView::Create(T100DiagramFrame* frame)
{
    m_frame         = frame;

    m_manager       = T100NEW wxAuiManager(m_frame);

    m_mainMenu      = T100NEW T100MainMenu();
    m_mainMenu->Create(m_frame);

    m_managerPanel  = T100NEW T100DiagramManagerPanel(m_frame);
    m_propertyPanel = T100NEW T100DiagramPropertyPanel(m_frame);
    m_canvas        = T100NEW T100Canvas(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB);

    m_manager->AddPane(m_managerPanel, wxAuiPaneInfo().Name(wxT("Manager")).Caption(wxT("Manager")).MinSize(100, -1).BestSize(300, -1).Left());
    m_manager->AddPane(m_propertyPanel, wxAuiPaneInfo().Name(wxT("Property")).Caption(wxT("Property")).MinSize(100, -1).BestSize(300, -1).Left());
    m_manager->AddPane(m_canvas, wxAuiPaneInfo().Name(wxT("Canvas")).Caption(wxT("Canvas")).CloseButton(T100FALSE).Center());

    m_mainMenu->ViewManager(T100TRUE);
    m_mainMenu->ViewProperty(T100TRUE);

    m_frame->Maximize();
    m_manager->Update();
}

T100VOID T100DiagramView::Destroy()
{
    m_manager->UnInit();
    m_mainMenu->Destroy();

    T100SAFE_DELETE(m_canvas);
    T100SAFE_DELETE(m_mainMenu);
    T100SAFE_DELETE(m_manager);
}

T100VOID T100DiagramView::Position(T100ElementBase* element)
{
    if(!element){
        return;
    }

    m_canvas->SetCursor(wxCURSOR_CROSS);
    m_canvas->m_current = element;
    m_canvas->Change(T100CANVAS_STATE_CREATE);

    m_canvas->Refresh();
}

T100VOID T100DiagramView::Edit(T100ElementBase* element)
{
    if(!element){
        return;
    }

    m_canvas->Edit(element);
}

T100VOID T100DiagramView::Select(T100ElementBase* element)
{
    if(!element){
        return;
    }

    m_canvas->Select(element);
}

T100VOID T100DiagramView::Tie(T100ElementBase* element)
{
    if(!element){
        return;
    }

    m_canvas->SetCursor(wxCURSOR_CROSS);
    m_canvas->m_current = element;
    m_canvas->Change(T100CANVAS_STATE_TIE_START);

    m_canvas->Refresh();
}

T100VOID T100DiagramView::TieStart(T100ElementBase* element)
{
    if(!element){
        return;
    }

    m_canvas->TieStart(element);
}

T100VOID T100DiagramView::TieEnd(T100ElementBase* element)
{
    if(!element){
        return;
    }

    if(m_canvas->TieEnd(element)){
        m_managerPanel->Clear();
    }
}

T100BOOL T100DiagramView::Create()
{
    m_canvas->Clear();
    return T100TRUE;
}

T100BOOL T100DiagramView::Open(T100DiagramInfo* info)
{
    if(m_canvas->Open(info)){
        m_mainMenu->Open();
        UpdateTitle();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramView::Append()
{
    if(m_canvas->Append()){
        m_managerPanel->Clear();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramView::Save()
{
    if(m_canvas->Save()){
        m_mainMenu->Save();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramView::Remove()
{
    return m_canvas->Remove();
}

T100BOOL T100DiagramView::Close()
{
    if(m_canvas->Clear()){
        m_mainMenu->Close();
        UpdateTitle(T100FALSE);
    }
}

T100VOID T100DiagramView::Quit()
{
    m_frame->Destroy();
}

T100VOID T100DiagramView::Dirty()
{
    m_mainMenu->Dirty();
    UpdateTitle(T100TRUE);
}

T100VOID T100DiagramView::CanvasState(T100STRING& value)
{
    m_frame->SetStatusText(value, 1);
}

T100VOID T100DiagramView::CanvasPosition(T100STRING& value)
{
    m_frame->SetStatusText(value, 2);
}

T100VOID T100DiagramView::ShowViewManager(T100BOOL flag)
{
    if(flag){
        m_manager->GetPane(m_managerPanel).Show();
    }else{
        m_manager->GetPane(m_managerPanel).Hide();
    }
    m_mainMenu->ViewManager(flag);
    m_manager->Update();
}

T100VOID T100DiagramView::ShowViewProperty(T100BOOL flag)
{
    if(flag){
        m_manager->GetPane(m_propertyPanel).Show();
    }else{
        m_manager->GetPane(m_propertyPanel).Hide();
    }
    m_mainMenu->ViewProperty(flag);
    m_manager->Update();
}

T100BOOL T100DiagramView::ShowOpenFileDialog(T100WSTRING& path)
{
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_OK == dialog.ShowModal()){
        path    = dialog.GetPath().ToStdWstring();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramView::ShowSaveFileDialog(T100WSTRING& path)
{
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_OK == dialog.ShowModal()){
        path    = dialog.GetPath().ToStdWstring();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramView::ShowSourceImportDialog()
{
    T100SourceImportDialog      dialog(m_frame);

    if(wxID_OK == dialog.ShowModal()){
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100DiagramView::UpdateTitle(T100BOOL flag)
{
    m_frame->SetLabel(m_projectTitle);
}

T100VOID T100DiagramView::Update()
{
    m_canvas->UpdateDiagram();
    m_mainMenu->Dirty();
    UpdateTitle(T100TRUE);
}
