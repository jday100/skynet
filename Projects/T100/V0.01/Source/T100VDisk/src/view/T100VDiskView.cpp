#include "T100VDiskView.h"

T100VDiskView::T100VDiskView()
{
    //ctor
}

T100VDiskView::~T100VDiskView()
{
    //dtor
}

T100VOID T100VDiskView::setFrame(wxFrame* frame)
{
    m_frame = frame;
}

wxFrame* T100VDiskView::getFrame()
{
    return m_frame;
}
