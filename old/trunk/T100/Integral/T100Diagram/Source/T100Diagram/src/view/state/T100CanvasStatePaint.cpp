#include "T100CanvasStatePaint.h"

#include <wx/dcbuffer.h>
#include "T100Canvas.h"

T100CanvasStatePaint::T100CanvasStatePaint() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStatePaint::~T100CanvasStatePaint()
{
    //dtor
}

T100VOID T100CanvasStatePaint::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    wxBufferedPaintDC       dc(canvas);

    dc.Clear();
    canvas->DoPrepareDC(dc);

    if(canvas->m_current){
        canvas->m_current->Draw(dc);
    }
}

T100VOID T100CanvasStatePaint::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStatePaint::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStatePaint::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStatePaint::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStatePaint::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStatePaint::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{

}
