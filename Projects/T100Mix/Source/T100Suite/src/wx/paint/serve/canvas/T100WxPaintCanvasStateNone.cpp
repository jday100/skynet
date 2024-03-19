#include "T100WxPaintCanvasStateNone.h"

#include <wx/dcclient.h>
#include "T100WxPaintCanvas.h"

T100WxPaintCanvasStateNone::T100WxPaintCanvasStateNone()
    :T100WxPaintCanvasStateBase()
{
    //ctor
}

T100WxPaintCanvasStateNone::~T100WxPaintCanvasStateNone()
{
    //dtor
}

T100VOID T100WxPaintCanvasStateNone::OnPaint(wxPaintEvent& event, T100WxPaintCanvas* canvas)
{
    wxClientDC      dc(canvas);

    dc.DrawCircle(100, 100, 10);
}

T100VOID T100WxPaintCanvasStateNone::OnMouseLeftDown(wxMouseEvent& event)
{

}

T100VOID T100WxPaintCanvasStateNone::OnMouseLeftUp(wxMouseEvent& event)
{

}

T100VOID T100WxPaintCanvasStateNone::OnMouseLeftDClick(wxMouseEvent& event)
{

}

T100VOID T100WxPaintCanvasStateNone::OnMouseMove(wxMouseEvent& event)
{

}

T100VOID T100WxPaintCanvasStateNone::OnKeyUp(wxKeyEvent& event)
{

}
