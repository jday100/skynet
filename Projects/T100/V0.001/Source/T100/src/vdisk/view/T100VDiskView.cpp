#include "T100VDiskView.h"

T100VDiskView::T100VDiskView()
{
    //ctor
}

T100VDiskView::~T100VDiskView()
{
    //dtor
    destroy();
}

T100VOID T100VDiskView::create()
{
    m_frame = T100NEW T100VDiskFrame(T100NULL);
}

T100VOID T100VDiskView::destroy()
{
    if(m_frame){
        T100DELETE(m_frame);
    }
}

T100VOID T100VDiskView::setFrame(T100VDiskFrame* frame)
{
    m_frame = frame;
}

T100VDiskFrame* T100VDiskView::getFrame()
{
    return m_frame;
}

T100BOOL T100VDiskView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100VDiskView::start()
{
    return T100FALSE;
}
