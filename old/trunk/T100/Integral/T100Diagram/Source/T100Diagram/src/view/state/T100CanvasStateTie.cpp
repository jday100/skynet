#include "T100CanvasStateTie.h"

#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateTie::T100CanvasStateTie() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateTie::~T100CanvasStateTie()
{
    //dtor
}

T100VOID T100CanvasStateTie::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTie::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTie::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTie::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTie::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTie::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());

        T100DiagramInvoking::OnTieStart(value);
    }
}

T100VOID T100CanvasStateTie::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{

}
