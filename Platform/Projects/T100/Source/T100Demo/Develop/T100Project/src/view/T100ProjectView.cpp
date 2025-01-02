#include "T100ProjectView.h"

#include "T100ProjectMDIMainFrame.h"
#include "T100ProjectViewManager.h"
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
    m_frame->setView(this);
    m_manager->getAuiManager()->SetFrame(m_frame);

    m_platen    = T100NEW T100ProjectPlatenManager(this);
    if(m_platen){
        m_platen->getDefault()->create();
    }
}

T100VOID T100ProjectView::destroy()
{
    m_manager->getAuiManager()->UnInit();

    T100SAFE_DELETE m_frame;
    T100SAFE_DELETE m_platen;
    T100SAFE_DELETE m_manager;
}

wxFrame* T100ProjectView::getFrame()
{
    return m_frame;
}

T100ProjectViewManager* T100ProjectView::getViewManager()
{
    return m_manager;
}

T100ProjectPlatenManager* T100ProjectView::getPlatenManager()
{
    return m_platen;
}

T100BOOL T100ProjectView::show()
{
    m_frame->Show();
    m_manager->getAuiManager()->Update();

    return T100TRUE;
}

T100BOOL T100ProjectView::hide()
{
    return m_frame->Hide();
}

T100BOOL T100ProjectView::close()
{
    exit(0);
}
