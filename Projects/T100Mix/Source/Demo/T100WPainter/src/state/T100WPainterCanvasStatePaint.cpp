#include "T100WPainterCanvasStatePaint.h"

#include <wx/dcclient.h>
#include "T100WPainterCanvas.h"

T100WPainterCanvasStatePaint::T100WPainterCanvasStatePaint()
    :T100WPainterCanvasState()
{
    //ctor
}

T100WPainterCanvasStatePaint::~T100WPainterCanvasStatePaint()
{
    //dtor
}

T100VOID T100WPainterCanvasStatePaint::OnEraseBackGround(T100WPainterCanvas* canvas, wxEraseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnPaint(T100WPainterCanvas* canvas, wxPaintEvent& event)
{
    wxClientDC          dc(canvas);

    dc.DrawCircle(100, 100, 10);
}

T100VOID T100WPainterCanvasStatePaint::OnMouseEnter(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeave(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeftDown(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeftUp(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeftDClick(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseMove(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnKeyUp(T100WPainterCanvas* canvas, wxKeyEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnResize(T100WPainterCanvas* canvas, wxSizeEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollBottom(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollLineDown(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollPageDown(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollThumbTrack(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

