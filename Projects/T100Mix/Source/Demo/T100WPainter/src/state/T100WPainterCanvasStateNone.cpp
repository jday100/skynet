#include "T100WPainterCanvasStateNone.h"

#include "T100WPainterCanvas.h"

T100WPainterCanvasStateNone::T100WPainterCanvasStateNone()
    :T100WPainterCanvasState()
{
    //ctor
}

T100WPainterCanvasStateNone::~T100WPainterCanvasStateNone()
{
    //dtor
}

T100VOID T100WPainterCanvasStateNone::OnEraseBackGround(T100WPainterCanvas* canvas, wxEraseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnPaint(T100WPainterCanvas* canvas, wxPaintEvent& event)
{
    if(canvas){
        canvas->Paint();
    }
}

T100VOID T100WPainterCanvasStateNone::OnMouseEnter(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnMouseLeave(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnMouseLeftDown(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnMouseLeftUp(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnMouseLeftDClick(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnMouseMove(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnKeyUp(T100WPainterCanvas* canvas, wxKeyEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnResize(T100WPainterCanvas* canvas, wxSizeEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnScrollBottom(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnScrollLineDown(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnScrollPageDown(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStateNone::OnScrollThumbTrack(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}
