#include "wx\paint\view\T100WxPaintCanvas.h"

#include <wx/dcclient.h>

BEGIN_EVENT_TABLE(T100WxPaintCanvas,wxScrolledWindow)
    EVT_PAINT(T100WxPaintCanvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100WxPaintCanvas::OnEraseBackGround)
    //
    EVT_MOUSEWHEEL(T100WxPaintCanvas::OnMouseWheel)
END_EVENT_TABLE()

T100WxPaintCanvas::T100WxPaintCanvas(wxWindow *parent,
                     wxWindowID winid,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name)
{
    //ctor

    SetSize(600, 400);
}

T100WxPaintCanvas::~T100WxPaintCanvas()
{
    //dtor
}

void T100WxPaintCanvas::OnPaint(wxPaintEvent& event)
{
    wxClientDC      dc(this);

    dc.DrawCircle(100, 100, 10 * m_scale);
}

void T100WxPaintCanvas::OnEraseBackGround(wxEraseEvent& event)
{
}

void T100WxPaintCanvas::OnMouseWheel(wxMouseEvent& event)
{
}

void T100WxPaintCanvas::OnResize(wxSizeEvent& event)
{
}

void T100WxPaintCanvas::OnLeftDClick(wxMouseEvent& event)
{
}

void T100WxPaintCanvas::OnLeftDown(wxMouseEvent& event)
{
    m_scale = 1.2 * m_scale;
    Refresh();
}
