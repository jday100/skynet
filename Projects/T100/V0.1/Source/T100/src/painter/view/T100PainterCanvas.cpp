#include "T100PainterCanvas.h"

#include "T100ElementBase.h"

namespace T100Painter{

BEGIN_EVENT_TABLE(T100PainterCanvas,wxScrolledWindow)
    EVT_PAINT(T100PainterCanvas::OnPaint)
END_EVENT_TABLE()

T100PainterCanvas::T100PainterCanvas(wxWindow *parent, wxWindowID winid, const wxPoint& pos,
                     const wxSize& size, long style, const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name),
    m_elements()
{
    //ctor
}

T100PainterCanvas::~T100PainterCanvas()
{
    //dtor
}

T100PAINTER_ELEMENT_VECTOR& T100PainterCanvas::getElements()
{
    return m_elements;
}

void T100PainterCanvas::OnPaint(wxPaintEvent& event)
{
    for(T100ElementBase* item : m_elements){
        item->draw();
    }
}

}
