#include "T100ProjectView.h"

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

T100VOID T100ProjectView::show()
{
    /*
    if(m_frame){
        m_frame->Show();
    }

    if(m_manager){
        m_manager->Update();
    }
    */
}

}
