#include "T100CanvasStateNone.h"

#include "T100Canvas.h"

T100CanvasStateNone::T100CanvasStateNone()
    :T100CanvasState()
{
    //ctor
}

T100CanvasStateNone::~T100CanvasStateNone()
{
    //dtor
}

T100VOID T100CanvasStateNone::OnEraseBackGround(T100Canvas* canvas, wxEraseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnPaint(T100Canvas* canvas, wxPaintEvent& event)
{
    if(canvas){
        canvas->Paint();
    }
}

T100VOID T100CanvasStateNone::OnMouseEnter(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnMouseLeave(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnMouseLeftDown(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnMouseLeftUp(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnMouseLeftDClick(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnMouseMove(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStateNone::OnKeyUp(T100Canvas* canvas, wxKeyEvent& event)
{

}

T100VOID T100CanvasStateNone::OnResize(T100Canvas* canvas, wxSizeEvent& event)
{

}

T100VOID T100CanvasStateNone::OnScrollBottom(T100Canvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100CanvasStateNone::OnScrollLineDown(T100Canvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100CanvasStateNone::OnScrollPageDown(T100Canvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100CanvasStateNone::OnScrollThumbTrack(T100Canvas* canvas, wxScrollWinEvent& event)
{

}
