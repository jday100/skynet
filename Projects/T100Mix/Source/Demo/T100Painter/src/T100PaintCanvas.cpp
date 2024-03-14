#include "T100PaintCanvas.h"

#include <wx/dcclient.h>

BEGIN_EVENT_TABLE(T100PaintCanvas,wxScrolledWindow)
    EVT_PAINT(T100PaintCanvas::OnPaint)
END_EVENT_TABLE()

T100PaintCanvas::T100PaintCanvas(wxWindow *parent,
                     wxWindowID winid,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name)
{
    //ctor
}

T100PaintCanvas::~T100PaintCanvas()
{
    //dtor
}

void T100PaintCanvas::OnPaint(wxPaintEvent& event)
{
    wxClientDC      dc(this);

    dc.DrawCircle(100, 100, 10);
}

void T100PaintCanvas::OnEraseBackground(wxEraseEvent& event)
{
}

void T100PaintCanvas::OnMouseWheel(wxMouseEvent& event)
{
}

void T100PaintCanvas::OnResize(wxSizeEvent& event)
{
}

void T100PaintCanvas::OnLeftDClick(wxMouseEvent& event)
{
}

void T100PaintCanvas::OnLeftDown(wxMouseEvent& event)
{
}
