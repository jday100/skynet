#include "T100VPCView.h"

#include "T100VPCFrame.h"
#include "T100VPCScreen.h"
#include "T100VPCConfigDialog.h"


namespace T100VPC{

T100VPCView::T100VPCView()
{
    //ctor
    create();
}

T100VPCView::~T100VPCView()
{
    //dtor
    destroy();
}

T100VOID T100VPCView::create()
{
    m_frame = T100NEW T100VPCFrame(T100NULL);
}

T100VOID T100VPCView::destroy()
{
    T100SAFE_DELETE(m_frame);
}

T100VOID T100VPCView::setFrame(T100VPCFrame* frame)
{
    m_frame = frame;
}

T100VPCFrame* T100VPCView::getFrame()
{
    return m_frame;
}

T100VPCScreen* T100VPCView::getScreen()
{
    return m_screen;
}

T100VPCConfigDialog* T100VPCView::getConfig()
{
    return m_config;
}

T100BOOL T100VPCView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100VPCView::hide()
{
    if(m_frame){
        return m_frame->Hide();
    }
    return T100FALSE;
}

T100BOOL T100VPCView::quit()
{
    T100SAFE_DELETE(m_frame);
}

}
