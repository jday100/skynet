#include "T100PainterView.h"

T100PainterView::T100PainterView()
{
    //ctor
    create();
}

T100PainterView::~T100PainterView()
{
    //dtor
    destroy();
}

T100VOID T100PainterView::create()
{
    m_frame             = T100NEW T100PainterFrame(T100NULL);
    m_canvas            = T100NEW T100Canvas(m_frame);
    m_elements_panel    = T100NEW T100PainterElementsPanel(m_frame);

    m_frame->getAuiManager()->AddPane(m_elements_panel, wxAuiPaneInfo().Name(wxT("Elements")).BestSize(300, -1).Left());
    m_frame->getAuiManager()->Update();
}

T100VOID T100PainterView::destroy()
{
    T100DELETE  m_frame;
}

T100BOOL T100PainterView::show()
{
    return m_frame->Show();
}

T100Canvas* T100PainterView::getCanvas()
{
    return m_canvas;
}

T100PainterFrame* T100PainterView::getFrame()
{
    return m_frame;
}
