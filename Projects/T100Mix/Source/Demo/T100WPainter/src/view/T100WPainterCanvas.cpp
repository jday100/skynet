#include "T100WPainterCanvas.h"

#include <wx/dcclient.h>

BEGIN_EVENT_TABLE(T100WPainterCanvas,wxScrolledWindow)
    EVT_PAINT(T100WPainterCanvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100WPainterCanvas::OnEraseBackGround)
END_EVENT_TABLE()

T100WPainterCanvas::T100WPainterCanvas(wxWindow *parent,
                     wxWindowID winid,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name)
{
    //ctor
    create();
}

T100WPainterCanvas::~T100WPainterCanvas()
{
    //dtor
    destroy();
}

T100VOID T100WPainterCanvas::create()
{

}

T100VOID T100WPainterCanvas::destroy()
{

}

T100VOID T100WPainterCanvas::Change(T100WORD state)
{

}

void T100WPainterCanvas::OnEraseBackGround(wxEraseEvent& event)
{

}

void T100WPainterCanvas::OnPaint(wxPaintEvent& event)
{
    wxClientDC          dc(this);

    dc.DrawCircle(100, 100, 10);
}
