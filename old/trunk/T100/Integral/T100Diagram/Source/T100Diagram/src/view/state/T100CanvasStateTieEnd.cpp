#include "T100CanvasStateTieEnd.h"

#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateTieEnd::T100CanvasStateTieEnd() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateTieEnd::~T100CanvasStateTieEnd()
{
    //dtor
}

T100VOID T100CanvasStateTieEnd::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieEnd::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieEnd::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieEnd::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieEnd::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieEnd::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());

        T100DiagramInvoking::OnTieEnd(value);
    }
}

T100VOID T100CanvasStateTieEnd::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{

}
