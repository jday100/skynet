#include "T100VDiskView.h"
#include "T100VDiskMain.h"


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

T100BOOL T100VDiskView::quit()
{
    T100VDiskFrame*     frame   = T100NULL;

    frame = static_cast<T100VDiskFrame*>(m_frame);

    if(!frame){
        return T100FALSE;
    }

    frame->Close();

    return T100TRUE;
}
