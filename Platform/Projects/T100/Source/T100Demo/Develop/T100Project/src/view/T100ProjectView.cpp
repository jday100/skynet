#include "T100ProjectView.h"

#include "T100ProjectPlatenManager.h"

T100ProjectView::T100ProjectView()
{
    //ctor
    create();
}

T100ProjectView::~T100ProjectView()
{
    //dtor
    destroy();
}

T100VOID T100ProjectView::create()
{
    m_manager   = T100NEW T100ProjectViewManager();
    m_frame     = T100NEW T100ProjectMDIMainFrame(m_manager->getDocManager(), 0, wxID_ANY, wxT(""));
    m_manager->getAuiManager()->SetFrame(m_frame);

    m_platen    = T100NEW T100ProjectPlatenManager(this);
    if(m_platen){
        m_platen->getDefault()->create();
    }
}

T100VOID T100ProjectView::destroy()
{
    T100SAFE_DELETE m_frame;
    T100SAFE_DELETE m_platen;
    T100SAFE_DELETE m_manager;
}

wxFrame* T100ProjectView::getFrame()
{
    return m_frame;
}

T100BOOL T100ProjectView::show()
{
    return m_frame->Show();
}

T100BOOL T100ProjectView::hide()
{
    return m_frame->Hide();
}
