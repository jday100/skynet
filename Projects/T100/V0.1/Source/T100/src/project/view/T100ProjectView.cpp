#include "T100ProjectView.h"

#include "T100ProjectFrame.h"


namespace T100PROJECT{

T100ProjectView::T100ProjectView()
{
    //ctor
}

T100ProjectView::~T100ProjectView()
{
    //dtor
    destroy();
}

T100BOOL T100ProjectView::create()
{

}

T100VOID T100ProjectView::destroy()
{

}

T100VOID T100ProjectView::setParent(wxWindow* parent)
{
    m_parent = parent;
}

T100VOID T100ProjectView::setRootFrame(wxFrame* frame)
{
    //m_root = frame;
}

T100VOID T100ProjectView::setManager(wxAuiManager* manager)
{
    m_manager = manager;
}


T100BOOL T100ProjectView::create_alone()
{
    m_manager   = T100NEW wxAuiManager();
    m_frame     = T100NEW T100ProjectFrame(T100NULL, wxID_ANY, wxDefaultPosition, wxSize(800, 600));

    m_projects_panel    = T100NEW T100ProjectProjectsPanel(m_frame);

    m_projects_panel->create();

    m_manager->SetFrame(m_frame);
    m_manager->AddPane(m_projects_panel, wxAuiPaneInfo().Name(wxT("Projects")).BestSize(400, -1).Left());

    return T100TRUE;
}

T100BOOL T100ProjectView::create_embed()
{
    if(m_root){
        m_projects_panel    = T100NEW T100ProjectProjectsPanel(m_root);
    }
    return T100TRUE;
}

T100VOID T100ProjectView::show()
{
    if(m_frame){
        m_frame->Show();
    }

    if(m_manager){
        m_manager->Update();
    }
}

T100ProjectProjectsPanel* T100ProjectView::getProjectCtrl()
{
    return m_projects_panel;
}

T100BOOL T100ProjectView::OpenFile(T100STRING& file)
{

}

T100BOOL T100ProjectView::CloseFile()
{

}

T100BOOL T100ProjectView::Quit()
{
    if(m_manager){
        m_manager->UnInit();
    }

    if(m_frame){
        m_frame->Destroy();
    }

    if(m_callback){
        (m_callback_frame->*m_callback)(T100NULL);
    }

    exit(0);

    return T100TRUE;
}

T100BOOL T100ProjectView::LoadFile(T100MansionInfo* info)
{

}

T100BOOL T100ProjectView::UpdateMenu()
{

}

T100BOOL T100ProjectView::ShowProjects()
{
    m_manager->GetPane(m_projects_panel).Show();
    m_manager->Update();
}

}
