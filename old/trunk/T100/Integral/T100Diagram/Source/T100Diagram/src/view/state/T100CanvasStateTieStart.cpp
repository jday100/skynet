#include "T100CanvasStateTieStart.h"

#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateTieStart::T100CanvasStateTieStart() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateTieStart::~T100CanvasStateTieStart()
{
    //dtor
}

T100VOID T100CanvasStateTieStart::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieStart::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieStart::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieStart::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieStart::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateTieStart::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());

        T100DiagramInvoking::OnTieStart(value);
    }
}

T100VOID T100CanvasStateTieStart::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{

}
