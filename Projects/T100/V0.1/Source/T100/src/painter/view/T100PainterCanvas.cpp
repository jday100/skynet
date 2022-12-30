#include "T100PainterCanvas.h"

#include <wx/dcbuffer.h>
#include "T100ElementBase.h"
#include "T100PainterCallback.h"

namespace T100Painter{

BEGIN_EVENT_TABLE(T100PainterCanvas,wxScrolledWindow)
    EVT_PAINT(T100PainterCanvas::OnPaint)
    //
    EVT_LEFT_DOWN(T100PainterCanvas::OnMouseLeftDown)
    EVT_LEFT_UP(T100PainterCanvas::OnMouseLeftUp)
    EVT_MOVING(T100PainterCanvas::OnMouseMoving)
    //
END_EVENT_TABLE()

T100PainterCanvas::T100PainterCanvas(wxWindow *parent, wxWindowID winid, const wxPoint& pos,
                     const wxSize& size, long style, const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name)
{
    //ctor
    create();
}

T100PainterCanvas::~T100PainterCanvas()
{
    //dtor
    destroy();
}

T100VOID T100PainterCanvas::create()
{

}

T100VOID T100PainterCanvas::destroy()
{

}

T100BOOL T100PainterCanvas::Load(T100PAINTER_ELEMENT_VECTOR* elements)
{
    m_elements = elements;
    return T100TRUE;
}

void T100PainterCanvas::OnPaint(wxPaintEvent& event)
{
    if(!m_elements)return;

    wxBufferedPaintDC       dc(this);

    for(T100ElementBase* item : *m_elements){
        item->draw(dc);
    }
}

void T100PainterCanvas::OnMouseLeftDown(wxMouseEvent& event)
{
    T100PainterCallback::canvas_mouse_left_down(&event);
}

void T100PainterCanvas::OnMouseLeftUp(wxMouseEvent& event)
{
    T100PainterCallback::canvas_mouse_left_up(&event);
}

void T100PainterCanvas::OnMouseMoving(wxMoveEvent& event)
{
    T100PainterCallback::canvas_mouse_moving();
}

}
