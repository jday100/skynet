#include "T100WPainterView.h"

T100WPainterView::T100WPainterView()
{
    //ctor
    create();
}

T100WPainterView::~T100WPainterView()
{
    //dtor
    destroy();
}

T100VOID T100WPainterView::create()
{
    m_frame             = T100NEW T100WPainterFrame(0);
    //m_elements_panel    = T100NEW T100WPainterElementsPanel(m_frame);
}

T100VOID T100WPainterView::destroy()
{

}

T100BOOL T100WPainterView::show()
{
    return m_frame->Show();
}

T100WPainterFrame* T100WPainterView::getFrame()
{
    return m_frame;
}
