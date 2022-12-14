#include "T100IDEView.h"

#include "T100IDEMainFrame.h"
#include "T100IDEPlatenManager.h"
#include "T100IDEViewManager.h"
#include "T100IDEPlatenBase.h"

namespace T100IDE{

T100IDEView::T100IDEView()
{
    //ctor
    create();
}

T100IDEView::~T100IDEView()
{
    //dtor
    destroy();
}

T100VOID T100IDEView::create()
{
    m_manager   = T100NEW T100IDEViewManager();

    m_frame     = T100NEW T100IDEMainFrame(m_manager->getDocManager(), m_parent);
    m_frame->setView(this);
    m_manager->getAuiManager()->SetFrame(m_frame);

    m_platen    = T100NEW T100IDEPlatenManager(this);
    if(m_platen){
        m_platen->getDefault()->create();
    }
}

T100VOID T100IDEView::destroy()
{
    T100SAFE_DELETE(m_frame);
    T100SAFE_DELETE(m_platen);
    T100SAFE_DELETE(m_manager);
}

T100IDEMainFrame* T100IDEView::getFrame()
{
    return m_frame;
}

T100IDEViewManager* T100IDEView::getViewManager()
{
    return m_manager;
}

T100IDEPlatenManager* T100IDEView::getPlatenManager()
{
    return m_platen;
}

T100VOID T100IDEView::show()
{
    if(m_frame){
        m_frame->Show();
    }

    m_manager->getAuiManager()->Update();
}

}
